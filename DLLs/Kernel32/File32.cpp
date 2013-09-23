/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 ‚Æ‚æ‚µ‚Ü
 *  $Id: File32.cpp,v 1.1 2003/05/01 02:57:16 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [File32.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "File32.h"
#include "Path.h"
#include "Win32Trace.h"
#include "Win32Error.h"
#include "Win32String.h"

File::File
(int fd):
magic(FILE_MAGIC),
fd(fd)
{
}

File::~File
(void)
{
	if (fd >= 0) close(fd);
	magic = 0;
}

bool
File::Create
(LPCSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes,
	DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile)
{
	int flags = 0;
	int mode = 0777;
	if (0 != (dwDesiredAccess & GENERIC_READ)) {
		if (0 != (dwDesiredAccess & GENERIC_WRITE)) {
			flags |= O_RDWR;
			dwDesiredAccess &= ~(GENERIC_READ | GENERIC_WRITE);
		} else {
			flags |= O_RDONLY;
			dwDesiredAccess &= ~GENERIC_READ;
		}
	} else if (0 != (dwDesiredAccess & GENERIC_WRITE)) {
		flags |= O_WRONLY;
		dwDesiredAccess &= ~GENERIC_WRITE;
	}
	switch (dwCreationDisposition) {
	case CREATE_NEW:
		flags |= O_EXCL | O_CREAT;
		dwCreationDisposition = 0;
		break;
	case CREATE_ALWAYS:
		flags |= O_CREAT | O_TRUNC;
		dwCreationDisposition = 0;
		break;
	case OPEN_EXISTING:
		dwCreationDisposition = 0;
		break;
	case OPEN_ALWAYS:
		flags |= O_CREAT;
		dwCreationDisposition = 0;
		break;
	case TRUNCATE_EXISTING:
		flags |= O_TRUNC;
		dwCreationDisposition = 0;
		break;
	}
	if (0 != dwDesiredAccess) WIN32API_INFO("\tignore dwDesiredAccess: $%08x\n", dwDesiredAccess);
	if (0 != dwShareMode) WIN32API_INFO("\tignore dwShareMode: $%08x\n", dwShareMode);
	if (NULL != lpSecurityAttributes) WIN32API_INFO("\tignore lpSecurityAttributes\n");
	if (0 != dwCreationDisposition) WIN32API_INFO("\tignore dwCreationDisposition: $%08x\n", dwCreationDisposition);
	if (0 != dwFlagsAndAttributes) WIN32API_INFO("\tignore dwFlagsAndAttributes: $%08x\n", dwFlagsAndAttributes);
	if (INVALID_HANDLE_VALUE != hTemplateFile) WIN32API_INFO("\tignore hTemplateFile: $%08x\n", hTemplateFile);
	WIN32API_INFO("\tlpFileName: %s\n", lpFileName);
	Path filename(lpFileName);
	filename.ToNativePath(true);
	WIN32API_INFO("open: %s\n", filename.GetPath());
	fd = open(filename.GetPath(), flags, mode);
	// XXX: SetLastError
	return fd >= 0;
}

DWORD
File::SetFilePointer
(ULONG lDistanceToMove, PLONG lpDistanceToMoveHigh, DWORD dwMoveMethod)
{
	if (NULL != lpDistanceToMoveHigh) WIN32API_INFO("\tignode lpDistanceToMoveHigh: $%08x\n", lpDistanceToMoveHigh);
	int whence;
	switch (dwMoveMethod) {
	case FILE_BEGIN:
		whence = SEEK_SET;
		break;
	case FILE_CURRENT:
		whence = SEEK_CUR;
		break;
	case FILE_END:
		whence = SEEK_END;
		break;
	default:
		WIN32API_ERROR(ERROR_BAD_ARGUMENTS);
		return (DWORD)-1;
	}
	off_t offset = lseek(fd, lDistanceToMove, whence);
	WIN32API_INFO("\tseek result: %d\n", offset);
	if (offset >= 0) {
		WIN32API_ERROR(ERROR_SUCCESS);
	} else {
		WIN32API_ERROR(ERROR_SEEK);
	}
	return (DWORD)offset;
}

BOOL
File::Read
(LPVOID lpBuffer, DWORD nNumberOfBytesToRead, LPDWORD lpNumberOfBytesRead, LPOVERLAPPED lpOverlapped)
{
	if (NULL != lpOverlapped) {
		WIN32API_INFO("\tlpOverlapped: not impl.\n");
		return FALSE;
	}
	off_t start = lseek(fd, 0, SEEK_CUR);
	WIN32API_INFO("\tread start pos: %d\n", start);
	ssize_t readsize = read(fd, lpBuffer, nNumberOfBytesToRead);
	off_t end = lseek(fd, 0, SEEK_CUR);
	WIN32API_INFO("\tread end pos: %d\n", end);
	if (readsize == -1) {
		// XXX: SetLastError
		return FALSE;
	}
	if (0 == readsize) readsize = end - start;
	*lpNumberOfBytesRead = readsize;
	WIN32API_INFO("\tread %d bytes\n", readsize);
	WIN32API_ERROR(ERROR_SUCCESS);
	return TRUE;
}

BOOL
File::Write
(LPCVOID lpBuffer, DWORD nNumberOfBytesToWrite, LPDWORD lpNumberOfBytesWritten, LPOVERLAPPED lpOverlapped)
{
	if (NULL != lpOverlapped) {
		WIN32API_INFO("\tlpOverlapped: not impl.\n");
		return FALSE;
	}
	ssize_t writesize = write(fd, lpBuffer, nNumberOfBytesToWrite);
	if (writesize == -1) {
		// XXX: SetLastError
		return FALSE;
	}
	*lpNumberOfBytesWritten = writesize;
	WIN32API_ERROR(ERROR_SUCCESS);
	return TRUE;
}

DWORD
File::GetFileType
(void)
{
	if (fd < 0) return FILE_TYPE_UNKNOWN;
	WIN32API_ERROR(ERROR_SUCCESS);
	if (1 == isatty(fd)) return FILE_TYPE_CHAR;
	struct stat st;
	if (0 != fstat(fd, &st)) return FILE_TYPE_UNKNOWN;
	if (S_ISREG(st.st_mode)) return FILE_TYPE_DISK;
	if (S_ISCHR(st.st_mode)) return FILE_TYPE_CHAR;
	if (S_ISFIFO(st.st_mode)) return FILE_TYPE_PIPE;
	return FILE_TYPE_UNKNOWN;
}

DWORD
File::GetFileSize
(void)
{
	if (fd < 0) return (DWORD)-1;
	WIN32API_ERROR(ERROR_SUCCESS);
	struct stat st;
	DWORD rc = (DWORD)-1;
	if (0 == fstat(fd, &st)) rc = st.st_size;
	return rc;
}

File *
File::HandleToFile
(HANDLE hFile)
{
	if (NULL == hFile) return NULL;
	if (INVALID_HANDLE_VALUE == hFile) return NULL;
	File *file = (File *)((ULONG)hFile | 0x80000000L);
	if (file->magic != FILE_MAGIC) return NULL;
	return file;
}

HANDLE
File::FileToHandle
(File *file)
{
	return (HANDLE)((ULONG)file & 0x7fffffffL);
}

static HANDLE
CreateFileU
(LPCSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes,
	DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	File *file = new File();
	if (NULL != file) {
		if (file->Create(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes,
			dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile)) {
			rc = File::FileToHandle(file);
		} else {
			delete file;
		}
	} else {
		WIN32API_ERROR(ERROR_NOT_ENOUGH_MEMORY);
	}
	return rc;
}

extern "C" HANDLE WINAPI
CreateFileA
(LPCSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes,
	DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_POINTER(lpFileName);
	WIN32API_POINTER(lpSecurityAttributes);
	WIN32API_ENTER("HANDLE", "CreateFileA", "LPCSTR", lpFileName, "DWORD", dwDesiredAccess, "DWORD", dwShareMode, "LPSECURITY_ATTRIBUTES", lpSecurityAttributes, "DWORD", dwCreationDisposition, "DWORD", dwFlagsAndAttributes, "HANDLE", hTemplateFile, NULL);
	Win32String filename;
	filename.SetToA(lpFileName);
	rc = CreateFileU(filename.StringU(), dwDesiredAccess, dwShareMode, lpSecurityAttributes,
		dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
CreateFileW
(LPCWSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes,
	DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_POINTER(lpFileName);
	WIN32API_POINTER(lpSecurityAttributes);
	WIN32API_ENTER("HANDLE", "CreateFileW", "LPCWSTR", lpFileName, "DWORD", dwDesiredAccess, "DWORD", dwShareMode, "LPSECURITY_ATTRIBUTES", lpSecurityAttributes, "DWORD", dwCreationDisposition, "DWORD", dwFlagsAndAttributes, "HANDLE", hTemplateFile, NULL);
	Win32String filename;
	filename.SetToW(lpFileName);
	rc = CreateFileU(filename.StringU(), dwDesiredAccess, dwShareMode, lpSecurityAttributes,
		dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
SetFilePointer
(HANDLE hFile, LONG lDistanceToMove, PLONG lpDistanceToMoveHigh, DWORD dwMoveMethod)
{
	DWORD rc = (DWORD)-1;
	WIN32API_POINTER(lpDistanceToMoveHigh);
	WIN32API_ENTER("DWORD", "SetFilePointer", "HANDLE", hFile, "LONG", lDistanceToMove, "PLONG", lpDistanceToMoveHigh, "DWORD", dwMoveMethod, NULL);
	File *file = File::HandleToFile(hFile);
	if (NULL != file) {
		rc = file->SetFilePointer(lDistanceToMove, lpDistanceToMoveHigh, dwMoveMethod);
	} else {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ReadFile
(HANDLE hFile, LPVOID lpBuffer, DWORD nNumberOfBytesToRead,
	LPDWORD lpNumberOfBytesRead, LPOVERLAPPED lpOverlapped)
{
	BOOL rc = FALSE;
	WIN32API_POINTER(lpBuffer);
	WIN32API_POINTER(lpNumberOfBytesRead);
	WIN32API_POINTER(lpOverlapped);
	WIN32API_ENTER("BOOL", "ReadFile", "HANDLE", hFile, "LPVOID", lpBuffer, "DWORD", nNumberOfBytesToRead, "LPDWORD", lpNumberOfBytesRead, "LPOVERLAPPED", lpOverlapped, NULL);
	File *file = File::HandleToFile(hFile);
	if (NULL != file) {
		rc = file->Read(lpBuffer, nNumberOfBytesToRead, lpNumberOfBytesRead, lpOverlapped);
	} else {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ReadFileEx
(HANDLE hFile, LPVOID lpBuffer, DWORD nNumberOfBytesToRead,
	LPOVERLAPPED lpOverlapped, LPOVERLAPPED_COMPLETION_ROUTINE lpOverlappedCompletionRoutine)
{
	BOOL rc = FALSE;
	WIN32API_POINTER(lpBuffer);
	WIN32API_POINTER(lpOverlapped);
	WIN32API_POINTER(lpOverlappedCompletionRoutine);
	WIN32API_ENTER("BOOL", "ReadFileEx", "HANDLE", hFile, "LPVOID", lpBuffer, "DWORD", nNumberOfBytesToRead,
		"LPOVERLAPPED", lpOverlapped, "LPOVERLAPPED_COMPLETION_ROUTINE", lpOverlappedCompletionRoutine, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
WriteFile
(HANDLE hFile, LPCVOID lpBuffer, DWORD nNumberOfBytesToWrite,
	LPDWORD lpNumberOfBytesWritten, LPOVERLAPPED lpOverlapped)
{
	BOOL rc = FALSE;
	WIN32API_POINTER(lpBuffer);
	WIN32API_POINTER(lpNumberOfBytesWritten);
	WIN32API_POINTER(lpOverlapped);
	WIN32API_ENTER("BOOL", "WriteFile", "HANDLE", hFile, "LPCVOID", lpBuffer, "DWORD", nNumberOfBytesToWrite, "LPDWORD", lpNumberOfBytesWritten, "LPOVERLAPPED", lpOverlapped, NULL);
	File *file = File::HandleToFile(hFile);
	if (NULL != file) {
		rc = file->Write(lpBuffer, nNumberOfBytesToWrite, lpNumberOfBytesWritten, lpOverlapped);
	} else {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
WriteFileEx
(HANDLE hFile, PCVOID lpBuffer, DWORD nNumberOfBytesToWrite,
	LPOVERLAPPED lpOverlapped, LPOVERLAPPED_COMPLETION_ROUTINE lpOverlappedCompletionRoutine)
{
	BOOL rc = FALSE;
	WIN32API_POINTER(lpBuffer);
	WIN32API_POINTER(lpOverlapped);
	WIN32API_POINTER(lpOverlappedCompletionRoutine);
	WIN32API_ENTER("BOOL", "WriteFileEx", "HANDLE", hFile, "LPCVOID", lpBuffer, "DWORD", nNumberOfBytesToWrite,
		"LPOVERLAPPED", lpOverlapped, "LPOVERLAPPED_COMPLETION_ROUTINE", lpOverlappedCompletionRoutine, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
FlushFileBuffers
(HANDLE hFile)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "FlushFileBuffers", "HANDLE", hFile, NULL);
	File *file = File::HandleToFile(hFile);
	if (NULL != file) {
		rc = TRUE;
		WIN32API_ERROR(ERROR_SUCCESS);
	} else {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetFileType
(HANDLE hFile)
{
	DWORD rc = FILE_TYPE_UNKNOWN;
	WIN32API_ENTER("DWORD", "GetFileType", "HANDLE", hFile, NULL);
	File *file = File::HandleToFile(hFile);
	if (NULL != file) {
		rc = file->GetFileType();
	} else {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetFileSize
(HANDLE hFile, LPDWORD lpFileSizeHigh)
{
	DWORD rc = (DWORD)-1;
	WIN32API_POINTER(lpFileSizeHigh);
	WIN32API_ENTER("DWORD", "GetFileSize", "HANDLE", hFile, "LPDWORD", lpFileSizeHigh, NULL);
	File *file = File::HandleToFile(hFile);
	if (NULL != file) {
		rc = file->GetFileSize();
	} else {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetEndOfFile
(HANDLE hFile)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetEndOfFile", "HANDLE", hFile, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
LockFile
(HANDLE arg0, DWORD arg1, DWORD arg2, DWORD arg3, DWORD arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "LockFile", "HANDLE", arg0, "DWORD", arg1, "DWORD", arg2, "DWORD", arg3, "DWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
LockFileEx
(HANDLE arg0, DWORD arg1, DWORD arg2, DWORD arg3, DWORD arg4, LPOVERLAPPED arg5)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "LockFileEx", "HANDLE", arg0, "DWORD", arg1, "DWORD", arg2, "DWORD", arg3, "DWORD", arg4, "LPOVERLAPPED", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
UnlockFile
(HANDLE arg0, DWORD arg1, DWORD arg2, DWORD arg3, DWORD arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "UnlockFile", "HANDLE", arg0, "DWORD", arg1, "DWORD", arg2, "DWORD", arg3, "DWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
UnlockFileEx
(HANDLE arg0, DWORD arg1, DWORD arg2, DWORD arg3, LPOVERLAPPED arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "UnlockFileEx", "HANDLE", arg0, "DWORD", arg1, "DWORD", arg2, "DWORD", arg3, "LPOVERLAPPED", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetFileInformationByHandle
(HANDLE arg0, LPBY_HANDLE_FILE_INFORMATION arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetFileInformationByHandle", "HANDLE", arg0, "LPBY_HANDLE_FILE_INFORMATION", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetFileTime
(HANDLE arg0, LPFILETIME arg1, LPFILETIME arg2, LPFILETIME arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetFileTime", "HANDLE", arg0, "LPFILETIME", arg1, "LPFILETIME", arg2, "LPFILETIME", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetFileTime
(HANDLE arg0, const FILETIME* arg1, const FILETIME* arg2, const FILETIME* arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetFileTime", "HANDLE", arg0, "const FILETIME*", arg1, "const FILETIME*", arg2, "const FILETIME*", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}
