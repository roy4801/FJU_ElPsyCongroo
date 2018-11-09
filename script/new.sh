#!/bin/bash

clear

cat template | sed -e "s/PROBLEM \"\"/PROBLEM \"$1\"/g" > $1.cpp
touch $1.in
touch $1.out

echo $1 Created