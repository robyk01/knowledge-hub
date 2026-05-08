#!/bin/bash

if [ $# -eq 0 ] ; then read -p "Introduceti nr: " n ; else n=$1 ; fi

function factorial(){
    if [ $1 -le 1 ]
    then return 1
    else
        ((prev=$1-1))
        factorial $prev
        ((rez=$1*$?))
        return $rez
    fi
}

factorial $n
echo "Rezultat factoria $n este: $?"