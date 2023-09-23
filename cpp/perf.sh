#!/bin/sh

echo "perf stat $1 input"
perf stat "$1" input
echo

echo "perf stat $1 < input"
perf stat "$1" < input
echo

