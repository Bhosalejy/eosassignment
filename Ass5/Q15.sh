#!/bin/bash

echo "Enter the first file name:"
read file1

echo "Enter the second file name:"
read file2

if [ ! -f "$file1" ]; then
    echo "Error: File $file1 does not exist."
    exit 1
fi

tr '[:upper:][:lower:]' '[:lower:][:upper:]' < "$file1" >> "$file2"

echo "Contents of $file1 in reverse case have been appended to $file2."
