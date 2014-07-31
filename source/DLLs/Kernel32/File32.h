/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 ‚Æ‚æ‚µ‚Ü
 *  $Id: File32.h,v 1.1 2003/05/01 02:57:16 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [File32.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__File32_h__)
#	define	__File32_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if !defined(__Handle_h__)
#		include "Handle.h"
#	endif	// !defined(__Handle_h__)

#	if !defined(__Win32Structures_h__)
#		include "Win32Structures.h"
#	endif	// !defined(__Win32Structures_h__)

#	define	GENERIC_READ						(0x80000000L)
#	define	GENERIC_WRITE						(0x40000000L)

#	if defined(FILE_SHARE_READ)
#		undef	FILE_SHARE_READ)
#	endif	// defined(_FILE_SHARE_READ)
#	define	FILE_SHARE_READ						0x00000001
#	if defined(FILE_SHARE_WRITE)
#		undef	FILE_SHARE_WRITE)
#	endif	// defined(FILE_SHARE_WRITE)
#	define	FILE_SHARE_WRITE					0x00000002
#	if defined(_FILE_SHARE_DELETE)
#		undef	FILE_SHARE_DELETE
#	endif	// defined(FILE_SHARE_DELETE)
#	define	FILE_SHARE_DELETE					0x00000004

#	define	CREATE_NEW							1
#	define	CREATE_ALWAYS						2
#	define	OPEN_EXISTING						3
#	define	OPEN_ALWAYS							4
#	define	TRUNCATE_EXISTING					5

#	define	FILE_TYPE_UNKNOWN					(0)
#	define	FILE_TYPE_DISK						(1)
#	define	FILE_TYPE_CHAR						(2)
#	define	FILE_TYPE_PIPE						(3)

#	define	FILE_BEGIN							(0)
#	define	FILE_CURRENT						(1)
#	define	FILE_END							(2)

#	define	FILE_MAGIC							'_FIL'

class File: public HandleObject {
public:
	DWORD magic;
private:
	int fd;
public:
	File(int fd = -1);
	~File(void);

	bool Create(LPCSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode,
		LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition,
		DWORD dwFlagsAndAttributes, HANDLE hTemplateFile);
	DWORD SetFilePointer(ULONG lDistanceToMove, PLONG lpDistanceToMoveHigh, DWORD dwMoveMethod);
	BOOL Read(LPVOID lpBuffer, DWORD nNumberOfBytesToRead,
		LPDWORD lpNumberOfBytesRead, LPOVERLAPPED lpOverlapped);
	BOOL Write(LPCVOID lpBuffer, DWORD nNumberOfBytesToWrite,
		LPDWORD lpNumberOfBytesWritten, LPOVERLAPPED lpOverlapped);

	DWORD GetFileType(void);
	DWORD GetFileSize(void);

	static File *HandleToFile(HANDLE hFile);
	static HANDLE FileToHandle(File *);
};

#		if !defined(__File__)
#			define	__File__
#		endif	// !defined(__File__)

static HANDLE CreateFileU(LPCSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode,
	LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition,
	DWORD dwFlagsAndAttributes, HANDLE hTemplateFile);

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

HANDLE WINAPI CreateFileA(LPCSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode,
	LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition,
	DWORD dwFlagsAndAttributes, HANDLE hTemplateFile);
HANDLE WINAPI CreateFileW(LPCWSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode,
	LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition,
	DWORD dwFlagsAndAttributes, HANDLE hTemplateFile);
DWORD WINAPI SetFilePointer(HANDLE hFile, LONG lDistanceToMove,
	PLONG lpDistanceToMoveHigh, DWORD dwMoveMethod);
BOOL WINAPI ReadFile(HANDLE hFile, LPVOID lpBuffer, DWORD nNumberOfBytesToRead,
	LPDWORD lpNumberOfBytesRead, LPOVERLAPPED lpOverlapped);
BOOL WINAPI ReadFileEx(HANDLE hFile, LPVOID lpBuffer, DWORD nNumberOfBytesToRead,
	LPOVERLAPPED lpOverlapped, LPOVERLAPPED_COMPLETION_ROUTINE lpOverlappedCompletionRoutine);
BOOL WINAPI WriteFile(HANDLE hFile, LPCVOID lpBuffer, DWORD nNumberOfBytesToWrite,
	LPDWORD lpNumberOfBytesWritten, LPOVERLAPPED lpOverlapped);
BOOL WINAPI WriteFileEx(HANDLE hFile, LPCVOID lpBuffer, DWORD nNumberOfBytesToWrite,
	LPOVERLAPPED lpOverlapped, LPOVERLAPPED_COMPLETION_ROUTINE lpOverlappedCompletionRoutine);
BOOL WINAPI FlushFileBuffers(HANDLE hFile);
DWORD WINAPI GetFileType(HANDLE hFile);
DWORD WINAPI GetFileSize(HANDLE hFile, LPDWORD lpFileSizeHigh);
BOOL WINAPI SetEndOfFile(HANDLE hFile);

BOOL WINAPI LockFile(HANDLE,DWORD,DWORD,DWORD,DWORD);
BOOL WINAPI LockFileEx(HANDLE,DWORD,DWORD,DWORD,DWORD,LPOVERLAPPED);
BOOL WINAPI UnlockFile(HANDLE,DWORD,DWORD,DWORD,DWORD);
BOOL WINAPI UnlockFileEx(HANDLE,DWORD,DWORD,DWORD,LPOVERLAPPED);
BOOL WINAPI GetFileInformationByHandle(HANDLE,LPBY_HANDLE_FILE_INFORMATION);
BOOL WINAPI GetFileTime(HANDLE,LPFILETIME,LPFILETIME,LPFILETIME);
BOOL WINAPI SetFileTime(HANDLE,const FILETIME*,const FILETIME*,const FILETIME*);

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__File32_h__)
