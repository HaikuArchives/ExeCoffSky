/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: win32_server.cpp,v 1.1 2003/05/01 02:41:08 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [win32_server.cpp]
 * -------------------------------------------------------------------------------------------- */
#define	__Main__
#include "Common.h"
#undef	__Main__
#include "Win32Server.h"
#include "Win32Client.h"

int
main
(int argc, char **argv)
{
	if ((argc == 3) && (0 == strcmp(argv[1], "!e"))) {
		// client
		DOUT("win32_client: exec '%s'\n", argv[2]);
		Win32Client win32client(argv[2]);
		win32client.Run();
		DOUT("win32_client exit\n");
	} else {
		// server
		DOUT("win32_server launched\n");
		Win32Server win32server;
		win32server.Run();
		DOUT("win32_server shutdown\n");
	}
	return 0;
}
