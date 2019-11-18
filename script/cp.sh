#!/bin/bash
clear
g++ $1.cpp -DDBG -o $1
if [[ "$?"=="0" ]]; then
	echo Running
	./$1 < $1.in > $1$2.out
	echo END
fi