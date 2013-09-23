/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 Ç∆ÇÊÇµÇ‹
 *  $Id: Local.cpp,v 1.1 2003/05/01 02:57:16 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Local.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "Local.h"
#include "Win32Trace.h"
#include "Win32Error.h"

Local::Local
(void):
lock_count(0),
size(0),
buffer(NULL),
zeroinit(false),
fixed(false)
{
	h.magic = LOCAL_MAGIC;
	h.owner = this;
}

Local::~Local
(void)
{
	h.magic = 0;
	h.owner = NULL;
	if (NULL != buffer) {
		buffer->magic = 0;
		buffer->owner = NULL;
		free(buffer);
	}
	WIN32API_ERROR(ERROR_SUCCESS);
}

HLOCAL
Local::Allocate
(UINT uFlags, UINT nBytes)
{
	nBytes += 0xfff;
	nBytes &= ~0xff;
	if (0 != (uFlags & LMEM_ZEROINIT)) {
		uFlags &= ~LMEM_ZEROINIT;
		zeroinit = true;
	}
	buffer = (block *)malloc(sizeof(block) + nBytes);
	if (NULL == buffer) {
		WIN32API_ERROR(ERROR_NOT_ENOUGH_MEMORY);
		return NULL;
	}
	buffer->magic = LOCALBLOCK_MAGIC;
	buffer->owner = this;
	size = nBytes;
	HLOCAL rc = NULL;
	if (0 == (uFlags & LMEM_MOVEABLE)) {
		fixed = true;
		rc = (HLOCAL)Lock();
	} else {
		rc = (HLOCAL)this;
		uFlags &= ~LMEM_MOVEABLE;
	}
	if (0 != uFlags) WIN32API_INFO("\tunknown flags: $%08x\n", uFlags);
	WIN32API_ERROR(ERROR_SUCCESS);
	return rc;
}

HLOCAL
Local::ReAllocate
(UINT uFlags, UINT nBytes)
{
	nBytes += 0xfff;
	nBytes &= ~0xff;
	if (NULL == buffer) return Allocate(uFlags, nBytes);
	HLOCAL rc = NULL;
/*
	if (0 != lock_count) {
		WIN32API_INFO("\tcan not reallocate: locked\n");
		WIN32API_ERROR(ERROR_LOCKED);
		return rc;
	}
*/
	if (0 != (uFlags & LMEM_MODIFY)) {
		// ëÆê´ïœçX
modify:
		WIN32API_INFO("\tchange flags to $%08x\n", uFlags);
		uFlags &= ~LMEM_MODIFY;
		if (0 == (uFlags & LMEM_MOVEABLE)) {
			fixed = true;
			rc = (HLOCAL)&buffer[1];
		} else {
			rc = (HLOCAL)&(&h)[1];
			uFlags &= ~LMEM_MOVEABLE;
		}
		if (0 != uFlags) WIN32API_INFO("\tunknown flags: $%08x\n", uFlags);
		WIN32API_ERROR(ERROR_SUCCESS);
		return rc;
	}
	if (nBytes < size) {
		// èkè¨
		WIN32API_INFO("\tshrinking buffer ...\n");
		goto modify;
	}
	// ägëÂ
	WIN32API_INFO("\texpanding buffer ...\n");
	block *oldbuffer = buffer;
	SIZE_T oldsize = size;
	bool oldzeroinit = zeroinit;
	bool oldfixed = fixed;
	rc = Allocate(uFlags, nBytes);
	if (NULL == rc) {
		buffer = oldbuffer;
		size = oldsize;
		zeroinit = oldzeroinit;
		fixed = oldfixed;
		return rc;
	}
	memcpy((char *)&buffer[1], (char *)&oldbuffer[1], oldsize);
	oldbuffer->magic = 0;
	oldbuffer->owner = NULL;
	free(oldbuffer);
	return rc;
}

LPVOID
Local::Lock
(void)
{
	lock_count++;
	WIN32API_ERROR(ERROR_SUCCESS);
	return (LPVOID)&buffer[1];
}

BOOL
Local::Unlock
(void)
{
	if (0 == lock_count) {
		WIN32API_ERROR(ERROR_LOCK_FAILED);
		return FALSE;
	}
	WIN32API_ERROR(ERROR_SUCCESS);
	lock_count--;
	return TRUE;
}

SIZE_T
Local::GetSize
(void)
{
	return size;
}

Local *
Local::HandleToLocal
(HLOCAL hLocal)
{
	if (NULL == hLocal) return NULL;
	block *b = (block *)hLocal;
	b--;
	if (b->magic == LOCALBLOCK_MAGIC) {
		WIN32API_INFO("\tthis address may mean a pointer\n");
		b = (block *)b->owner;
	} else {
		WIN32API_INFO("\tthis address may mean a handle\n");
		b++;
	}
	Local *l = (Local *)b;
	if (l->h.magic != LOCAL_MAGIC) return NULL;
	return l;
}

HLOCAL
Local::MemoryToHandle
(LPCVOID pMem)
{
	if (NULL == pMem) return NULL;
	block *b = (block *)pMem;
	b--;
	if (b->magic != LOCALBLOCK_MAGIC) return NULL;
	Local *l = b->owner;
	if (NULL == l) return NULL;
	if (l->h.magic != LOCAL_MAGIC) return NULL;
	return (HLOCAL)l;
}

extern "C" HLOCAL WINAPI
LocalAlloc
(UINT uFlags, UINT nBytes)
{
	HLOCAL rc = NULL;
	WIN32API_ENTER("HLOCAL", "LocalAlloc", "UINT", uFlags, "UINT", nBytes, NULL);
	Local *local = new Local();
	if (NULL != local) {
		rc = local->Allocate(uFlags, nBytes);
	} else {
		WIN32API_ERROR(ERROR_NOT_ENOUGH_MEMORY);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LPVOID WINAPI
LocalLock
(HLOCAL hMem)
{
	LPVOID rc = NULL;
	WIN32API_ENTER("LPVOID", "LocalLock", "HLOCAL", hMem, NULL);
	Local *local = Local::HandleToLocal(hMem);
	if (NULL != local) {
		rc = local->Lock();
	} else {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
LocalUnlock
(HLOCAL hMem)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "LocalUnlock", "HLOCAL", hMem, NULL);
	Local *local = Local::HandleToLocal(hMem);
	if (NULL != local) {
		rc = local->Unlock();
	} else {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HLOCAL WINAPI
LocalFree
(HLOCAL hMem)
{
	HLOCAL rc = hMem;
	WIN32API_ENTER("HLOCAL", "LocalFree", "HLOCAL", hMem, NULL);
	Local *local = Local::HandleToLocal(hMem);
	if (NULL != local) {
		delete local;
		rc = NULL;
	} else {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HLOCAL WINAPI
LocalReAlloc
(HLOCAL hMem, UINT nBytes, UINT nFlags)
{
	HLOCAL rc = NULL;
	WIN32API_ENTER("HLOCAL", "LocalReAlloc", "HLOCAL", hMem, "UINT", nBytes, "UINT", nFlags, NULL);
	Local *local = Local::HandleToLocal(hMem);
	if (NULL != local) {
		rc = local->ReAllocate(nFlags, nBytes);
	} else {
		WIN32API_INFO("\tinvalid handle\n");
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
LocalCompact
(UINT MinFree)
{
	UINT rc = 0;
	WIN32API_ENTER("UINT", "LocalCompact", "UINT", MinFree, NULL);
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
LocalFlags
(HLOCAL hMem)
{
	UINT rc = LMEM_INVALID_HANDLE;
	WIN32API_ENTER("UINT", "LocalFlags", "HLOCAL", hMem, NULL);
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HLOCAL WINAPI
LocalHandle
(LPCVOID pMem)
{
	HLOCAL rc = NULL;
	WIN32API_ENTER("HLOCAL", "LocalHandle", "LPCVOID", pMem, NULL);
	rc = Local::MemoryToHandle(pMem);
	if (NULL == rc) {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	} else {
		WIN32API_ERROR(ERROR_SUCCESS);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
LocalShrink
(HLOCAL hMem, UINT arg)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("UINT", "LocalShrink", "HLOCAL", hMem, "UINT", arg, NULL);
	Local *local = Local::HandleToLocal(hMem);
	if (NULL == local) {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	} else {
		WIN32API_ERROR(ERROR_SUCCESS);
		rc = TRUE;
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
LocalSize
(HLOCAL hMem)
{
	UINT rc = 0;
	WIN32API_ENTER("UINT", "LocalSize", "HLOCAL", hMem, NULL);
	Local *local = Local::HandleToLocal(hMem);
	if (NULL == local) {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	} else {
		rc = local->GetSize();
	}
	WIN32API_LEAVE(rc);
	return rc;
}
