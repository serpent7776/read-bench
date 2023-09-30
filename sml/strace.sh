#!/bin/sh
echo "strace -e read $1 input"
time strace -e read "$1" input 2>&1 | uniq -c
