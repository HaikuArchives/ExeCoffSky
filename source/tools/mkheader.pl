#!/boot/home/config/bin/perl

use strict;

my $dll = shift;
open IN, "w32api/lib/${dll}.def" or die "open failed";
<IN>;	# LIBRARY *.dll
<IN>;	# EXPORTS
while (<IN>) {
	/(.+)@(\d+)/;
	my $func = $1;
	my $order = $2;
	my $line = `grep "API $func(" w32api/include/*`;
	if ($line) {
		$_ = $line;
		chomp;
		/\:(.+)/;
		print "$1\n";
	} else {
		print STDERR "!$func\n";
	}
}
close IN;

