#!/boot/home/config/bin/perl

use strict;

my $dll = shift;
my %tbl;

open IN, "w32api/lib/${dll}.def" or die "can not open def";
<IN>;
<IN>;
while (<IN>) {
	/^(.+)@(.+)$/;
	$tbl{$1} = $2;
}
close IN;

print "void *\n";
print "GetAddressByOrder\n";
print "(int order)\n";
print "{\n";
print "\treturn NULL;\n";
print "}\n";
