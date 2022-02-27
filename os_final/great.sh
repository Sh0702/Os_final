#!/bin/bash

echo "Enter number 1"
read num1
echo "Enter number 2"
read num2
echo "Enter number 3"
read num3

if [ $num1 -gt $num2 ] && [ $num1 -gt $num3 ]
then
    echo "Greatest number is "
    echo $num1
elif [ $num2 -gt $num1 ] && [ $num2 -gt $num3 ]
then
    echo "Greatest number is "
    echo $num2
else
    echo "Greatest number is "
    echo $num3
fi