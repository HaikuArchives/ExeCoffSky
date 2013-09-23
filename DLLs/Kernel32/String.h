/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: String.h,v 1.1 2003/05/01 02:57:17 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [String.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__String_h__)
#	define	__String_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if defined(__cplusplus)
extern "C" {
#	endif	// !defined(__cplusplus)

LPSTR WINAPI lstrcatA(LPSTR lpString1, LPCSTR lpString2);
LPWSTR WINAPI lstrcatW(LPWSTR lpString1, LPCWSTR lpString2);
int WINAPI lstrcmpA(LPCSTR lpString1, LPCSTR lpString2);
int WINAPI lstrcmpW(LPCWSTR lpString1, LPCWSTR lpString2);
int WINAPI lstrcmpiA(LPCSTR lpString1, LPCSTR lpString2);
int WINAPI lstrcmpiW(LPCWSTR lpString1, LPCWSTR lpString2);
LPTSTR WINAPI lstrcpyA(LPTSTR lpString1, LPCTSTR lpString2);
LPWSTR WINAPI lstrcpyW(LPWSTR lpString1, LPCWSTR lpString2);
LPSTR WINAPI lstrcpynA(LPSTR lpString1, LPCSTR lpString2, int nLength);
LPWSTR WINAPI lstrcpynW(LPWSTR lpString1, LPCWSTR lpString2, int nLength);
int WINAPI lstrlenA(LPCSTR lpString);
int WINAPI lstrlenW(LPCWSTR lpString);

#	if defined(__cplusplus)
};
#	endif	// !defined(__cplusplus)

#endif	// !defined(__String_h__)
