#!/bin/bash

clear

g++ $1.cpp -DDBG -I. -o $1

if [[ "$?"=="0" ]]; then
	echo Running
	./$1
fi

	