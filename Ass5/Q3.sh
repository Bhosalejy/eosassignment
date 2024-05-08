#!/bin/bash

echo "Enter the name of a file or directory:"
read name

if [ -f "$name" ]; then
    echo "$name is a file."
    
    size=$(wc -c < "$name")
    echo "File size: $size bytes"
    
elif [ -d "$name" ]; then
    echo "$name is a directory."
    
    ls "$name"
    
else
    echo "Invalid input. Please enter a valid file or directory name."
fi

