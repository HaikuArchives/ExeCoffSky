#!/boot/home/config/bin/perl

use strict;

my $dll = shift;
open IN, "diswin -x $dll |" or die "open failed";
<IN>;	# Export Table of *.dll:
my @files = ();
while (<IN>) {
	/(\w+)\.(\d+)\s+(\w+)/;
	my $ord = $2;
	my $func = $3;
	my $line = undef;
check:
	for my $f (@files) {
		print STDERR "finding $func in $f ...\n";
		open F, "< $f";
		while (<F>) {
			next if (!$line and !/$func/);
			chomp;
			chop;
			$line .= $_;
			if ($line =~ /\)\;/) {
				$line .= "\n";
				print STDERR "found: $line";
				last;
			}
			print STDERR "... $line ...";
		}
		last if $line;
	}
	if (!$line) {
		print STDERR "finding $func ...\n";
		$line = `grep "$func" vc98/Include/*.H`;
		if (!$line) {
			print STDERR "\tnot found !!!\n";
			next;
		}
		$line =~ /^([\w\/\.]+)\:/;
		my $name = $1;
		print STDERR "\tfound in $name\n";
		$files[$#files + 1] = $name;
		$line = undef;
		goto check;
	}
	$line =~ s/\s\s+/ /g;
	print "$line"
}
close IN;

