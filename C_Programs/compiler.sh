#!/bin/bash

echo "Compiling the specified Programme..."
#Only getting the first argument
if [ -z "$1" ]; then
    echo "No file specified"
    echo "Usage : ./compiler.sh path-to-your-programme"
    exit 1
fi
#Only getting the first argument
if [ "$2" ]; then
    echo "Too many arguments"
    echo "Usage : ./compiler.sh path-to-your-programme"
    exit 1
fi
#Extracting file path
filepath="$1"
filename=$(basename "$filepath" .c)
dir=$(dirname "$filepath")

gcc "$filepath" -o "$dir/$filename.out"

if [ $? -eq 0 ]; then
    echo "✓ Compilation successful: $dir/$filename.out"
    echo "Running..."
    "$dir/$filename.out"

    rm "$dir/$filename.out"
else
    echo "✗ Compilation failed!"
    exit 1
fi