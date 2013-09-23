/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 ‚Æ‚æ‚µ‚Ü
 *  $Id: Heap.h,v 1.1 2003/05/01 02:57:16 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Heap.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__Heap_h__)
#	define	__Heap_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	define	HEAP_NO_SERIALIZE			0x00000001
#	define	HEAP_GROWABLE				0x00000002
#	define	HEAP_GENERATE_EXCEPTIONS	0x00000004
#	define	HEAP_ZERO_MEMORY			0x00000008
#	define	HEAP_REALLOC_IN_PLACE_ONLY	0x00000010

#	define	HEAP_MAGIC					'_HAP'
#	define	BLOCK_MAGIC					'bLCk'

class Heap {
public:
	DWORD magic;
private:
	typedef struct _block {
		DWORD magic;
		SIZE_T size;
		struct _block *follow;
	} block;
	BLocker lock;
	BList list;
	BList heaps;
	BList blocks;
public:
	Heap(void);
	~Heap(void);
	
	bool Create(DWORD flOptions, SIZE_T dwInitialSize, SIZE_T dwMaimumSize);
	LPVOID Allocate(DWORD flags, SIZE_T size);
	LPVOID ReAllocate(DWORD flags, LPVOID ptr, SIZE_T size);
	bool Free(DWORD flags, LPVOID ptr);
	DWORD GetSize(DWORD flags, PCVOID ptr);
	inline void Lock(void) { lock.Lock(); };
	inline void Unlock(void) { lock.Unlock(); };
	inline bool Lock(DWORD &flags) {
		if (0 == (flags & HEAP_NO_SERIALIZE)) {
			Lock();
			return true;
		} else {
			flags &= ~HEAP_NO_SERIALIZE;
			return false;
		}
	};
private:
	Heap::block *FindBlock(SIZE_T size);
};

#	if !defined(__Heap__)
#		define	__Heap__
#	endif	// !defined(__Heap__)

typedef struct tagHEAPENTRY32 {
} HEAPENTRY32, *LPHEAPENTRY32;

typedef struct tagHEAPLIST32 {
} HEAPLIST32, *LPHEAPLIST32;

typedef struct tagPROCESS_HEAP_ENTRY {
} PROCESS_HEAP_ENTRY, *LPPROCESS_HEAP_ENTRY;

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

BOOL WINAPI Heap32First(LPHEAPENTRY32 lphe, DWORD th32ProcessID, DWORD th32HeapID);
BOOL WINAPI Heap32ListFirst(HANDLE hSnapShot, LPHEAPLIST32 lphl);
BOOL WINAPI Heap32ListNext(HANDLE hSnapShot, LPHEAPLIST32 lphl);
BOOL WINAPI Heap32Next(LPHEAPENTRY32 lphe);
LPVOID WINAPI HeapAlloc(HANDLE hHeap, DWORD dwFlags, SIZE_T dwBytes);
UINT WINAPI HeapCompact(HANDLE hHeap, DWORD dwFlags);
HANDLE WINAPI HeapCreate(DWORD flOptions, SIZE_T dwInitialSize, SIZE_T dwMaximumSize);
BOOL WINAPI HeapDestroy(HANDLE hHeap);
BOOL WINAPI HeapFree(HANDLE hHeap, DWORD dwFlags, LPVOID lpMem);
BOOL WINAPI HeapLock(HANDLE hHeap);
LPVOID WINAPI HeapReAlloc(HANDLE hHeap, DWORD dwFlags, LPVOID lpMem, SIZE_T dwBytes);
DWORD WINAPI HeapSize(HANDLE hHeap, DWORD dwFlags, PCVOID lpMem);
BOOL WINAPI HeapUnlock(HANDLE hHeap);
BOOL WINAPI HeapValidate(HANDLE hHeap, DWORD dwFlags, LPCVOID lpMem);
BOOL WINAPI HeapWalk(HANDLE hHeap, LPPROCESS_HEAP_ENTRY lpEntry);

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__Heap_h__)
