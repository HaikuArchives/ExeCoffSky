/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: ShellAbout.cpp,v 1.1 2003/05/01 03:33:11 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [ShellAbout.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "ShellAbout.h"
#include "Win32Trace.h"
#include "Kernel32/KernelVersion.h"
#include "User32/MessageBox.h"

extern "C" int WINAPI
ShellAboutA
(HWND hWnd, LPCSTR szApp, LPCSTR szOtherStuff, HICON hIcon)
{
	int rc = FALSE;
	WIN32API_POINTER(szApp);
	WIN32API_POINTER(szOtherStuff);
	WIN32API_ENTER("int", "ShellAboutA", "HWND", hWnd, "LPCSTR", szApp, "LPCSTR", szOtherStuff, "HICON", hIcon, NULL);
	WIN32API_INFO("\tszApp: %s\n", szApp);
	WIN32API_INFO("\tszOtherStuff: %s\n", szOtherStuff);
	BString caption(szApp);
	caption += " Version Information";
	OSVERSIONINFOA osvi;
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOA);
	WIN32API_INTERNAL_START();
	GetVersionExA(&osvi);
	BString text("Version ");
	text << osvi.dwMajorVersion << "." << osvi.dwMinorVersion << " ";
	text << "(Build " << osvi.dwBuildNumber << ": " << osvi.szCSDVersion << ")\n";
	text << "Copyright (C) 2000-2001 Toyoshima-House\n";
	if (NULL != szOtherStuff) text << szOtherStuff;
	rc = MessageBoxA(hWnd, text.String(), caption.String(), MB_OK | MB_ICONASTERISK);
	WIN32API_INTERNAL_END();
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
ShellAboutW
(HWND hWnd, LPCWSTR szApp, LPCWSTR szOtherStuff, HICON hIcon)
{
	int rc = FALSE;
	WIN32API_POINTER(szApp);
	WIN32API_POINTER(szOtherStuff);
	WIN32API_ENTER("int", "ShellAboutW", "HWND", hWnd, "LPCWSTR", szApp, "LPCWSTR", szOtherStuff, "HICON", hIcon, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}
