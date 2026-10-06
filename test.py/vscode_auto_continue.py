"""Auto-continue a Claude session in another VS Code window (Windows only).

Monitor mode watches the target window's pixels and only types "continue" +
Enter when the window has been visually still for a while - i.e. Claude has
stopped streaming and is waiting on you.

    python vscode_auto_continue.py --list
    python vscode_auto_continue.py --match AutoWorld                 # send once
    python vscode_auto_continue.py --match AutoWorld --monitor       # watch + auto-send
    python vscode_auto_continue.py --match AutoWorld --monitor --verbose

Keystrokes go to whatever is focused *inside* that window, so leave the Claude
prompt input box focused there.
"""

import argparse
import ctypes
import os
import re
import sys
import time
from ctypes import wintypes

if sys.platform != "win32":
    sys.exit("This script only runs on Windows.")

user32 = ctypes.WinDLL("user32", use_last_error=True)
kernel32 = ctypes.WinDLL("kernel32", use_last_error=True)
gdi32 = ctypes.WinDLL("gdi32", use_last_error=True)

SW_RESTORE = 9
VK_RETURN = 0x0D
VK_MENU = 0x12
INPUT_KEYBOARD = 1
KEYEVENTF_KEYUP = 0x0002
KEYEVENTF_SCANCODE = 0x0008
KEYEVENTF_UNICODE = 0x0004
SRCCOPY = 0x00CC0020
HALFTONE = 4
DIB_RGB_COLORS = 0
PW_RENDERFULLCONTENT = 0x00000002


# --- SendInput plumbing ----------------------------------------------------

class KEYBDINPUT(ctypes.Structure):
    _fields_ = [("wVk", wintypes.WORD),
                ("wScan", wintypes.WORD),
                ("dwFlags", wintypes.DWORD),
                ("time", wintypes.DWORD),
                ("dwExtraInfo", ctypes.POINTER(ctypes.c_ulong))]


class MOUSEINPUT(ctypes.Structure):
    _fields_ = [("dx", wintypes.LONG),
                ("dy", wintypes.LONG),
                ("mouseData", wintypes.DWORD),
                ("dwFlags", wintypes.DWORD),
                ("time", wintypes.DWORD),
                ("dwExtraInfo", ctypes.POINTER(ctypes.c_ulong))]


class HARDWAREINPUT(ctypes.Structure):
    _fields_ = [("uMsg", wintypes.DWORD),
                ("wParamL", wintypes.WORD),
                ("wParamH", wintypes.WORD)]


class _INPUTunion(ctypes.Union):
    _fields_ = [("ki", KEYBDINPUT), ("mi", MOUSEINPUT), ("hi", HARDWAREINPUT)]


class INPUT(ctypes.Structure):
    _fields_ = [("type", wintypes.DWORD), ("union", _INPUTunion)]


class LASTINPUTINFO(ctypes.Structure):
    _fields_ = [("cbSize", wintypes.UINT), ("dwTime", wintypes.DWORD)]


def _send(*inputs):
    n = len(inputs)
    arr = (INPUT * n)(*inputs)
    if user32.SendInput(n, arr, ctypes.sizeof(INPUT)) != n:
        raise ctypes.WinError(ctypes.get_last_error())


def _key_event(vk=0, scan=0, flags=0):
    return INPUT(type=INPUT_KEYBOARD,
                 union=_INPUTunion(ki=KEYBDINPUT(vk, scan, flags, 0, None)))


user32.MapVirtualKeyW.argtypes = [wintypes.UINT, wintypes.UINT]
user32.MapVirtualKeyW.restype = wintypes.UINT


def tap_vk(vk, mode="vk"):
    """Press and release a virtual key.

    The scan code matters: Chromium (so VS Code) derives KeyboardEvent.code
    from it, and a keystroke sent with wScan=0 arrives as an unidentified key
    that the keybinding layer ignores. Always send the real scan code.
    """
    scan = user32.MapVirtualKeyW(vk, 0)         # MAPVK_VK_TO_VSC
    if mode == "scancode":                      # hardware-style, vk omitted
        down = _key_event(scan=scan, flags=KEYEVENTF_SCANCODE)
        up = _key_event(scan=scan, flags=KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP)
    else:
        down = _key_event(vk=vk, scan=scan)
        up = _key_event(vk=vk, scan=scan, flags=KEYEVENTF_KEYUP)
    _send(down, up)


def _code_units(ch):
    """UTF-16 code units for a character (handles astral chars)."""
    cp = ord(ch)
    if cp <= 0xFFFF:
        return (cp,)
    cp -= 0x10000
    return (0xD800 + (cp >> 10), 0xDC00 + (cp & 0x3FF))


def type_text(text, char_delay=0.01):
    for ch in text:
        for code in _code_units(ch):
            _send(_key_event(scan=code, flags=KEYEVENTF_UNICODE),
                  _key_event(scan=code, flags=KEYEVENTF_UNICODE | KEYEVENTF_KEYUP))
        time.sleep(char_delay)


def user_idle_seconds():
    """Seconds since the human last touched the keyboard or mouse."""
    lii = LASTINPUTINFO(ctypes.sizeof(LASTINPUTINFO), 0)
    if not user32.GetLastInputInfo(ctypes.byref(lii)):
        return 0.0
    now = kernel32.GetTickCount() & 0xFFFFFFFF
    return ((now - lii.dwTime) & 0xFFFFFFFF) / 1000.0


# --- Window discovery ------------------------------------------------------

WNDENUMPROC = ctypes.WINFUNCTYPE(wintypes.BOOL, wintypes.HWND, wintypes.LPARAM)


def list_windows():
    """Return [(hwnd, title, pid)] for every visible titled top-level window."""
    found = []

    def cb(hwnd, _lparam):
        if not user32.IsWindowVisible(hwnd):
            return True
        length = user32.GetWindowTextLengthW(hwnd)
        if length == 0:
            return True
        buf = ctypes.create_unicode_buffer(length + 1)
        user32.GetWindowTextW(hwnd, buf, length + 1)
        pid = wintypes.DWORD()
        user32.GetWindowThreadProcessId(hwnd, ctypes.byref(pid))
        found.append((hwnd, buf.value, pid.value))
        return True

    user32.EnumWindows(WNDENUMPROC(cb), 0)
    return found


def vscode_windows(match=None, exclude=None):
    """VS Code windows whose title matches `match` and not `exclude` (regex)."""
    m = re.compile(match, re.I) if match else None
    x = re.compile(exclude, re.I) if exclude else None
    out = []
    for hwnd, title, pid in list_windows():
        if "visual studio code" not in title.lower():
            continue
        if m and not m.search(title):
            continue
        if x and x.search(title):
            continue
        out.append((hwnd, title, pid))
    return out


def window_title(hwnd):
    length = user32.GetWindowTextLengthW(hwnd)
    buf = ctypes.create_unicode_buffer(length + 1)
    user32.GetWindowTextW(hwnd, buf, length + 1)
    return buf.value


# --- Window capture (for activity detection) -------------------------------
# Handles are pointer-sized; declare restypes so 64-bit values aren't truncated.

user32.GetWindowDC.restype = ctypes.c_void_p
user32.GetWindowDC.argtypes = [wintypes.HWND]
user32.ReleaseDC.argtypes = [wintypes.HWND, ctypes.c_void_p]
user32.PrintWindow.argtypes = [wintypes.HWND, ctypes.c_void_p, wintypes.UINT]
gdi32.CreateCompatibleDC.restype = ctypes.c_void_p
gdi32.CreateCompatibleDC.argtypes = [ctypes.c_void_p]
gdi32.CreateCompatibleBitmap.restype = ctypes.c_void_p
gdi32.CreateCompatibleBitmap.argtypes = [ctypes.c_void_p, ctypes.c_int, ctypes.c_int]
gdi32.SelectObject.restype = ctypes.c_void_p
gdi32.SelectObject.argtypes = [ctypes.c_void_p, ctypes.c_void_p]
gdi32.DeleteObject.argtypes = [ctypes.c_void_p]
gdi32.DeleteDC.argtypes = [ctypes.c_void_p]
gdi32.SetStretchBltMode.argtypes = [ctypes.c_void_p, ctypes.c_int]
gdi32.StretchBlt.argtypes = [ctypes.c_void_p, ctypes.c_int, ctypes.c_int, ctypes.c_int,
                             ctypes.c_int, ctypes.c_void_p, ctypes.c_int, ctypes.c_int,
                             ctypes.c_int, ctypes.c_int, wintypes.DWORD]
gdi32.GetDIBits.restype = ctypes.c_int
gdi32.GetDIBits.argtypes = [ctypes.c_void_p, ctypes.c_void_p, wintypes.UINT, wintypes.UINT,
                            ctypes.c_void_p, ctypes.c_void_p, wintypes.UINT]


class BITMAPINFOHEADER(ctypes.Structure):
    _fields_ = [("biSize", wintypes.DWORD), ("biWidth", wintypes.LONG),
                ("biHeight", wintypes.LONG), ("biPlanes", wintypes.WORD),
                ("biBitCount", wintypes.WORD), ("biCompression", wintypes.DWORD),
                ("biSizeImage", wintypes.DWORD), ("biXPelsPerMeter", wintypes.LONG),
                ("biYPelsPerMeter", wintypes.LONG), ("biClrUsed", wintypes.DWORD),
                ("biClrImportant", wintypes.DWORD)]


class BITMAPINFO(ctypes.Structure):
    _fields_ = [("bmiHeader", BITMAPINFOHEADER), ("bmiColors", wintypes.DWORD * 3)]


THUMB_W, THUMB_H = 192, 128


def capture_thumb(hwnd):
    """Grab the window and shrink it to a small RGBA buffer, or None.

    PrintWindow with PW_RENDERFULLCONTENT works on Electron/Chromium windows
    even when they are behind other windows, so the target need not be visible.
    """
    if user32.IsIconic(hwnd) or not user32.IsWindow(hwnd):
        return None
    rect = wintypes.RECT()
    if not user32.GetWindowRect(hwnd, ctypes.byref(rect)):
        return None
    w, h = rect.right - rect.left, rect.bottom - rect.top
    if w <= 0 or h <= 0:
        return None

    win_dc = src_dc = dst_dc = src_bmp = dst_bmp = None
    try:
        win_dc = user32.GetWindowDC(hwnd)
        if not win_dc:
            return None
        src_dc = gdi32.CreateCompatibleDC(win_dc)
        dst_dc = gdi32.CreateCompatibleDC(win_dc)
        src_bmp = gdi32.CreateCompatibleBitmap(win_dc, w, h)
        dst_bmp = gdi32.CreateCompatibleBitmap(win_dc, THUMB_W, THUMB_H)
        if not all((src_dc, dst_dc, src_bmp, dst_bmp)):
            return None
        old_src = gdi32.SelectObject(src_dc, src_bmp)
        old_dst = gdi32.SelectObject(dst_dc, dst_bmp)

        if not user32.PrintWindow(hwnd, src_dc, PW_RENDERFULLCONTENT):
            return None
        gdi32.SetStretchBltMode(dst_dc, HALFTONE)
        if not gdi32.StretchBlt(dst_dc, 0, 0, THUMB_W, THUMB_H,
                                src_dc, 0, 0, w, h, SRCCOPY):
            return None

        # GetDIBits requires the bitmap not be selected into a DC.
        gdi32.SelectObject(src_dc, old_src)
        gdi32.SelectObject(dst_dc, old_dst)

        bmi = BITMAPINFO()
        bmi.bmiHeader.biSize = ctypes.sizeof(BITMAPINFOHEADER)
        bmi.bmiHeader.biWidth = THUMB_W
        bmi.bmiHeader.biHeight = -THUMB_H          # top-down
        bmi.bmiHeader.biPlanes = 1
        bmi.bmiHeader.biBitCount = 32
        bmi.bmiHeader.biCompression = 0            # BI_RGB
        buf = ctypes.create_string_buffer(THUMB_W * THUMB_H * 4)
        if not gdi32.GetDIBits(dst_dc, dst_bmp, 0, THUMB_H, buf,
                               ctypes.byref(bmi), DIB_RGB_COLORS):
            return None
        return buf.raw
    finally:
        for obj in (src_bmp, dst_bmp):
            if obj:
                gdi32.DeleteObject(obj)
        for dc in (src_dc, dst_dc):
            if dc:
                gdi32.DeleteDC(dc)
        if win_dc:
            user32.ReleaseDC(hwnd, win_dc)


def diff_fraction(a, b, tol=12):
    """Fraction of thumbnail pixels whose brightness moved more than `tol`."""
    if a is None or b is None or len(a) != len(b):
        return 1.0
    changed = total = 0
    for i in range(0, len(a), 4):
        pa = a[i] + a[i + 1] + a[i + 2]
        pb = b[i] + b[i + 1] + b[i + 2]
        if abs(pa - pb) > tol * 3:
            changed += 1
        total += 1
    return changed / total if total else 1.0


# --- Focus handling --------------------------------------------------------

def force_foreground(hwnd):
    """Bring hwnd to the front, working around the focus-stealing lock."""
    if user32.IsIconic(hwnd):
        user32.ShowWindow(hwnd, SW_RESTORE)
        time.sleep(0.2)

    if user32.SetForegroundWindow(hwnd) and user32.GetForegroundWindow() == hwnd:
        return True

    # Trick 1: a synthetic ALT tap unlocks SetForegroundWindow.
    tap_vk(VK_MENU)
    user32.SetForegroundWindow(hwnd)
    if user32.GetForegroundWindow() == hwnd:
        return True

    # Trick 2: attach our input queue to the foreground window's thread.
    fg = user32.GetForegroundWindow()
    cur_tid = kernel32.GetCurrentThreadId()
    fg_tid = user32.GetWindowThreadProcessId(fg, None)
    if fg_tid and fg_tid != cur_tid:
        user32.AttachThreadInput(cur_tid, fg_tid, True)
        try:
            user32.BringWindowToTop(hwnd)
            user32.SetForegroundWindow(hwnd)
        finally:
            user32.AttachThreadInput(cur_tid, fg_tid, False)
    return user32.GetForegroundWindow() == hwnd


def send_to_window(hwnd, text, press_enter=True, enter_mode="vk",
                   settle=0.4, enter_delay=0.3, attempts=3, verify=True):
    """Focus hwnd, type text, press Enter, then restore the previous window.

    Returns one of: "sent", "sent-unverified" (keystrokes went in but the
    window never repainted), "focus-failed" (nothing was typed).
    """
    caller = user32.GetForegroundWindow()
    for i in range(attempts):
        if force_foreground(hwnd):
            break
        time.sleep(0.5)                            # foreground lock, back off
    else:
        return "focus-failed"

    try:
        time.sleep(settle)
        if user32.GetForegroundWindow() != hwnd:   # focus slipped away
            return "focus-failed"
        before = capture_thumb(hwnd) if verify else None
        type_text(text)
        if press_enter:
            time.sleep(enter_delay)                # let the editor settle
            tap_vk(VK_RETURN, enter_mode)
        if before is None:
            return "sent"
        time.sleep(1.2)
        if diff_fraction(before, capture_thumb(hwnd)) < 0.0005:
            return "sent-unverified"               # nothing on screen moved
        return "sent"
    finally:
        if caller and caller != hwnd and user32.IsWindow(caller):
            force_foreground(caller)


# --- Logging ---------------------------------------------------------------

class Log:
    def __init__(self, path=None):
        self.fh = open(path, "a", encoding="utf-8") if path else None

    def __call__(self, msg):
        line = f"[{time.strftime('%H:%M:%S')}] {msg}"
        if sys.stdout:                  # pythonw.exe has no stdout
            print(line, flush=True)
        if self.fh:
            self.fh.write(line + "\n")
            self.fh.flush()


# --- Modes -----------------------------------------------------------------

def resolve_target(args, self_hwnd):
    targets = vscode_windows(args.match, args.exclude)
    if not args.include_self:
        targets = [t for t in targets if t[0] != self_hwnd]
    if not targets:
        return None, "No matching VS Code window found (try --list)."
    if len(targets) > 1 and args.index is None:
        lines = [f"  [{i}] {t[1]}" for i, t in enumerate(targets)]
        return None, ("Multiple VS Code windows matched; narrow with --match or "
                      "pick one with --index:\n" + "\n".join(lines))
    return targets[args.index or 0], None


def monitor(args, hwnd, log):
    """Watch the window and send only after it has been still long enough."""
    log(f"monitoring: {window_title(hwnd)}")
    log(f"idle-for={args.idle_for}s sample={args.sample}s "
        f"threshold={args.threshold} cooldown={args.cooldown}s "
        f"user-idle={args.user_idle}s pid={os.getpid()}")

    prev = None
    last_change = time.monotonic()
    last_send = 0.0
    sends = 0
    reported_ready = False
    warned_blind = False
    last_beat = 0.0

    while True:
        if not user32.IsWindow(hwnd):
            found = vscode_windows(args.match, args.exclude)
            if not found:
                log("target window closed - waiting for it to come back")
                time.sleep(args.sample)
                continue
            hwnd = found[0][0]
            prev, last_change = None, time.monotonic()
            log(f"re-attached to: {window_title(hwnd)}")

        frame = capture_thumb(hwnd)
        now = time.monotonic()

        if frame is None:                       # minimised or capture failed
            last_change = now                   # can't see it, assume busy
            prev = None
            if not warned_blind:
                log("cannot see the window (minimised?) - holding off. "
                    "Un-minimise it, or restart with --restore.")
                warned_blind = True
            time.sleep(args.sample)
            continue
        warned_blind = False

        if prev is not None:
            diff = diff_fraction(prev, frame, args.tol)
            if diff > args.threshold:
                last_change = now
                reported_ready = False
            if args.verbose:
                log(f"diff={diff:.5f} still={now - last_change:5.1f}s")
        prev = frame

        still = now - last_change
        since_send = now - last_send if last_send else 1e9
        human = user_idle_seconds()

        # A silent monitor is indistinguishable from a dead one: say what it sees.
        if not args.verbose and args.heartbeat and now - last_beat >= args.heartbeat:
            wait = max(0.0, args.cooldown - since_send)
            log(f"watching: still={still:.0f}s (need {args.idle_for:.0f}s), "
                f"you idle {human:.0f}s"
                + (f", cooldown {wait:.0f}s" if wait else "")
                + f", sends={sends}")
            last_beat = now

        if still >= args.idle_for and since_send >= args.cooldown:
            if human < args.user_idle:
                if args.verbose:
                    log(f"idle {still:.0f}s but you were active {human:.0f}s ago - holding")
            else:
                status = send_to_window(hwnd, args.text, press_enter=not args.no_enter,
                                        enter_mode=args.enter_mode)
                sends += 1
                log(f"{status} {args.text!r} #{sends} after {still:.0f}s idle")
                if status == "sent-unverified":
                    log("  the window did not repaint - the Claude prompt box may "
                        "not have keyboard focus in that window")
                elif status == "focus-failed":
                    log("  could not bring the window to the front - nothing typed")
                last_send = time.monotonic()
                last_change = time.monotonic()
                prev = None
                reported_ready = False
                if args.max_sends and sends >= args.max_sends:
                    log(f"reached --max-sends {args.max_sends}, exiting")
                    return
                time.sleep(1.0)
                continue
        elif still >= args.idle_for and not reported_ready:
            log(f"idle {still:.0f}s but in cooldown "
                f"({args.cooldown - since_send:.0f}s left)")
            reported_ready = True

        time.sleep(args.sample)


def main():
    p = argparse.ArgumentParser(
        description=__doc__,
        formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--list", action="store_true", help="list VS Code windows and exit")
    p.add_argument("--match", help="regex the target window title must match")
    p.add_argument("--exclude", help="regex of window titles to skip")
    p.add_argument("--index", type=int, help="pick the Nth match (see --list)")
    p.add_argument("--text", default="continue", help="text to type (default: continue)")
    p.add_argument("--no-enter", action="store_true", help="type the text but don't press Enter")
    p.add_argument("--enter-mode", choices=("vk", "scancode"), default="vk",
                   help="how to send Enter; try scancode if vk does not submit")
    p.add_argument("--include-self", action="store_true",
                   help="allow targeting the window that was focused at launch")
    p.add_argument("--dry-run", action="store_true", help="show the target, send nothing")

    g = p.add_argument_group("monitor mode")
    g.add_argument("--monitor", action="store_true",
                   help="watch the window and send only when it goes quiet")
    g.add_argument("--idle-for", type=float, default=45.0,
                   help="seconds of no visual change before sending (default: 45)")
    g.add_argument("--sample", type=float, default=2.0,
                   help="seconds between screenshots (default: 2)")
    g.add_argument("--threshold", type=float, default=0.002,
                   help="fraction of changed pixels that counts as activity (default: 0.002)")
    g.add_argument("--tol", type=int, default=12,
                   help="per-pixel brightness tolerance, 0-255 (default: 12)")
    g.add_argument("--cooldown", type=float, default=120.0,
                   help="minimum seconds between two sends (default: 120)")
    g.add_argument("--user-idle", type=float, default=5.0,
                   help="require this many seconds since your last keypress (default: 5)")
    g.add_argument("--max-sends", type=int, default=0,
                   help="stop after N sends; 0 = unlimited (default: 0)")
    g.add_argument("--restore", action="store_true",
                   help="un-minimise the target at startup (pixels are unreadable "
                        "while it is minimised)")
    g.add_argument("--verbose", action="store_true", help="log every sample")
    g.add_argument("--heartbeat", type=float, default=60.0,
                   help="seconds between 'still watching' status lines; 0 = off "
                        "(default: 60)")
    g.add_argument("--log", help="also append output to this file")

    # one-shot mode
    p.add_argument("--countdown", type=float, default=3.0,
                   help="seconds to wait before a one-shot send (default: 3)")
    args = p.parse_args()

    if args.list:
        wins = vscode_windows()
        if not wins:
            print("No VS Code windows found.")
        for i, (hwnd, title, pid) in enumerate(wins):
            print(f"[{i}] hwnd={hwnd} pid={pid}  {title}")
        return 0

    self_hwnd = user32.GetForegroundWindow()   # the window you launched from
    target, err = resolve_target(args, self_hwnd)
    if err:
        print(err, file=sys.stderr)
        return 1

    hwnd, title, _pid = target
    log = Log(args.log)

    if args.dry_run:
        frame = capture_thumb(hwnd)
        print(f"Target: {title}")
        print(f"Capture: {'ok' if frame else 'FAILED - idle detection will not work'}")
        print(f"Would send {args.text!r}" + ("" if args.no_enter else " + Enter"))
        return 0

    if args.monitor:
        if args.restore and user32.IsIconic(hwnd):
            caller = user32.GetForegroundWindow()
            user32.ShowWindow(hwnd, SW_RESTORE)
            time.sleep(0.4)
            if caller and caller != hwnd and user32.IsWindow(caller):
                force_foreground(caller)        # don't hijack the user's screen
            log("restored the target window (was minimised)")
        try:
            monitor(args, hwnd, log)
        except KeyboardInterrupt:
            log("stopped")
        return 0

    log(f"target: {title}")
    if args.countdown > 0:
        log(f"sending {args.text!r} in {args.countdown:g}s (Ctrl+C to abort)")
        time.sleep(args.countdown)
    status = send_to_window(hwnd, args.text, press_enter=not args.no_enter,
                            enter_mode=args.enter_mode)
    log(status)
    if status == "sent-unverified":
        log("  the window did not repaint - the Claude prompt box may not have "
            "keyboard focus in that window")
    return 0 if status.startswith("sent") else 1


if __name__ == "__main__":
    sys.exit(main())
