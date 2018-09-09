#!/bin/bash

clear

g++ $1.cpp -DDBG -o $1

if [[ "$?"=="0" ]]; then
	./$1
fi

	