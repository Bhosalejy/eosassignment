#!/bin/bash

echo -e "Enter Number : \c"
read num

while [ $num -gt 2 ]
do
for((i=2; i<=$num/2; i++))
do
  res=$(( num%i ))
  if [ $res -eq 0 ]
  then
    echo "$num is not a prime number."
    exit 0
  fi
done
echo "$num is a prime number."

