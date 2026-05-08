!#/bin/bash

if test $# -lt 1 ; then read -p "Enter first number: " n ; else n=$1 ; fi

if test $# -lt 2 ; then read -p "Enter second number: " m ; else m=$1 ; fi

prod=0
k=$m
while test $k -gt 0
do
	let prod=prod+$n
	let k=k-1
done

echo "Sum of $n $m times is: $prod"
