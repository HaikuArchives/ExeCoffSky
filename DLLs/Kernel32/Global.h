/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 ‚Æ‚æ‚µ‚Ü
 *  $Id: Global.h,v 1.1 2003/05/01 02:57:16 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Global.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__Global_h__)
#	define	__Global_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

typedef struct tagMEMORYSTATUS {
	PACKED(DWORD dwLength);
	PACKED(DWORD dwMemoryLoad);
	PACKED(DWORD dwTotalPhys);
	PACKED(DWORD dwAvailPhys);
	PACKED(DWORD dwTotalPageFile);
	PACKED(DWORD dwAvailPageFile);
	PACKED(DWORD dwTotalVirtual);
	PACKED(DWORD dwAvailVirtual);
} MEMORYSTATUS, *LPMEMORYSTATUS;

#	if !defined(__Local_h__)
#		include "Local.h"
#	endif	// !defined(__Local_h__)

#	define	GMEM_FIXED			LMEM_FIXED
#	define	GMEM_MOVEABLE		LMEM_MOVEABLE
#	define	GMEM_NOCOMPACT		LMEM_NOCOMPACT
#	define	GMEM_NODISCARD		LMEM_NODISCARD
#	define	GMEM_ZEROINIT		LMEM_ZEROINIT
#	define	GMEM_MODIFY			LMEM_MODIFY
#	define	GMEM_DISCARDABLE	LMEM_DISCARDABLE
#	define	GMEM_NOT_BANKED		0x1000
#	define	GMEM_SHARE			0x2000
#	define	GMEM_DDESHARE		0x2000
#	define	GMEM_NOTIFY			0x4000
#	define	GMEM_LOWER			GMEM_NOT_BANKED
#	define	GMEM_VALID_FLAGS	0x7f72
#	define	GMEM_INVALID_HANDLE	LMEM_INVALID_HANDLE
#	define	GHND				(GMEM_MOVEABLE | GMEM_ZEROINIT)
#	define	GPTR				(GMEM_FIXED | GMEM_ZEROINIT)
#	define	GMEM_DISCARDED		LMEM_DISCARDED
#	define	GMEM_LOCKCOUNT		0x00ff

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

HGLOBAL WINAPI GlobalAlloc(UINT uFlags, SIZE_T dwBytes);
LPVOID WINAPI GlobalLock(HGLOBAL hMem);
BOOL WINAPI GlobalUnlock(HGLOBAL hMem);
HGLOBAL WINAPI GlobalFree(HGLOBAL hMem);
LPVOID WINAPI GlobalWire(HGLOBAL hMem);
BOOL WINAPI GlobalUnWire(HGLOBAL hMem);
HGLOBAL WINAPI GlobalReAlloc(HGLOBAL hMem, DWORD dwBytes, UINT uFlags);
UINT WINAPI GlobalCompact(DWORD MimFree);
UINT WINAPI GlobalFlags(HGLOBAL hMem);
HGLOBAL WINAPI GlobalHandle(LPCVOID pMem);
DWORD WINAPI GlobalSize(HGLOBAL hMem);

VOID WINAPI GlobalFix(HGLOBAL hMem);
VOID WINAPI GlobalMemoryStatus(LPMEMORYSTATUS lpMemoryStatus);
VOID WINAPI GlobalUnfix(HGLOBAL hMem);

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__Global_h__)
