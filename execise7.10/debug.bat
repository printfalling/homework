@echo off
gcc -g %1 -o %1.exe
gdb %1.exe
pause
cmd /k cd C:\Users\john\Desktop\wang's files\