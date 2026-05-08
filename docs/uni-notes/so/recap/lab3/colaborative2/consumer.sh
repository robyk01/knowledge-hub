#!/bin/bash

sum=0
while read num
do
    ((num3=num*num*num))
    ((sum+=num3))
done

if [ $sum -eq 0 ] ; then echo NULL ; exit 1
else echo $sum ; exit 0
fi