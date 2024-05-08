#!/bin/bash

if [ $# -eq 0 ]; then
    echo "Error: Filename argument is missing"
    exit 1
fi

if [ -e $1 ]; then
    last_modified=$(stat -c %y $1)
    echo "Last modification time of $1: $last_modified"
else
    echo "File $1 does not exist"
fi

