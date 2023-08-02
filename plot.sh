#!/bin/sh

awk -v FS=, '
NR > 1 {
	# 1st row
	split($0, a, " ");
	label = a[1];
	gsub("_", "-", label)
	split($4, w, ":");
	# 2nd row
	getline;
	split($0, a, ",");
	split(a[4], x, ":");
	# 3rd row
	getline;
	split($0, a, ",");
	split(a[4], y, ":");
	# 4th row
	getline;
	split($0, a, ",");
	split(a[4], z, ":");
	# print result
	print(label, w[1]*60+w[2], x[1]*60+x[2], y[1]*60+y[2], z[1]*60+z[2]);
}' < data.csv > data.plot

echo "
set title 'Reading $1 file'
set style data histogram
set style fill solid border -1
set xtic rotate by -45
set ylabel 'Total time [s]'
set grid
plot 'data.plot' u 2:xticlabel(1) title 'from file (synced)', \
	'' u 3 title 'from stdin (synced)', \
	'' u 4 title 'from file (unsynced)', \
	'' u 5 title 'from stdin (unsynced)'
" | gnuplot --persist

