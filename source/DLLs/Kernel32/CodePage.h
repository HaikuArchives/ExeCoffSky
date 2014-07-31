/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000, 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: CodePage.h,v 1.1 2003/05/01 02:57:16 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [CodePage.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__CodePage_h__)
#	define	__CodePage_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

#	define	MAX_DEFAULTCHAR	2
#	define	MAX_LEADBYTES	12
#	define	MAX_PATH		WIN32_MAX_PATH

typedef BOOL (CALLBACK *CODEPAGE_ENUMPROCA)(LPSTR);
typedef BOOL (CALLBACK *CODEPAGE_ENUMPROCW)(LPWSTR);

typedef struct tagCPINFO {
	PACKED(UINT MaxCharSize);
	PACKED(BYTE DefaultChar[MAX_DEFAULTCHAR]);
	PACKED(BYTE LeadByte[MAX_LEADBYTES]);
} CPINFO, *LPCPINFO;

typedef struct tagCPINFOEXA {
	PACKED(UINT MaxCharSize);
	PACKED(BYTE DefaultChar[MAX_DEFAULTCHAR]);
	PACKED(BYTE LeadByte[MAX_LEADBYTES]);
	PACKED(WCHAR UnicodeDefaultChar);
	PACKED(UINT CodePage);
	PACKED(CHAR CodePageName[MAX_PATH]);
} CPINFOEXA, *LPCPINFOEXA;

typedef struct tagCPINFOEXW {
	PACKED(UINT MaxCharSize);
	PACKED(BYTE DefaultChar[MAX_DEFAULTCHAR]);
	PACKED(BYTE LeadByte[MAX_LEADBYTES]);
	PACKED(WCHAR UnicodeDefaultChar);
	PACKED(UINT CodePage);
	PACKED(WCHAR CodePageName[MAX_PATH]);
} CPINFOEXW, *LPCPINFOEXW;

BOOL WINAPI EnumSystemCodePagesA(CODEPAGE_ENUMPROCA lpCodePageEnumProc, DWORD dwFlags);
BOOL WINAPI EnumSystemCodePagesW(CODEPAGE_ENUMPROCW lpCodePageEnumProc, DWORD dwFlags);
UINT WINAPI GetACP(VOID);
BOOL WINAPI GetCPInfo(UINT CodePage, LPCPINFO lpCPInfo);
BOOL WINAPI GetCPInfoExA(UINT CodePage, DWORD dwFlags, LPCPINFOEXA lpCPInfoEx);
BOOL WINAPI GetCPInfoExW(UINT CodePage, DWORD dwFlags, LPCPINFOEXW lpCPInfoEx);
UINT WINAPI GetOEMCP(VOID);
BOOL WINAPI IsDBCSLeadByte(BYTE TestChar);
BOOL WINAPI IsDBCSLeadByteEx(UINT CodePage, BYTE TestChar);
BOOL WINAPI IsValidCodePage(UINT CodePage);
int WINAPI MultiByteToWideChar(UINT CodePage, DWORD dwFlags, LPCSTR lpMultiByteStr,
	int cchMultiByte, LPWSTR lpWideCharStr, int cchWideChar);
int WINAPI WideCharToMultiByte(UINT CodePage, DWORD dwFlags, LPCWSTR lpWideCharStr,
	int cchWideChar, LPSTR lpMultiByteStr, int cchMultiByte, LPCSTR lpDefaultChar, LPBOOL lpUsedDefaultChar);

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__CodePager_h__)
