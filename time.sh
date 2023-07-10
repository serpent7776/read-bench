#!/bin/sh
sz=`wc -c input | awk '{print $1}'`

function check() {
	if ! [ "$out" -eq "$sz" ]; then
		echo $out
		exit 1
	fi
}

echo "time $1 input"
out=`\time "$1" input`
check
echo

echo "time $1 < input"
out=`\time "$1" < input`
check
echo
