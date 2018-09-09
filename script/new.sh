#!/bin/bash

clear

cat template > $1.cpp
touch $1.in
touch $1.out

echo $1 Created