#!/bin/bash

clear

g++ -std=c++11 $1.cpp -DDBG -I. -o $1

if [[ "$?"=="0" ]]; then
	echo Running
	./$1
fi

	