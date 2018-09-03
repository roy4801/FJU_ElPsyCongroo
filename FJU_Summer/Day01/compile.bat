@echo off

cls
g++ %1.cpp -o %1.exe -DDBG

if %ERRORLEVEL% EQU 0 (
	%1.exe
)