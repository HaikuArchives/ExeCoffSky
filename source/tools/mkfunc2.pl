#!/boot/home/config/bin/perl

use strict;

my $h = shift;

open IN, "$h" or die "can not open";
while(<IN>) {
	next if $_ eq "\n";
	/(.+\sWINAPI)\s(\w+)\((.+)\);/ or
	/(WINOLEAPI)\s(\w+)\((.+)\);/ or
	/(.+)\s(\w+)\((.+)\);/;
	my $rv = $1;
	my $func = $2;
	my $arg = $3;
	print "extern \"C\" $rv\n";
	print "$func\n";
	my @args = split /,/, $arg;
	print "(";
	for (my $i = 0; $args[$i]; $i++) {
		$args[$i] =~ s/^\s+//;
		print ", " if ($i != 0);
		my $need_arg = 1;
		$need_arg = 0 if ($args[$i] eq "void" or $args[$i] eq "VOID");
		my @param = split /\s/, $args[$i];
		$need_arg = 0 if ($#param > 0 and ("const" ne $param[0] and "CONST" ne $param[0]));
		$need_arg = 0 if $#param > 1;
		if ($need_arg) {
			print "$args[$i] arg$i";
		} else {
			print "$args[$i]";
		}
	}
	print ")\n";
	print "{\n";
	my $type;
	if (/WINOLEAPI_\((\w+)\)/) {
		$type = $1;
	} elsif (/WINOLEAPI/ or /WINOLEAUTAPI/ or /STDAPI/) {
		$type = "HRESULT";
	} else {
		$rv =~ /(\w+)\sWINAPI/ or $rv =~ /(.+)\sPASCAL\sFAR/ or $rv =~ /(\w+)\sAPIENTRY/;
		$type = $1;
		die "unknown line: $_\n" if !$type;
		if ($type =~ /(.+)\s+__RPC_USER\s*/) {
			$type = $1;
			if ($type =~ /(\w+)(\s\w+)?\s+/) {
				$type = $1 . $2;
			}
		}
	}
	if (($type ne "void") and ($type ne "VOID")){
		my %val = (
			"SOCKET" => "(SOCKET)-1",
			"ATOM" => "(ATOM)0",
			"BOOL" => "FALSE",
			"LRESULT" => "0",
			"LPARAM" => "0",
			"LONG" => "0",
			"ULONG" => "0",
			"SHORT" => "0",
			"short" => "0",
			"long" => "0",
			"unsigned long" => "0",
			"unsigned char" => "0",
			"int" => "0",
			"WORD" => "0",
			"LCID" => "0",
			"MCIDEVICEID" => "(MCIDEVICEID)0",
			"DWORD" => "0",
			"UINT" => "0",
			"COLORREF" => "(COLORREF)0",
			"COORD" => "{ 0, 0 }",
			"PBYTE" => "NULL",
			"PUCHAR" => "NULL",
			"PVOID" => "NULL",
			"PDWORD" => "NULL",
			"LPVOID" => "NULL",
			"LPSTR" => "NULL",
			"LPWSTR" => "NULL",
			"HOOKPROC" => "NULL",
			"LANGID" => "9",
			"HOLEMENU" => "NULL",
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
			"HIMC" => "INVALID_HANDLE_VALUE",
			"HPROPSHEETPAGE" => "INVALID_HANDLE_VALUE",
			"HIMAGELIST" => "INVALID_HANDLE_VALUE",
			"struct protocol FAR *" => "NULL",
			"struct protoent FAR *" => "NULL",
			"struct servent FAR *" => "NULL",
			"char FAR *" => "NULL",
		);
		if ($val{$type} ne undef) {
			print "\t$type rc = $val{$type};\n";
		} else {
			die "unknown type '$type'\n";
		}
	}
	print "\tWIN32API_ENTER(\"$type\", \"$func\", ";
	for (my $i = 0; $args[$i]; $i++) {
		my $need_arg = 1;
		my $arg = "0";
		my @param = split /\s/, "$args[$i]";
		$need_arg = 0 if ($#param > 0 and ("const" ne $param[0] and "CONST" ne $param[0]));
		if (0 == $need_arg) {
			$arg = $param[$#param];
			$#param--;
			$args[$i] = join " ", @param;
		}
		$need_arg = 0 if ($args[$i] eq "void" or $args[$i] eq "VOID");
		$need_arg = 0 if $#param > 1;
		if ($need_arg) {
			print "\"$args[$i]\", arg$i, ";
		} else {
			if ($arg =~ /(\*+)(.+)/) {
				$args[$i] .= $1;
				$arg = $2;
			}
			print "\"$args[$i]\", $arg, ";
		}
	}
	print "NULL);\n";
	print "\tWIN32API_INFO(\"\\tnot impl.\\n\");\n";
	print "\tWIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);\n";
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
