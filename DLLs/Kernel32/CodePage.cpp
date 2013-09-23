/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 ‚Æ‚æ‚µ‚Ü
 *  $Id: CodePage.cpp,v 1.1 2003/05/01 02:57:16 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [CodePage.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "CodePage.h"
#include "Win32Trace.h"
#include "Win32Structures.h"
#include "Win32String.h"
#include "Win32Error.h"

extern "C" BOOL WINAPI
EnumSystemCodePagesA
(CODEPAGE_ENUMPROCA lpCodePageEnumProc, DWORD dwFlags)
{
	BOOL rc = FALSE;
	WIN32API_POINTER(lpCodePageEnumProc);
	WIN32API_ENTER("BOOL", "EnumSystemCodePagesA", "CODEPAGE_ENUMPROCA", lpCodePageEnumProc, "DWORD", dwFlags, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
EnumSystemCodePagesW
(CODEPAGE_ENUMPROCW lpCodePageEnumProc, DWORD dwFlags)
{
	BOOL rc = FALSE;
	WIN32API_POINTER(lpCodePageEnumProc);
	WIN32API_ENTER("BOOL", "EnumSystemCodePagesW", "CODEPAGE_ENUMPROCW", lpCodePageEnumProc, "DWORD", dwFlags, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
GetACP
(VOID)
{
	WIN32API_ENTER("UINT", "GetACP", NULL);
	UINT rc = Win32String::GetCodePage();
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetCPInfo
(UINT CodePage, LPCPINFO lpCPInfo)
{
	BOOL rc = FALSE;
	WIN32API_POINTER(lpCPInfo);
	WIN32API_ENTER("BOOL", "GetCPInfo", "UINT", CodePage, "LPCPINFO", lpCPInfo, NULL);
	if (0 == CodePage) CodePage = GetACP();
	if (932 != CodePage) {
		WIN32API_INFO("\tnot impl.\n");
		WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	} else {
		lpCPInfo->MaxCharSize = 2;
		lpCPInfo->DefaultChar[0] = 0x3f;
		lpCPInfo->DefaultChar[1] = 0;
		memset(lpCPInfo->LeadByte, 0, MAX_LEADBYTES);
		lpCPInfo->LeadByte[0] = 0x81;
		lpCPInfo->LeadByte[1] = 0x9f;
		lpCPInfo->LeadByte[2] = 0xe0;
		lpCPInfo->LeadByte[3] = 0xfc;
		rc = TRUE;
		WIN32API_ERROR(ERROR_SUCCESS);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetCPInfoExA
(UINT CodePage, DWORD dwFlags, LPCPINFOEXA lpCPInfoEx)
{
	BOOL rc = FALSE;
	WIN32API_POINTER(lpCPInfoEx);
	WIN32API_ENTER("BOOL", "GetCPInfoExA", "UINT", CodePage, "DWORD", dwFlags, "LPCPINFOEXA", lpCPInfoEx, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetCPInfoExW
(UINT CodePage, DWORD dwFlags, LPCPINFOEXW lpCPInfoEx)
{
	BOOL rc = FALSE;
	WIN32API_POINTER(lpCPInfoEx);
	WIN32API_ENTER("BOOL", "GetCPInfoExW", "UINT", CodePage, "DWORD", dwFlags, "LPCPINFOEXW", lpCPInfoEx, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
GetOEMCP
(VOID)
{
	WIN32API_ENTER("UINT", "GetOEMCP", NULL);
	WIN32API_INTERNAL_START();
	UINT rc = GetACP();
	WIN32API_INTERNAL_END();
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
IsDBCSLeadByte
(BYTE TestChar)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "IsDBCSLeadByteEx", "BYTE", TestChar, NULL);
	WIN32API_INTERNAL_START();
	IsDBCSLeadByteEx(GetACP(), TestChar);
	WIN32API_INTERNAL_END();
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
IsDBCSLeadByteEx
(UINT CodePage, BYTE TestChar)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "IsDBCSLeadByteEx", "UINT", CodePage, "BYTE", TestChar, NULL);
	WIN32API_INTERNAL_START();
	CPINFO info;
	GetCPInfo(CodePage, &info);
	WIN32API_INTERNAL_END();
	for (int i = 0; i < MAX_LEADBYTES >> 1; i++) {
		if (info.LeadByte[i * 2 + 0] == 0) break;
		if ((info.LeadByte[i * 2 + 0] <= TestChar) && (TestChar <= info.LeadByte[i * 2 + 1])) {
			rc = TRUE;
			break;
		}
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
IsValidCodePage
(UINT CodePage)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "IsValidCodePage", "UINT", CodePage, NULL);
	if (CodePage == 0) rc = TRUE;
	else if (CodePage == 932) rc = TRUE;
	else {
		WIN32API_INFO("\tnot impl.\n");
		WIN32API_ERROR(ERROR_NO_UNICODE_TRANSLATION);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
MultiByteToWideChar
(UINT CodePage, DWORD dwFlags, LPCSTR lpMultiByteStr, int cchMultiByte, LPWSTR lpWideCharStr, int cchWideChar)
{
	int rc = 0;
	WIN32API_POINTER(lpMultiByteStr);
	WIN32API_POINTER(lpWideCharStr);
	WIN32API_ENTER("int", "MultiByteToWideChar", "UINT", CodePage, "DWORD", dwFlags, "LPCSTR", lpMultiByteStr, "int", cchMultiByte, "LPWSTR", lpWideCharStr, "int", cchWideChar, NULL);
	WIN32API_INTERNAL_START();
	BOOL f = IsValidCodePage(CodePage);
	WIN32API_INTERNAL_END();
	if (f) {
		Win32String::Lock();
		UINT acp = Win32String::GetCodePage();
		Win32String::SetCodePage(CodePage);
		if (0 != dwFlags) WIN32API_INFO("\tignore dwFlags: $%08x\n", dwFlags);
		Win32String str;
		if (-1 == cchMultiByte) str.SetToA(lpMultiByteStr);
		else str.SetToA(lpMultiByteStr, cchMultiByte);
		WIN32API_INFO("\tlpMultiByteStr: %s\n", str.StringU());
		if (0 == cchWideChar) {
			rc = str.LengthW();
		} else {
			if ((UINT)cchWideChar < str.LengthW()) {
				WIN32API_ERROR(ERROR_MORE_DATA);
			} else {
				memcpy(lpWideCharStr, str.StringW(), str.LengthW());
				rc = str.LengthW();
				WIN32API_ERROR(ERROR_SUCCESS);
			}
		}
		Win32String::SetCodePage(acp);
		Win32String::Unlock();
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
WideCharToMultiByte
(UINT CodePage, DWORD dwFlags, LPCWSTR lpWideCharStr, int cchWideChar, LPSTR lpMultiByteStr, int cchMultiByte, LPCSTR lpDefaultChar, LPBOOL lpUsedDefaultChar)
{
	int rc = 0;
	WIN32API_POINTER(lpWideCharStr);
	WIN32API_POINTER(lpMultiByteStr);
	WIN32API_POINTER(lpDefaultChar);
	WIN32API_ENTER("int", "WideCharToMultiByte", "UINT", CodePage, "DWORD", dwFlags, "LPCWSTR", lpWideCharStr, "int", cchWideChar, "LPSTR", lpMultiByteStr, "int", cchMultiByte, "LPCSTR", lpDefaultChar, "LPBOOL", lpUsedDefaultChar, NULL);
	WIN32API_INTERNAL_START();
	BOOL f = IsValidCodePage(CodePage);
	WIN32API_INTERNAL_END();
	if (f) {
		Win32String::Lock();
		UINT acp = Win32String::GetCodePage();
		Win32String::SetCodePage(CodePage);
		if (0 != dwFlags) WIN32API_INFO("\tignore dwFlags: $%08x\n", dwFlags);
		Win32String str;
		if (-1 == cchWideChar) str.SetToW(lpWideCharStr);
		else str.SetToW(lpWideCharStr, cchWideChar);
		WIN32API_INFO("\tlpWideCharStr: %s\n", str.StringU());
		if (0 == cchMultiByte) {
			rc = str.LengthA();
		} else {
			if ((UINT)cchMultiByte < str.LengthA()) {
				WIN32API_ERROR(ERROR_MORE_DATA);
			} else {
				memcpy(lpMultiByteStr, str.StringA(), str.LengthA());
				rc = str.LengthA();
				WIN32API_ERROR(ERROR_SUCCESS);
			}
		}
		Win32String::SetCodePage(acp);
		Win32String::Unlock();
	}
	WIN32API_LEAVE(rc);
	return rc;
}
