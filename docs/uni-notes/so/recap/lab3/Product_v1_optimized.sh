#!/bin/bash

if [ $# -lt 1 ]
then
    echo -n "Introduceti primul nr: "
    read n
else
    n=$1
fi

if [ $# -lt 2 ]
then
    echo -n "Introduceti al doilea nr: "
    read m
else
    m=$2
fi

prod=0
for ((i=1; i<=m; i++))
do
    ((prod=prod+n))
done

echo "Rezultatul dintre $n si $m este: $prod"
