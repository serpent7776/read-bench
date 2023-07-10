#!/bin/sh
echo "strace -e read $1 input"
strace -e read "$1" input 2>&1 | grep -wc read
echo "strace -e read $1 < input"
strace -e read "$1" < input 2>&1 | grep -wc read
