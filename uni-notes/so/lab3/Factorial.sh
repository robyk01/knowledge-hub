#!/bin/bash

if test $# -eq 0 ; then read -p "Enter n: " n ; else n=$1 ; fi

function factorial(){
    if test $1 -le 1
    then
	    return 1
    else
	    let n_1=$1-1
	    factorial $n_1
	    let rez=$1*$?
	    return $rez
    fi
}

factorial $n
echo "Factorial($n)=$?"
