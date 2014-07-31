#!/boot/home/config/bin/perl

use strict;

my $api = shift;
my $v = 0;
if ($api eq "-v") {
	$v = 1;
	$api = shift;
}
my $mode = 0;

while (<>) {
	if ($mode == 0) {
		if (/\s$api/) {
			$mode = 1;
			print if ($v == 0);
		} else {
			print if ($v == 1);
		}
	} else {
		print if ($v == 0);
		$mode = 0 if /\->/;
	}
}

