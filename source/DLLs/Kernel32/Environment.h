/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: Environment.h,v 1.1 2003/05/01 02:57:16 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Environment.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__Environment_h__)
#	define	__Environment_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

static BOOL SetEnvironmentVariableU(LPCSTR lpName, LPCSTR lpValue);

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

DWORD WINAPI ExpandEnvironmentStringsA(LPCSTR lpSrc, LPSTR lpDst, DWORD nSize);
DWORD WINAPI ExpandEnvironmentStringsW(LPCWSTR lpSrc, LPWSTR lpDst, DWORD nSize);
BOOL WINAPI FreeEnvironmentStringsA(LPTSTR lpszEnvironmentBlock);
BOOL WINAPI FreeEnvironmentStringsW(LPTSTR lpszEnvironmentBlock);
LPVOID WINAPI GetEnvironmentStrings(VOID);
LPVOID WINAPI GetEnvironmentStringsA(VOID);
LPVOID WINAPI GetEnvironmentStringsW(VOID);
DWORD WINAPI GetEnvironmentVariableA(LPCSTR lpName, LPSTR lpBuffer, DWORD nSize);
DWORD WINAPI GetEnvironmentVariableW(LPCWSTR lpName, LPWSTR lpBuffer, DWORD nSize);
BOOL WINAPI SetEnvironmentVariableA(LPCSTR lpName, LPCSTR lpValue);
BOOL WINAPI SetEnvironmentVariableW(LPCWSTR lpName, LPCWSTR lpValue);

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__Environment_h__)
