#!/bin/bash

echo -n "Enter number : "
read num

echo "$num 's table : "
i=1								
while [ $i -lt 11 ]				
do
	echo `expr $i \* $num`	
	i=`expr $i + 1`				
done

