/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 ‚Æ‚æ‚µ‚Ü
 *  $Id: File16.cpp,v 1.1 2003/05/01 02:57:16 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [File16.h]
 * -------------------------------------------------------------------------------------------- */
#include "File16.h"
#include "File32.h"
#include "Path.h"
#include "Win32Trace.h"
#include "Win32Error.h"

extern "C" HFILE WINAPI
OpenFile
(LPCSTR lpFileName, LPOFSTRUCT lpReOpenBuff, UINT uStyle)
{
	HFILE rc = HFILE_ERROR;
	WIN32API_POINTER(lpFileName);
	WIN32API_POINTER(lpReOpenBuff);
	WIN32API_ENTER("HFILE", "OpenFile", "LPCSTR", lpFileName, "LPOFSTRUCT", lpReOpenBuff, "UINT", uStyle, NULL);
	WIN32API_INFO("lpFileName = %s\n", lpFileName);
	Path filename(lpFileName);
	filename.ToNativePath(true);
	WIN32API_INFO("native file name = %s\n", filename.GetPath());
	int mode = uStyle & 3;
	uStyle &= ~3;
	switch (mode) {
	case OF_READ:
		mode = O_RDONLY;
		break;
	case OF_WRITE:
		mode = O_WRONLY;
		break;
	case OF_READWRITE:
		mode = O_RDWR;
		break;
	default:
		mode = -1;
		break;
	}
	if (0 != (OF_CREATE & uStyle)) {
		mode = O_RDWR | O_CREAT | O_TRUNC;
		uStyle &= ~OF_CREATE;
	}
	if (0 != uStyle) WIN32API_INFO("\tignore uStyle: $%08x\n", uStyle);
	if (mode >= 0) {
		int fd = open(filename.GetPath(), mode);
		if (fd >= 0) {
			rc = fd + 1;
			// XXX:
			WIN32API_INFO("\tOFSTRUCT not be filled (not impl.)\n");
			lpReOpenBuff->cBytes = sizeof(OFSTRUCT);
			lpReOpenBuff->fFixedDisk = 1;
			lpReOpenBuff->nErrCode = 0;
			snprintf((char *)lpReOpenBuff->szPathName, OFS_MAXPATHNAME, "%s", lpFileName);
		}
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HFILE WINAPI
_lcreat
(LPCSTR lpFileName, int fnAttribute)
{
	HFILE rc = HFILE_ERROR;
	WIN32API_POINTER(lpFileName);
	WIN32API_ENTER("HFILE", "_lcreat", "LPCSTR", lpFileName, "int", fnAttribute, NULL);
	WIN32API_INFO("\tlpFileName: %s\n", lpFileName);
	WIN32API_INFO("\tignore fnAttribute: %d\n", fnAttribute);
	Path path(lpFileName);
	path.ToNativePath(true);
	int fd = creat(path.GetPath(), 0777);
	if (fd >= 0) rc = (fd + 1);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HFILE WINAPI
_lopen
(LPCSTR lpPathName, int iReadWrite)
{
	HFILE rc = HFILE_ERROR;
	WIN32API_POINTER(lpPathName);
	WIN32API_ENTER("HFILE", "_lopen", "LPCSTR", lpPathName, "int", iReadWrite, NULL);
	WIN32API_INFO("lpPathName: %s\n", lpPathName);
	int flags = 0;
	switch (iReadWrite & 0xf) {
	case OF_READ:
		flags = O_RDONLY;
		break;
	case OF_WRITE:
		flags = O_WRONLY;
		break;
	case OF_READWRITE:
		flags = O_RDWR;
		break;
	default:
		flags = -1;
	}
	iReadWrite &= ~0xf;
	if (0 != iReadWrite) WIN32API_INFO("\tignore iReadWrite: %08x\n", iReadWrite);
	Path path(lpPathName);
	path.ToNativePath(true);
	int fd = open(path.GetPath(), flags);
	if (fd >= 0) rc = (fd + 1);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
_lread
(HFILE hFile, LPVOID lpBuffer, UINT uBytes)
{
	UINT rc = 0;
	WIN32API_POINTER(lpBuffer);
	WIN32API_ENTER("UINT", "_lread", "HFILE", hFile, "LPVOID", lpBuffer, "UINT", uBytes, NULL);
	int fd = (int)hFile - 1;
	rc = read(fd, lpBuffer, uBytes);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
_lwrite
(HFILE hFile, LPVOID lpBuffer, UINT cbWrite)
{
	UINT rc = 0;
	WIN32API_POINTER(lpBuffer);
	WIN32API_ENTER("UINT", "_lwrite", "HFILE", hFile, "LPVOID", lpBuffer, "UINT", cbWrite, NULL);
	int fd = (int)hFile - 1;
	rc = write(fd, lpBuffer, cbWrite);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
_llseek
(HFILE hFile, LONG lOffset, int iOrigin)
{
	LONG rc = 0;
	WIN32API_ENTER("LONG", "_llseek", "HFILE", hFile, "LONG", lOffset, "int", iOrigin, NULL);
	int fd = (int)hFile - 1;
	rc = lseek(fd, lOffset, iOrigin);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HFILE WINAPI
_lclose
(HFILE hFile)
{
	HFILE rc = 0;
	WIN32API_ENTER("HFILE", "_lclose", "HFILE", hFile, NULL);
	int fd = (int)hFile - 1;
	if (0 == close(fd)) rc = 0;
	else rc = HFILE_ERROR;
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" long WINAPI
_hread
(HFILE hFile, LPVOID lpBuffer, long lBytes)
{
	long rc = 0;
	WIN32API_ENTER("long", "_hread", "HFILE", hFile, "LPVOID", lpBuffer, "long", lBytes, NULL);
	int fd = (int)hFile - 1;
	rc = read(fd, lpBuffer, lBytes);
	if (rc < 0) {
		WIN32API_INTERNAL_START();
		if (FALSE == ReadFile((HANDLE)hFile, lpBuffer, lBytes, (LPDWORD)&rc, NULL)) rc = -1;
		WIN32API_INTERNAL_END();
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" long WINAPI
_hwrite
(HFILE hFile, LPVOID lpBuffer, long lBytes)
{
	long rc = 0;
	WIN32API_ENTER("long", "_hwrite", "HFILE", hFile, "LPVOID", lpBuffer, "long", lBytes, NULL);
	int fd = (int)hFile - 1;
	rc = write(fd, lpBuffer, lBytes);
	WIN32API_LEAVE(rc);
	return rc;
}
