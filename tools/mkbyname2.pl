#!/boot/home/config/bin/perl

use strict;

my $dll = shift;
my $h = shift;
open IN, "diswin -x $dll |" or die "open failed";
<IN>;	# Export Table of *.dll:
my @files = ();
print <<EOD;
void *
GetAddressByName
(const char *name)
{
	if (NULL == name) return NULL;
EOD
while (<IN>) {
	/(\w+)\.(\d+)\s+(\w+)/;
	my $ord = $2;
	my $func = $3;
	my $line = undef;

	if (`grep $func $h`) {
		print "\telse if (0 == strcmp(name, \"$func\")) return (void *)$func;\n";
	} else {
		print "//\telse if (0 == strcmp(name, \"$func\")) return (void *)$func;\n";
	}
}
print <<EOD;
	return NULL;
}
EOD
close IN;

