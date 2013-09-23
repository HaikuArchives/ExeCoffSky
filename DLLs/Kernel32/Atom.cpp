/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: Atom.cpp,v 1.1 2003/05/01 02:57:16 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Atom.h]
 * -------------------------------------------------------------------------------------------- */
#include "Atom.h"
#include "Win32Trace.h"
#include "Win32Error.h"

extern "C" ATOM WINAPI
AddAtomA
(LPCSTR arg0)
{
	ATOM rc = 0;
	WIN32API_ENTER("ATOM", "AddAtomA", "LPCSTR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" ATOM WINAPI
AddAtomW
(LPCWSTR arg0)
{
	ATOM rc = 0;
	WIN32API_ENTER("ATOM", "AddAtomW", "LPCWSTR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" ATOM WINAPI
DeleteAtom
(ATOM arg0)
{
	ATOM rc = 0;
	WIN32API_ENTER("ATOM", "DeleteAtom", "ATOM", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" ATOM WINAPI
FindAtomA
(LPCSTR arg0)
{
	ATOM rc = 0;
	WIN32API_ENTER("ATOM", "FindAtomA", "LPCSTR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" ATOM WINAPI
FindAtomW
(LPCWSTR arg0)
{
	ATOM rc = 0;
	WIN32API_ENTER("ATOM", "FindAtomW", "LPCWSTR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
GetAtomNameA
(ATOM arg0, LPSTR arg1, int arg2)
{
	UINT rc = 0;
	WIN32API_ENTER("UINT", "GetAtomNameA", "ATOM", arg0, "LPSTR", arg1, "int", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
GetAtomNameW
(ATOM arg0, LPWSTR arg1, int arg2)
{
	UINT rc = 0;
	WIN32API_ENTER("UINT", "GetAtomNameW", "ATOM", arg0, "LPWSTR", arg1, "int", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
InitAtomTable
(DWORD arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "InitAtomTable", "DWORD", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" ATOM WINAPI
GlobalAddAtomA
(LPCSTR lpString)
{
	ATOM rc = 0;
	WIN32API_ENTER("ATOM", "GlobalAddAtomA", "LPCSTR", lpString, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" ATOM WINAPI
GlobalAddAtomW
(LPCWSTR arg0)
{
	ATOM rc = 0;
	WIN32API_ENTER("ATOM", "GlobalAddAtomW", "LPCWSTR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" ATOM WINAPI
GlobalDeleteAtom
(ATOM arg0)
{
	ATOM rc = 0;
	WIN32API_ENTER("ATOM", "GlobalDeleteAtom", "ATOM", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" ATOM WINAPI
GlobalFindAtomA
(LPCSTR arg0)
{
	ATOM rc = 0;
	WIN32API_ENTER("ATOM", "GlobalFindAtomA", "LPCSTR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" ATOM WINAPI
GlobalFindAtomW
(LPCWSTR arg0)
{
	ATOM rc = 0;
	WIN32API_ENTER("ATOM", "GlobalFindAtomW", "LPCWSTR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
GlobalGetAtomNameA
(ATOM arg0, LPSTR arg1, int arg2)
{
	UINT rc = 0;
	WIN32API_ENTER("UINT", "GlobalGetAtomNameA", "ATOM", arg0, "LPSTR", arg1, "int", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
GlobalGetAtomNameW
(ATOM arg0, LPWSTR arg1, int arg2)
{
	UINT rc = 0;
	WIN32API_ENTER("UINT", "GlobalGetAtomNameW", "ATOM", arg0, "LPWSTR", arg1, "int", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}
