#!/bin/sh

filename=$1
extension="${filename##*.}"
name="${filename%.*}"

if [ $extension = "c" ]; then
    echo "Compiling C file"
    gcc $1 -o $name
    echo "Running C file"
    ./$name
    rm $name
elif [ $extension = "cpp" ]; then
    echo "Compiling C++ file"
    g++ $1 -o $name
    echo "Running C++ file"
    ./$name
    rm $name
else
    echo "Invalid file extension"
fi