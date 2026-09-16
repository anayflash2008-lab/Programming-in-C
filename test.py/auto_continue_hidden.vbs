' Launches auto_continue_forever.bat with no visible console window.
' Copied into the Startup folder so the watcher comes back after a reboot.
CreateObject("WScript.Shell").Run """D:\Anay\C\test.py\auto_continue_forever.bat""", 0, False
