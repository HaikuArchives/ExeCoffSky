/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 ‚Æ‚æ‚µ‚Ü
 *  $Id: FileOperation.h,v 1.1 2003/05/01 02:57:16 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [FileOperation.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__FileOperation_h__)
#	define	__FileOperation_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if !defined(__Win32Structures_h__)
#		include "Win32Structures.h"
#	endif	// !defined(__Win32Structures_h__)

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

BOOL WINAPI CopyFileA(LPCSTR,LPCSTR,BOOL);
BOOL WINAPI CopyFileW(LPCWSTR,LPCWSTR,BOOL);
BOOL WINAPI CopyFileExA(LPCSTR,LPCSTR,LPPROGRESS_ROUTINE,LPVOID,LPBOOL,DWORD);
BOOL WINAPI CopyFileExW(LPCWSTR,LPCWSTR,LPPROGRESS_ROUTINE,LPVOID,LPBOOL,DWORD);
BOOL WINAPI DeleteFileA(LPCSTR lpFileName);
BOOL WINAPI DeleteFileW(LPCWSTR lpFileName);
DWORD WINAPI GetFileAttributesA(LPCSTR lpFileName);
DWORD WINAPI GetFileAttributesW(LPCWSTR lpFileName);
BOOL WINAPI GetFileAttributesExA(LPCSTR lpFileName, GET_FILEEX_INFO_LEVELS fInfoLevelId, LPVOID lpFileInformation);
BOOL WINAPI GetFileAttributesExW(LPCWSTR lpFileName, GET_FILEEX_INFO_LEVELS fInfoLevelId, LPVOID lpFileInformation);
BOOL WINAPI SetFileAttributesA(LPCSTR lpFileName, DWORD dwFileAttributes);
BOOL WINAPI SetFileAttributesW(LPCWSTR lpFileName, DWORD dwFileAttributes);
BOOL WINAPI MoveFileA(LPCSTR,LPCSTR);
BOOL WINAPI MoveFileW(LPCWSTR,LPCWSTR);
BOOL WINAPI MoveFileExA(LPCSTR,LPCSTR,DWORD);
BOOL WINAPI MoveFileExW(LPCWSTR,LPCWSTR,DWORD);

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__FileOperation_h__)
