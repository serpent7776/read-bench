#!/bin/sh

./time.sh $1 2>&1 | perl -e '
use strict;
use warnings;
use feature q/say/;
$,=", ";
while (<>) {
	if (m#^time\s./(.*)$#) {
		my $label="$1";
		my $t = <>;
		my @times = ($t =~ m#([\d.]+)user\s+([\d.]+)system\s+([\d.:]+)elapsed\s+(\d+)%CPU.+\d*avgtext.*\d*avgdata\s+(\d+)maxresident.k#);
		my $i = <>;
		my @ios = ($i =~ m#\d+inputs.*\d+outputs.*(\d+)major.(\d+)minor.*pagefaults\s*\d+swaps#);
		say $label, @times, @ios;
	}
}
'
