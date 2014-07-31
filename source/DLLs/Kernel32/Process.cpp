/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: Process.cpp,v 1.1 2003/05/01 02:57:17 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Process.cpp]
 * TODO: Exit‚ÌÛ‚ÌDetachedProcessˆ—
 * -------------------------------------------------------------------------------------------- */
#include "Process.h"
#include "Coff.h"
#include "Win32Trace.h"
#include "Win32String.h"
#include "Win32Error.h"
#include "Module.h"

Process *
Process::current_process = NULL;

Process::Process
(void):
magic(PROCESS_MAGIC),
startdir(NULL),
hInstance(INVALID_HANDLE_VALUE),
ec(STILL_ACTIVE),
shutdown_level(0x280),
shutdown_flags(0),
creation_time(system_time()),
exit_time(0),
user_time(0),
kernel_time(0)
{
	Lock();
	main_thread.Shift();
	memset(&infoa, 0, sizeof(STARTUPINFOA));
	memset(&infow, 0, sizeof(STARTUPINFOW));
	current_process = this;
	Unlock();
}

Process::~Process
(void)
{
	Lock();
	current_process = NULL;
	magic = 0;
	if (NULL != startdir) free(startdir);
	if (NULL != infoa.lpReserved) free(infoa.lpReserved);
	if (NULL != infoa.lpDesktop) free(infoa.lpDesktop);
	if (NULL != infoa.lpTitle) free(infoa.lpTitle);
	if (NULL != infow.lpReserved) free(infow.lpReserved);
	if (NULL != infow.lpDesktop) free(infow.lpDesktop);
	if (NULL != infow.lpTitle) free(infow.lpTitle);
	Unlock();
}

void
Process::SetStartupInfoA
(LPSTARTUPINFOA info)
{
	Lock();
	memcpy(&infoa, info, info->cb);
	memcpy(&infow, info, info->cb);
	if (NULL != info->lpReserved) {
		Win32String reserved;
		reserved.SetToA(info->lpReserved);
		infoa.lpReserved = strdup(reserved.StringA());
		infow.lpReserved = Win32String::strdupW(reserved.StringW());
	}
	if (NULL != info->lpDesktop) {
		Win32String desktop;
		desktop.SetToA(info->lpDesktop);
		infoa.lpDesktop = strdup(desktop.StringA());
		infow.lpDesktop = Win32String::strdupW(desktop.StringW());
	}
	if (NULL != info->lpTitle) {
		Win32String title;
		title.SetToA(info->lpTitle);
		infoa.lpTitle = strdup(title.StringA());
		infow.lpTitle = Win32String::strdupW(title.StringW());
	}
	Unlock();
}

void
Process::GetStartupInfoA
(LPSTARTUPINFOA info)
{
	Lock();
	WIN32API_INFO("\tcbSize: %d\n", info->cb);
	if (info->cb != sizeof(STARTUPINFOA)) {
		WIN32API_INFO("\tinvalid size specified: should be %d\n", sizeof(STARTUPINFOA));
		memcpy(info, &infoa, sizeof(STARTUPINFOA));
	} else {
		memcpy(info, &infoa, info->cb);
	}
	Unlock();
}

void
Process::SetStartupInfoW
(LPSTARTUPINFOW info)
{
	Lock();
	memcpy(&infoa, info, info->cb);
	memcpy(&infow, info, info->cb);
	if (NULL != info->lpReserved) {
		Win32String reserved;
		reserved.SetToW(info->lpReserved);
		infoa.lpReserved = strdup(reserved.StringA());
		infow.lpReserved = Win32String::strdupW(reserved.StringW());
	}
	if (NULL != info->lpDesktop) {
		Win32String desktop;
		desktop.SetToW(info->lpDesktop);
		infoa.lpDesktop = strdup(desktop.StringA());
		infow.lpDesktop = Win32String::strdupW(desktop.StringW());
	}
	if (NULL != info->lpTitle) {
		Win32String title;
		title.SetToW(info->lpTitle);
		infoa.lpTitle = strdup(title.StringA());
		infow.lpTitle = Win32String::strdupW(title.StringW());
	}
	Unlock();
}

void
Process::GetStartupInfoW
(LPSTARTUPINFOW info)
{
	Lock();
	memcpy(info, &infow, info->cb);
	Unlock();
}

BOOL
Process::SetStdHandle
(DWORD n, HANDLE h)
{
	Lock();
	BOOL rc = TRUE;
	switch (n) {
	case STD_INPUT_HANDLE:
		infoa.hStdInput = h;
		break;
	case STD_OUTPUT_HANDLE:
		infoa.hStdOutput = h;
		break;
	case STD_ERROR_HANDLE:
		infoa.hStdError = h;
		break;
	default:
		rc = FALSE;
	}
	Unlock();
	return rc;
}

HANDLE
Process::GetStdHandle
(DWORD n)
{
	Lock();
	HANDLE rc = INVALID_HANDLE_VALUE;
	switch (n) {
	case STD_INPUT_HANDLE:
		rc = infoa.hStdInput;
		break;
	case STD_OUTPUT_HANDLE:
		rc = infoa.hStdOutput;
		break;
	case STD_ERROR_HANDLE:
		rc = infoa.hStdError;
		break;
	}
	Unlock();
	return rc;
}

void
Process::SetInstance
(HINSTANCE hInstance)
{
	Lock();
	WIN32API_INFO("ProcessInstance = %p\n", hInstance);
	this->hInstance = hInstance;
	Unlock();
}

HINSTANCE
Process::GetInstance
(void)
{
	Lock();
	HINSTANCE rc = hInstance;
	Unlock();
	return rc;
}

void
Process::SetExitCode
(DWORD code)
{
	Lock();
	ec = code;
	// XXX: set user/kernel time
	exit_time = system_time();
	Unlock();
}

DWORD
Process::GetExitCode
(void)
{
	Lock();
	DWORD rc = ec;
	Unlock();
	return rc;
}

BOOL
Process::SetShutdownParameters
(DWORD level, DWORD flags)
{
	Lock();
	shutdown_level = level;
	shutdown_flags = flags;
	Unlock();
	return TRUE;
}

BOOL
Process::GetShutdownParameters
(LPDWORD level, LPDWORD flags)
{
	Lock();
	if (NULL != level) *level = shutdown_level;
	if (NULL != flags) *flags = shutdown_flags;
	Unlock();
	return TRUE;
}

bool
Process::SetStartupDirectory
(const char *dir)
{
	Lock();
	if (NULL != startdir) free(startdir);
	startdir = strdup(dir);
	Unlock();
	return NULL != startdir;
}

char *
Process::GetStartupDirectory(void)
{
	return startdir;
}

bool
Process::HeapAppend(Heap *heap)
{
	Lock();
	bool rc = heaps.AddItem((void *)heap);
	Unlock();
	return rc;
}

bool
Process::HeapRemove(Heap *heap)
{
	Lock();
	bool rc = heaps.RemoveItem((void *)heap);
	Unlock();
	return rc;
}

Heap *
Process::GetHeap
(void)
{
	Lock();
	Heap *rc = (Heap *)heaps.ItemAt(0);
	Unlock();
	return rc;
}

int
Process::GetHeaps
(int count, Heap **_heaps)
{
	Lock();
	int rc = count;
	int32 n = heaps.CountItems();
	if (rc > n) rc = n;
	for (int32 i = 0; i < n; i++) _heaps[i] = (Heap *)heaps.ItemAt(i);
	Unlock();
	return rc;
}

HMODULE
Process::FindModuleByName
(LPCSTR lpModuleName)
{
	struct fmbn rc;
	rc.hModule = NULL;
	rc.lpModuleName = lpModuleName;
	HMODULE hModule = NULL;
	modules.DoForEach(FindModule, (void *)&rc);
	hModule = rc.hModule;
	return hModule;
}

bool
Process::AddModule
(HMODULE hModule)
{
	Lock();
	bool rc = modules.AddItem((void *)hModule);
	Unlock();
	return rc;
}

bool
Process::DelModule
(HMODULE hModule)
{
	Lock();
	bool rc = modules.RemoveItem((void *)hModule);
	Unlock();
	return rc;
}

void
Process::GetTimes
(LPFILETIME lpCreationTime, LPFILETIME lpExitTime, LPFILETIME lpKernelTime, LPFILETIME lpUserTime)
{
	Lock();
	Thread::ToFileTime(lpCreationTime, creation_time);
	Thread::ToFileTime(lpExitTime, exit_time);
	if (ec == STILL_ACTIVE) {
		// XXX
		Thread::ToFileTime(lpKernelTime, 0);
		Thread::ToFileTime(lpUserTime, 0);
	} else {
		Thread::ToFileTime(lpKernelTime, kernel_time);
		Thread::ToFileTime(lpUserTime, user_time);
	}
	Unlock();
}

DWORD
Process::GetVersion
(void)
{
	Lock();
	Coff *coff = Coff::InstanceToCoff(GetInstance());
	Unlock();
	return coff->GetVersion();
}

DWORD
Process::GetID
(void)
{
	thread_info info;
	if (B_OK == get_thread_info(find_thread(NULL), &info)) return (DWORD)info.team;
	return 0;
}

port_id
Process::GetPort
(void)
{
	Lock();
	port_id id = main_thread.GetPort();
	Unlock();
	return id;
}

Thread *
Process::GetMainThread
(void)
{
	return &main_thread;
}

DWORD
Process::GetCurrentProcessId
(void)
{
	return GetCurrentProcessObject()->GetID();
}

Process *
Process::GetCurrentProcessObject
(void)
{
	return current_process;
}

Process *
Process::GetProcessObject
(DWORD id)
{
	if (current_process->GetID() == id) return current_process;
	return NULL;
}

bool
Process::FindModule
(void *item, void *arg)
{
	HMODULE hModule = (HMODULE)item;
	struct fmbn *param = (struct fmbn *)arg;
	Image *img = HandleToImage(hModule);
	if (0 == strcasecmp(img->GetFileName(), param->lpModuleName)) {
		param->hModule = item;
		return true;
	}
	return false;
}

BOOL
CreateProcessU
(LPCSTR lpApplicationName, LPCSTR lpCommandLine,
	LPSECURITY_ATTRIBUTES lpProcessAttributes, LPSECURITY_ATTRIBUTES lpThreadAttributes,
	BOOL bInheritHandles, DWORD dwCreationFlags, LPVOID lpEnvironment, LPCSTR lpCurrentDirectory,
	LPSTARTUPINFOA lpStartupInfo, LPPROCESS_INFORMATION lpProcessInformation)
{
	BOOL rc = FALSE;
	WIN32API_INFO("\tlpApplicationName: %s\n", lpApplicationName);
	WIN32API_INFO("\tlpCommandLine: %s\n", lpCommandLine);
	WIN32API_INFO("\tlpCurrentDirectory: %s\n", lpCurrentDirectory);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	return rc;
}

extern "C" VOID WINAPI
ExitProcess
(UINT uExitCode)
{
	WIN32API_ENTER("VOID", "ExitProcess", "UINT", uExitCode, NULL);
	WIN32API_LEAVE(0);
	exit(uExitCode);
}

extern "C" BOOL WINAPI
CreateProcessA
(LPCSTR lpApplicationName, LPSTR lpCommandLine,
	LPSECURITY_ATTRIBUTES lpProcessAttributes, LPSECURITY_ATTRIBUTES lpThreadAttributes,
	BOOL bInheritHandles, DWORD dwCreationFlags, LPVOID lpEnvironment, LPCSTR lpCurrentDirectory,
	LPSTARTUPINFOA lpStartupInfo, LPPROCESS_INFORMATION lpProcessInformation)
{
	BOOL rc = FALSE;
	WIN32API_POINTER(lpApplicationName);
	WIN32API_POINTER(lpProcessAttributes);
	WIN32API_POINTER(lpThreadAttributes);
	WIN32API_POINTER(lpEnvironment);
	WIN32API_POINTER(lpCurrentDirectory);
	WIN32API_POINTER(lpStartupInfo);
	WIN32API_POINTER(lpProcessInformation);
	WIN32API_ENTER("BOOL", "CreateProcessA", "LPCSTR", lpApplicationName, "LPSTR", lpCommandLine,
		"LPSECURITY_ATTRIBUTES", lpProcessAttributes, "LPSECURITY_ATTRIBUTES", lpThreadAttributes,
		"BOOL", bInheritHandles, "DWORD", dwCreationFlags, "PVOID", lpEnvironment, "LPCSTR", lpCurrentDirectory,
		"LPSTARTUPINFOA", lpStartupInfo, "LPPROCESS_INFORMATION", lpProcessInformation, NULL);
	Win32String application;
	application.SetToA(lpApplicationName);
	Win32String command;
	command.SetToA(lpCommandLine);
	Win32String cwd;
	cwd.SetToA(lpCurrentDirectory);
	rc = CreateProcessU(application.StringU(), command.StringU(), lpProcessAttributes, lpThreadAttributes,
		bInheritHandles, dwCreationFlags, lpEnvironment, cwd.StringU(), lpStartupInfo, lpProcessInformation);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CreateProcessW
(LPCWSTR lpApplicationName, LPWSTR lpCommandLine,
	LPSECURITY_ATTRIBUTES lpProcessAttributes, LPSECURITY_ATTRIBUTES lpThreadAttributes,
	BOOL bInheritHandles, DWORD dwCreationFlags, LPVOID lpEnvironment, LPCWSTR lpCurrentDirectory,
	LPSTARTUPINFOW lpStartupInfo, LPPROCESS_INFORMATION lpProcessInformation)
{
	BOOL rc = FALSE;
	WIN32API_POINTER(lpApplicationName);
	WIN32API_POINTER(lpProcessAttributes);
	WIN32API_POINTER(lpThreadAttributes);
	WIN32API_POINTER(lpEnvironment);
	WIN32API_POINTER(lpCurrentDirectory);
	WIN32API_POINTER(lpStartupInfo);
	WIN32API_POINTER(lpProcessInformation);
	WIN32API_ENTER("BOOL", "CreateProcessW", "LPCWSTR", lpApplicationName, "LPWSTR", lpCommandLine,
		"LPSECURITY_ATTRIBUTES", lpProcessAttributes, "LPSECURITY_ATTRIBUTES", lpThreadAttributes,
		"BOOL", bInheritHandles, "DWORD", dwCreationFlags, "PVOID", lpEnvironment, "LPCWSTR", lpCurrentDirectory,
		"LPSTARTUPINFOW", lpStartupInfo, "LPPROCESS_INFORMATION", lpProcessInformation, NULL);
	Win32String application;
	application.SetToW(lpApplicationName);
	Win32String command;
	command.SetToW(lpCommandLine);
	Win32String cwd;
	cwd.SetToW(lpCurrentDirectory);
	// XXX: lpStartupInfo
	rc = CreateProcessU(application.StringU(), command.StringU(), lpProcessAttributes, lpThreadAttributes,
		bInheritHandles, dwCreationFlags, lpEnvironment, cwd.StringU(), (LPSTARTUPINFOA)lpStartupInfo, lpProcessInformation);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DebugActiveProcess
(DWORD dwProcessId)
{
	BOOL rc = TRUE;
	WIN32API_ENTER("BOOL", "DebugActiveProcess", "DWORD", dwProcessId, NULL);
	send_signal((pid_t)dwProcessId, SIGUSR1);	// disable dynamic relocation
	send_signal((pid_t)dwProcessId, SIGSEGV);	// raise debugger
	WIN32API_ERROR(ERROR_SUCCESS);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
GetCurrentProcess
(VOID)
{
	WIN32API_ENTER("HANDLE", "GetCurrentProcess", NULL);
	HANDLE rc = (HANDLE)Process::GetCurrentProcessObject();
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetCurrentProcessId
(VOID)
{
	WIN32API_ENTER("DWORD", "GetCurrentProcessId", NULL);
	DWORD rc = Process::GetCurrentProcessId();
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetExitCodeProcess
(HANDLE hProcess, PDWORD lpExitCode)
{
	BOOL rc = FALSE;
	WIN32API_POINTER(lpExitCode);
	WIN32API_ENTER("BOOL", "GetExitCodeProcess", "HANDLE", hProcess, "PDWORD", lpExitCode, NULL);
	Process *process = REINTERPRET_CAST(Process *, hProcess);
	if ((NULL != process) && (process->magic == PROCESS_MAGIC)) {
		*lpExitCode = process->GetExitCode();
		WIN32API_ERROR(ERROR_SUCCESS);
	} else {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetProcessAffinityMask
(HANDLE hProcess, LPDWORD lpProcessAffinityMask, LPDWORD lpSystemAffinityMask)
{
	BOOL rc = FALSE;
	WIN32API_POINTER(lpSystemAffinityMask);
	WIN32API_ENTER("BOOL", "GetProcessAffinityMask", "HANDLE", hProcess, "LPDWORD", lpProcessAffinityMask, "LPDWORD", lpSystemAffinityMask, NULL);
	WIN32API_INFO("\tnot impl\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
GetProcessHeap
(VOID)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "GetProcessHeap", "VOID", 0, NULL);
	Process *process = Process::GetCurrentProcessObject();
	if (NULL != process) {
		rc = (HANDLE)process->GetHeap();
		WIN32API_ERROR(ERROR_SUCCESS);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetProcessHeaps
(DWORD NumberOfHeaps, PHANDLE ProcessHeaps)
{
	DWORD rc = 0;
	WIN32API_POINTER(ProcessHeaps);
	WIN32API_ENTER("DWORD", "GetProcessHeaps", "DWORD", NumberOfHeaps, "PHANDLE", ProcessHeaps, NULL);
	Process *process = Process::GetCurrentProcessObject();
	if (NULL != process) {
		rc = (DWORD)process->GetHeaps(NumberOfHeaps, REINTERPRET_CAST(Heap **, ProcessHeaps));
		WIN32API_ERROR(ERROR_SUCCESS);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetProcessPriorityBoost
(HANDLE hProcess, PBOOL pDisablePriorityBoost)
{
	BOOL rc = FALSE;
	WIN32API_POINTER(pDisablePriorityBoost);
	WIN32API_ENTER("BOOL", "GetProcessPriorityBoost", "HANDLE", hProcess, "PBOOL", pDisablePriorityBoost, NULL);
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetProcessShutdownParameters
(LPDWORD lpdwLevel, LPDWORD lpdwFlags)
{
	BOOL rc = FALSE;
	WIN32API_POINTER(lpdwLevel);
	WIN32API_POINTER(lpdwFlags);
	WIN32API_ENTER("BOOL", "GetProcessShutdownParameters", "PDWORD", lpdwLevel, "PDWORD", lpdwFlags, NULL);
	Process *process = Process::GetCurrentProcessObject();
	if (NULL != process) {
		rc = process->GetShutdownParameters(lpdwLevel, lpdwFlags);
		WIN32API_ERROR(ERROR_SUCCESS);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetProcessTimes
(HANDLE hProcess, LPFILETIME lpCreationTime, LPFILETIME lpExitTime, LPFILETIME lpKernelTime, LPFILETIME lpUserTime)
{
	BOOL rc = FALSE;
	WIN32API_POINTER(lpCreationTime);
	WIN32API_POINTER(lpExitTime);
	WIN32API_POINTER(lpKernelTime);
	WIN32API_POINTER(lpUserTime);
	WIN32API_ENTER("BOOL", "GetProcessTimes", "HANDLE", hProcess,
		"LPFILETIME", lpCreationTime, "LPFILETIME", lpExitTime,
		"LPFILETIME", lpKernelTime, "LPFILETIME", lpUserTime, NULL);
	Process *process = REINTERPRET_CAST(Process *, hProcess);
	if ((NULL != process) && (process->magic == PROCESS_MAGIC)) {
		process->GetTimes(lpCreationTime, lpExitTime, lpKernelTime, lpUserTime);
		WIN32API_ERROR(ERROR_SUCCESS);
	} else {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetProcessVersion
(DWORD ProcessId)
{
	DWORD rc = 0;
	WIN32API_ENTER("DWORD", "GetProcessVersion", "DWORD", ProcessId, NULL);
	Process *process = Process::GetProcessObject(ProcessId);
	if (NULL != process) {
		rc = process->GetVersion();
		WIN32API_ERROR(ERROR_SUCCESS);
	} else {
		WIN32API_ERROR(ERROR_BAD_ARGUMENTS);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetProcessWorkingSetSize
(HANDLE hProcess, LPDWORD lpMinimumWorkingSetSize, LPDWORD lpMaximumWorkingSetSize)
{
	BOOL rc = FALSE;
	WIN32API_POINTER(lpMinimumWorkingSetSize);
	WIN32API_POINTER(lpMaximumWorkingSetSize);
	WIN32API_ENTER("BOOL", "GetProcessWorkingSetSize", "HANDLE", hProcess, "PDWORD", lpMinimumWorkingSetSize, "PDWORD", lpMaximumWorkingSetSize, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" VOID WINAPI
GetStartupInfoA
(LPSTARTUPINFOA lpStartupInfo)
{
	WIN32API_POINTER(lpStartupInfo);
	WIN32API_ENTER("VOID", "GetStartupInfoA", "LPSTARTUPINFOA", lpStartupInfo, NULL);
	Process *process = Process::GetCurrentProcessObject();
	if (NULL != process) process->GetStartupInfoA(lpStartupInfo);
	WIN32API_LEAVE(0);
}

extern "C" VOID WINAPI
GetStartupInfoW
(LPSTARTUPINFOW lpStartupInfo)
{
	WIN32API_POINTER(lpStartupInfo);
	WIN32API_ENTER("VOID", "GetStartupInfoW", "LPSTARTUPINFOW", lpStartupInfo, NULL);
	Process *process = Process::GetCurrentProcessObject();
	if (NULL != process) process->GetStartupInfoW(lpStartupInfo);
	WIN32API_LEAVE(0);
}

extern "C" HANDLE WINAPI
OpenProcess
(DWORD dwDesiredAccess, BOOL bInheritHandle, DWORD dwProcessId)
{
	HANDLE rc = NULL;
	WIN32API_ENTER("HANDLE", "OpenProcess", "DWORD", dwDesiredAccess, "BOOL", bInheritHandle, "DWORD", dwProcessId, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ReadProcessMemory
(HANDLE hProcess, LPCVOID lpBaseAddress, LPVOID lpBuffer, DWORD nSize, LPDWORD lpNumberOfBytesRead)
{
	BOOL rc = FALSE;
	WIN32API_POINTER(lpBaseAddress);
	WIN32API_POINTER(lpBuffer);
	WIN32API_POINTER(lpNumberOfBytesRead);
	WIN32API_ENTER("BOOL", "ReadProcessMemory", "HANDLE", hProcess, "LPCVOID", lpBaseAddress,
		"LPVOID", lpBuffer, "DWORD", nSize, "LPDWORD", lpNumberOfBytesRead, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetProcessAffinityMask
(HANDLE hProcess, DWORD dwProcessAffinityMask)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetProcessAffinityMask", "HANDLE", hProcess, "DWORD", dwProcessAffinityMask, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetProcessPriorityBoost
(HANDLE hProcess, BOOL DisablePriorityBoost)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetProcessPriorityBoost", "HANDLE", hProcess, "BOOL", DisablePriorityBoost, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetProcessShutdownParameters
(DWORD dwLevel, DWORD dwFlags)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetProcessShutdownParameters", "DWORD", dwLevel, "DWORD", dwFlags, NULL);
	Process *process = Process::GetCurrentProcessObject();
	if (NULL != process) {
		rc = process->SetShutdownParameters(dwLevel, dwFlags);
		WIN32API_ERROR(ERROR_SUCCESS);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetProcessWorkingSetSize
(HANDLE hProcess, DWORD dwMinimumWorkingSetSize, DWORD dwMaximumWorkingSetSize)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetProcessWorkingSetSize", "HANDLE", hProcess, "DWORD", dwMinimumWorkingSetSize, "DWORD", dwMaximumWorkingSetSize, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
TerminateProcess
(HANDLE hProcess, UINT uExitCode)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "TerminateProcess", "HANDLE", hProcess, "UINT", uExitCode, NULL);
	WIN32API_INFO("\tnot impl\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
WriteProcessMemory
(HANDLE hProcess, LPVOID lpBaseAddress, LPVOID lpBuffer, DWORD nSize, LPDWORD lpNumberOfBytesWritten)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "WriteProcessMemory", "HANDLE", hProcess, "LPVOID", lpBaseAddress, "LPVOID", lpBuffer, "DWORD", nSize, "LPDWORD", lpNumberOfBytesWritten, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}
