#!/bin/bash
clear
g++ -std=c++11 $1.cpp -o $1
if [[ "$?" == "0" ]]; then
	echo Running
	./$1 < $1.in 2>&1 | tee $1$2.out # > $1$2.out
	echo END
fi