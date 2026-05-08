#!/bin/bash

if [ $# -lt 1 ] ; then read -p "Citeste numarul p: " p ; else p=$1 ; fi

shift

for num in $@
do
    if [ $num -lt $p ]
    then
        echo "$num"
    fi
done