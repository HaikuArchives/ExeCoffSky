/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: Process.h,v 1.1 2003/05/01 02:57:17 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Process.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__Process_h__)
#	define	__Process_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if !defined(__Win32Structures_h__)
#		include "Win32Structures.h"
#	endif	// !defined(__Win32Structures_h__)

#	if !defined(__Handle_h__)
#		include "Handle.h"
#	endif	// !defined(__Handle_h__)

#	if !defined(__Thread_h__)
#		include "Thread.h"
#	endif	// !defined(__Thread_h__)

#	if !defined(__Heap__)
class Heap;
#		define	__Heap__
#	endif	// !defined(__Heap__)

#	if !defined(__Coff__)
class Coff;
#		define	__Coff__
#	endif	// !defined(__Coff__)

#	define	STARTF_USESTDHANDLES	(0x00000100)

#	define	PROCESS_MAGIC	'_PRC'

class Process: HandleObject {
	struct fmbn {
		HMODULE hModule;
		LPCSTR lpModuleName;
	};
public:
	DWORD magic;
private:
	static Process *current_process;
	Thread main_thread;
	char *startdir;
	STARTUPINFOA infoa;
	STARTUPINFOW infow;
	HINSTANCE hInstance;
	DWORD ec;
	BList heaps;
	BLocker lock;
	DWORD shutdown_level;
	DWORD shutdown_flags;
	bigtime_t creation_time;
	bigtime_t exit_time;
	bigtime_t user_time;
	bigtime_t kernel_time;
	BList modules;
public:
	Process(void);
	~Process(void);

	void SetStartupInfoA(LPSTARTUPINFOA info);
	void GetStartupInfoA(LPSTARTUPINFOA info);
	void SetStartupInfoW(LPSTARTUPINFOW info);
	void GetStartupInfoW(LPSTARTUPINFOW info);
	BOOL SetStdHandle(DWORD n, HANDLE h);
	HANDLE GetStdHandle(DWORD n);
	void SetInstance(HINSTANCE hInstance);
	HINSTANCE GetInstance(void);
	void SetExitCode(DWORD code);
	DWORD GetExitCode(void);
	BOOL SetShutdownParameters(DWORD level, DWORD flags);
	BOOL GetShutdownParameters(LPDWORD level, LPDWORD flags);
	bool SetStartupDirectory(const char *dir);
	char *GetStartupDirectory(void);

	bool HeapAppend(Heap *heap);
	bool HeapRemove(Heap *heap);
	Heap *GetHeap(void);
	int GetHeaps(int count, Heap **heaps);

	HMODULE FindModuleByName(LPCSTR lpModuleName);
	bool AddModule(HMODULE hModule);
	bool DelModule(HMODULE hModule);

	void GetTimes(LPFILETIME lpCreationTime, LPFILETIME lpExitTime, LPFILETIME lpKernelTime, LPFILETIME lpUserTime);
	DWORD GetVersion(void);
	DWORD GetID(void);
	port_id GetPort(void);
	Thread *GetMainThread(void);

	static DWORD GetCurrentProcessId(void);
	static Process *GetCurrentProcessObject(void);
	static Process *GetProcessObject(DWORD id);
private:
	inline void Lock(void) { lock.Lock(); };
	inline void Unlock(void) { lock.Unlock(); };
	static bool FindModule(void *item, void *arg);
};

#	if !defined(__Process__)
#		define	__Process__
#	endif	// !defined(__Process__)

static BOOL CreateProcessU(LPCSTR lpApplicationName, LPCSTR lpCommandLine,
	LPSECURITY_ATTRIBUTES lpProcessAttributes, LPSECURITY_ATTRIBUTES lpThreadAttributes,
	BOOL bInheritHandles, DWORD dwCreationFlags, LPVOID lpEnvironment, LPCSTR lpCurrentDirectory,
	LPSTARTUPINFOA lpStartupInfo, LPPROCESS_INFORMATION lpProcessInformation);

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

VOID WINAPI ExitProcess(UINT uExitCode);
BOOL WINAPI CreateProcessA(LPCSTR lpApplicationName, LPSTR lpCommandLine,
	LPSECURITY_ATTRIBUTES lpProcessAttributes, LPSECURITY_ATTRIBUTES lpThreadAttributes,
	BOOL bInheritHandles, DWORD dwCreationFlags, LPVOID lpEnvironment, LPCSTR lpCurrentDirectory,
	LPSTARTUPINFOA lpStartupInfo, LPPROCESS_INFORMATION lpProcessInformation);
BOOL WINAPI CreateProcessW(LPCWSTR lpApplicationName, LPWSTR lpCommandLine,
	LPSECURITY_ATTRIBUTES lpProcessAttributes, LPSECURITY_ATTRIBUTES lpThreadAttributes,
	BOOL bInheritHandles, DWORD dwCreationFlags, LPVOID lpEnvironment, LPCWSTR lpCurrentDirectory,
	LPSTARTUPINFOW lpStartupInfo, LPPROCESS_INFORMATION lpProcessInformation);
BOOL WINAPI DebugActiveProcess(DWORD dwProcessId);
HANDLE WINAPI GetCurrentProcess(VOID);
DWORD WINAPI GetCurrentProcessId(VOID);
BOOL WINAPI GetExitCodeProcess(HANDLE hProcess, LPDWORD lpExitCode);
BOOL WINAPI GetProcessAffinityMask(HANDLE hProcess, LPDWORD lpProcessAffinityMask, LPDWORD lpSystemAffinityMask);
HANDLE WINAPI GetProcessHeap(VOID);
DWORD WINAPI GetProcessHeaps(DWORD NumberOfHeaps, PHANDLE ProcessHeaps);
BOOL WINAPI GetProcessPriorityBoost(HANDLE hProcess, PBOOL pDisablePriorityBoost);
BOOL WINAPI GetProcessShutdownParameters(LPDWORD lpdwLevel, LPDWORD lpdwFlags);
BOOL WINAPI GetProcessTimes(HANDLE hProcess, LPFILETIME lpCreationTime, LPFILETIME lpExitTime, LPFILETIME lpKernelTime, LPFILETIME lpUserTime);
DWORD WINAPI GetProcessVersion(DWORD ProcessId);
BOOL WINAPI GetProcessWorkingSetSize(HANDLE hProcess, LPDWORD lpMinimumWorkingSetSize, LPDWORD lpMaximumWorkingSetSize);
VOID WINAPI GetStartupInfoA(LPSTARTUPINFOA lpStartupInfo);
VOID WINAPI GetStartupInfoW(LPSTARTUPINFOW lpStartupInfo);
HANDLE WINAPI OpenProcess(DWORD dwDesiredAccess, BOOL bInheritHandle, DWORD dwProcessId);
BOOL WINAPI ReadProcessMemory(HANDLE hProcess, LPCVOID lpBaseAddress, PVOID lpBuffer, DWORD nSize, LPDWORD lpNumberOfBytesRead);
BOOL WINAPI SetProcessAffinityMask(HANDLE hProcess, DWORD dwProcessAffinityMask);
BOOL WINAPI SetProcessPriorityBoost(HANDLE hProcess, BOOL DisablePriorityBoost);
BOOL WINAPI SetProcessShutdownParameters(DWORD dwLevel, DWORD dwFlags);
BOOL WINAPI SetProcessWorkingSetSize(HANDLE hProcess, DWORD dwMinimumWorkingSetSize, DWORD dwMaximumWorkingSetSize);
BOOL WINAPI TerminateProcess(HANDLE hProcess, UINT uExitCode);
BOOL WINAPI WriteProcessMemory(HANDLE hProcess, LPVOID lpBaseAddress, LPVOID lpBuffer, DWORD nSize, LPDWORD lpNumberOfBytesWritten);

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__Process_h__)
