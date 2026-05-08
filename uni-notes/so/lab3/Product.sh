#!/bin/bash
if  [ $# -lt 1 ]
then
	echo -n "Enter first number: "
	read n
else
	n=$1
fi

if [ $# -lt 2 ]
then
	echo -n "Enter the second number: "
	read m
else
	m=$2
fi

prod=0
for i in `seq 1 $m`
do
	let prod=prod+$n
done

echo "Result of $n * $m is: $prod"


