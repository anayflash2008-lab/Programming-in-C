@echo off
REM Keeps the AutoWorld auto-continue watcher alive forever.
REM If the watcher ever exits (crash, VS Code restart, error), wait 5s and
REM start it again. Close the window or kill python.exe to stop it.

cd /d "D:\Anay\C\test.py"

:loop
echo [%date% %time%] starting watcher >> continue.log
python -u auto_continue.py AutoWorld --watch --idle 10 --cooldown 10 >> continue.log 2>&1
echo [%date% %time%] watcher exited, restarting in 5s >> continue.log
timeout /t 5 /nobreak >nul
goto loop
