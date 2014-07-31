/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 ‚Æ‚æ‚µ‚Ü
 *  $Id: Virtual.h,v 1.1 2003/05/01 02:57:17 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Virtual.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__Virtual_h__)
#	define	__Virtual_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	define	MEM_COMMIT				0x00001000
#	define	MEM_RESERVE				0x00002000
#	define	MEM_DECOMMIT			0x00004000
#	define	MEM_DELEASE				0x00008000
#	define	MEM_FREE				0x00010000
#	define	MEM_PRIVATE				0x00020000
#	define	MEM_MAPPED				0x00040000
#	define	MEM_TOP_DOWN			0x00100000
#	define	MEM_IMAGE				0x01000000

#	define	PAGE_NOACCESS			0x00000001
#	define	PAGE_READONLY			0x00000002
#	define	PAGE_READWRITE			0x00000004
#	define	PAGE_WRITECOPY			0x00000008
#	define	PAGE_EXECUTE			0x00000010
#	define	PAGE_EXECUTE_READ		0x00000020
#	define	PAGE_EXECUTE_READWRITE	0x00000040
#	define	PAGE_EXECUTE_WRITECOPY	0x00000080
#	define	PAGE_CUARD				0x00000100
#	define	PAGE_NOCACHE			0x00000200

typedef struct tagMEMORY_BASIC_INFORMATION {
} MEMORY_BASIC_INFORMATION, *PMEMORY_BASIC_INFORMATION, *LPMEMORY_BASIC_INFORMATION;

class Virtual {
private:
	typedef struct _ReservedList{
		LPVOID lpAddress;
		DWORD dwSize;
		struct _ReservedList *next;
	} ReservedList, *LpReservedList;
	static LpReservedList reserved_list;
public:
	static LPVOID Reserve(LPVOID lpAddress, DWORD dwSize);
	static LPVOID Commit(LPVOID lpAddress, DWORD dwSize);
};

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

LPVOID WINAPI VirtualAlloc(LPVOID lpAddress, SIZE_T dwSize, DWORD flAllocationType, DWORD flProtect);
BOOL WINAPI VirtualFree(LPVOID lpAddress, SIZE_T dwSize, DWORD dwFreeType);
BOOL WINAPI VirtualFreeEx(HANDLE,PVOID,DWORD,DWORD);
BOOL WINAPI VirtualLock(PVOID,DWORD);
BOOL WINAPI VirtualProtect(PVOID,DWORD,DWORD,PDWORD);
BOOL WINAPI VirtualProtectEx(HANDLE,PVOID,DWORD,DWORD,PDWORD);
DWORD WINAPI VirtualQuery(LPCVOID,PMEMORY_BASIC_INFORMATION,DWORD);
DWORD WINAPI VirtualQueryEx(HANDLE,LPCVOID,PMEMORY_BASIC_INFORMATION,DWORD);
BOOL WINAPI VirtualUnlock(PVOID,DWORD);

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__Virtual_h__)
