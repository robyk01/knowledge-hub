#!/bin/bash

if test $# -lt 1
then
	read -p "Enter number: " n
else
	n=$1
fi

if test $# -lt 2 ; then read -p "Enter the second number: " m ; else m=$1 ; fi

prod=0
for i in `seq 1 $m`
do
    let prod=prod+$n
done

echo "First number is $n and second number is $m and the sum is $prod"
