/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: FindFile.h,v 1.1 2003/05/01 02:57:16 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [FindFirst.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__FindFirst_h__)
#	define	__FindFirst_h__

#	if defined(__cplusplus)
#		if !defined(__Common_h__)
#			include "Common.h"
#		endif	// !defined(__Common_h__)

extern "C" {
#	endif	// defined(__cplusplus)

#	define	WIN32_MAX_PATH	260

#	if !defined(__Win32Structures_h__)
#		include "Win32Structures.h"
#	endif	// !defined(__Win32Structures_h__)

typedef struct tagWIN32_FIND_DATAA {
	PACKED(DWORD dwFileAttributes);
	PACKED(FILETIME ftCreationTime);
	PACKED(FILETIME ftLastAccessTime);
	PACKED(FILETIME ftLastWriteTime);
	PACKED(DWORD nFileSizeHigh);
	PACKED(DWORD nFileSizeLow);
	PACKED(DWORD dwReserved0);
	PACKED(DWORD dwReserved1);
	PACKED(CHAR cFileName[WIN32_MAX_PATH]);
	PACKED(CHAR cAlternateFileName[14]);
} WIN32_FIND_DATAA, *LPWIN32_FIND_DATAA;

typedef struct tagWIN32_FIND_DATAW {
	PACKED(DWORD dwFileAttributes);
	PACKED(FILETIME ftCreationTime);
	PACKED(FILETIME ftLastAccessTime);
	PACKED(FILETIME ftLastWriteTime);
	PACKED(DWORD nFileSizeHigh);
	PACKED(DWORD nFileSizeLow);
	PACKED(DWORD dwReserved0);
	PACKED(DWORD dwReserved1);
	PACKED(WCHAR cFileName[WIN32_MAX_PATH]);
	PACKED(WCHAR cAlternateFileName[14]);
} WIN32_FIND_DATAW, *LPWIN32_FIND_DATAW;

typedef enum tagFINDEX_INFO_LEVELS {
	FindExInfoStandard,
	FindExInfoMaxInfoLevel,
} FINDEX_INFO_LEVELS;

typedef enum tagFINDEX_SEARCH_OPS {
	FindExSearchNameMatch,
	FindExSearchLimitToDirectories,
	FindExSearchLimitToDevices,
} FINDEX_SEARCH_OPS;

HANDLE WINAPI FindFirstFileA(LPCSTR lpFileName, LPWIN32_FIND_DATAA lpFindFileData);
HANDLE WINAPI FindFirstFileW(LPCWSTR lpFileName, LPWIN32_FIND_DATAW lpFindFileData);
HANDLE WINAPI FindFirstFileExA(LPCSTR lpFileName, FINDEX_INFO_LEVELS fInfoLevelId, LPVOID lpFindFileData,
	FINDEX_SEARCH_OPS fSearchOp, LPVOID lpSearchFilter, DWORD dwAdditionalFlag);
HANDLE WINAPI FindFirstFileExW(LPCWSTR lpFileName, FINDEX_INFO_LEVELS fInfoLevelId, PVOID lpFindFileData,
	FINDEX_SEARCH_OPS fSearchOp, PVOID lpSearchFilter, DWORD dwAdditionalFlag);
BOOL WINAPI FindNextFileA(HANDLE hFindFile, LPWIN32_FIND_DATAA lpFindFileData);
BOOL WINAPI FindNextFileW(HANDLE hFindFile, LPWIN32_FIND_DATAW lpFindFileData);
BOOL WINAPI FindClose(HANDLE hFindFile);

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__FindFirst_h__)
