/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 とよしま
 *  $Id: Local.h,v 1.1 2003/05/01 02:57:16 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Local.h]
 *   ローカルヒープの実装。スレッドは考慮しない（これがWin32API的に正しいのかは不明）。
 * -------------------------------------------------------------------------------------------- */

#if !defined(__Local_h__)
#	define	__Local_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	define	LOCAL_MAGIC		'_LCL'
#	define	LOCALBLOCK_MAGIC	'_LCb'

#	define	LMEM_FIXED			0x0000
#	define	LMEM_MOVEABLE		0x0002
#	define	LMEM_NOCOMPACT		0x0010
#	define	LMEM_NODISCARD		0x0020
#	define	LMEM_ZEROINIT		0x0040
#	define	LMEM_MODIFY			0x0080
#	define	LMEM_LOCKCOUNT		0x00ff
#	define	LMEM_DISCARDABLE	0x0f00
#	define	LMEM_VALID_FLAGS	0x0f72
#	define	LMEM_DISCARDED		0x4000
#	define	LMEM_INVALID_HANDLE	0x8000
#	define	LHND				(LMEM_MOVABLE | LMEM_ZEROINIT)
#	define	LPTR				(LMEM_FIXED | LMEM_ZEROINIT)
#	define	NONZEROLHND			LMEM_MOVEABLE
#	define	NONZEROLPTR			LMEM_FIXED

class Local {
	typedef struct _block {
		DWORD magic;
		Local *owner;
	} block;
public:
	block h;
private:
	int lock_count;
	SIZE_T size;
	block *buffer;
	bool zeroinit;
	bool fixed;
public:
	Local(void);
	~Local(void);
	
	HLOCAL Allocate(UINT uFlags, UINT nBytes);
	HLOCAL ReAllocate(UINT uFlags, UINT nBytes);
	LPVOID Lock(void);
	BOOL Unlock(void);
	SIZE_T GetSize(void);

	static Local *HandleToLocal(HLOCAL hLocal);
	static HLOCAL MemoryToHandle(LPCVOID pMem);
};

#	if !defined(__Local__)
#		define	__Local__
#	endif	// !defined(__Local__)

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

HLOCAL WINAPI LocalAlloc(UINT uFlags, UINT nBytes);
LPVOID WINAPI LocalLock(HLOCAL hMem);
BOOL WINAPI LocalUnlock(HLOCAL hMem);
HLOCAL WINAPI LocalFree(HLOCAL hMem);
HLOCAL WINAPI LocalReAlloc(HLOCAL hMem, UINT nBytes, UINT uFlags);
UINT WINAPI LocalCompact(UINT MimFree);
UINT WINAPI LocalFlags(HLOCAL hMem);
HLOCAL WINAPI LocalHandle(LPCVOID pMem);
BOOL WINAPI LocalShrink(HLOCAL hMem, UINT arg);
UINT WINAPI LocalSize(HLOCAL hMem);

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__Local_h__)
