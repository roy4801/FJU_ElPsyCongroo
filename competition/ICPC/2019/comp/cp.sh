#!/bin/bash
clear
g++ -std=c++11 $1.cpp -o $1
if [[ "$?" == "0" ]]; then
    echo Running
    ./$1 < $1.in >$1$2.out
    echo END
    cat $1$2.out
fi
