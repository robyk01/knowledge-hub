#!/bin/bash

if [ $# -eq 0 ] ; then echo "Nu ati introdus numerele" ; exit 1; fi

min=$1
max=$1

shift

for p in $@
do
    if ((p > max)) ; then max=$p ; fi
    if ((p < min)) ; then min=$p; fi
done

echo "Maximul este $max iar minimul este $min"
