#!/bin/sh

gcc $1.c -o $1 && ./$1
rm $1