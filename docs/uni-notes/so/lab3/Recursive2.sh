#!/bin/bash

if test $# -eq 0 ; then read -p "Enter n: " n ; else n=$1 ; fi

function recursive(){
	local k=$1
	if test $k -eq 0
	then
		echo "2*0 = 1" >&2
		return 1
	else
		let k_1=$k-1
		recursive $k_1
		let rez=2*$?
		echo "2^$k = $rez" >&2
		return $rez
	fi
}

recursive $n
echo "Recursive($n):$?"
