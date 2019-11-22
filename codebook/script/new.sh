#!/bin/bash

clear
cat template.cpp > $1.cpp
touch $1.in $1.out
echo $1 Created