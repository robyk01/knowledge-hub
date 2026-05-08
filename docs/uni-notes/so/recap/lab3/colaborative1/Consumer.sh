#!/bin/bash

n=$(echo $values | cut -d" " -f1)
m=$(echo $values | cut -d" " -f2)

if [ -z $n -a -z $m ] ; then exit 1; fi

if [ $m -lt 0 ] ; then exit 2; fi

prod=0
for ((i=1; i<=m; i++))
do
    ((prod+=n))
done

echo "Rezultatul lui $n*$m este $prod"
exit 0