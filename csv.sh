#!/bin/sh

./time.sh $1 2>&1 | perl -e '
use strict;
use warnings;
use feature q/say/;
my ($user, $system, $elapsed, $cpu, $maxresident, $major, $minor);
$,=", ";
while (<>) {
	if (m#^time\s./(.*)$#) {
		my $label="$1";
		my $times = <>;
		$times =~ m#([\d.]+)user\s+([\d.]+)system\s+([\d.:]+)elapsed\s+(\d+)%CPU.+\d*avgtext.*\d*avgdata\s+(\d+)maxresident.k#;
		$user=$1;
		$system=$2;
		$elapsed=$3;
		$cpu=$4;
		$maxresident=$5;
		my $ios = <>;
		$ios =~ m#\d+inputs.*\d+outputs.*(\d+)major.(\d+)minor.*pagefaults\s*\d+swaps#;
		$major=$1;
		$minor=$2;
		say $label, $user, $system, $elapsed, $cpu, $maxresident, $major, $minor;
	}
}
'
