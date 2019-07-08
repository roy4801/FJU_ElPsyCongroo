#!/bin/bash

clear

mkdir $1
pushd $1 > /dev/null

cat ../template > $1.cpp

touch $1.in
touch $1.out

echo $1 CREATED
popd  > /dev/null