/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 ‚Æ‚æ‚µ‚Ü
 *  $Id: Virtual.cpp,v 1.1 2003/05/01 02:57:17 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Virtual.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "Virtual.h"
#include "Coff.h"
#include "Process.h"
#include "Win32Trace.h"

Virtual::LpReservedList
Virtual::reserved_list = NULL;

LPVOID
Virtual::Reserve
(LPVOID lpAddress, DWORD dwSize)
{
	area_id id = create_area("win32_virtual", &lpAddress, (NULL == lpAddress)? B_ANY_ADDRESS: B_EXACT_ADDRESS,
		(dwSize + B_PAGE_SIZE - 1) / B_PAGE_SIZE * B_PAGE_SIZE, B_NO_LOCK, B_READ_AREA | B_WRITE_AREA);
	if (id < B_OK) return NULL;
	LPVOID rc = lpAddress;
	if (NULL != rc) {
		LpReservedList list = new ReservedList();
		if (NULL == list) {
			delete_area(id);
			return NULL;
		}
		list->lpAddress = rc;
		list->dwSize = dwSize;
		list->next = reserved_list;
		reserved_list = list;
	}
#if defined(ENABLE_DYNAMIC_RELOCATION)
	Process *process = Process::GetCurrentProcessObject();
	if (NULL != process) {
		HINSTANCE hInstance = process->GetInstance();
		Coff *coff = Coff::InstanceToCoff(hInstance);
		coff->VAreaAdd((void *)rc, (int)dwSize);
	}
#endif	// defined(ENABLE_DYNAMIC_RELOCATION)
	return rc;
}

LPVOID
Virtual::Commit
(LPVOID lpAddress, DWORD dwSize)
{
	for (LpReservedList list = reserved_list; NULL != list; list = list->next) {
		if (list->lpAddress > lpAddress) continue;
		if (((DWORD)list->lpAddress + list->dwSize) < ((DWORD)lpAddress + dwSize)) continue;
		return lpAddress;
	}
	LPVOID rc = Reserve(lpAddress, dwSize);
	WIN32API_INFO("\treserve: %p\n", rc);
	if (NULL != rc) return Commit(rc, dwSize);
	return NULL;
}

extern "C" LPVOID WINAPI
VirtualAlloc
(LPVOID lpAddress, SIZE_T dwSize, DWORD flAllocationType, DWORD flProtect)
{
	LPVOID rc = NULL;
	WIN32API_ENTER("LPVOID", "VirtualAlloc", "LPVOID", lpAddress, "SIZE_T", dwSize, "DWORD", flAllocationType, "DWORD", flProtect, NULL);
	if (0 != (flAllocationType & MEM_RESERVE)) {
		flAllocationType &= ~MEM_RESERVE;
		rc = Virtual::Reserve(lpAddress, dwSize);
	}
	if (0 != (flAllocationType & MEM_COMMIT)) {
		flAllocationType &= ~MEM_COMMIT;
		rc = Virtual::Commit(lpAddress, dwSize);
	}
	if (NULL != rc) {
		if (0 != flAllocationType) WIN32API_INFO("\tnot support: flAllocationType: $%08x\n", flAllocationType);
		if (0 != flProtect) WIN32API_INFO("\tnot support: flProtect: $%08x\n", flProtect);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
VirtualFree
(LPVOID lpAddress, SIZE_T dwSize, DWORD dwFreeType)
{
	BOOL rc;
	WIN32API_ENTER("BOOL", "VirtualFree", "LPVOID", lpAddress, "SIZE_T", dwSize, "DWORD", dwFreeType, NULL);
	area_id id = area_for(lpAddress);
	if (id < B_OK) rc = FALSE;
	else rc = (B_OK == delete_area(id));
	if (TRUE == rc) {
		if (0 != dwFreeType) WIN32API_INFO("\tnot support: dwFreeType: $%08x\n", dwFreeType);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
VirtualFreeEx
(HANDLE arg0, PVOID arg1, DWORD arg2, DWORD arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "VirtualFreeEx", "HANDLE", arg0, "PVOID", arg1, "DWORD", arg2, "DWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
VirtualLock
(PVOID arg0, DWORD arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "VirtualLock", "PVOID", arg0, "DWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
VirtualProtect
(PVOID arg0, DWORD arg1, DWORD arg2, PDWORD arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "VirtualProtect", "PVOID", arg0, "DWORD", arg1, "DWORD", arg2, "PDWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
VirtualProtectEx
(HANDLE arg0, PVOID arg1, DWORD arg2, DWORD arg3, PDWORD arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "VirtualProtectEx", "HANDLE", arg0, "PVOID", arg1, "DWORD", arg2, "DWORD", arg3, "PDWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
VirtualQuery
(LPCVOID arg0, PMEMORY_BASIC_INFORMATION arg1, DWORD arg2)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "VirtualQuery", "LPCVOID", arg0, "PMEMORY_BASIC_INFORMATION", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
VirtualQueryEx
(HANDLE arg0, LPCVOID arg1, PMEMORY_BASIC_INFORMATION arg2, DWORD arg3)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "VirtualQueryEx", "HANDLE", arg0, "LPCVOID", arg1, "PMEMORY_BASIC_INFORMATION", arg2, "DWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
VirtualUnlock
(PVOID arg0, DWORD arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "VirtualUnlock", "PVOID", arg0, "DWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}
