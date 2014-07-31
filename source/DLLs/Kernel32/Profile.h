/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: Profile.h,v 1.1 2003/05/01 02:57:17 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Profile.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__Profile_h__)
#	define	__Profile_h__

#	if defined(__cplusplus)
#		if !defined(__Common_h__)
#			include "Common.h"
#		endif	// !defined(__Common_h__)
#	endif	// defined(__cplusplus)

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

UINT WINAPI GetPrivateProfileIntA(LPCSTR lpAppName, LPCSTR lpKeyName, INT nDefault, LPCSTR lpFileName);
UINT WINAPI GetPrivateProfileIntW(LPCWSTR lpAppName, LPCWSTR lpKeyName, INT nDefault, LPCWSTR lpFileName);
DWORD WINAPI GetPrivateProfileSectionA(LPCSTR lpAppName, LPSTR lpReturnedString, DWORD nSize, LPCSTR lpFileName);
DWORD WINAPI GetPrivateProfileSectionW(LPCWSTR lpAppName, LPWSTR lpReturnedString, DWORD nSize, LPCWSTR lpFileName);
DWORD WINAPI GetPrivateProfileStringA(LPCSTR lpAppName, LPCSTR lpKeyName, LPCSTR lpDefault, LPSTR lpReturnedString, DWORD nSize, LPCSTR lpFileName);
DWORD WINAPI GetPrivateProfileStringW(LPCWSTR lpAppName, LPCWSTR lpKeyName, LPCWSTR lpDefault, LPWSTR lpReturnedString, DWORD nSize, LPCWSTR lpFileName);
DWORD WINAPI GetPrivateProfileSectionNamesA(LPSTR lpszReturnBuffer, DWORD nSize, LPCSTR lpFileName);
DWORD WINAPI GetPrivateProfileSectionNamesW(LPWSTR lpszReturnBuffer, DWORD nSize, LPCWSTR lpFileName);
BOOL WINAPI GetPrivateProfileStructA(LPCSTR lpszSection, LPCSTR lpszKey, LPVOID lpStruct, UINT uSizeStruct, LPCSTR szFile);
BOOL WINAPI GetPrivateProfileStructW(LPCWSTR lpszSection, LPCWSTR lpszKey, LPVOID lpStruct, UINT uSizeStruct, LPCWSTR szFile);
BOOL WINAPI WritePrivateProfileSectionA(LPCSTR lpAppName, LPCSTR lpString, LPCSTR lpFileName);
BOOL WINAPI WritePrivateProfileSectionW(LPCWSTR lpAppName, LPCWSTR lpString, LPCWSTR lpFileName);
BOOL WINAPI WritePrivateProfileStringA(LPCSTR lpAppName, LPCSTR lpKeyName, LPCSTR lpString, LPCSTR lpFileName);
BOOL WINAPI WritePrivateProfileStringW(LPCWSTR lpAppName, LPCWSTR lpKeyName, LPCWSTR lpString, LPCWSTR lpFileName);
BOOL WINAPI WritePrivateProfileStructA(LPCSTR lpszSection, LPCSTR lpszKey, LPVOID lpStruct, UINT uSizeStruct, LPCSTR szFile);
BOOL WINAPI WritePrivateProfileStructW(LPCWSTR lpszSection, LPCWSTR lpszKey, LPVOID lpStruct, UINT uSizeStruct, LPCWSTR szFile);
UINT WINAPI GetProfileIntA(LPCSTR lpAppName, LPCSTR lpKeyName, INT nDefault);
UINT WINAPI GetProfileIntW(LPCWSTR lpAppName, LPCWSTR lpKeyName, INT nDefault);
DWORD WINAPI GetProfileSectionA(LPCSTR lpAppName, LPSTR lpReturnedString, DWORD nSize);
DWORD WINAPI GetProfileSectionW(LPCWSTR lpAppName, LPWSTR lpReturnedString, DWORD nSize);
DWORD WINAPI GetProfileStringA(LPCSTR lpAppName, LPCSTR lpKeyName, LPCSTR lpDefault, LPSTR lpReturnedString, DWORD nSize);
DWORD WINAPI GetProfileStringW(LPCWSTR lpAppName, LPCWSTR lpKeyName, LPCWSTR lpDefault, LPWSTR lpReturnedString, DWORD nSize);
BOOL WINAPI WriteProfileSectionA(LPCSTR lpAppName, LPCSTR lpString);
BOOL WINAPI WriteProfileSectionW(LPCWSTR lpAppName, LPCWSTR lpString);
BOOL WINAPI WriteProfileStringA(LPCSTR lpAppName, LPCSTR lpKeyName, LPCSTR lpString);
BOOL WINAPI WriteProfileStringW(LPCWSTR lpAppName, LPCWSTR lpKeyName, LPCWSTR lpString);

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__Profile_h__)
