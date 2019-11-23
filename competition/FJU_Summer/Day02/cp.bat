@echo off

cls

g++ %1.cpp -DDBG -o %1.exe

if %ERRORLEVEL% EQU 0 (
	%1.exe
)