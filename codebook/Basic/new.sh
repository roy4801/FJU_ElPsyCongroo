#!/bin/bash
clear
mkdir $1
pushd $1 > /dev/null
cat ../template.cpp \
| sed -e "s/{1}/$1/g; s/{2}/$2/g" > $1.cpp
touch $1.in $1.out
echo $1 CREATED
popd > /dev/null