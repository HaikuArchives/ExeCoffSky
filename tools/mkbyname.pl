#!/boot/home/config/bin/perl

use strict;

my $dll = shift;

open IN, "header/${dll}.h" or open IN, "header/${dll}.h" or die "can not open header";
print "void *\n";
print "GetAddressByName\n";
print "(const char *name)\n";
print "{\n";
print "\tif (NULL == name) return NULL;\n";
while (<IN>) {
	chomp;
	/.+\sWINAPI\s(\w+)\(/;
	my $func = $1;
	print "\telse if (0 == strcmp(name, \"$func\")) return (void *)$func;\n";
}
close IN;
print "\treturn NULL;\n";
print "}\n";
