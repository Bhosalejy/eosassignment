#!/bin/bash


echo "This is to HIDE any file."
echo "Enter the name of the file  in the current directory:"
read file

mv $file .$file
echo ".....The file has been hide successfully....."
