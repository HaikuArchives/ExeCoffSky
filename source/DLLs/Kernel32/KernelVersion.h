/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: KernelVersion.h,v 1.1 2003/05/01 02:57:16 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [KernelVersion.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__KernelVersion_h__)
#	define	__KernelVersion_h__

#	if defined(__cplusplus)
#		if !defined(__Common_h__)
#			include "Common.h"
#		endif	// !defined(__Common_h__)

extern "C" {
#	endif	// defined(__cplusplus)

typedef struct tagOSVERSIONINFOA {
	PACKED(DWORD dwOSVersionInfoSize);
	PACKED(DWORD dwMajorVersion);
	PACKED(DWORD dwMinorVersion);
	PACKED(DWORD dwBuildNumber);
	PACKED(DWORD dwPlatformId);
	PACKED(CHAR szCSDVersion[128]);
} OSVERSIONINFOA, *LPOSVERSIONINFOA;

typedef struct tagOSVERSIONINFOW {
	PACKED(DWORD dwOSVersionInfoSize);
	PACKED(DWORD dwMajorVersion);
	PACKED(DWORD dwMinorVersion);
	PACKED(DWORD dwBuildNumber);
	PACKED(DWORD dwPlatformId);
	PACKED(WCHAR szCSDVersion[128]);
} OSVERSIONINFOW, *LPOSVERSIONINFOW;

DWORD WINAPI GetVersion(VOID);
BOOL WINAPI GetVersionExA(LPOSVERSIONINFOA lpVersionInfo);
BOOL WINAPI GetVersionExW(LPOSVERSIONINFOW lpVersionInfo);

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__KernelVersion_h__)
