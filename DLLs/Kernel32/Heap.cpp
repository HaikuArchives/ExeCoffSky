/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 とよしま
 *  $Id: Heap.cpp,v 1.1 2003/05/01 02:57:16 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Heap.cpp]
 *  TODO: 現在はばらばらに確保しているが、本来はヒープとして大きなメモリを確保し、
 *  その内部のメモリをやりくりするのが正しい。
 * -------------------------------------------------------------------------------------------- */
#include "Heap.h"
#include "Process.h"
#include "Kernel32.h"
#include "Win32Trace.h"
#include "Win32Error.h"

Heap::Heap
(void):
magic(HEAP_MAGIC)
{
}

Heap::~Heap
(void)
{
	magic = 0;
	int32 n = heaps.CountItems();
	for (int i = 0; i < n; i++) free(heaps.ItemAt(i));
}

bool
Heap::Create
(DWORD flOptions, SIZE_T dwInitialSize, SIZE_T dwMaximumSize)
{
	bool lock = Lock(flOptions);
	if (0 != flOptions) WIN32API_INFO("\tignore flOptions: $%08x\n", flOptions);
	SIZE_T size = dwInitialSize;
	if (size < dwMaximumSize) size = dwMaximumSize;
	size = (size + B_PAGE_SIZE - 1) / B_PAGE_SIZE * B_PAGE_SIZE;
	WIN32API_INFO("\tallocating memory $%08x bytes for heap\n", size);
	void *buffer = malloc(size);
	bool rc = false;
	if (NULL != buffer) {
		heaps.AddItem(buffer);
		block *b = (block *)buffer;
		b->magic = BLOCK_MAGIC;
		b->size = size - sizeof(block);
		b->follow = NULL;
		rc = list.AddItem((void *)b);
		if (rc) {
			WIN32API_ERROR(ERROR_SUCCESS);
		} else free(buffer);
	} else {
		WIN32API_INFO("\tfailed: not enough memory\n");
		WIN32API_ERROR(ERROR_NOT_ENOUGH_MEMORY);
	}
	if (lock) Unlock();
	return rc;
}

LPVOID
Heap::Allocate
(DWORD flags, SIZE_T size)
{
	size += 0xfff;
	size &= ~0xff;
	bool lock = Lock(flags);
	LPVOID rc = NULL;
	block *b = FindBlock(size);
	if (NULL != b) {
		if (list.RemoveItem((void *)b)) {
			block *next = (block *)&((char *)&b[1])[size];
			int next_size = b->size - size - sizeof(block);
			if (next_size > 0) {
				next->magic = BLOCK_MAGIC;
				next->size = next_size;
				next->follow = NULL;
				list.AddItem((void *)next);
				b->size = size;
				b->follow = next;
			} else b->follow = NULL;
			rc = (LPVOID)&b[1];
			WIN32API_ERROR(ERROR_SUCCESS);
		} else {
			WIN32API_INFO("\tfailed to remove block from list\n");
		}
	} else {
		void *buffer = malloc(size + sizeof(block));
		if (NULL != buffer) {
			heaps.AddItem(buffer);
			block *b = (block *)buffer;
			b->magic = BLOCK_MAGIC;
			b->size = size;
			b->follow = NULL;
			rc = (LPVOID)&b[1];
			WIN32API_ERROR(ERROR_SUCCESS);
		} else {
			WIN32API_ERROR(ERROR_NOT_ENOUGH_MEMORY);
		}
	}
	if ((NULL != rc) && (0 != (flags & HEAP_ZERO_MEMORY))) {
		flags &= ~HEAP_ZERO_MEMORY;
		memset(rc, 0, size);
	}
	if (0 != flags) WIN32API_INFO("\tignore flags: $%08x\n", flags);
	if (NULL != rc) blocks.AddItem(rc);
	if (lock) Unlock();
	return rc;
}

LPVOID
Heap::ReAllocate
(DWORD flags, LPVOID ptr, SIZE_T size)
{
	bool lock = Lock(flags);
	LPVOID rc = NULL;
	block *b = (block *)ptr;
	b--;
	if (!blocks.HasItem(ptr) || (b->magic != BLOCK_MAGIC)) {
		WIN32API_ERROR(ERROR_BAD_ARGUMENTS);
	} else {
		SIZE_T org_size = b->size;
check:
		if (b->size < size) {
			// 拡大
			if ((b->follow != NULL) && list.HasItem((void *)b->follow)) {
				// 連続して拡大
				list.RemoveItem((void *)b->follow);
				b->size += b->follow->size + sizeof(block);
				b->follow = b->follow->follow;
				goto check;
			} else {
				// 別の場所に再配置
				if (0 != (flags & HEAP_REALLOC_IN_PLACE_ONLY)) {
					rc = NULL;
					// 延びたヒープを戻す
					block *next = (block *)&((char *)&b[1])[org_size];
					int next_size = b->size - org_size - sizeof(block);
					if (next_size > 0) {
						next->magic = BLOCK_MAGIC;
						next->size = next_size;
						next->follow = NULL;
						list.AddItem((void *)next);
						b->size = org_size;
						b->follow = next;
					} else b->follow = NULL;
					WIN32API_ERROR(ERROR_NOT_ENOUGH_MEMORY);
				} else {
					LPVOID newmem = Allocate(flags, size);
					if (NULL == newmem) {
						WIN32API_ERROR(ERROR_NOT_ENOUGH_MEMORY);
					} else {
						memcpy(newmem, ptr, org_size);
						Free(flags, ptr);
						rc = newmem;
					}
				}
			}
			if ((NULL != rc) && (0 != (HEAP_ZERO_MEMORY & flags))) memset(&((char *)rc)[org_size], 0, size - org_size);
		} else {
			// 縮小
			block *next = (block *)&((char *)&b[1])[size];
			int next_size = b->size - size - sizeof(block);
			if (next_size > 0) {
				next->magic = BLOCK_MAGIC;
				next->size = next_size;
				next->follow = NULL;
				list.AddItem((void *)next);
				b->size = size;
				b->follow = next;
			} else b->follow = NULL;
			rc = (LPVOID)&b[1];
			WIN32API_ERROR(ERROR_SUCCESS);
		}
	}
	if (lock) Unlock();
	return rc;
}

bool
Heap::Free
(DWORD flags, LPVOID ptr)
{
	bool lock = Lock(flags);
	block *b = (block *)ptr;
	b--;
	bool rc = false;
	if (!blocks.HasItem(ptr) || (b->magic != BLOCK_MAGIC)) {
		WIN32API_ERROR(ERROR_BAD_ARGUMENTS);
	} else {
		list.AddItem((void *)b);
		blocks.RemoveItem(ptr);
		rc = true;
	}
	if (lock) Unlock();
	return rc;
}

DWORD
Heap::GetSize
(DWORD flags, PCVOID ptr)
{
	bool lock = Lock(flags);
	DWORD size = 0;
	block *b = (block *)ptr;
	b--;
	if (b->magic != BLOCK_MAGIC) {
		WIN32API_ERROR(ERROR_BAD_ARGUMENTS);
	} else {
		size = b->size;
	}
	if (lock) Unlock();
	return size;
}

Heap::block *
Heap::FindBlock
(SIZE_T size)
{
	int32 n = list.CountItems();
	block *cblock = NULL;
	SIZE_T csize = 0;
	WIN32API_INFO("\tfind ideal block...\n");
	for (int32 i = 0; i < n; i++) {
		block *b = (block *)list.ItemAt(i);
		if (NULL == b) continue;
		if (b->size > size) {
			WIN32API_INFO("\tblock (%p: $%08x) found\n", b, b->size);
			if (NULL == cblock) {
				WIN32API_INFO("\t\tthis block is first candidate\n");
				cblock = b;
				csize = b->size;
			} else if (csize > b->size) {
				WIN32API_INFO("\t\tthis block seem to be better candidate\n");
				cblock = b;
				csize = b->size;
			}
		}
	}
	return cblock;
}

extern "C" BOOL WINAPI
Heap32First
(LPHEAPENTRY32 lphe, DWORD th32ProcessID, DWORD th32HeapID)
{
	BOOL rc = FALSE;
	WIN32API_POINTER(lphe);
	WIN32API_ENTER("BOOL", "Heap32First", "LPHEAPENTRY32", lphe, "DWORD", th32ProcessID, "DWORD", th32HeapID, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
Heap32ListFirst
(HANDLE hSnapShot, LPHEAPLIST32 lphl)
{
	BOOL rc = FALSE;
	WIN32API_POINTER(lphl);
	WIN32API_ENTER("BOOL", "Heap32ListFirst", "HANDLE", hSnapShot, "LPHEAPLIST32", lphl, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
Heap32ListNext
(HANDLE hSnapShot, LPHEAPLIST32 lphl)
{
	BOOL rc = FALSE;
	WIN32API_POINTER(lphl);
	WIN32API_ENTER("BOOL", "Heap32ListNext", "HANDLE", hSnapShot, "LPHEAPLIST32", lphl, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
Heap32Next
(LPHEAPENTRY32 lphe)
{
	BOOL rc = FALSE;
	WIN32API_POINTER(lphe);
	WIN32API_ENTER("BOOL", "Heap32Next", "LPHEAPENTRY32", lphe, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LPVOID WINAPI
HeapAlloc
(HANDLE hHeap, DWORD dwFlags, SIZE_T dwBytes)
{
	LPVOID rc = NULL;
	WIN32API_ENTER("LPVOID", "HeapAlloc", "HANDLE", hHeap, "DWORD", dwFlags, "SIZE_T", dwBytes, NULL);
	Heap *heap = REINTERPRET_CAST(Heap *, hHeap);
	if ((NULL != heap) && (heap->magic == HEAP_MAGIC)) {
		rc = heap->Allocate(dwFlags, dwBytes);
		if (NULL != rc) WIN32API_ERROR(ERROR_SUCCESS);
	} else {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
HeapCompact
(HANDLE hHeap, DWORD dwFlags)
{
	UINT rc = 0;
	WIN32API_ENTER("UINT", "HeapCompact", "HANDLE", hHeap, "DWORD", dwFlags, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
HeapCreate
(DWORD flOptions, SIZE_T dwInitialSize, SIZE_T dwMaximumSize)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "HeapCreate", "DWORD", flOptions, "SIZE_T", dwInitialSize, "SIZE_T", dwMaximumSize, NULL);
	WIN32API_INFO("\tdwInitialSize: $%08x\n", dwInitialSize);
	WIN32API_INFO("\tdwMaximumSize: $%08x\n", dwMaximumSize);
	Heap *heap = new Heap();
	if (NULL != heap) {
		if (heap->Create(flOptions, dwInitialSize, dwMaximumSize)) {
			WIN32API_ERROR(ERROR_SUCCESS);
			rc = (HANDLE)heap;
			Process::GetCurrentProcessObject()->HeapAppend(heap);
		} else {
			delete heap;
		}
	} else {
		WIN32API_ERROR(ERROR_NOT_ENOUGH_MEMORY);
	}
	WIN32API_LEAVE(rc);
	return rc;
}


extern "C" BOOL WINAPI
HeapDestroy
(HANDLE hHeap)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "HeapDestroy", "HANDLE", hHeap, NULL);
	Heap *heap = REINTERPRET_CAST(Heap *, hHeap);
	if ((NULL != heap) && (heap->magic == HEAP_MAGIC)) {
		Process::GetCurrentProcessObject()->HeapRemove(heap);
		delete heap;
		rc = TRUE;
		WIN32API_ERROR(ERROR_SUCCESS);
	} else {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
HeapFree
(HANDLE hHeap, DWORD dwFlags, LPVOID lpMem)
{
	BOOL rc = FALSE;
	WIN32API_POINTER(lpMem);
	WIN32API_ENTER("BOOL", "HeapFree", "HANDLE", hHeap, "DWORD", dwFlags, "LPVOID", lpMem, NULL);
	Heap *heap = REINTERPRET_CAST(Heap *, hHeap);
	if ((NULL != heap) && (heap->magic == HEAP_MAGIC)) {
		if (heap->Free(dwFlags, lpMem)) {
			rc = TRUE;
			WIN32API_ERROR(ERROR_SUCCESS);
		}
	} else {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
HeapLock
(HANDLE hHeap)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "HeapLock", "HANDLE", hHeap, NULL);
	Heap *heap = REINTERPRET_CAST(Heap *, hHeap);
	if ((NULL != heap) && (heap->magic == HEAP_MAGIC)) {
		heap->Lock();
		rc = TRUE;
		WIN32API_ERROR(ERROR_SUCCESS);
	} else {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	}
	WIN32API_LEAVE(rc);
	return rc;
}


extern "C" LPVOID WINAPI
HeapReAlloc
(HANDLE hHeap, DWORD dwFlags, LPVOID lpMem, SIZE_T dwBytes)
{
	LPVOID rc = NULL;
	WIN32API_POINTER(lpMem);
	WIN32API_ENTER("LPVOID", "HeapReAlloc", "HANDLE", hHeap, "DWORD", dwFlags, "LPVOID", lpMem, "SIZE_T", dwBytes, NULL);
	Heap *heap = REINTERPRET_CAST(Heap *, hHeap);
	if ((NULL != heap) && (heap->magic == HEAP_MAGIC)) {
		rc = heap->ReAllocate(dwFlags, lpMem, dwBytes);
		if (NULL != rc) {
			WIN32API_ERROR(ERROR_SUCCESS);
		}
	} else {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	}
	WIN32API_LEAVE(rc);
	return rc;
}


extern "C" DWORD WINAPI
HeapSize
(HANDLE hHeap, DWORD dwFlags, PCVOID lpMem)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "HeapSize", "HANDLE", hHeap, "DWORD", dwFlags, "PCVOID", lpMem, NULL);
	Heap *heap = REINTERPRET_CAST(Heap *, hHeap);
	if ((NULL != heap) && (heap->magic == HEAP_MAGIC)) {
		rc = heap->GetSize(dwFlags, lpMem);
		if ((DWORD)-1 != rc) WIN32API_ERROR(ERROR_SUCCESS);
	} else {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
HeapUnlock
(HANDLE hHeap)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "HeapUnlock", "HANDLE", hHeap, NULL);
	Heap *heap = REINTERPRET_CAST(Heap *, hHeap);
	if ((NULL != heap) && (heap->magic == HEAP_MAGIC)) {
		heap->Unlock();
		rc = TRUE;
		WIN32API_ERROR(ERROR_SUCCESS);
	} else {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
HeapValidate
(HANDLE hHeap, DWORD dwFlags, LPCVOID lpMem)
{
	BOOL rc = TRUE;
	WIN32API_ENTER("BOOL", "HeapValidate", "HANDLE", hHeap, "DWORD", dwFlags, "LPCVOID", lpMem, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
HeapWalk
(HANDLE hHeap, LPPROCESS_HEAP_ENTRY lpEntry)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "HeapWalk", "HANDLE", hHeap, "LPPROCESS_HEAP_ENTRY", lpEntry, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}
