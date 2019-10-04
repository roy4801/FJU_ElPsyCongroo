@echo off

cls

g++ -std=c++11 %1.cpp -o %1.exe
echo COMPILEING...

if %ERRORLEVEL% EQU 0 (
	echo FINISH
	%1.exe < %1.in > %1.out
)

