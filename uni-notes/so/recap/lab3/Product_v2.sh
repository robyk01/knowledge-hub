#!/bin/bash

if [ $# -lt 1 ] ; then read -p "Introduceti primul nr: " n ; else n=$1 ; fi

if [ $# -lt 2 ] ; then read -p "Introduceti al doilea nr: " m ; else m=$2 ; fi

prod=0
k=0
while [ $k -lt $m ] ; do let prod=prod+n ; let k++ ; done

echo "Rezultatul $n * $m este: $prod"
