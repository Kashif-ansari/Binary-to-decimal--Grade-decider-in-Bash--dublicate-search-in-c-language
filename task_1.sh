#!/bin/bash
echo "Hello world"
echo "Task 1"
echo "Please enter binary number "
read num
dec=0
power=0
while [ $num -ne 0 ]
do
mod=$((num%10))
num=$((num/10))
mod=$((mod*2**power))
dec=$((dec+mod))
power=$((power+1))
done

echo "Decimal number $dec"
