#!/bin/sh

awk -v FS=, '
NR > 1 {
	split($0, a, " ");
	label = a[1];
	gsub("_", "-", label)
	split($4, x, ":");
	getline;
	split($0, b, ",");
	# print(b[4]);
	split(b[4], y, ":");
	print(label, x[1]*60+x[2], y[1]*60+y[2]);
}' < data.csv > data.plot

echo "
set title 'Reading $1 file'
set style data histogram
set style fill solid border -1
set xtic rotate by -45
set ylabel 'Total time [s]'
plot 'data.plot' u 2:xticlabel(1) title 'from file', '' u 3 title 'from stdin'
" | gnuplot --persist

