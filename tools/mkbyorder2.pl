#!/boot/home/config/bin/perl

use strict;

my $dll = shift;
my $h = shift;
open IN, "diswin -x $dll |" or die "open failed";
<IN>;	# Export Table of *.dll:
my @files = ();
print <<EOD;
void *
GetAddressByOrder
(int order)
{
	switch (order) {
EOD
while (<IN>) {
	/(\w+)\.(\d+)\s+(\w+)/;
	my $ord = $2;
	my $func = $3;
	my $line = undef;

	if (`grep $func $h`) {
	    print "\tcase $ord:\treturn (void*)$func;\n";
	} else {
	    print "//\tcase $ord:\treturn (void*)$func;\n";
	}
}
print <<EOD;
	}
	return NULL;
}
EOD
close IN;

