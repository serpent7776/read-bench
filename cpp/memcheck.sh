#!/bin/sh

echo "memcheck $1 input"
valgrind "$1" input
echo

echo "memcheck $1 < input"
valgrind "$1" < input
echo
