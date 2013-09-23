/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000, 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: Kernel32.h,v 1.1 2003/05/01 02:57:16 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Kernel32.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__Kernel32_h__)
#	define	__Kernel32_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if !defined(__Win32Structures_h__)
#		include "Win32Structures.h"
#	endif	// !defined(__Win32Structures_h__)

#	if !defined(__Handle_h__)
#		include "Handle.h"
#	endif	// !defined(__Handle_h__)

#	if !defined(__Heap_h__)
#		include "Heap.h"
#	endif	// !defined(__Heap_h__)

#	if !defined(__Profile_h__)
#		include "Profile.h"
#	endif	// !defined(__Profile_h__)

#	if !defined(__Path_h__)
#		include "Path.h"
#	endif	// !defined(__Path_h__)

#	if !defined(__Mutex_h__)
#		include "Mutex.h"
#	endif	// !defined(__Mutex_h__)

#	if !defined(__LastError_h__)
#		include "LastError.h"
#	endif	// !defined(__LastError_h__)

#	if !defined(__FindFile_h__)
#		include "FindFile.h"
#	endif	// !defined(__FindFile_h__)

#	if !defined(__CriticalSection_h__)
#		include "CriticalSection.h"
#	endif	// !defined(__CriticalSection_h__)

#	if !defined(__KernelVersion_h__)
#		include "KernelVersion.h"
#	endif	// !defined(__KernelVersion_h__)

#	if !defined(__Interlock_h__)
#		include "Interlock.h"
#	endif	// !defined(__Interlock_h__)

#	if !defined(__Module_h__)
#		include "Module.h"
#	endif	// !defined(__Module_h__)

#	if !defined(__Thread_h__)
#		include "Thread.h"
#	endif	// !defined(__Thread_h__)

#	if !defined(__Process_h__)
#		include "Process.h"
#	endif	// !defined(__Process_h__)

#	if !defined(__Tls_h__)
#		include "Tls.h"
#	endif	// !defined(__Tls_h__)

#	if !defined(__CodePage_h__)
#		include "CodePage.h"
#	endif	// !defined(__CodePage_h__)

#	if !defined(__Locale_h__)
#		include "Locale.h"
#	endif	// !defined(__Locale_h__)

#	if !defined(__Virtual_h__)
#		include "Virtual.h"
#	endif	// !defined(__Virtual_h__)

#	if !defined(__Local_h__)
#		include "Local.h"
#	endif	// !defined(__Local_h__)

#	if !defined(__Global_h__)
#		include "Global.h"
#	endif	// !defined(__Global_h__)

#	if !defined(__Atom_h__)
#		include "Atom.h"
#	endif	// !defined(__Atom_h__)

#	if !defined(__File16_h__)
#		include "File16.h"
#	endif	// !defined(__File16_h__)

#	if !defined(__File32_h__)
#		include "File32.h"
#	endif	// !defined(__File32_h__)

#	if !defined(__FileOperation_h__)
#		include "FileOperation.h"
#	endif	// !defined(__FileOperation_h__)

#	if !defined(__String_h__)
#		include "String.h"
#	endif	// !defined(__String_h__)

#	if !defined(__Semaphore_h__)
#		include "Semaphore.h"
#	endif	// !defined(__Semaphore_h__)

#	if !defined(__Volume_h__)
#		include "Volume.h"
#	endif	// !defined(__Volume_h__)

#	if !defined(__Environment_h__)
#		include "Environment.h"
#	endif	// !defined(__Environment_h__)

#	if !defined(__Resource_h__)
#		include "Resource.h"
#	endif	// !defined(__Resource_h__)

#	if !defined(__Time_h__)
#		include "Time.h"
#	endif	// !defined(__Time_h__)

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

DWORD WINAPI LoadModule(LPCSTR,PVOID);
LPTSTR WINAPI GetCommandLineA(VOID);
VOID WINAPI RtlUnwind(UNKNOWN);
BOOL WINAPI QueryPerformanceFrequency(LPLARGE_INTEGER lpFrequency);
BOOL WINAPI QueryPerformanceCounter(LPLARGE_INTEGER lpPerformanceCount);
VOID WINAPI FatalAppExitA(UINT uAction, LPCTSTR lpMessageText);
LONG WINAPI UnhandledExceptionFilter(LPEXCEPTION_POINTERS exceptionInfo);
UINT WINAPI WinExec(LPCSTR lpCmdLine, UINT uCmdShow);
#undef OutputDebugStringA
VOID WINAPI OutputDebugStringA(LPCTSTR lpOutputString);
VOID WINAPI DebugBreak(VOID);
BOOL WINAPI IsBadReadPtr(LPCVOID lp, UINT ucb);
BOOL WINAPI IsBadWritePtr(LPCVOID lp, UINT ucb);
BOOL WINAPI AllocConsole(void);
BOOL WINAPI AreFileApisANSI(void);
BOOL WINAPI BackupRead(HANDLE,PBYTE,DWORD,PDWORD,BOOL,BOOL,PVOID);
BOOL WINAPI BackupSeek(HANDLE,DWORD,DWORD,PDWORD,PDWORD,PVOID);
BOOL WINAPI BackupWrite(HANDLE,PBYTE,DWORD,PDWORD,BOOL,BOOL,PVOID);
BOOL WINAPI Beep(DWORD,DWORD);
BOOL WINAPI BuildCommDCBA(LPCSTR,LPDCB);
BOOL WINAPI BuildCommDCBAndTimeoutsA(LPCSTR,LPDCB,LPCOMMTIMEOUTS);
BOOL WINAPI BuildCommDCBAndTimeoutsW(LPCWSTR,LPDCB,LPCOMMTIMEOUTS);
BOOL WINAPI BuildCommDCBW(LPCWSTR,LPDCB);
BOOL WINAPI CallNamedPipeA(LPCSTR,PVOID,DWORD,PVOID,DWORD,PDWORD,DWORD);
BOOL WINAPI CallNamedPipeW(LPCWSTR,PVOID,DWORD,PVOID,DWORD,PDWORD,DWORD);
BOOL WINAPI CancelIo(HANDLE);
BOOL WINAPI CancelWaitableTimer(HANDLE);
BOOL WINAPI ClearCommBreak(HANDLE);
BOOL WINAPI ClearCommError(HANDLE,PDWORD,LPCOMSTAT);
VOID WINAPI CmdBatNotification(LPVOID arg0);
BOOL WINAPI CommConfigDialogA(LPCSTR,HWND,LPCOMMCONFIG);
BOOL WINAPI CommConfigDialogW(LPCWSTR,HWND,LPCOMMCONFIG);
BOOL WINAPI ConnectNamedPipe(HANDLE,LPOVERLAPPED);
BOOL WINAPI ContinueDebugEvent(DWORD,DWORD,DWORD);
PVOID WINAPI ConvertThreadToFiber(PVOID);
HANDLE WINAPI CreateConsoleScreenBuffer(DWORD,DWORD,LPSECURITY_ATTRIBUTES,DWORD,PVOID);
HANDLE WINAPI CreateEventA(LPSECURITY_ATTRIBUTES,BOOL,BOOL,LPCSTR);
HANDLE WINAPI CreateEventW(LPSECURITY_ATTRIBUTES,BOOL,BOOL,LPCWSTR);
LPVOID WINAPI CreateFiber(DWORD,LPFIBER_START_ROUTINE,LPVOID);
HANDLE WINAPI CreateFileMappingA(HANDLE,LPSECURITY_ATTRIBUTES,DWORD,DWORD,DWORD,LPCSTR);
HANDLE WINAPI CreateFileMappingW(HANDLE,LPSECURITY_ATTRIBUTES,DWORD,DWORD,DWORD,LPCWSTR);
HANDLE WINAPI CreateHardLinkA(LPCSTR,LPCSTR,LPSECURITY_ATTRIBUTES);
HANDLE WINAPI CreateHardLinkW(LPCWSTR,LPCWSTR,LPSECURITY_ATTRIBUTES);
HANDLE WINAPI CreateIoCompletionPort(HANDLE,HANDLE,DWORD,DWORD);
HANDLE WINAPI CreateMailslotA(LPCSTR,DWORD,DWORD,LPSECURITY_ATTRIBUTES);
HANDLE WINAPI CreateMailslotW(LPCWSTR,DWORD,DWORD,LPSECURITY_ATTRIBUTES);
HANDLE WINAPI CreateNamedPipeA(LPCSTR,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,LPSECURITY_ATTRIBUTES);
HANDLE WINAPI CreateNamedPipeW(LPCWSTR,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,LPSECURITY_ATTRIBUTES);
BOOL WINAPI CreatePipe(PHANDLE,PHANDLE,LPSECURITY_ATTRIBUTES,DWORD);
DWORD WINAPI CreateTapePartition(HANDLE,DWORD,DWORD,DWORD);
HANDLE WINAPI CreateToolhelp32Snapshot(DWORD,DWORD);
HANDLE WINAPI CreateWaitableTimerA(LPSECURITY_ATTRIBUTES,BOOL,LPCSTR);
HANDLE WINAPI CreateWaitableTimerW(LPSECURITY_ATTRIBUTES,BOOL,LPCWSTR);
BOOL WINAPI DefineDosDeviceA(DWORD,LPCSTR,LPCSTR);
BOOL WINAPI DefineDosDeviceW(DWORD,LPCWSTR,LPCWSTR);
void WINAPI DeleteFiber(PVOID);
BOOL WINAPI DeviceIoControl(HANDLE,DWORD,PVOID,DWORD,PVOID,DWORD,PDWORD,POVERLAPPED);
BOOL WINAPI DisableThreadLibraryCalls(HMODULE);
BOOL WINAPI DisconnectNamedPipe(HANDLE);
DWORD WINAPI EraseTape(HANDLE,DWORD,BOOL);
BOOL WINAPI EscapeCommFunction(HANDLE,DWORD);
void WINAPI FatalAppExitW(UINT,LPCWSTR);
void WINAPI FatalExit(int);
BOOL WINAPI FillConsoleOutputAttribute(HANDLE,WORD,DWORD,COORD,PDWORD);
BOOL WINAPI FillConsoleOutputCharacterA(HANDLE,CHAR,DWORD,COORD,PDWORD);
BOOL WINAPI FillConsoleOutputCharacterW(HANDLE,WCHAR,DWORD,COORD,PDWORD);
BOOL WINAPI FindCloseChangeNotification(HANDLE);
HANDLE WINAPI FindFirstChangeNotificationA(LPCSTR,BOOL,DWORD);
HANDLE WINAPI FindFirstChangeNotificationW(LPCWSTR,BOOL,DWORD);
BOOL WINAPI FindNextChangeNotification(HANDLE);
BOOL WINAPI FlushConsoleInputBuffer(HANDLE);
BOOL WINAPI FlushInstructionCache(HANDLE,PCVOID,DWORD);
BOOL WINAPI FlushViewOfFile(PCVOID,DWORD);
int WINAPI FoldStringA(DWORD,LPCSTR,int,LPSTR,int);
int WINAPI FoldStringW(DWORD,LPCWSTR,int,LPWSTR,int);
DWORD WINAPI FormatMessageA(DWORD,PCVOID,DWORD,DWORD,LPSTR,DWORD,va_list*);
DWORD WINAPI FormatMessageW(DWORD,PCVOID,DWORD,DWORD,LPWSTR,DWORD,va_list*);
BOOL WINAPI FreeConsole(void);
BOOL WINAPI GenerateConsoleCtrlEvent(DWORD,DWORD);
BOOL WINAPI GetBinaryTypeA(LPCSTR,PDWORD);
BOOL WINAPI GetBinaryTypeW(LPCWSTR,PDWORD);
BOOL WINAPI GetCommConfig(HANDLE,LPCOMMCONFIG,PDWORD);
BOOL WINAPI GetCommMask(HANDLE,PDWORD);
BOOL WINAPI GetCommModemStatus(HANDLE,PDWORD);
BOOL WINAPI GetCommProperties(HANDLE,LPCOMMPROP);
BOOL WINAPI GetCommState(HANDLE,LPDCB);
BOOL WINAPI GetCommTimeouts(HANDLE,LPCOMMTIMEOUTS);
LPWSTR WINAPI GetCommandLineW(VOID);
DWORD WINAPI GetCompressedFileSizeA(LPCSTR,PDWORD);
DWORD WINAPI GetCompressedFileSizeW(LPCWSTR,PDWORD);
BOOL WINAPI GetComputerNameA(LPSTR,PDWORD);
BOOL WINAPI GetComputerNameW(LPWSTR,PDWORD);
UINT WINAPI GetConsoleCP(void);
BOOL WINAPI GetConsoleCursorInfo(HANDLE,PCONSOLE_CURSOR_INFO);
BOOL WINAPI GetConsoleMode(HANDLE,PDWORD);
UINT WINAPI GetConsoleOutputCP(void);
BOOL WINAPI GetConsoleScreenBufferInfo(HANDLE,PCONSOLE_SCREEN_BUFFER_INFO);
DWORD WINAPI GetConsoleTitleA(LPSTR,DWORD);
DWORD WINAPI GetConsoleTitleW(LPWSTR,DWORD);
BOOL WINAPI GetDefaultCommConfigA(LPCSTR,LPCOMMCONFIG,PDWORD);
BOOL WINAPI GetDefaultCommConfigW(LPCWSTR,LPCOMMCONFIG,PDWORD);
COORD WINAPI GetLargestConsoleWindowSize(HANDLE);
BOOL WINAPI GetMailslotInfo(HANDLE,PDWORD,PDWORD,PDWORD,PDWORD);
BOOL WINAPI GetNamedPipeHandleStateA(HANDLE,PDWORD,PDWORD,PDWORD,PDWORD,LPSTR,DWORD);
BOOL WINAPI GetNamedPipeHandleStateW(HANDLE,PDWORD,PDWORD,PDWORD,PDWORD,LPWSTR,DWORD);
BOOL WINAPI GetNamedPipeInfo(HANDLE,PDWORD,PDWORD,PDWORD,PDWORD);
BOOL WINAPI GetNumberOfConsoleInputEvents(HANDLE,PDWORD);
BOOL WINAPI GetNumberOfConsoleMouseButtons(PDWORD);
BOOL WINAPI GetOverlappedResult(HANDLE,LPOVERLAPPED,PDWORD,BOOL);
DWORD WINAPI GetPriorityClass(HANDLE);
BOOL WINAPI GetQueuedCompletionStatus(HANDLE,PDWORD,PDWORD,LPOVERLAPPED*,DWORD);
VOID WINAPI GetSystemInfo(LPSYSTEM_INFO);
BOOL WINAPI GetSystemPowerStatus(LPSYSTEM_POWER_STATUS);
DWORD WINAPI GetTapeParameters(HANDLE,DWORD,PDWORD,PVOID);
DWORD WINAPI GetTapePosition(HANDLE,DWORD,PDWORD,PDWORD,PDWORD);
DWORD WINAPI GetTapeStatus(HANDLE);
UINT WINAPI GetTempFileNameA(LPCSTR,LPCSTR,UINT,LPSTR);
UINT WINAPI GetTempFileNameW(LPCWSTR,LPCWSTR,UINT,LPWSTR);
VOID WINAPI GetVDMCurrentDirectories(LPVOID arg0, LPVOID arg1);
BOOL WINAPI IsBadCodePtr(FARPROC);
BOOL WINAPI IsBadHugeReadPtr(PCVOID,UINT);
BOOL WINAPI IsBadHugeWritePtr(PVOID,UINT);
BOOL WINAPI IsBadStringPtrA(LPCSTR,UINT);
BOOL WINAPI IsBadStringPtrW(LPCWSTR,UINT);
BOOL WINAPI IsDebuggerPresent(void);
BOOL WINAPI IsProcessorFeaturePresent(DWORD);
PVOID WINAPI MapViewOfFile(HANDLE,DWORD,DWORD,DWORD,DWORD);
PVOID WINAPI MapViewOfFileEx(HANDLE,DWORD,DWORD,DWORD,DWORD,PVOID);
int WINAPI MulDiv(int,int,int);
HANDLE WINAPI OpenEventA(DWORD,BOOL,LPCSTR);
HANDLE WINAPI OpenEventW(DWORD,BOOL,LPCWSTR);
HANDLE WINAPI OpenFileMappingA(DWORD,BOOL,LPCSTR);
HANDLE WINAPI OpenFileMappingW(DWORD,BOOL,LPCWSTR);
HANDLE WINAPI OpenWaitableTimerA(DWORD,BOOL,LPCSTR);
HANDLE WINAPI OpenWaitableTimerW(DWORD,BOOL,LPCWSTR);
void WINAPI OutputDebugStringW(LPCWSTR);
BOOL WINAPI PeekConsoleInputA(HANDLE,PINPUT_RECORD,DWORD,PDWORD);
BOOL WINAPI PeekConsoleInputW(HANDLE,PINPUT_RECORD,DWORD,PDWORD);
BOOL WINAPI PeekNamedPipe(HANDLE,PVOID,DWORD,PDWORD,PDWORD,PDWORD);
BOOL WINAPI PostQueuedCompletionStatus(HANDLE,DWORD,DWORD,LPOVERLAPPED);
DWORD WINAPI PrepareTape(HANDLE,DWORD,BOOL);
BOOL WINAPI PulseEvent(HANDLE);
BOOL WINAPI PurgeComm(HANDLE,DWORD);
DWORD WINAPI QueryDosDeviceA(LPCSTR,LPSTR,DWORD);
DWORD WINAPI QueryDosDeviceW(LPCWSTR,LPWSTR,DWORD);
DWORD WINAPI QueueUserAPC(PAPCFUNC,HANDLE,DWORD);
void WINAPI RaiseException(DWORD,DWORD,DWORD,const DWORD*);
BOOL WINAPI ReadConsoleA(HANDLE,PVOID,DWORD,PDWORD,PVOID);
BOOL WINAPI ReadConsoleInputA(HANDLE,PINPUT_RECORD,DWORD,PDWORD);
BOOL WINAPI ReadConsoleInputW(HANDLE,PINPUT_RECORD,DWORD,PDWORD);
BOOL WINAPI ReadConsoleOutputA(HANDLE,PCHAR_INFO,COORD,COORD,PSMALL_RECT);
BOOL WINAPI ReadConsoleOutputAttribute(HANDLE,LPWORD,DWORD,COORD,LPDWORD);
BOOL WINAPI ReadConsoleOutputCharacterA(HANDLE,LPSTR,DWORD,COORD,PDWORD);
BOOL WINAPI ReadConsoleOutputCharacterW(HANDLE,LPWSTR,DWORD,COORD,PDWORD);
BOOL WINAPI ReadConsoleOutputW(HANDLE,PCHAR_INFO,COORD,COORD,PSMALL_RECT);
BOOL WINAPI ReadConsoleW(HANDLE,PVOID,DWORD,PDWORD,PVOID);
BOOL WINAPI ReadDirectoryChangesW(HANDLE,PVOID,DWORD,BOOL,DWORD,PDWORD,LPOVERLAPPED,LPOVERLAPPED_COMPLETION_ROUTINE);
BOOL WINAPI ResetEvent(HANDLE);
BOOL WINAPI ScrollConsoleScreenBufferA(HANDLE,const SMALL_RECT*,const SMALL_RECT*,COORD,const CHAR_INFO*);
BOOL WINAPI ScrollConsoleScreenBufferW(HANDLE,const SMALL_RECT*,const SMALL_RECT*,COORD,const CHAR_INFO*);
BOOL WINAPI SetCommBreak(HANDLE);
BOOL WINAPI SetCommConfig(HANDLE,LPCOMMCONFIG,DWORD);
BOOL WINAPI SetCommMask(HANDLE,DWORD);
BOOL WINAPI SetCommState(HANDLE,LPDCB);
BOOL WINAPI SetCommTimeouts(HANDLE,LPCOMMTIMEOUTS);
BOOL WINAPI SetComputerNameA(LPCSTR);
BOOL WINAPI SetComputerNameW(LPCWSTR);
BOOL WINAPI SetConsoleActiveScreenBuffer(HANDLE);
BOOL WINAPI SetConsoleCP(UINT);
BOOL WINAPI SetConsoleCtrlHandler(PHANDLER_ROUTINE,BOOL);
BOOL WINAPI SetConsoleCursorInfo(HANDLE,const CONSOLE_CURSOR_INFO*);
BOOL WINAPI SetConsoleCursorPosition(HANDLE,COORD);
BOOL WINAPI SetConsoleMode(HANDLE,DWORD);
BOOL WINAPI SetConsoleOutputCP(UINT);
BOOL WINAPI SetConsoleScreenBufferSize(HANDLE,COORD);
BOOL WINAPI SetConsoleTextAttribute(HANDLE,WORD);
BOOL WINAPI SetConsoleTitleA(LPCSTR);
BOOL WINAPI SetConsoleTitleW(LPCWSTR);
BOOL WINAPI SetConsoleWindowInfo(HANDLE,BOOL,const SMALL_RECT*);
BOOL WINAPI SetDefaultCommConfigA(LPCSTR,LPCOMMCONFIG,DWORD);
BOOL WINAPI SetDefaultCommConfigW(LPCWSTR,LPCOMMCONFIG,DWORD);
UINT WINAPI SetErrorMode(UINT);
BOOL WINAPI SetEvent(HANDLE);
VOID WINAPI SetFileApisToANSI(void);
VOID WINAPI SetFileApisToOEM(void);
BOOL WINAPI SetMailslotInfo(HANDLE,DWORD);
BOOL WINAPI SetNamedPipeHandleState(HANDLE,PDWORD,PDWORD,PDWORD);
BOOL WINAPI SetPriorityClass(HANDLE,DWORD);
BOOL WINAPI SetSystemPowerState(BOOL,BOOL);
DWORD WINAPI SetTapeParameters(HANDLE,DWORD,PVOID);
DWORD WINAPI SetTapePosition(HANDLE,DWORD,DWORD,DWORD,DWORD,BOOL);
LPTOP_LEVEL_EXCEPTION_FILTER WINAPI SetUnhandledExceptionFilter(LPTOP_LEVEL_EXCEPTION_FILTER);
BOOL WINAPI SetWaitableTimer(HANDLE,const LARGE_INTEGER*,LONG,PTIMERAPCROUTINE,PVOID,BOOL);
BOOL WINAPI SetupComm(HANDLE,DWORD,DWORD);
BOOL WINAPI SignalObjectAndWait(HANDLE,HANDLE,DWORD,BOOL);
void WINAPI Sleep(DWORD dwMilliseconds);
DWORD WINAPI SleepEx(DWORD,BOOL);
void WINAPI SwitchToFiber(PVOID);
BOOL WINAPI TransactNamedPipe(HANDLE,PVOID,DWORD,PVOID,DWORD,PDWORD,LPOVERLAPPED);
BOOL WINAPI TransmitCommChar(HANDLE,char);
BOOL WINAPI UnmapViewOfFile(PVOID);
DWORD WINAPI VerLanguageNameA(DWORD,LPSTR,DWORD);
DWORD WINAPI VerLanguageNameW(DWORD,LPWSTR,DWORD);
BOOL WINAPI WaitCommEvent(HANDLE,PDWORD,LPOVERLAPPED);
BOOL WINAPI WaitForDebugEvent(LPDEBUG_EVENT,DWORD);
BOOL WINAPI WaitNamedPipeA(LPCSTR,DWORD);
BOOL WINAPI WaitNamedPipeW(LPCWSTR,DWORD);
BOOL WINAPI WriteConsoleA(HANDLE,PCVOID,DWORD,PDWORD,PVOID);
BOOL WINAPI WriteConsoleInputA(HANDLE,const INPUT_RECORD*,DWORD,PDWORD);
BOOL WINAPI WriteConsoleInputW(HANDLE,const INPUT_RECORD*,DWORD,PDWORD);
BOOL WINAPI WriteConsoleOutputA(HANDLE,const CHAR_INFO*,COORD,COORD,PSMALL_RECT);
BOOL WINAPI WriteConsoleOutputAttribute(HANDLE,const WORD*,DWORD,COORD,PDWORD);
BOOL WINAPI WriteConsoleOutputCharacterA(HANDLE,LPCSTR,DWORD,COORD,PDWORD);
BOOL WINAPI WriteConsoleOutputCharacterW(HANDLE,LPCWSTR,DWORD,COORD,PDWORD);
BOOL WINAPI WriteConsoleOutputW(HANDLE,const CHAR_INFO*,COORD,COORD,PSMALL_RECT);
BOOL WINAPI WriteConsoleW(HANDLE,PCVOID,DWORD,PDWORD,PVOID);
DWORD WINAPI WriteTapemark(HANDLE,DWORD,DWORD,BOOL);

#	if defined(_BUILTIN_DLL)
void *Kernel32_GetAddressByOrder(int order);
void *Kernel32_GetAddressByName(const char *name);
#	endif	// defined(_BUILTIN_DLL)

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__Kernel32_h__)
