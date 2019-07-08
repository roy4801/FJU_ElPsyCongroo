#!/bin/bash
clear
pushd $1 > /dev/null
echo compiling...
g++ -DDBG $1.cpp -o $1
if [[ "$?" == "0" ]]; then
	echo FINISHED
	./$1
fi
popd > /dev/null