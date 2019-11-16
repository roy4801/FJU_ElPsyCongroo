@echo off

cls

if "%1"=="strip" (
	cls && g++ %2.cpp -DDBG -o %2.exe && %2.exe
	goto :EX
)

if "%1"=="dbg" (
	cls && g++ -g %2.cpp -DDBG -o %2.exe
	gdb %2.exe
	goto :EX
)

g++ %1.cpp -DDBG -DDBP -o %1.exe

if %ERRORLEVEL% EQU 0 (
	%1.exe < %1.in > %1.out
)

:EX