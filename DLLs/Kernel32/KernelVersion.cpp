/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000, 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: KernelVersion.cpp,v 1.1 2003/05/01 02:57:16 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [KernelVersion.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "KernelVersion.h"
#include "Win32Trace.h"
#include "Build.h"

extern "C" DWORD WINAPI
GetVersion
(VOID)
{
	DWORD rc = 0;
	WIN32API_ENTER("DWORD", "GetVersion", NULL);
	rc = (0 << 16) | 5;	// Windows 2000
//	rc = (0 << 16) | 4;	// Windows NT 4.0
//	rc = (0 << 16) | 3;	// Windows NT 3.0/3.1
//	rc = (1 << 16) | 4;	// Windows 95/98
//	rc = (1 << 16) | 3;	// Windows 3.1 with Win32s
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetVersionExA
(LPOSVERSIONINFOA lpVersionInfo)
{
	BOOL rc = FALSE;
	WIN32API_POINTER(lpVersionInfo);
	WIN32API_ENTER("BOOL", "GetVersionExA", "LPOSVERSIONINFOA", lpVersionInfo, NULL);
	if (lpVersionInfo->dwOSVersionInfoSize == sizeof(OSVERSIONINFOA)) {
		lpVersionInfo->dwMajorVersion = 5;
		lpVersionInfo->dwMinorVersion = 0;
		lpVersionInfo->dwBuildNumber = BUILD_COUNT;
		lpVersionInfo->dwPlatformId = 2;	// VER_PLATFORM_WIN32_NT
		snprintf(lpVersionInfo->szCSDVersion, 128, "BeOS");
		rc = TRUE;
	} else {
		WIN32API_INFO("invalid structure size (dwOsVersionInfoSize: %d)\n", lpVersionInfo->dwOSVersionInfoSize);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetVersionExW
(LPOSVERSIONINFOW lpVersionInfo)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetVersionExW", "LPOSVERSIONINFOW", lpVersionInfo, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}
