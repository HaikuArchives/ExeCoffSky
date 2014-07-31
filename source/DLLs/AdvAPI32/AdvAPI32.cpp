/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: AdvAPI32.cpp,v 1.1 2003/05/01 02:42:42 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [AdvAPI32.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "AdvAPI32.h"
#include "Win32Trace.h"

extern "C" BOOL WINAPI
AbortSystemShutdownA
(LPCSTR arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "AbortSystemShutdownA", "LPCSTR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
AbortSystemShutdownW
(LPCWSTR arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "AbortSystemShutdownW", "LPCWSTR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
AccessCheck
(PSECURITY_DESCRIPTOR arg0, HANDLE arg1, DWORD arg2, PGENERIC_MAPPING arg3, PPRIVILEGE_SET arg4, PDWORD arg5, PDWORD arg6, PBOOL arg7)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "AccessCheck", "PSECURITY_DESCRIPTOR", arg0, "HANDLE", arg1, "DWORD", arg2, "PGENERIC_MAPPING", arg3, "PPRIVILEGE_SET", arg4, "PDWORD", arg5, "PDWORD", arg6, "PBOOL", arg7, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
AccessCheckAndAuditAlarmA
(LPCSTR arg0, LPVOID arg1, LPSTR arg2, LPSTR arg3, PSECURITY_DESCRIPTOR arg4, DWORD arg5, PGENERIC_MAPPING arg6, BOOL arg7, PDWORD arg8, PBOOL arg9, PBOOL arg10)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "AccessCheckAndAuditAlarmA", "LPCSTR", arg0, "LPVOID", arg1, "LPSTR", arg2, "LPSTR", arg3, "PSECURITY_DESCRIPTOR", arg4, "DWORD", arg5, "PGENERIC_MAPPING", arg6, "BOOL", arg7, "PDWORD", arg8, "PBOOL", arg9, "PBOOL", arg10, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
AccessCheckAndAuditAlarmW
(LPCWSTR arg0, LPVOID arg1, LPWSTR arg2, LPWSTR arg3, PSECURITY_DESCRIPTOR arg4, DWORD arg5, PGENERIC_MAPPING arg6, BOOL arg7, PDWORD arg8, PBOOL arg9, PBOOL arg10)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "AccessCheckAndAuditAlarmW", "LPCWSTR", arg0, "LPVOID", arg1, "LPWSTR", arg2, "LPWSTR", arg3, "PSECURITY_DESCRIPTOR", arg4, "DWORD", arg5, "PGENERIC_MAPPING", arg6, "BOOL", arg7, "PDWORD", arg8, "PBOOL", arg9, "PBOOL", arg10, NULL);	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
AddAccessAllowedAce
(PACL arg0, DWORD arg1, DWORD arg2, PSID arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "AddAccessAllowedAce", "PACL", arg0, "DWORD", arg1, "DWORD", arg2, "PSID", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
AddAccessDeniedAce
(PACL arg0, DWORD arg1, DWORD arg2, PSID arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "AddAccessDeniedAce", "PACL", arg0, "DWORD", arg1, "DWORD", arg2, "PSID", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
AddAce
(PACL arg0, DWORD arg1, DWORD arg2, PVOID arg3, DWORD arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "AddAce", "PACL", arg0, "DWORD", arg1, "DWORD", arg2, "PVOID", arg3, "DWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
AddAuditAccessAce
(PACL arg0, DWORD arg1, DWORD arg2, PSID arg3, BOOL arg4, BOOL arg5)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "AddAuditAccessAce", "PACL", arg0, "DWORD", arg1, "DWORD", arg2, "PSID", arg3, "BOOL", arg4, "BOOL", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
AdjustTokenGroups
(HANDLE arg0, BOOL arg1, PTOKEN_GROUPS arg2, DWORD arg3, PTOKEN_GROUPS arg4, PDWORD arg5)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "AdjustTokenGroups", "HANDLE", arg0, "BOOL", arg1, "PTOKEN_GROUPS", arg2, "DWORD", arg3, "PTOKEN_GROUPS", arg4, "PDWORD", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
AdjustTokenPrivileges
(HANDLE arg0, BOOL arg1, PTOKEN_PRIVILEGES arg2, DWORD arg3, PTOKEN_PRIVILEGES arg4, PDWORD arg5)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "AdjustTokenPrivileges", "HANDLE", arg0, "BOOL", arg1, "PTOKEN_PRIVILEGES", arg2, "DWORD", arg3, "PTOKEN_PRIVILEGES", arg4, "PDWORD", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
AllocateAndInitializeSid
(PSID_IDENTIFIER_AUTHORITY arg0, BYTE arg1, DWORD arg2, DWORD arg3, DWORD arg4, DWORD arg5, DWORD arg6, DWORD arg7, DWORD arg8, DWORD arg9, PSID* arg10)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "AllocateAndInitializeSid", "PSID_IDENTIFIER_AUTHORITY", arg0, "BYTE", arg1, "DWORD", arg2, "DWORD", arg3, "DWORD", arg4, "DWORD", arg5, "DWORD", arg6, "DWORD", arg7, "DWORD", arg8, "DWORD", arg9, "PSID*", arg10, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
AllocateLocallyUniqueId
(PLUID arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "AllocateLocallyUniqueId", "PLUID", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
AreAllAccessesGranted
(DWORD arg0, DWORD arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "AreAllAccessesGranted", "DWORD", arg0, "DWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
AreAnyAccessesGranted
(DWORD arg0, DWORD arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "AreAnyAccessesGranted", "DWORD", arg0, "DWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
BackupEventLogA
(HANDLE arg0, LPCSTR arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "BackupEventLogA", "HANDLE", arg0, "LPCSTR", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
BackupEventLogW
(HANDLE arg0, LPCWSTR arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "BackupEventLogW", "HANDLE", arg0, "LPCWSTR", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ChangeServiceConfigA
(SC_HANDLE arg0, DWORD arg1, DWORD arg2, DWORD arg3, LPCSTR arg4, LPCSTR arg5, LPDWORD arg6, LPCSTR arg7, LPCSTR arg8, LPCSTR arg9, LPCSTR arg10)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ChangeServiceConfigA", "SC_HANDLE", arg0, "DWORD", arg1, "DWORD", arg2, "DWORD", arg3, "LPCSTR", arg4, "LPCSTR", arg5, "LPDWORD", arg6, "LPCSTR", arg7, "LPCSTR", arg8, "LPCSTR", arg9, "LPCSTR", arg10, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ChangeServiceConfigW
(SC_HANDLE arg0, DWORD arg1, DWORD arg2, DWORD arg3, LPCWSTR arg4, LPCWSTR arg5, LPDWORD arg6, LPCWSTR arg7, LPCWSTR arg8, LPCWSTR arg9, LPCWSTR arg10)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ChangeServiceConfigW", "SC_HANDLE", arg0, "DWORD", arg1, "DWORD", arg2, "DWORD", arg3, "LPCWSTR", arg4, "LPCWSTR", arg5, "LPDWORD", arg6, "LPCWSTR", arg7, "LPCWSTR", arg8, "LPCWSTR", arg9, "LPCWSTR", arg10, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ClearEventLogA
(HANDLE arg0, LPCSTR arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ClearEventLogA", "HANDLE", arg0, "LPCSTR", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ClearEventLogW
(HANDLE arg0, LPCWSTR arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ClearEventLogW", "HANDLE", arg0, "LPCWSTR", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CloseEventLog
(HANDLE arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CloseEventLog", "HANDLE", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CloseServiceHandle
(SC_HANDLE arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CloseServiceHandle", "SC_HANDLE", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ControlService
(SC_HANDLE arg0, DWORD arg1, LPSERVICE_STATUS arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ControlService", "SC_HANDLE", arg0, "DWORD", arg1, "LPSERVICE_STATUS", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CopySid
(DWORD arg0, PSID arg1, PSID arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CopySid", "DWORD", arg0, "PSID", arg1, "PSID", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CreatePrivateObjectSecurity
(PSECURITY_DESCRIPTOR arg0, PSECURITY_DESCRIPTOR arg1, PSECURITY_DESCRIPTOR* arg2, BOOL arg3, HANDLE arg4, PGENERIC_MAPPING arg5)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CreatePrivateObjectSecurity", "PSECURITY_DESCRIPTOR", arg0, "PSECURITY_DESCRIPTOR", arg1, "PSECURITY_DESCRIPTOR*", arg2, "BOOL", arg3, "HANDLE", arg4, "PGENERIC_MAPPING", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CreateProcessAsUserA
(HANDLE arg0, LPCSTR arg1, LPSTR arg2, LPSECURITY_ATTRIBUTES arg3, LPSECURITY_ATTRIBUTES arg4, BOOL arg5, DWORD arg6, PVOID arg7, LPCSTR arg8, LPSTARTUPINFOA arg9, LPPROCESS_INFORMATION arg10)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CreateProcessAsUserA", "HANDLE", arg0, "LPCSTR", arg1, "LPSTR", arg2, "LPSECURITY_ATTRIBUTES", arg3, "LPSECURITY_ATTRIBUTES", arg4, "BOOL", arg5, "DWORD", arg6, "PVOID", arg7, "LPCSTR", arg8, "LPSTARTUPINFOA", arg9, "LPPROCESS_INFORMATION", arg10, NULL);	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CreateProcessAsUserW
(HANDLE arg0, LPCWSTR arg1, LPWSTR arg2, LPSECURITY_ATTRIBUTES arg3, LPSECURITY_ATTRIBUTES arg4, BOOL arg5, DWORD arg6, PVOID arg7, LPCWSTR arg8, LPSTARTUPINFOW arg9, LPPROCESS_INFORMATION arg10)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CreateProcessAsUserW", "HANDLE", arg0, "LPCWSTR", arg1, "LPWSTR", arg2, "LPSECURITY_ATTRIBUTES", arg3, "LPSECURITY_ATTRIBUTES", arg4, "BOOL", arg5, "DWORD", arg6, "PVOID", arg7, "LPCWSTR", arg8, "LPSTARTUPINFOW", arg9, "LPPROCESS_INFORMATION", arg10, NULL);	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" SC_HANDLE WINAPI
CreateServiceA
(SC_HANDLE arg0, LPCSTR arg1, LPCSTR arg2, DWORD arg3, DWORD arg4, DWORD arg5, DWORD arg6, LPCSTR arg7, LPCSTR arg8, PDWORD arg9, LPCSTR arg10, LPCSTR arg11, LPCSTR arg12)
{
	SC_HANDLE rc = (SC_HANDLE)-1;
	WIN32API_ENTER("SC_HANDLE", "CreateServiceA", "SC_HANDLE", arg0, "LPCSTR", arg1, "LPCSTR", arg2, "DWORD", arg3, "DWORD", arg4, "DWORD", arg5, "DWORD", arg6, "LPCSTR", arg7, "LPCSTR", arg8, "PDWORD", arg9, "LPCSTR", arg10, "LPCSTR", arg11, "LPCSTR", arg12, NULL);	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" SC_HANDLE WINAPI
CreateServiceW
(SC_HANDLE arg0, LPCWSTR arg1, LPCWSTR arg2, DWORD arg3, DWORD arg4, DWORD arg5, DWORD arg6, LPCWSTR arg7, LPCWSTR arg8, PDWORD arg9, LPCWSTR arg10, LPCWSTR arg11, LPCWSTR arg12)
{
	SC_HANDLE rc = (SC_HANDLE)-1;
	WIN32API_ENTER("SC_HANDLE", "CreateServiceW", "SC_HANDLE", arg0, "LPCWSTR", arg1, "LPCWSTR", arg2, "DWORD", arg3, "DWORD", arg4, "DWORD", arg5, "DWORD", arg6, "LPCWSTR", arg7, "LPCWSTR", arg8, "PDWORD", arg9, "LPCWSTR", arg10, "LPCWSTR", arg11, "LPCWSTR", arg12, NULL);	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CryptAcquireContextA
(HCRYPTPROV* arg0, LPCSTR arg1, LPCSTR arg2, DWORD arg3, DWORD arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CryptAcquireContextA", "HCRYPTPROV*", arg0, "LPCSTR", arg1, "LPCSTR", arg2, "DWORD", arg3, "DWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CryptAcquireContextW
(HCRYPTPROV* arg0, LPCWSTR arg1, LPCWSTR arg2, DWORD arg3, DWORD arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CryptAcquireContextW", "HCRYPTPROV*", arg0, "LPCWSTR", arg1, "LPCWSTR", arg2, "DWORD", arg3, "DWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CryptCreateHash
(HCRYPTPROV arg0, ALG_ID arg1, HCRYPTKEY arg2, DWORD arg3, HCRYPTHASH* arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CryptCreateHash", "HCRYPTPROV", arg0, "ALG_ID", arg1, "HCRYPTKEY", arg2, "DWORD", arg3, "HCRYPTHASH*", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CryptDecrypt
(HCRYPTKEY arg0, HCRYPTHASH arg1, BOOL arg2, DWORD arg3, PBYTE arg4, PDWORD arg5)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CryptDecrypt", "HCRYPTKEY", arg0, "HCRYPTHASH", arg1, "BOOL", arg2, "DWORD", arg3, "PBYTE", arg4, "PDWORD", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CryptDeriveKey
(HCRYPTPROV arg0, ALG_ID arg1, HCRYPTHASH arg2, DWORD arg3, HCRYPTKEY* arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CryptDeriveKey", "HCRYPTPROV", arg0, "ALG_ID", arg1, "HCRYPTHASH", arg2, "DWORD", arg3, "HCRYPTKEY*", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CryptDestroyHash
(HCRYPTHASH arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CryptDestroyHash", "HCRYPTHASH", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CryptDestroyKey
(HCRYPTKEY arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CryptDestroyKey", "HCRYPTKEY", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CryptEncrypt
(HCRYPTKEY arg0, HCRYPTHASH arg1, BOOL arg2, DWORD arg3, PBYTE arg4, PDWORD arg5, DWORD arg6)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CryptEncrypt", "HCRYPTKEY", arg0, "HCRYPTHASH", arg1, "BOOL", arg2, "DWORD", arg3, "PBYTE", arg4, "PDWORD", arg5, "DWORD", arg6, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CryptExportKey
(HCRYPTKEY arg0, HCRYPTKEY arg1, DWORD arg2, DWORD arg3, PBYTE arg4, PDWORD arg5)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CryptExportKey", "HCRYPTKEY", arg0, "HCRYPTKEY", arg1, "DWORD", arg2, "DWORD", arg3, "PBYTE", arg4, "PDWORD", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CryptGenKey
(HCRYPTPROV arg0, ALG_ID arg1, DWORD arg2, HCRYPTKEY* arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CryptGenKey", "HCRYPTPROV", arg0, "ALG_ID", arg1, "DWORD", arg2, "HCRYPTKEY*", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CryptGenRandom
(HCRYPTPROV arg0, DWORD arg1, PBYTE arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CryptGenRandom", "HCRYPTPROV", arg0, "DWORD", arg1, "PBYTE", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CryptGetHashParam
(HCRYPTHASH arg0, DWORD arg1, PBYTE arg2, PDWORD arg3, DWORD arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CryptGetHashParam", "HCRYPTHASH", arg0, "DWORD", arg1, "PBYTE", arg2, "PDWORD", arg3, "DWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CryptGetKeyParam
(HCRYPTKEY arg0, DWORD arg1, PBYTE arg2, PDWORD arg3, DWORD arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CryptGetKeyParam", "HCRYPTKEY", arg0, "DWORD", arg1, "PBYTE", arg2, "PDWORD", arg3, "DWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CryptGetProvParam
(HCRYPTPROV arg0, DWORD arg1, PBYTE arg2, PDWORD arg3, DWORD arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CryptGetProvParam", "HCRYPTPROV", arg0, "DWORD", arg1, "PBYTE", arg2, "PDWORD", arg3, "DWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CryptGetUserKey
(HCRYPTPROV arg0, DWORD arg1, HCRYPTKEY* arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CryptGetUserKey", "HCRYPTPROV", arg0, "DWORD", arg1, "HCRYPTKEY*", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CryptHashData
(HCRYPTHASH arg0, PBYTE arg1, DWORD arg2, DWORD arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CryptHashData", "HCRYPTHASH", arg0, "PBYTE", arg1, "DWORD", arg2, "DWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CryptHashSessionKey
(HCRYPTHASH arg0, HCRYPTKEY arg1, DWORD arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CryptHashSessionKey", "HCRYPTHASH", arg0, "HCRYPTKEY", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CryptImportKey
(HCRYPTPROV arg0, PBYTE arg1, DWORD arg2, HCRYPTKEY arg3, DWORD arg4, HCRYPTKEY* arg5)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CryptImportKey", "HCRYPTPROV", arg0, "PBYTE", arg1, "DWORD", arg2, "HCRYPTKEY", arg3, "DWORD", arg4, "HCRYPTKEY*", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CryptReleaseContext
(HCRYPTPROV arg0, DWORD arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CryptReleaseContext", "HCRYPTPROV", arg0, "DWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CryptSetHashParam
(HCRYPTHASH arg0, DWORD arg1, PBYTE arg2, DWORD arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CryptSetHashParam", "HCRYPTHASH", arg0, "DWORD", arg1, "PBYTE", arg2, "DWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CryptSetKeyParam
(HCRYPTKEY arg0, DWORD arg1, PBYTE arg2, DWORD arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CryptSetKeyParam", "HCRYPTKEY", arg0, "DWORD", arg1, "PBYTE", arg2, "DWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CryptSetProvParam
(HCRYPTPROV arg0, DWORD arg1, PBYTE arg2, DWORD arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CryptSetProvParam", "HCRYPTPROV", arg0, "DWORD", arg1, "PBYTE", arg2, "DWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CryptSetProviderA
(LPCSTR arg0, DWORD arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CryptSetProviderA", "LPCSTR", arg0, "DWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CryptSetProviderW
(LPCWSTR arg0, DWORD arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CryptSetProviderW", "LPCWSTR", arg0, "DWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CryptSignHashA
(HCRYPTHASH arg0, DWORD arg1, LPCSTR arg2, DWORD arg3, PBYTE arg4, PDWORD arg5)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CryptSignHashA", "HCRYPTHASH", arg0, "DWORD", arg1, "LPCSTR", arg2, "DWORD", arg3, "PBYTE", arg4, "PDWORD", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CryptSignHashW
(HCRYPTHASH arg0, DWORD arg1, LPCWSTR arg2, DWORD arg3, PBYTE arg4, PDWORD arg5)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CryptSignHashW", "HCRYPTHASH", arg0, "DWORD", arg1, "LPCWSTR", arg2, "DWORD", arg3, "PBYTE", arg4, "PDWORD", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CryptVerifySignatureA
(HCRYPTHASH arg0, PBYTE arg1, DWORD arg2, HCRYPTKEY arg3, LPCSTR arg4, DWORD arg5)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CryptVerifySignatureA", "HCRYPTHASH", arg0, "PBYTE", arg1, "DWORD", arg2, "HCRYPTKEY", arg3, "LPCSTR", arg4, "DWORD", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CryptVerifySignatureW
(HCRYPTHASH arg0, PBYTE arg1, DWORD arg2, HCRYPTKEY arg3, LPCWSTR arg4, DWORD arg5)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CryptVerifySignatureW", "HCRYPTHASH", arg0, "PBYTE", arg1, "DWORD", arg2, "HCRYPTKEY", arg3, "LPCWSTR", arg4, "DWORD", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DeleteAce
(PACL arg0, DWORD arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DeleteAce", "PACL", arg0, "DWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DeleteService
(SC_HANDLE arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DeleteService", "SC_HANDLE", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DeregisterEventSource
(HANDLE arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DeregisterEventSource", "HANDLE", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DestroyPrivateObjectSecurity
(PSECURITY_DESCRIPTOR* arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DestroyPrivateObjectSecurity", "PSECURITY_DESCRIPTOR*", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DuplicateToken
(HANDLE arg0, SECURITY_IMPERSONATION_LEVEL arg1, PHANDLE arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DuplicateToken", "HANDLE", arg0, "SECURITY_IMPERSONATION_LEVEL", arg1, "PHANDLE", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DuplicateTokenEx
(HANDLE arg0, DWORD arg1, LPSECURITY_ATTRIBUTES arg2, SECURITY_IMPERSONATION_LEVEL arg3, TOKEN_TYPE arg4, PHANDLE arg5)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DuplicateTokenEx", "HANDLE", arg0, "DWORD", arg1, "LPSECURITY_ATTRIBUTES", arg2, "SECURITY_IMPERSONATION_LEVEL", arg3, "TOKEN_TYPE", arg4, "PHANDLE", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
EnumDependentServicesA
(SC_HANDLE arg0, DWORD arg1, LPENUM_SERVICE_STATUSA arg2, DWORD arg3, PDWORD arg4, PDWORD arg5)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "EnumDependentServicesA", "SC_HANDLE", arg0, "DWORD", arg1, "LPENUM_SERVICE_STATUSA", arg2, "DWORD", arg3, "PDWORD", arg4, "PDWORD", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
EnumDependentServicesW
(SC_HANDLE arg0, DWORD arg1, LPENUM_SERVICE_STATUSW arg2, DWORD arg3, PDWORD arg4, PDWORD arg5)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "EnumDependentServicesW", "SC_HANDLE", arg0, "DWORD", arg1, "LPENUM_SERVICE_STATUSW", arg2, "DWORD", arg3, "PDWORD", arg4, "PDWORD", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
EnumServicesStatusA
(SC_HANDLE arg0, DWORD arg1, DWORD arg2, LPENUM_SERVICE_STATUSA arg3, DWORD arg4, PDWORD arg5, PDWORD arg6, PDWORD arg7)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "EnumServicesStatusA", "SC_HANDLE", arg0, "DWORD", arg1, "DWORD", arg2, "LPENUM_SERVICE_STATUSA", arg3, "DWORD", arg4, "PDWORD", arg5, "PDWORD", arg6, "PDWORD", arg7, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
EnumServicesStatusW
(SC_HANDLE arg0, DWORD arg1, DWORD arg2, LPENUM_SERVICE_STATUSW arg3, DWORD arg4, PDWORD arg5, PDWORD arg6, PDWORD arg7)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "EnumServicesStatusW", "SC_HANDLE", arg0, "DWORD", arg1, "DWORD", arg2, "LPENUM_SERVICE_STATUSW", arg3, "DWORD", arg4, "PDWORD", arg5, "PDWORD", arg6, "PDWORD", arg7, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
EqualPrefixSid
(PSID arg0, PSID arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "EqualPrefixSid", "PSID", arg0, "PSID", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
EqualSid
(PSID arg0, PSID arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "EqualSid", "PSID", arg0, "PSID", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
FindFirstFreeAce
(PACL arg0, PVOID* arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "FindFirstFreeAce", "PACL", arg0, "PVOID*", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" PVOID WINAPI
FreeSid
(PSID arg0)
{
	PVOID rc = NULL;
	WIN32API_ENTER("PVOID", "FreeSid", "PSID", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetAce
(PACL arg0, DWORD arg1, PVOID arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetAce", "PACL", arg0, "DWORD", arg1, "PVOID", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetAclInformation
(PACL arg0, PVOID arg1, DWORD arg2, ACL_INFORMATION_CLASS arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetAclInformation", "PACL", arg0, "PVOID", arg1, "DWORD", arg2, "ACL_INFORMATION_CLASS", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetFileSecurityA
(LPCSTR arg0, SECURITY_INFORMATION arg1, PSECURITY_DESCRIPTOR arg2, DWORD arg3, PDWORD arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetFileSecurityA", "LPCSTR", arg0, "SECURITY_INFORMATION", arg1, "PSECURITY_DESCRIPTOR", arg2, "DWORD", arg3, "PDWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetFileSecurityW
(LPCWSTR arg0, SECURITY_INFORMATION arg1, PSECURITY_DESCRIPTOR arg2, DWORD arg3, PDWORD arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetFileSecurityW", "LPCWSTR", arg0, "SECURITY_INFORMATION", arg1, "PSECURITY_DESCRIPTOR", arg2, "DWORD", arg3, "PDWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetKernelObjectSecurity
(HANDLE arg0, SECURITY_INFORMATION arg1, PSECURITY_DESCRIPTOR arg2, DWORD arg3, PDWORD arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetKernelObjectSecurity", "HANDLE", arg0, "SECURITY_INFORMATION", arg1, "PSECURITY_DESCRIPTOR", arg2, "DWORD", arg3, "PDWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetLengthSid
(PSID arg0)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "GetLengthSid", "PSID", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetNumberOfEventLogRecords
(HANDLE arg0, PDWORD arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetNumberOfEventLogRecords", "HANDLE", arg0, "PDWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetOldestEventLogRecord
(HANDLE arg0, PDWORD arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetOldestEventLogRecord", "HANDLE", arg0, "PDWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetPrivateObjectSecurity
(PSECURITY_DESCRIPTOR arg0, SECURITY_INFORMATION arg1, PSECURITY_DESCRIPTOR arg2, DWORD arg3, PDWORD arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetPrivateObjectSecurity", "PSECURITY_DESCRIPTOR", arg0, "SECURITY_INFORMATION", arg1, "PSECURITY_DESCRIPTOR", arg2, "DWORD", arg3, "PDWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetSecurityDescriptorControl
(PSECURITY_DESCRIPTOR arg0, PSECURITY_DESCRIPTOR_CONTROL arg1, PDWORD arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetSecurityDescriptorControl", "PSECURITY_DESCRIPTOR", arg0, "PSECURITY_DESCRIPTOR_CONTROL", arg1, "PDWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetSecurityDescriptorDacl
(PSECURITY_DESCRIPTOR arg0, LPBOOL arg1, PACL* arg2, LPBOOL arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetSecurityDescriptorDacl", "PSECURITY_DESCRIPTOR", arg0, "LPBOOL", arg1, "PACL*", arg2, "LPBOOL", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetSecurityDescriptorGroup
(PSECURITY_DESCRIPTOR arg0, PSID* arg1, LPBOOL arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetSecurityDescriptorGroup", "PSECURITY_DESCRIPTOR", arg0, "PSID*", arg1, "LPBOOL", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetSecurityDescriptorLength
(PSECURITY_DESCRIPTOR arg0)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "GetSecurityDescriptorLength", "PSECURITY_DESCRIPTOR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetSecurityDescriptorOwner
(PSECURITY_DESCRIPTOR arg0, PSID* arg1, LPBOOL arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetSecurityDescriptorOwner", "PSECURITY_DESCRIPTOR", arg0, "PSID*", arg1, "LPBOOL", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetSecurityDescriptorSacl
(PSECURITY_DESCRIPTOR arg0, LPBOOL arg1, PACL* arg2, LPBOOL arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetSecurityDescriptorSacl", "PSECURITY_DESCRIPTOR", arg0, "LPBOOL", arg1, "PACL*", arg2, "LPBOOL", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetServiceDisplayNameA
(SC_HANDLE arg0, LPCSTR arg1, LPSTR arg2, PDWORD arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetServiceDisplayNameA", "SC_HANDLE", arg0, "LPCSTR", arg1, "LPSTR", arg2, "PDWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetServiceDisplayNameW
(SC_HANDLE arg0, LPCWSTR arg1, LPWSTR arg2, PDWORD arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetServiceDisplayNameW", "SC_HANDLE", arg0, "LPCWSTR", arg1, "LPWSTR", arg2, "PDWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetServiceKeyNameA
(SC_HANDLE arg0, LPCSTR arg1, LPSTR arg2, PDWORD arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetServiceKeyNameA", "SC_HANDLE", arg0, "LPCSTR", arg1, "LPSTR", arg2, "PDWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetServiceKeyNameW
(SC_HANDLE arg0, LPCWSTR arg1, LPWSTR arg2, PDWORD arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetServiceKeyNameW", "SC_HANDLE", arg0, "LPCWSTR", arg1, "LPWSTR", arg2, "PDWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" PSID_IDENTIFIER_AUTHORITY WINAPI
GetSidIdentifierAuthority
(PSID arg0)
{
	PSID_IDENTIFIER_AUTHORITY rc = (PSID_IDENTIFIER_AUTHORITY)-1;
	WIN32API_ENTER("PSID_IDENTIFIER_AUTHORITY", "GetSidIdentifierAuthority", "PSID", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetSidLengthRequired
(UCHAR arg0)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "GetSidLengthRequired", "UCHAR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" PDWORD WINAPI
GetSidSubAuthority
(PSID arg0, DWORD arg1)
{
	PDWORD rc = NULL;
	WIN32API_ENTER("PDWORD", "GetSidSubAuthority", "PSID", arg0, "DWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" PUCHAR WINAPI
GetSidSubAuthorityCount
(PSID arg0)
{
	PUCHAR rc = NULL;
	WIN32API_ENTER("PUCHAR", "GetSidSubAuthorityCount", "PSID", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetTokenInformation
(HANDLE arg0, TOKEN_INFORMATION_CLASS arg1, PVOID arg2, DWORD arg3, PDWORD arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetTokenInformation", "HANDLE", arg0, "TOKEN_INFORMATION_CLASS", arg1, "PVOID", arg2, "DWORD", arg3, "PDWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetUserNameW
(LPWSTR arg0, PDWORD arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetUserNameW", "LPWSTR", arg0, "PDWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ImpersonateLoggedOnUser
(HANDLE arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImpersonateLoggedOnUser", "HANDLE", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ImpersonateNamedPipeClient
(HANDLE arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImpersonateNamedPipeClient", "HANDLE", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ImpersonateSelf
(SECURITY_IMPERSONATION_LEVEL arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImpersonateSelf", "SECURITY_IMPERSONATION_LEVEL", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
InitializeAcl
(PACL arg0, DWORD arg1, DWORD arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "InitializeAcl", "PACL", arg0, "DWORD", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
InitializeSecurityDescriptor
(PSECURITY_DESCRIPTOR arg0, DWORD arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "InitializeSecurityDescriptor", "PSECURITY_DESCRIPTOR", arg0, "DWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
InitiateSystemShutdownA
(LPSTR arg0, LPSTR arg1, DWORD arg2, BOOL arg3, BOOL arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "InitiateSystemShutdownA", "LPSTR", arg0, "LPSTR", arg1, "DWORD", arg2, "BOOL", arg3, "BOOL", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
InitiateSystemShutdownW
(LPWSTR arg0, LPWSTR arg1, DWORD arg2, BOOL arg3, BOOL arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "InitiateSystemShutdownW", "LPWSTR", arg0, "LPWSTR", arg1, "DWORD", arg2, "BOOL", arg3, "BOOL", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
IsTextUnicode
(PCVOID arg0, int arg1, LPINT arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "IsTextUnicode", "PCVOID", arg0, "int", arg1, "LPINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
IsValidAcl
(PACL arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "IsValidAcl", "PACL", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
IsValidSecurityDescriptor
(PSECURITY_DESCRIPTOR arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "IsValidSecurityDescriptor", "PSECURITY_DESCRIPTOR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
IsValidSid
(PSID arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "IsValidSid", "PSID", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" SC_LOCK WINAPI
LockServiceDatabase
(SC_HANDLE arg0)
{
	SC_LOCK rc = (SC_LOCK)-1;
	WIN32API_ENTER("SC_LOCK", "LockServiceDatabase", "SC_HANDLE", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
LogonUserA
(LPSTR arg0, LPSTR arg1, LPSTR arg2, DWORD arg3, DWORD arg4, PHANDLE arg5)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "LogonUserA", "LPSTR", arg0, "LPSTR", arg1, "LPSTR", arg2, "DWORD", arg3, "DWORD", arg4, "PHANDLE", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
LogonUserW
(LPWSTR arg0, LPWSTR arg1, LPWSTR arg2, DWORD arg3, DWORD arg4, PHANDLE arg5)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "LogonUserW", "LPWSTR", arg0, "LPWSTR", arg1, "LPWSTR", arg2, "DWORD", arg3, "DWORD", arg4, "PHANDLE", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
LookupAccountNameA
(LPCSTR arg0, LPCSTR arg1, PSID arg2, PDWORD arg3, LPSTR arg4, PDWORD arg5, PSID_NAME_USE arg6)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "LookupAccountNameA", "LPCSTR", arg0, "LPCSTR", arg1, "PSID", arg2, "PDWORD", arg3, "LPSTR", arg4, "PDWORD", arg5, "PSID_NAME_USE", arg6, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
LookupAccountNameW
(LPCWSTR arg0, LPCWSTR arg1, PSID arg2, PDWORD arg3, LPWSTR arg4, PDWORD arg5, PSID_NAME_USE arg6)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "LookupAccountNameW", "LPCWSTR", arg0, "LPCWSTR", arg1, "PSID", arg2, "PDWORD", arg3, "LPWSTR", arg4, "PDWORD", arg5, "PSID_NAME_USE", arg6, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
LookupAccountSidA
(LPCSTR arg0, PSID arg1, LPSTR arg2, PDWORD arg3, LPSTR arg4, PDWORD arg5, PSID_NAME_USE arg6)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "LookupAccountSidA", "LPCSTR", arg0, "PSID", arg1, "LPSTR", arg2, "PDWORD", arg3, "LPSTR", arg4, "PDWORD", arg5, "PSID_NAME_USE", arg6, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
LookupAccountSidW
(LPCWSTR arg0, PSID arg1, LPWSTR arg2, PDWORD arg3, LPWSTR arg4, PDWORD arg5, PSID_NAME_USE arg6)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "LookupAccountSidW", "LPCWSTR", arg0, "PSID", arg1, "LPWSTR", arg2, "PDWORD", arg3, "LPWSTR", arg4, "PDWORD", arg5, "PSID_NAME_USE", arg6, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
LookupPrivilegeDisplayNameA
(LPCSTR arg0, LPCSTR arg1, LPSTR arg2, PDWORD arg3, PDWORD arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "LookupPrivilegeDisplayNameA", "LPCSTR", arg0, "LPCSTR", arg1, "LPSTR", arg2, "PDWORD", arg3, "PDWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
LookupPrivilegeDisplayNameW
(LPCWSTR arg0, LPCWSTR arg1, LPWSTR arg2, PDWORD arg3, PDWORD arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "LookupPrivilegeDisplayNameW", "LPCWSTR", arg0, "LPCWSTR", arg1, "LPWSTR", arg2, "PDWORD", arg3, "PDWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
LookupPrivilegeNameA
(LPCSTR arg0, PLUID arg1, LPSTR arg2, PDWORD arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "LookupPrivilegeNameA", "LPCSTR", arg0, "PLUID", arg1, "LPSTR", arg2, "PDWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
LookupPrivilegeNameW
(LPCWSTR arg0, PLUID arg1, LPWSTR arg2, PDWORD arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "LookupPrivilegeNameW", "LPCWSTR", arg0, "PLUID", arg1, "LPWSTR", arg2, "PDWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
LookupPrivilegeValueA
(LPCSTR arg0, LPCSTR arg1, PLUID arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "LookupPrivilegeValueA", "LPCSTR", arg0, "LPCSTR", arg1, "PLUID", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
LookupPrivilegeValueW
(LPCWSTR arg0, LPCWSTR arg1, PLUID arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "LookupPrivilegeValueW", "LPCWSTR", arg0, "LPCWSTR", arg1, "PLUID", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
MakeAbsoluteSD
(PSECURITY_DESCRIPTOR arg0, PSECURITY_DESCRIPTOR arg1, PDWORD arg2, PACL arg3, PDWORD arg4, PACL arg5, PDWORD arg6, PSID arg7, PDWORD arg8, PSID arg9, PDWORD arg10)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "MakeAbsoluteSD", "PSECURITY_DESCRIPTOR", arg0, "PSECURITY_DESCRIPTOR", arg1, "PDWORD", arg2, "PACL", arg3, "PDWORD", arg4, "PACL", arg5, "PDWORD", arg6, "PSID", arg7, "PDWORD", arg8, "PSID", arg9, "PDWORD", arg10, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
MakeSelfRelativeSD
(PSECURITY_DESCRIPTOR arg0, PSECURITY_DESCRIPTOR arg1, PDWORD arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "MakeSelfRelativeSD", "PSECURITY_DESCRIPTOR", arg0, "PSECURITY_DESCRIPTOR", arg1, "PDWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" VOID WINAPI
MapGenericMask
(PDWORD arg0, PGENERIC_MAPPING arg1)
{
	WIN32API_ENTER("VOID", "MapGenericMask", "PDWORD", arg0, "PGENERIC_MAPPING", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(0);
}

extern "C" BOOL WINAPI
NotifyBootConfigStatus
(BOOL arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "NotifyBootConfigStatus", "BOOL", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
NotifyChangeEventLog
(HANDLE arg0, HANDLE arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "NotifyChangeEventLog", "HANDLE", arg0, "HANDLE", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ObjectCloseAuditAlarmA
(LPCSTR arg0, PVOID arg1, BOOL arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ObjectCloseAuditAlarmA", "LPCSTR", arg0, "PVOID", arg1, "BOOL", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ObjectCloseAuditAlarmW
(LPCWSTR arg0, PVOID arg1, BOOL arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ObjectCloseAuditAlarmW", "LPCWSTR", arg0, "PVOID", arg1, "BOOL", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ObjectDeleteAuditAlarmA
(LPCSTR arg0, PVOID arg1, BOOL arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ObjectDeleteAuditAlarmA", "LPCSTR", arg0, "PVOID", arg1, "BOOL", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ObjectDeleteAuditAlarmW
(LPCWSTR arg0, PVOID arg1, BOOL arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ObjectDeleteAuditAlarmW", "LPCWSTR", arg0, "PVOID", arg1, "BOOL", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ObjectOpenAuditAlarmA
(LPCSTR arg0, PVOID arg1, LPSTR arg2, LPSTR arg3, PSECURITY_DESCRIPTOR arg4, HANDLE arg5, DWORD arg6, DWORD arg7, PPRIVILEGE_SET arg8, BOOL arg9, BOOL arg10, PBOOL arg11)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ObjectOpenAuditAlarmA", "LPCSTR", arg0, "PVOID", arg1, "LPSTR", arg2, "LPSTR", arg3, "PSECURITY_DESCRIPTOR", arg4, "HANDLE", arg5, "DWORD", arg6, "DWORD", arg7, "PPRIVILEGE_SET", arg8, "BOOL", arg9, "BOOL", arg10, "PBOOL", arg11, NULL);	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ObjectOpenAuditAlarmW
(LPCWSTR arg0, PVOID arg1, LPWSTR arg2, LPWSTR arg3, PSECURITY_DESCRIPTOR arg4, HANDLE arg5, DWORD arg6, DWORD arg7, PPRIVILEGE_SET arg8, BOOL arg9, BOOL arg10, PBOOL arg11)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ObjectOpenAuditAlarmW", "LPCWSTR", arg0, "PVOID", arg1, "LPWSTR", arg2, "LPWSTR", arg3, "PSECURITY_DESCRIPTOR", arg4, "HANDLE", arg5, "DWORD", arg6, "DWORD", arg7, "PPRIVILEGE_SET", arg8, "BOOL", arg9, "BOOL", arg10, "PBOOL", arg11, NULL);	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ObjectPrivilegeAuditAlarmA
(LPCSTR arg0, PVOID arg1, HANDLE arg2, DWORD arg3, PPRIVILEGE_SET arg4, BOOL arg5)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ObjectPrivilegeAuditAlarmA", "LPCSTR", arg0, "PVOID", arg1, "HANDLE", arg2, "DWORD", arg3, "PPRIVILEGE_SET", arg4, "BOOL", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ObjectPrivilegeAuditAlarmW
(LPCWSTR arg0, PVOID arg1, HANDLE arg2, DWORD arg3, PPRIVILEGE_SET arg4, BOOL arg5)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ObjectPrivilegeAuditAlarmW", "LPCWSTR", arg0, "PVOID", arg1, "HANDLE", arg2, "DWORD", arg3, "PPRIVILEGE_SET", arg4, "BOOL", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
OpenBackupEventLogA
(LPCSTR arg0, LPCSTR arg1)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "OpenBackupEventLogA", "LPCSTR", arg0, "LPCSTR", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
OpenBackupEventLogW
(LPCWSTR arg0, LPCWSTR arg1)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "OpenBackupEventLogW", "LPCWSTR", arg0, "LPCWSTR", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
OpenEventLogW
(LPCWSTR arg0, LPCWSTR arg1)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "OpenEventLogW", "LPCWSTR", arg0, "LPCWSTR", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
OpenProcessToken
(HANDLE arg0, DWORD arg1, PHANDLE arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "OpenProcessToken", "HANDLE", arg0, "DWORD", arg1, "PHANDLE", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" SC_HANDLE WINAPI
OpenSCManagerA
(LPCSTR arg0, LPCSTR arg1, DWORD arg2)
{
	SC_HANDLE rc = (SC_HANDLE)-1;
	WIN32API_ENTER("SC_HANDLE", "OpenSCManagerA", "LPCSTR", arg0, "LPCSTR", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" SC_HANDLE WINAPI
OpenSCManagerW
(LPCWSTR arg0, LPCWSTR arg1, DWORD arg2)
{
	SC_HANDLE rc = (SC_HANDLE)-1;
	WIN32API_ENTER("SC_HANDLE", "OpenSCManagerW", "LPCWSTR", arg0, "LPCWSTR", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" SC_HANDLE WINAPI
OpenServiceA
(SC_HANDLE arg0, LPCSTR arg1, DWORD arg2)
{
	SC_HANDLE rc = (SC_HANDLE)-1;
	WIN32API_ENTER("SC_HANDLE", "OpenServiceA", "SC_HANDLE", arg0, "LPCSTR", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" SC_HANDLE WINAPI
OpenServiceW
(SC_HANDLE arg0, LPCWSTR arg1, DWORD arg2)
{
	SC_HANDLE rc = (SC_HANDLE)-1;
	WIN32API_ENTER("SC_HANDLE", "OpenServiceW", "SC_HANDLE", arg0, "LPCWSTR", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
OpenThreadToken
(HANDLE arg0, DWORD arg1, BOOL arg2, PHANDLE arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "OpenThreadToken", "HANDLE", arg0, "DWORD", arg1, "BOOL", arg2, "PHANDLE", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
PrivilegedServiceAuditAlarmA
(LPCSTR arg0, LPCSTR arg1, HANDLE arg2, PPRIVILEGE_SET arg3, BOOL arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "PrivilegedServiceAuditAlarmA", "LPCSTR", arg0, "LPCSTR", arg1, "HANDLE", arg2, "PPRIVILEGE_SET", arg3, "BOOL", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
PrivilegedServiceAuditAlarmW
(LPCWSTR arg0, LPCWSTR arg1, HANDLE arg2, PPRIVILEGE_SET arg3, BOOL arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "PrivilegedServiceAuditAlarmW", "LPCWSTR", arg0, "LPCWSTR", arg1, "HANDLE", arg2, "PPRIVILEGE_SET", arg3, "BOOL", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
QueryServiceConfigA
(SC_HANDLE arg0, LPQUERY_SERVICE_CONFIGA arg1, DWORD arg2, PDWORD arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "QueryServiceConfigA", "SC_HANDLE", arg0, "LPQUERY_SERVICE_CONFIGA", arg1, "DWORD", arg2, "PDWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
QueryServiceConfigW
(SC_HANDLE arg0, LPQUERY_SERVICE_CONFIGW arg1, DWORD arg2, PDWORD arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "QueryServiceConfigW", "SC_HANDLE", arg0, "LPQUERY_SERVICE_CONFIGW", arg1, "DWORD", arg2, "PDWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
QueryServiceLockStatusA
(SC_HANDLE arg0, LPQUERY_SERVICE_LOCK_STATUSA arg1, DWORD arg2, PDWORD arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "QueryServiceLockStatusA", "SC_HANDLE", arg0, "LPQUERY_SERVICE_LOCK_STATUSA", arg1, "DWORD", arg2, "PDWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
QueryServiceLockStatusW
(SC_HANDLE arg0, LPQUERY_SERVICE_LOCK_STATUSW arg1, DWORD arg2, PDWORD arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "QueryServiceLockStatusW", "SC_HANDLE", arg0, "LPQUERY_SERVICE_LOCK_STATUSW", arg1, "DWORD", arg2, "PDWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
QueryServiceObjectSecurity
(SC_HANDLE arg0, SECURITY_INFORMATION arg1, PSECURITY_DESCRIPTOR arg2, DWORD arg3, LPDWORD arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "QueryServiceObjectSecurity", "SC_HANDLE", arg0, "SECURITY_INFORMATION", arg1, "PSECURITY_DESCRIPTOR", arg2, "DWORD", arg3, "LPDWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
QueryServiceStatus
(SC_HANDLE arg0, LPSERVICE_STATUS arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "QueryServiceStatus", "SC_HANDLE", arg0, "LPSERVICE_STATUS", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ReadEventLogA
(HANDLE arg0, DWORD arg1, DWORD arg2, PVOID arg3, DWORD arg4, DWORD * arg5, DWORD * arg6)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ReadEventLogA", "HANDLE", arg0, "DWORD", arg1, "DWORD", arg2, "PVOID", arg3, "DWORD", arg4, "DWORD *", arg5, "DWORD *", arg6, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ReadEventLogW
(HANDLE arg0, DWORD arg1, DWORD arg2, PVOID arg3, DWORD arg4, DWORD * arg5, DWORD * arg6)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ReadEventLogW", "HANDLE", arg0, "DWORD", arg1, "DWORD", arg2, "PVOID", arg3, "DWORD", arg4, "DWORD *", arg5, "DWORD *", arg6, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
RegisterEventSourceW
(LPCWSTR arg0, LPCWSTR arg1)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "RegisterEventSourceW", "LPCWSTR", arg0, "LPCWSTR", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" SERVICE_STATUS_HANDLE WINAPI
RegisterServiceCtrlHandlerA
(LPCSTR arg0, LPHANDLER_FUNCTION arg1)
{
	SERVICE_STATUS_HANDLE rc = (SERVICE_STATUS_HANDLE)-1;
	WIN32API_ENTER("SERVICE_STATUS_HANDLE", "RegisterServiceCtrlHandlerA", "LPCSTR", arg0, "LPHANDLER_FUNCTION", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" SERVICE_STATUS_HANDLE WINAPI
RegisterServiceCtrlHandlerW
(LPCWSTR arg0, LPHANDLER_FUNCTION arg1)
{
	SERVICE_STATUS_HANDLE rc = (SERVICE_STATUS_HANDLE)-1;
	WIN32API_ENTER("SERVICE_STATUS_HANDLE", "RegisterServiceCtrlHandlerW", "LPCWSTR", arg0, "LPHANDLER_FUNCTION", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ReportEventA
(HANDLE arg0, WORD arg1, WORD arg2, DWORD arg3, PSID arg4, WORD arg5, DWORD arg6, LPCSTR* arg7, PVOID arg8)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ReportEventA", "HANDLE", arg0, "WORD", arg1, "WORD", arg2, "DWORD", arg3, "PSID", arg4, "WORD", arg5, "DWORD", arg6, "LPCSTR*", arg7, "PVOID", arg8, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ReportEventW
(HANDLE arg0, WORD arg1, WORD arg2, DWORD arg3, PSID arg4, WORD arg5, DWORD arg6, LPCWSTR* arg7, PVOID arg8)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ReportEventW", "HANDLE", arg0, "WORD", arg1, "WORD", arg2, "DWORD", arg3, "PSID", arg4, "WORD", arg5, "DWORD", arg6, "LPCWSTR*", arg7, "PVOID", arg8, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
RevertToSelf
(void)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "RevertToSelf", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetAclInformation
(PACL arg0, PVOID arg1, DWORD arg2, ACL_INFORMATION_CLASS arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetAclInformation", "PACL", arg0, "PVOID", arg1, "DWORD", arg2, "ACL_INFORMATION_CLASS", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetFileSecurityA
(LPCSTR arg0, SECURITY_INFORMATION arg1, PSECURITY_DESCRIPTOR arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetFileSecurityA", "LPCSTR", arg0, "SECURITY_INFORMATION", arg1, "PSECURITY_DESCRIPTOR", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetFileSecurityW
(LPCWSTR arg0, SECURITY_INFORMATION arg1, PSECURITY_DESCRIPTOR arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetFileSecurityW", "LPCWSTR", arg0, "SECURITY_INFORMATION", arg1, "PSECURITY_DESCRIPTOR", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetKernelObjectSecurity
(HANDLE arg0, SECURITY_INFORMATION arg1, PSECURITY_DESCRIPTOR arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetKernelObjectSecurity", "HANDLE", arg0, "SECURITY_INFORMATION", arg1, "PSECURITY_DESCRIPTOR", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetPrivateObjectSecurity
(SECURITY_INFORMATION arg0, PSECURITY_DESCRIPTOR arg1, PSECURITY_DESCRIPTOR * arg2, PGENERIC_MAPPING arg3, HANDLE arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetPrivateObjectSecurity", "SECURITY_INFORMATION", arg0, "PSECURITY_DESCRIPTOR", arg1, "PSECURITY_DESCRIPTOR *", arg2, "PGENERIC_MAPPING", arg3, "HANDLE", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetSecurityDescriptorDacl
(PSECURITY_DESCRIPTOR arg0, BOOL arg1, PACL arg2, BOOL arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetSecurityDescriptorDacl", "PSECURITY_DESCRIPTOR", arg0, "BOOL", arg1, "PACL", arg2, "BOOL", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetSecurityDescriptorGroup
(PSECURITY_DESCRIPTOR arg0, PSID arg1, BOOL arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetSecurityDescriptorGroup", "PSECURITY_DESCRIPTOR", arg0, "PSID", arg1, "BOOL", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetSecurityDescriptorOwner
(PSECURITY_DESCRIPTOR arg0, PSID arg1, BOOL arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetSecurityDescriptorOwner", "PSECURITY_DESCRIPTOR", arg0, "PSID", arg1, "BOOL", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetSecurityDescriptorSacl
(PSECURITY_DESCRIPTOR arg0, BOOL arg1, PACL arg2, BOOL arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetSecurityDescriptorSacl", "PSECURITY_DESCRIPTOR", arg0, "BOOL", arg1, "PACL", arg2, "BOOL", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetServiceObjectSecurity
(SC_HANDLE arg0, SECURITY_INFORMATION arg1, PSECURITY_DESCRIPTOR arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetServiceObjectSecurity", "SC_HANDLE", arg0, "SECURITY_INFORMATION", arg1, "PSECURITY_DESCRIPTOR", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetServiceStatus
(SERVICE_STATUS_HANDLE arg0, LPSERVICE_STATUS arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetServiceStatus", "SERVICE_STATUS_HANDLE", arg0, "LPSERVICE_STATUS", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetTokenInformation
(HANDLE arg0, TOKEN_INFORMATION_CLASS arg1, PVOID arg2, DWORD arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetTokenInformation", "HANDLE", arg0, "TOKEN_INFORMATION_CLASS", arg1, "PVOID", arg2, "DWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
StartServiceA
(SC_HANDLE arg0, DWORD arg1, LPCSTR* arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "StartServiceA", "SC_HANDLE", arg0, "DWORD", arg1, "LPCSTR*", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
StartServiceCtrlDispatcherA
(LPSERVICE_TABLE_ENTRYA arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "StartServiceCtrlDispatcherA", "LPSERVICE_TABLE_ENTRYA", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
StartServiceCtrlDispatcherW
(LPSERVICE_TABLE_ENTRYW arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "StartServiceCtrlDispatcherW", "LPSERVICE_TABLE_ENTRYW", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
StartServiceW
(SC_HANDLE arg0, DWORD arg1, LPCWSTR arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "StartServiceW", "SC_HANDLE", arg0, "DWORD", arg1, "LPCWSTR", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
UnlockServiceDatabase
(SC_LOCK arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "UnlockServiceDatabase", "SC_LOCK", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
WinLoadTrustProvider
(GUID* arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "WinLoadTrustProvider", "GUID*", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

#if defined(_BUILTIN_DLL)

#	define	GetAddressByOrder	AdvAPI32_GetAddressByOrder
#	define	GetAddressByName	AdvAPI32_GetAddressByName

#	include "AdvAPI32/GetAddressByOrder.h"
#	include "AdvAPI32/GetAddressByName.h"

#endif	// defined(_BUILTIN_DLL)
