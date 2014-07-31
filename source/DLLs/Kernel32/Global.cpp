/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 ‚Æ‚æ‚µ‚Ü
 *  $Id: Global.cpp,v 1.1 2003/05/01 02:57:16 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Global.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "Global.h"
#include "Local.h"
#include "Win32Trace.h"
#include "Win32Error.h"

extern "C" HGLOBAL WINAPI
GlobalAlloc
(UINT uFlags, SIZE_T dwBytes)
{
	WIN32API_ENTER("HGLOBAL", "GlobalAlloc", "UINT", uFlags, "SIZE_T", dwBytes, NULL);
	WIN32API_INTERNAL_START();
	HGLOBAL rc = (HGLOBAL)LocalAlloc(uFlags, dwBytes);
	WIN32API_INTERNAL_END();
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LPVOID WINAPI
GlobalLock
(HGLOBAL hMem)
{
	WIN32API_ENTER("LPVOID", "GlobalLock", "HGLOBAL", hMem, NULL);
	WIN32API_INTERNAL_START();
	LPVOID rc = LocalLock((HLOCAL)hMem);
	WIN32API_INTERNAL_END();
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GlobalUnlock
(HGLOBAL hMem)
{
	WIN32API_ENTER("BOOL", "GlobalUnlock", "HGLOBAL", hMem, NULL);
	WIN32API_INTERNAL_START();
	BOOL rc = LocalUnlock((HLOCAL)hMem);
	WIN32API_INTERNAL_END();
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HGLOBAL WINAPI
GlobalFree
(HGLOBAL hMem)
{
	WIN32API_ENTER("HGLOBAL", "GlobalFree", "HGLOBAL", hMem, NULL);
	WIN32API_INTERNAL_START();
	HGLOBAL rc = (HGLOBAL)LocalFree((HLOCAL)hMem);
	WIN32API_INTERNAL_END();
	WIN32API_LEAVE(rc);
	return rc;

}

extern "C" LPVOID WINAPI
GlobalWire
(HGLOBAL hMem)
{
	WIN32API_ENTER("LPVOID", "GlobalWire", "HGLOBAL", hMem, NULL);
	WIN32API_INTERNAL_START();
	LPVOID rc = LocalLock((HLOCAL)hMem);
	WIN32API_INTERNAL_END();
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GlobalUnWire
(HGLOBAL hMem)
{
	WIN32API_ENTER("BOOL", "GlobalUnWire", "HGLOBAL", hMem, NULL);
	WIN32API_INTERNAL_START();
	BOOL rc = LocalUnlock((HLOCAL)hMem);
	WIN32API_INTERNAL_END();
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HGLOBAL WINAPI
GlobalReAlloc
(HGLOBAL hMem, DWORD dwBytes, UINT uFlags)
{
	WIN32API_ENTER("HGLOBAL", "GlobalReAlloc", "HGLOBAL", hMem, "DWORD", dwBytes, "UINT", uFlags, NULL);
	WIN32API_INTERNAL_START();
	HGLOBAL rc = (HGLOBAL)LocalReAlloc((HLOCAL)hMem, dwBytes, uFlags);
	WIN32API_INTERNAL_END();
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
GlobalCompact
(DWORD MimFree)
{
	WIN32API_ENTER("UINT", "GlobalCompact", "DWORD", MimFree, NULL);
	WIN32API_INTERNAL_START();
	UINT rc = LocalCompact(MimFree);
	WIN32API_INTERNAL_END();
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
GlobalFlags
(HGLOBAL hMem)
{
	WIN32API_ENTER("UINT", "GlobalFlags", "HGLOBAL", hMem, NULL);
	WIN32API_INTERNAL_START();
	UINT rc = LocalFlags((HLOCAL)hMem);
	WIN32API_INTERNAL_END();
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HGLOBAL WINAPI
GlobalHandle
(LPCVOID pMem)
{
	WIN32API_ENTER("HGLOBAL", "GlobalHandle", "LPCVOID", pMem, NULL);
	WIN32API_INTERNAL_START();
	HGLOBAL rc = (HGLOBAL)LocalHandle(pMem);
	WIN32API_INTERNAL_END();
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GlobalSize
(HGLOBAL hMem)
{
	WIN32API_ENTER("DWORD", "GlobalSize", "HGLOBAL", hMem, NULL);
	WIN32API_INTERNAL_START();
	DWORD rc = LocalSize((HLOCAL)hMem);
	WIN32API_INTERNAL_END();
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" VOID WINAPI
GlobalFix
(HGLOBAL hMem)
{
	WIN32API_ENTER("VOID", "GlobalFix", "HGLOBAL", hMem, NULL);
	WIN32API_ERROR(ERROR_SUCCESS);
	WIN32API_LEAVE(0);
}

extern "C" VOID WINAPI
GlobalMemoryStatus
(LPMEMORYSTATUS lpMemoryStatus)
{
	WIN32API_POINTER(lpMemoryStatus);
	WIN32API_ENTER("VOID", "GlobalMemoryStatus", "LPMEMORYSTATUS", lpMemoryStatus, NULL);
	if (lpMemoryStatus->dwLength != sizeof(MEMORYSTATUS)) {
		WIN32API_INFO("\tdwLength = %d (!= %d) ... fixed to %d\n",
			lpMemoryStatus->dwLength, sizeof(MEMORYSTATUS), sizeof(MEMORYSTATUS));
		lpMemoryStatus->dwLength = sizeof(MEMORYSTATUS);
	}
	lpMemoryStatus->dwMemoryLoad = 0;	// XXX
	system_info info;
	get_system_info(&info);
	lpMemoryStatus->dwTotalPhys = info.max_pages * B_PAGE_SIZE;
	lpMemoryStatus->dwAvailPhys = (info.max_pages - info.used_pages) * B_PAGE_SIZE;
	// XXX: todo
	lpMemoryStatus->dwTotalPageFile = lpMemoryStatus->dwTotalPhys;
	lpMemoryStatus->dwAvailPageFile = lpMemoryStatus->dwAvailPhys;
	// XXX: todo
	lpMemoryStatus->dwTotalVirtual = lpMemoryStatus->dwTotalPhys;
	lpMemoryStatus->dwAvailVirtual = lpMemoryStatus->dwAvailPhys;
	WIN32API_LEAVE(0);
}

extern "C" VOID WINAPI
GlobalUnfix
(HGLOBAL hMem)
{
	WIN32API_ENTER("VOID", "GlobalUnfix", "HGLOBAL", hMem, NULL);
	WIN32API_ERROR(ERROR_SUCCESS);
	WIN32API_LEAVE(0);
}
