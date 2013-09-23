#!/boot/home/config/bin/perl

use strict;

my $dll = shift;

open IN, "header2/${dll}.h" or open IN, "header/${dll}.h" or die "can not open";
while(<IN>) {
	/(.+\sWINAPI)\s(\w+)\((.+)\);/ or
	/(WINOLEAPI)\s(\w+)\((.+)\);/;
	my $rv = $1;
	my $func = $2;
	my $arg = $3;
	print "extern \"C\" $rv\n";
	print "$func\n";
	my @args = split /,/, $arg;
	print "(";
	for (my $i = 0; $args[$i]; $i++) {
		print ", " if ($i != 0);
		if (($args[$i] ne "void") && ($args[$i] ne "VOID")) {
			print "$args[$i] arg$i";
		} else {
			print "$args[$i]";
		}
	}
	print ")\n";
	print "{\n";
	$rv =~ /(\w+)\sWINAPI/;
	my $type = $1;
	if (($type ne "void") && ($type ne "VOID")){
		my %val = (
			"ATOM" => "(ATOM)-1",
			"BOOL" => "FALSE",
			"LRESULT" => "(LRESULT)-1",
			"LPARAM" => "(LPARAM)-1",
			"LONG" => "(LONG)-1",
			"SHORT" => "(SHORT)-1",
			"long" => "(long)-1",
			"int" => "(int)-1",
			"WORD" => "(WORD)-1",
			"LCID" => "(LCID)-1",
			"MCIDEVICEID" => "(MCIDEVICEID)-1",
			"DWORD" => "(DWORD)-1",
			"UINT" => "(UINT)-1",
			"COLORREF" => "(COLORREF)-1",
			"COORD" => "{ 0, 0 }",
			"PBYTE" => "NULL",
			"PUCHAR" => "NULL",
			"PVOID" => "NULL",
			"PDWORD" => "NULL",
			"LPVOID" => "NULL",
			"LPSTR" => "NULL",
			"LPWSTR" => "NULL",
			"HOOKPROC" => "NULL",
			"LANGID" => "(LANGID)-1",
			"HENHMETAFILE" => "INVALID_HANDLE_VALUE",
			"HMETAFILE" => "INVALID_HANDLE_VALUE",
			"HCOLORSPACE" => "INVALID_HANDLE_VALUE",
			"HRGN" => "INVALID_HANDLE_VALUE",
			"HFONT" => "INVALID_HANDLE_VALUE",
			"HGDIOBJ" => "INVALID_HANDLE_VALUE",
			"HPALETTE" => "INVALID_HANDLE_VALUE",
			"HPEN" => "INVALID_HANDLE_VALUE",
			"HDRVR" => "INVALID_HANDLE_VALUE",
			"HMMIO" => "(HHMIO)INVALID_HANDLE_VALUE",
			"HTASK" => "INVALID_HANDLE_VALUE",
			"HHOOK" => "INVALID_HANDLE_VALUE",
			"HDDEDATA" => "INVALID_HANDLE_VALUE",
			"HCONV" => "INVALID_HANDLE_VALUE",
			"HSZ" => "INVALID_HANDLE_VALUE",
			"HCONVLIST" => "INVALID_HANDLE_VALUE",
			"HANDLE" => "INVALID_HANDLE_VALUE",
			"HRSRC" => "INVALID_HANDLE_VALUE",
			"HMODULE" => "INVALID_HANDLE_VALUE",
			"HGLOBAL" => "INVALID_HANDLE_VALUE",
			"HINSTANCE" => "INVALID_HANDLE_VALUE",
			"HLOCAL" => "INVALID_HANDLE_VALUE",
			"HKL" => "INVALID_HANDLE_VALUE",
			"HDWP" => "INVALID_HANDLE_VALUE",
			"HDC" => "INVALID_HANDLE_VALUE",
			"HDESK" => "INVALID_HANDLE_VALUE",
			"HMENU" => "INVALID_HANDLE_VALUE",
			"HWND" => "INVALID_HANDLE_VALUE",
			"HICON" => "INVALID_HANDLE_VALUE",
			"HBRUSH" => "INVALID_HANDLE_VALUE",
			"HBITMAP" => "INVALID_HANDLE_VALUE",
			"HWINSTA" => "INVALID_HANDLE_VALUE",
			"HCURSOR" => "INVALID_HANDLE_VALUE",
			"HACCEL" => "INVALID_HANDLE_VALUE",
			"HFILE" => "(HFILE)INVALID_HANDLE_VALUE",
			"LPTOP_LEVEL_EXCEPTION_FILTER" => "NULL",
			"FARPROC" => "(FARPROC)NULL",
			"YIELDPROC" => "(YIELDPROC)NULL",
			"LPMMIOPROC" => "(LPMMIOPROC)NULL",
			"MMRESULT" => "(MMRESULT)-1",
			"MCIERROR" => "(MCIERROR)-1",
			"FOURCC" => "(FOURCC)-1",
			"SC_HANDLE" => "(SC_HANDLE)-1",
			"SC_LOCK" => "(SC_LOCK)-1",
			"PSID_IDENTIFIER_AUTHORITY" => "(PSID_IDENTIFIER_AUTHORITY)-1",
			"SERVICE_STATUS_HANDLE" => "(SERVICE_STATUS_HANDLE)-1",
			"HRESULT" => "(HRESULT)-1",
			"LPITEMIDLIST" => "NULL",
		);
		if ($val{$type}) {
			print "\t$type rc = $val{$type};\n";
		} else {
			die "unknown type \'$type\'";
		}
	}
	print "\tWIN32API_ENTER(\"$type\", \"$func\", ";
	for (my $i = 0; $args[$i]; $i++) {
		if (($args[$i] ne "void") && ($args[$i] ne "VOID")) {
			print "\"$args[$i]\", arg$i, ";
		} else {
			print "\"$args[$i]\", 0, ";
		}
	}
	print "NULL);\n";
	print "\tWIN32API_INFO(\"\\tnot impl.\\n\");\n";
	if (($type ne "void") && ($type ne "VOID")) {
		print "\tWIN32API_LEAVE(rc);\n";
		print "\treturn rc;\n";
	} else {
		print "\tWIN32API_LEAVE(0);\n";
	}
	print "}\n\n";
	print STDERR;
}
close IN;
