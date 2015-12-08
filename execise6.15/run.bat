@echo off
gcc %1 -o %1.exe 2> log.txt
%1.exe
pause
cmd /k cd C: