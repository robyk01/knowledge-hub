#!/bin/bash

if [ $# -lt 1 ] ; then read -p "Introduceti primul nr: " n ; else n=$1 ; fi

if [ $# -lt 2 ] ; then read -p "Introduceti al doilea nr: " m ; else m=$2 ; fi

if [ $m -lt 0 ]
then
    ((n=-n))
    ((m=-m))
fi

export values="$n $m"
./Consumer.sh