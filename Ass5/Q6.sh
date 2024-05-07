#!/bin/bash

# leap year

echo -n "Enter year : " 
    read year 
      
    rem=$(( $year % 4 )) 
      
    if [ $rem -eq 0 ] 
    then 
      echo "$year is leap year" 
    else 
      echo "$year is not a leap year" 
    fi 
