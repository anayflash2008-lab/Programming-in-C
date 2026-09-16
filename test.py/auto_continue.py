"""Type "continue" + Enter into another VS Code window.

    python auto_continue.py AutoWorld            send once, now
    python auto_continue.py AutoWorld --watch    send only when it goes quiet

Watch mode reads the modification time of that session's Claude Code
transcript. Claude appends to it while working, so when it has not been
touched for --idle seconds the session is genuinely waiting. This works even
when the window is covered or minimised, and it never fires mid-response.
It also holds off while you are typing, so it will not steal focus from you.

The caret must already be in the Claude prompt in that window - a click in a
code file there and the next "continue" lands in your source.
"""

import argparse
import ctypes
import json
import os
import sys
import time
from ctypes import wintypes

user32 = ctypes.WinDLL("user32", use_last_error=True)
kernel32 = ctypes.WinDLL("kernel32", use_last_error=True)


# --- keyboard --------------------------------------------------------------

class KEYBDINPUT(ctypes.Structure):
    _fields_ = [("wVk", wintypes.WORD), ("wScan", wintypes.WORD),
                ("dwFlags", wintypes.DWORD), ("time", wintypes.DWORD),
                ("dwExtraInfo", ctypes.POINTER(ctypes.c_ulong))]


class INPUT(ctypes.Structure):
    class _U(ctypes.Union):
        _fields_ = [("ki", KEYBDINPUT), ("pad", ctypes.c_ubyte * 32)]
    _fields_ = [("type", wintypes.DWORD), ("u", _U)]


class LASTINPUTINFO(ctypes.Structure):
    _fields_ = [("cbSize", wintypes.UINT), ("dwTime", wintypes.DWORD)]


user32.VkKeyScanW.restype = ctypes.c_short


def key(vk=0, scan=0, flags=0):
    return INPUT(type=1, u=INPUT._U(ki=KEYBDINPUT(vk, scan, flags, 0, None)))


def send(*events):
    arr = (INPUT * len(events))(*events)
    user32.SendInput(len(events), arr, ctypes.sizeof(INPUT))


def tap(vk, hold=0.06):
    """Press a key the way a person does.

    Two things matter, and both were needed to make Enter register in VS Code:
    the real scan code (Chromium builds KeyboardEvent.code from it), and a
    short hold - a down/up pair with no gap gets coalesced and ignored.
    """
    scan = user32.MapVirtualKeyW(vk, 0)
    send(key(vk=vk, scan=scan))
    time.sleep(hold)
    send(key(vk=vk, scan=scan, flags=0x0002))


def type_text(text):
    """Type with real virtual keys; Electron ignores Unicode packets."""
    for ch in text:
        vk = user32.VkKeyScanW(ord(ch))
        if vk == -1:
            c = ord(ch)
            send(key(scan=c, flags=0x0004), key(scan=c, flags=0x0004 | 0x0002))
        else:
            shift, vk = (vk >> 8) & 1, vk & 0xFF
            sh_scan = user32.MapVirtualKeyW(0x10, 0)
            if shift:
                send(key(vk=0x10, scan=sh_scan))
            tap(vk, hold=0.03)
            if shift:
                send(key(vk=0x10, scan=sh_scan, flags=0x0002))
        time.sleep(0.02)


def user_idle():
    """Seconds since you last touched the keyboard or mouse."""
    lii = LASTINPUTINFO(ctypes.sizeof(LASTINPUTINFO), 0)
    if not user32.GetLastInputInfo(ctypes.byref(lii)):
        return 0.0
    now = kernel32.GetTickCount() & 0xFFFFFFFF
    return ((now - lii.dwTime) & 0xFFFFFFFF) / 1000.0


# --- windows ---------------------------------------------------------------

def find_window(match):
    """First visible VS Code window whose title contains `match`."""
    hits = []

    def cb(hwnd, _):
        if not user32.IsWindowVisible(hwnd):
            return True
        n = user32.GetWindowTextLengthW(hwnd)
        if n:
            buf = ctypes.create_unicode_buffer(n + 1)
            user32.GetWindowTextW(hwnd, buf, n + 1)
            t = buf.value
            if "Visual Studio Code" in t and (not match or match.lower() in t.lower()):
                hits.append((hwnd, t))
        return True

    proto = ctypes.WINFUNCTYPE(wintypes.BOOL, wintypes.HWND, wintypes.LPARAM)
    user32.EnumWindows(proto(cb), 0)
    return hits[0] if hits else (None, None)


def focus(hwnd, attempts=4):
    """Windows blocks background apps from stealing focus; work around it."""
    for i in range(attempts):
        if _focus_once(hwnd):
            return True
        time.sleep(0.4 + 0.3 * i)                   # let the lock lapse
    return False


def _focus_once(hwnd):
    if user32.IsIconic(hwnd):
        user32.ShowWindow(hwnd, 9)                  # SW_RESTORE
        time.sleep(0.3)

    # Drop the foreground lock timeout, which is what makes
    # SetForegroundWindow silently fail for a background process.
    user32.SystemParametersInfoW(0x2001, 0, ctypes.c_void_p(0), 0)  # SPI_SETFOREGROUNDLOCKTIMEOUT

    user32.SetForegroundWindow(hwnd)
    if user32.GetForegroundWindow() == hwnd:
        return True

    # Borrow the foreground window's input queue, then take focus.
    # (Do NOT tap ALT to unlock focus: ALT activates VS Code's menu bar, and
    # the menu then eats the Enter instead of the prompt submitting.)
    fg = user32.GetForegroundWindow()
    mine = kernel32.GetCurrentThreadId()
    theirs = user32.GetWindowThreadProcessId(fg, None)
    if theirs and theirs != mine:
        user32.AttachThreadInput(mine, theirs, True)
        user32.BringWindowToTop(hwnd)
        user32.SetForegroundWindow(hwnd)
        user32.AttachThreadInput(mine, theirs, False)
    return user32.GetForegroundWindow() == hwnd


# --- actions ---------------------------------------------------------------

def send_continue(hwnd, title, text="continue"):
    back_to = user32.GetForegroundWindow()
    if not focus(hwnd):
        print("could not focus:", title, flush=True)
        return False
    time.sleep(0.5)
    if user32.GetForegroundWindow() != hwnd:        # never type into the wrong window
        print("focus slipped, nothing typed", flush=True)
        return False
    type_text(text)
    time.sleep(0.3)
    tap(0x0D)                                       # Enter
    print(time.strftime("[%H:%M:%S]"), "sent to:", title, flush=True)
    if back_to and back_to != hwnd and user32.IsWindow(back_to):
        time.sleep(0.4)
        focus(back_to)
    return True


def find_transcript(match):
    """Newest Claude Code transcript for the project matching `match`.

    Claude Code appends to this file as it works, so its modification time is
    a direct read on whether that session is busy - and unlike watching the
    screen, it works while the window is covered or minimised.
    """
    base = os.path.join(os.path.expanduser("~"), ".claude", "projects")
    if not os.path.isdir(base):
        return None
    best = None
    for d in os.listdir(base):
        if match and match.lower().replace(" ", "") not in d.lower().replace("-", ""):
            continue
        full = os.path.join(base, d)
        if not os.path.isdir(full):
            continue
        for f in os.listdir(full):
            if f.endswith(".jsonl"):
                fp = os.path.join(full, f)
                if best is None or os.path.getmtime(fp) > os.path.getmtime(best):
                    best = fp
    return best


def session_waiting(path, tail=262144):
    """True only when the assistant has finished its turn.

    A quiet file is not enough: during a long tool call nothing is written for
    a while, and firing then submits into a running turn, which interrupts it.
    The last entry tells us the real state - stop_reason "tool_use" or a
    pending tool_use block means it is still working.
    """
    try:
        with open(path, "rb") as f:
            f.seek(0, 2)
            size = f.tell()
            f.seek(max(0, size - tail))
            data = f.read()
    except OSError:
        return False

    for line in reversed([l for l in data.splitlines() if l.strip()]):
        try:
            e = json.loads(line.decode("utf-8", "replace"))
        except Exception:
            continue
        kind = e.get("type")
        if kind not in ("assistant", "user"):
            continue                            # skip meta rows
        msg = e.get("message") or {}
        content = msg.get("content")

        if kind == "user":
            # A tool result or a fresh prompt means the assistant is about to
            # work. An interruption marker means the opposite: it stopped and
            # is sitting idle, so that is a safe moment to send.
            text = content if isinstance(content, str) else ""
            if isinstance(content, list):
                for b in content:
                    if isinstance(b, dict):
                        if b.get("type") == "tool_result":
                            return False
                        if b.get("type") == "text":
                            text += str(b.get("text") or "")
            return text.strip().startswith("[Request interrupted")

        if isinstance(content, list):
            for b in content:
                if isinstance(b, dict) and b.get("type") == "tool_use":
                    return False                # tool still running
        if msg.get("stop_reason") in (None, "tool_use"):
            return False
        return True                             # end_turn: waiting for you
    return False


def watch(match, idle_for, cooldown, sample, quiet_you, minutes=0):
    # Wait for the window and the transcript rather than giving up: VS Code
    # may not be open yet, or may be restarted while this keeps running.
    hwnd = title = transcript = None
    warned = False
    while not (hwnd and transcript):
        hwnd, title = find_window(match)
        transcript = find_transcript(match)
        if hwnd and transcript:
            break
        if not warned:
            print(time.strftime("[%H:%M:%S]"),
                  "waiting for VS Code window / transcript matching", repr(match),
                  flush=True)
            warned = True
        time.sleep(5)

    print(time.strftime("[%H:%M:%S]"), "watching:", title, flush=True)
    print("  transcript:", transcript, flush=True)
    print("  idle=%gs cooldown=%gs sample=%gs" % (idle_for, cooldown, sample), flush=True)

    deadline = time.monotonic() + minutes * 60 if minutes else None
    last_send = 0.0
    sent_at_mtime = None
    while True:
        time.sleep(sample)
        if deadline and time.monotonic() > deadline:
            print(time.strftime("[%H:%M:%S]"), "time limit reached, stopping", flush=True)
            return 0
        try:
            mtime = os.path.getmtime(transcript)
        except OSError:
            transcript = find_transcript(match) or transcript
            continue                            # rotated or busy; try again
        quiet = time.time() - mtime

        if mtime == sent_at_mtime:
            continue        # our last "continue" has not registered yet
        if quiet < idle_for:
            continue                            # still writing: Claude is working
        if not session_waiting(transcript):
            continue                            # mid tool call: do not interrupt
        if time.monotonic() - last_send < cooldown:
            continue
        if user_idle() < quiet_you:             # don't grab focus while you type
            continue
        if not user32.IsWindow(hwnd):
            hwnd, title = find_window(match)
            if not hwnd:
                continue

        print(time.strftime("[%H:%M:%S]"),
              "idle %.0fs -> sending" % quiet, flush=True)
        # Only treat it as sent if it really went in; otherwise a single
        # focus failure would wedge the watcher waiting for a transcript
        # change that can never come.
        if send_continue(hwnd, title):
            sent_at_mtime = mtime
        last_send = time.monotonic()


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("match", nargs="?", default="", help="part of the window title")
    ap.add_argument("--watch", action="store_true", help="send only when the window is quiet")
    ap.add_argument("--idle", type=float, default=10.0, help="seconds of stillness (default 10)")
    ap.add_argument("--cooldown", type=float, default=60.0, help="min seconds between sends")
    ap.add_argument("--sample", type=float, default=2.0, help="seconds between screenshots")
    ap.add_argument("--threshold", type=float, default=0.002, help="pixel change = activity")
    ap.add_argument("--your-idle", type=float, default=3.0, help="wait until you stop typing")
    ap.add_argument("--minutes", type=float, default=0, help="stop after N minutes; 0 = run until stopped")
    a = ap.parse_args()

    if a.watch:
        while True:                     # forever: survive any unexpected error
            try:
                return watch(a.match, a.idle, a.cooldown, a.sample,
                             a.your_idle, a.minutes)
            except KeyboardInterrupt:
                print("stopped")
                return 0
            except Exception as e:
                print(time.strftime("[%H:%M:%S]"),
                      "error: %s - restarting in 5s" % e, flush=True)
                time.sleep(5)

    hwnd, title = find_window(a.match)
    if not hwnd:
        print("no VS Code window matching", repr(a.match))
        return 1
    return 0 if send_continue(hwnd, title) else 1


if __name__ == "__main__":
    sys.exit(main())
