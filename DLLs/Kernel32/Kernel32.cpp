/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000, 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: Kernel32.cpp,v 1.1 2003/05/01 02:57:16 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Kernel32.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "Kernel32.h"
#include "Win32Trace.h"

extern "C" LPTSTR WINAPI
GetCommandLineA
(VOID)
{
	static char buf[3];
	snprintf(buf, 3, "Be");
	LPTSTR rc = (LPTSTR)buf;
	WIN32API_ENTER("LPTSTR", "GetCommandLineA", NULL);
	WIN32API_INFO("\tnot impl. => dummy\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" VOID WINAPI
RtlUnwind
(UNKNOWN)
{
	WIN32API_ENTER("VOID", "RtlUnwind", NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(0);
}

extern "C" BOOL WINAPI
QueryPerformanceFrequency
(LPLARGE_INTEGER lpFrequency)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "QueryPerformanceFrequency", lpFrequency, NULL);
	WIN32API_INFO("\tnot impl\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
QueryPerformanceCounter
(LPLARGE_INTEGER lpPerformanceCount)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "QueryPerformanceCounter", lpPerformanceCount, NULL);
	WIN32API_INFO("\tnot impl\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" VOID WINAPI
FatalAppExitA
(UINT uAction, LPCTSTR lpMessageText)
{
	WIN32API_ENTER("VOID", "FatalAppExitA", "UINT", uAction, "LPCTSTR", lpMessageText, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(0);
}

extern "C" LONG WINAPI
UnhandledExceptionFilter
(LPEXCEPTION_POINTERS exceptionInfo)
{
	LONG rc = 0;
	WIN32API_ENTER("LONG", "UnhandledExceptionFilter", exceptionInfo, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
WinExec
(LPCSTR lpCmdLine, UINT uCmdShow)
{
	UINT rc = 0;
	WIN32API_ENTER("UINT", "WinExec", "LPCSTR", lpCmdLine, "UINT", uCmdShow, NULL);
	WIN32API_INFO("\tcommand: %s\n", lpCmdLine);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" VOID WINAPI
OutputDebugStringA
(LPCTSTR lpOutputString)
{
	WIN32API_POINTER(lpOutputString);
	WIN32API_ENTER("VOID", "OutputDebugStringA", "LPCTSTR", lpOutputString, NULL);
	WIN32API_INFO("lpOutputString: %s\n", lpOutputString);
	syslog(LOG_DEBUG, "%s", lpOutputString);
	WIN32API_LEAVE(0);
}

extern "C" VOID WINAPI
DebugBreak
(VOID)
{
	WIN32API_ENTER("VOID", "DebugBreak", NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE("VOID");
}

extern "C" BOOL WINAPI
IsBadReadPtr
(LPCVOID lp, UINT ucb)
{
	BOOL rc = TRUE;
	WIN32API_POINTER(lp);
	WIN32API_ENTER("BOOL", "IsBadReadPtr", "LPCVOID", lp, "UINT", ucb, NULL);
	for (;;) {
		area_id id = area_for((void *)lp);
		if (id < B_OK) break;
		area_info info;
		status_t rv = get_area_info(id, &info);
		if (rv != B_OK) break;
		if (0 == (info.protection & B_READ_AREA)) break;
		lp = (LPCVOID)((UINT)lp + info.size);
		ucb -= info.size;
		if ((long)ucb <= 0) {
			rc = FALSE;
			break;
		}
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
IsBadWritePtr
(LPCVOID lp, UINT ucb)
{
	BOOL rc = TRUE;
	WIN32API_ENTER("BOOL", "IsBadWritePtr", "LPCVOID", lp, "UINT", ucb, NULL);
	for (;;) {
		area_id id = area_for((void *)lp);
		if (id < B_OK) break;
		area_info info;
		status_t rv = get_area_info(id, &info);
		if (rv != B_OK) break;
		if (0 == (info.protection & B_WRITE_AREA)) break;
		lp = (LPCVOID)((UINT)lp + info.size);
		ucb -= info.size;
		if ((long)ucb <= 0) {
			rc = FALSE;
			break;
		}
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
AllocConsole
(void)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "AllocConsole", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
AreFileApisANSI
(void)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "AreFileApisANSI", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
BackupRead
(HANDLE arg0, PBYTE arg1, DWORD arg2, PDWORD arg3, BOOL arg4, BOOL arg5, PVOID arg6)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "BackupRead", "HANDLE", arg0, "PBYTE", arg1, "DWORD", arg2, "PDWORD", arg3, "BOOL", arg4, "BOOL", arg5, "PVOID", arg6, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
BackupSeek
(HANDLE arg0, DWORD arg1, DWORD arg2, PDWORD arg3, PDWORD arg4, PVOID arg5)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "BackupSeek", "HANDLE", arg0, "DWORD", arg1, "DWORD", arg2, "PDWORD", arg3, "PDWORD", arg4, "PVOID", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
BackupWrite
(HANDLE arg0, PBYTE arg1, DWORD arg2, PDWORD arg3, BOOL arg4, BOOL arg5, PVOID arg6)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "BackupWrite", "HANDLE", arg0, "PBYTE", arg1, "DWORD", arg2, "PDWORD", arg3, "BOOL", arg4, "BOOL", arg5, "PVOID", arg6, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
Beep
(DWORD arg0, DWORD arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "Beep", "DWORD", arg0, "DWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
BuildCommDCBA
(LPCSTR arg0, LPDCB arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "BuildCommDCBA", "LPCSTR", arg0, "LPDCB", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
BuildCommDCBAndTimeoutsA
(LPCSTR arg0, LPDCB arg1, LPCOMMTIMEOUTS arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "BuildCommDCBAndTimeoutsA", "LPCSTR", arg0, "LPDCB", arg1, "LPCOMMTIMEOUTS", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
BuildCommDCBAndTimeoutsW
(LPCWSTR arg0, LPDCB arg1, LPCOMMTIMEOUTS arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "BuildCommDCBAndTimeoutsW", "LPCWSTR", arg0, "LPDCB", arg1, "LPCOMMTIMEOUTS", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
BuildCommDCBW
(LPCWSTR arg0, LPDCB arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "BuildCommDCBW", "LPCWSTR", arg0, "LPDCB", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CallNamedPipeA
(LPCSTR arg0, PVOID arg1, DWORD arg2, PVOID arg3, DWORD arg4, PDWORD arg5, DWORD arg6)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CallNamedPipeA", "LPCSTR", arg0, "PVOID", arg1, "DWORD", arg2, "PVOID", arg3, "DWORD", arg4, "PDWORD", arg5, "DWORD", arg6, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CallNamedPipeW
(LPCWSTR arg0, PVOID arg1, DWORD arg2, PVOID arg3, DWORD arg4, PDWORD arg5, DWORD arg6)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CallNamedPipeW", "LPCWSTR", arg0, "PVOID", arg1, "DWORD", arg2, "PVOID", arg3, "DWORD", arg4, "PDWORD", arg5, "DWORD", arg6, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CancelIo
(HANDLE arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CancelIo", "HANDLE", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CancelWaitableTimer
(HANDLE arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CancelWaitableTimer", "HANDLE", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ClearCommBreak
(HANDLE arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ClearCommBreak", "HANDLE", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ClearCommError
(HANDLE arg0, PDWORD arg1, LPCOMSTAT arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ClearCommError", "HANDLE", arg0, "PDWORD", arg1, "LPCOMSTAT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" VOID WINAPI
CmdBatNotification
(LPVOID arg0)
{
	WIN32API_ENTER("VOID", "CmdBatNotification", "LPVOID", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(0);
}

extern "C" BOOL WINAPI
CommConfigDialogA
(LPCSTR arg0, HWND arg1, LPCOMMCONFIG arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CommConfigDialogA", "LPCSTR", arg0, "HWND", arg1, "LPCOMMCONFIG", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CommConfigDialogW
(LPCWSTR arg0, HWND arg1, LPCOMMCONFIG arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CommConfigDialogW", "LPCWSTR", arg0, "HWND", arg1, "LPCOMMCONFIG", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ConnectNamedPipe
(HANDLE arg0, LPOVERLAPPED arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ConnectNamedPipe", "HANDLE", arg0, "LPOVERLAPPED", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ContinueDebugEvent
(DWORD arg0, DWORD arg1, DWORD arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ContinueDebugEvent", "DWORD", arg0, "DWORD", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" PVOID WINAPI
ConvertThreadToFiber
(PVOID arg0)
{
	PVOID rc = NULL;
	WIN32API_ENTER("PVOID", "ConvertThreadToFiber", "PVOID", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
CreateConsoleScreenBuffer
(DWORD arg0, DWORD arg1, LPSECURITY_ATTRIBUTES arg2, DWORD arg3, PVOID arg4)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "CreateConsoleScreenBuffer", "DWORD", arg0, "DWORD", arg1, "LPSECURITY_ATTRIBUTES", arg2, "DWORD", arg3, "PVOID", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
CreateEventA
(LPSECURITY_ATTRIBUTES arg0, BOOL arg1, BOOL arg2, LPCSTR arg3)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "CreateEventA", "LPSECURITY_ATTRIBUTES", arg0, "BOOL", arg1, "BOOL", arg2, "LPCSTR", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
CreateEventW
(LPSECURITY_ATTRIBUTES arg0, BOOL arg1, BOOL arg2, LPCWSTR arg3)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "CreateEventW", "LPSECURITY_ATTRIBUTES", arg0, "BOOL", arg1, "BOOL", arg2, "LPCWSTR", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LPVOID WINAPI
CreateFiber
(DWORD arg0, LPFIBER_START_ROUTINE arg1, LPVOID arg2)
{
	LPVOID rc = NULL;
	WIN32API_ENTER("LPVOID", "CreateFiber", "DWORD", arg0, "LPFIBER_START_ROUTINE", arg1, "LPVOID", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
CreateFileMappingA
(HANDLE arg0, LPSECURITY_ATTRIBUTES arg1, DWORD arg2, DWORD arg3, DWORD arg4, LPCSTR arg5)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "CreateFileMappingA", "HANDLE", arg0, "LPSECURITY_ATTRIBUTES", arg1, "DWORD", arg2, "DWORD", arg3, "DWORD", arg4, "LPCSTR", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
CreateFileMappingW
(HANDLE arg0, LPSECURITY_ATTRIBUTES arg1, DWORD arg2, DWORD arg3, DWORD arg4, LPCWSTR arg5)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "CreateFileMappingW", "HANDLE", arg0, "LPSECURITY_ATTRIBUTES", arg1, "DWORD", arg2, "DWORD", arg3, "DWORD", arg4, "LPCWSTR", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
CreateHardLinkA
(LPCSTR arg0, LPCSTR arg1, LPSECURITY_ATTRIBUTES arg2)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "CreateHardLinkA", "LPCSTR", arg0, "LPCSTR", arg1, "LPSECURITY_ATTRIBUTES", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
CreateHardLinkW
(LPCWSTR arg0, LPCWSTR arg1, LPSECURITY_ATTRIBUTES arg2)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "CreateHardLinkW", "LPCWSTR", arg0, "LPCWSTR", arg1, "LPSECURITY_ATTRIBUTES", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
CreateIoCompletionPort
(HANDLE arg0, HANDLE arg1, DWORD arg2, DWORD arg3)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "CreateIoCompletionPort", "HANDLE", arg0, "HANDLE", arg1, "DWORD", arg2, "DWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
CreateMailslotA
(LPCSTR arg0, DWORD arg1, DWORD arg2, LPSECURITY_ATTRIBUTES arg3)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "CreateMailslotA", "LPCSTR", arg0, "DWORD", arg1, "DWORD", arg2, "LPSECURITY_ATTRIBUTES", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
CreateMailslotW
(LPCWSTR arg0, DWORD arg1, DWORD arg2, LPSECURITY_ATTRIBUTES arg3)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "CreateMailslotW", "LPCWSTR", arg0, "DWORD", arg1, "DWORD", arg2, "LPSECURITY_ATTRIBUTES", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
CreateNamedPipeA
(LPCSTR arg0, DWORD arg1, DWORD arg2, DWORD arg3, DWORD arg4, DWORD arg5, DWORD arg6, LPSECURITY_ATTRIBUTES arg7)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "CreateNamedPipeA", "LPCSTR", arg0, "DWORD", arg1, "DWORD", arg2, "DWORD", arg3, "DWORD", arg4, "DWORD", arg5, "DWORD", arg6, "LPSECURITY_ATTRIBUTES", arg7, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
CreateNamedPipeW
(LPCWSTR arg0, DWORD arg1, DWORD arg2, DWORD arg3, DWORD arg4, DWORD arg5, DWORD arg6, LPSECURITY_ATTRIBUTES arg7)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "CreateNamedPipeW", "LPCWSTR", arg0, "DWORD", arg1, "DWORD", arg2, "DWORD", arg3, "DWORD", arg4, "DWORD", arg5, "DWORD", arg6, "LPSECURITY_ATTRIBUTES", arg7, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CreatePipe
(PHANDLE arg0, PHANDLE arg1, LPSECURITY_ATTRIBUTES arg2, DWORD arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CreatePipe", "PHANDLE", arg0, "PHANDLE", arg1, "LPSECURITY_ATTRIBUTES", arg2, "DWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
CreateTapePartition
(HANDLE arg0, DWORD arg1, DWORD arg2, DWORD arg3)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "CreateTapePartition", "HANDLE", arg0, "DWORD", arg1, "DWORD", arg2, "DWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
CreateToolhelp32Snapshot
(DWORD arg0, DWORD arg1)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "CreateToolhelp32Snapshot", "DWORD", arg0, "DWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
CreateWaitableTimerA
(LPSECURITY_ATTRIBUTES arg0, BOOL arg1, LPCSTR arg2)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "CreateWaitableTimerA", "LPSECURITY_ATTRIBUTES", arg0, "BOOL", arg1, "LPCSTR", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
CreateWaitableTimerW
(LPSECURITY_ATTRIBUTES arg0, BOOL arg1, LPCWSTR arg2)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "CreateWaitableTimerW", "LPSECURITY_ATTRIBUTES", arg0, "BOOL", arg1, "LPCWSTR", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DefineDosDeviceA
(DWORD arg0, LPCSTR arg1, LPCSTR arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DefineDosDeviceA", "DWORD", arg0, "LPCSTR", arg1, "LPCSTR", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DefineDosDeviceW
(DWORD arg0, LPCWSTR arg1, LPCWSTR arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DefineDosDeviceW", "DWORD", arg0, "LPCWSTR", arg1, "LPCWSTR", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" void WINAPI
DeleteFiber
(PVOID arg0)
{
	WIN32API_ENTER("void", "DeleteFiber", "PVOID", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(0);
}

extern "C" BOOL WINAPI
DeviceIoControl
(HANDLE arg0, DWORD arg1, PVOID arg2, DWORD arg3, PVOID arg4, DWORD arg5, PDWORD arg6, POVERLAPPED arg7)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DeviceIoControl", "HANDLE", arg0, "DWORD", arg1, "PVOID", arg2, "DWORD", arg3, "PVOID", arg4, "DWORD", arg5, "PDWORD", arg6, "POVERLAPPED", arg7, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DisableThreadLibraryCalls
(HMODULE arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DisableThreadLibraryCalls", "HMODULE", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DisconnectNamedPipe
(HANDLE arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DisconnectNamedPipe", "HANDLE", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
EraseTape
(HANDLE arg0, DWORD arg1, BOOL arg2)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "EraseTape", "HANDLE", arg0, "DWORD", arg1, "BOOL", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
EscapeCommFunction
(HANDLE arg0, DWORD arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "EscapeCommFunction", "HANDLE", arg0, "DWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" void WINAPI
FatalAppExitW
(UINT arg0, LPCWSTR arg1)
{
	WIN32API_ENTER("void", "FatalAppExitW", "UINT", arg0, "LPCWSTR", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(0);
}

extern "C" void WINAPI
FatalExit
(int arg0)
{
	WIN32API_ENTER("void", "FatalExit", "int", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(0);
}

extern "C" BOOL WINAPI
FillConsoleOutputAttribute
(HANDLE arg0, WORD arg1, DWORD arg2, COORD arg3, PDWORD arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "FillConsoleOutputAttribute", "HANDLE", arg0, "WORD", arg1, "DWORD", arg2, "COORD", arg3, "PDWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
FillConsoleOutputCharacterA
(HANDLE arg0, CHAR arg1, DWORD arg2, COORD arg3, PDWORD arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "FillConsoleOutputCharacterA", "HANDLE", arg0, "CHAR", arg1, "DWORD", arg2, "COORD", arg3, "PDWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
FillConsoleOutputCharacterW
(HANDLE arg0, WCHAR arg1, DWORD arg2, COORD arg3, PDWORD arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "FillConsoleOutputCharacterW", "HANDLE", arg0, "WCHAR", arg1, "DWORD", arg2, "COORD", arg3, "PDWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
FindCloseChangeNotification
(HANDLE arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "FindCloseChangeNotification", "HANDLE", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
FindFirstChangeNotificationA
(LPCSTR arg0, BOOL arg1, DWORD arg2)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "FindFirstChangeNotificationA", "LPCSTR", arg0, "BOOL", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
FindFirstChangeNotificationW
(LPCWSTR arg0, BOOL arg1, DWORD arg2)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "FindFirstChangeNotificationW", "LPCWSTR", arg0, "BOOL", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
FindNextChangeNotification
(HANDLE arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "FindNextChangeNotification", "HANDLE", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
FlushConsoleInputBuffer
(HANDLE arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "FlushConsoleInputBuffer", "HANDLE", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
FlushInstructionCache
(HANDLE arg0, PCVOID arg1, DWORD arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "FlushInstructionCache", "HANDLE", arg0, "PCVOID", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
FlushViewOfFile
(PCVOID arg0, DWORD arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "FlushViewOfFile", "PCVOID", arg0, "DWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
FoldStringA
(DWORD arg0, LPCSTR arg1, int arg2, LPSTR arg3, int arg4)
{
	int rc = -1;
	WIN32API_ENTER("int", "FoldStringA", "DWORD", arg0, "LPCSTR", arg1, "int", arg2, "LPSTR", arg3, "int", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
FoldStringW
(DWORD arg0, LPCWSTR arg1, int arg2, LPWSTR arg3, int arg4)
{
	int rc = -1;
	WIN32API_ENTER("int", "FoldStringW", "DWORD", arg0, "LPCWSTR", arg1, "int", arg2, "LPWSTR", arg3, "int", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
FormatMessageA
(DWORD arg0, PCVOID arg1, DWORD arg2, DWORD arg3, LPSTR arg4, DWORD arg5, va_list* arg6)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "FormatMessageA", "DWORD", arg0, "PCVOID", arg1, "DWORD", arg2, "DWORD", arg3, "LPSTR", arg4, "DWORD", arg5, "va_list*", arg6, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
FormatMessageW
(DWORD arg0, PCVOID arg1, DWORD arg2, DWORD arg3, LPWSTR arg4, DWORD arg5, va_list* arg6)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "FormatMessageW", "DWORD", arg0, "PCVOID", arg1, "DWORD", arg2, "DWORD", arg3, "LPWSTR", arg4, "DWORD", arg5, "va_list*", arg6, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
FreeConsole
(void)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "FreeConsole", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GenerateConsoleCtrlEvent
(DWORD arg0, DWORD arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GenerateConsoleCtrlEvent", "DWORD", arg0, "DWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetBinaryTypeA
(LPCSTR arg0, PDWORD arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetBinaryTypeA", "LPCSTR", arg0, "PDWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetBinaryTypeW
(LPCWSTR arg0, PDWORD arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetBinaryTypeW", "LPCWSTR", arg0, "PDWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetCommConfig
(HANDLE arg0, LPCOMMCONFIG arg1, PDWORD arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetCommConfig", "HANDLE", arg0, "LPCOMMCONFIG", arg1, "PDWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetCommMask
(HANDLE arg0, PDWORD arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetCommMask", "HANDLE", arg0, "PDWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetCommModemStatus
(HANDLE arg0, PDWORD arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetCommModemStatus", "HANDLE", arg0, "PDWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetCommProperties
(HANDLE arg0, LPCOMMPROP arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetCommProperties", "HANDLE", arg0, "LPCOMMPROP", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetCommState
(HANDLE arg0, LPDCB arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetCommState", "HANDLE", arg0, "LPDCB", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetCommTimeouts
(HANDLE arg0, LPCOMMTIMEOUTS arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetCommTimeouts", "HANDLE", arg0, "LPCOMMTIMEOUTS", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LPWSTR WINAPI
GetCommandLineW
(VOID)
{
	static short buf[3] = { 'B', 'e', 0 };
	LPWSTR rc = buf;
	WIN32API_ENTER("LPWSTR", "GetCommandLineW", "VOID", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetCompressedFileSizeA
(LPCSTR arg0, PDWORD arg1)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "GetCompressedFileSizeA", "LPCSTR", arg0, "PDWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetCompressedFileSizeW
(LPCWSTR arg0, PDWORD arg1)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "GetCompressedFileSizeW", "LPCWSTR", arg0, "PDWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetComputerNameA
(LPSTR arg0, PDWORD arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetComputerNameA", "LPSTR", arg0, "PDWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetComputerNameW
(LPWSTR arg0, PDWORD arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetComputerNameW", "LPWSTR", arg0, "PDWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
GetConsoleCP
(void)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "GetConsoleCP", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetConsoleCursorInfo
(HANDLE arg0, PCONSOLE_CURSOR_INFO arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetConsoleCursorInfo", "HANDLE", arg0, "PCONSOLE_CURSOR_INFO", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetConsoleMode
(HANDLE arg0, PDWORD arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetConsoleMode", "HANDLE", arg0, "PDWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
GetConsoleOutputCP
(void)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "GetConsoleOutputCP", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetConsoleScreenBufferInfo
(HANDLE arg0, PCONSOLE_SCREEN_BUFFER_INFO arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetConsoleScreenBufferInfo", "HANDLE", arg0, "PCONSOLE_SCREEN_BUFFER_INFO", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetConsoleTitleA
(LPSTR arg0, DWORD arg1)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "GetConsoleTitleA", "LPSTR", arg0, "DWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetConsoleTitleW
(LPWSTR arg0, DWORD arg1)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "GetConsoleTitleW", "LPWSTR", arg0, "DWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetDefaultCommConfigA
(LPCSTR arg0, LPCOMMCONFIG arg1, PDWORD arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetDefaultCommConfigA", "LPCSTR", arg0, "LPCOMMCONFIG", arg1, "PDWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetDefaultCommConfigW
(LPCWSTR arg0, LPCOMMCONFIG arg1, PDWORD arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetDefaultCommConfigW", "LPCWSTR", arg0, "LPCOMMCONFIG", arg1, "PDWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" COORD WINAPI
GetLargestConsoleWindowSize
(HANDLE arg0)
{
	COORD rc = { 0, 0 };
	WIN32API_ENTER("COORD", "GetLargestConsoleWindowSize", "HANDLE", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(0);
	return rc;
}

extern "C" BOOL WINAPI
GetMailslotInfo
(HANDLE arg0, PDWORD arg1, PDWORD arg2, PDWORD arg3, PDWORD arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetMailslotInfo", "HANDLE", arg0, "PDWORD", arg1, "PDWORD", arg2, "PDWORD", arg3, "PDWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetNamedPipeHandleStateA
(HANDLE arg0, PDWORD arg1, PDWORD arg2, PDWORD arg3, PDWORD arg4, LPSTR arg5, DWORD arg6)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetNamedPipeHandleStateA", "HANDLE", arg0, "PDWORD", arg1, "PDWORD", arg2, "PDWORD", arg3, "PDWORD", arg4, "LPSTR", arg5, "DWORD", arg6, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetNamedPipeHandleStateW
(HANDLE arg0, PDWORD arg1, PDWORD arg2, PDWORD arg3, PDWORD arg4, LPWSTR arg5, DWORD arg6)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetNamedPipeHandleStateW", "HANDLE", arg0, "PDWORD", arg1, "PDWORD", arg2, "PDWORD", arg3, "PDWORD", arg4, "LPWSTR", arg5, "DWORD", arg6, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetNamedPipeInfo
(HANDLE arg0, PDWORD arg1, PDWORD arg2, PDWORD arg3, PDWORD arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetNamedPipeInfo", "HANDLE", arg0, "PDWORD", arg1, "PDWORD", arg2, "PDWORD", arg3, "PDWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetNumberOfConsoleInputEvents
(HANDLE arg0, PDWORD arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetNumberOfConsoleInputEvents", "HANDLE", arg0, "PDWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetNumberOfConsoleMouseButtons
(PDWORD arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetNumberOfConsoleMouseButtons", "PDWORD", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetOverlappedResult
(HANDLE arg0, LPOVERLAPPED arg1, PDWORD arg2, BOOL arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetOverlappedResult", "HANDLE", arg0, "LPOVERLAPPED", arg1, "PDWORD", arg2, "BOOL", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetPriorityClass
(HANDLE arg0)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "GetPriorityClass", "HANDLE", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetQueuedCompletionStatus
(HANDLE arg0, PDWORD arg1, PDWORD arg2, LPOVERLAPPED* arg3, DWORD arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetQueuedCompletionStatus", "HANDLE", arg0, "PDWORD", arg1, "PDWORD", arg2, "LPOVERLAPPED*", arg3, "DWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" VOID WINAPI
GetSystemInfo
(LPSYSTEM_INFO arg0)
{
	WIN32API_ENTER("VOID", "GetSystemInfo", "LPSYSTEM_INFO", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(0);
}

extern "C" BOOL WINAPI
GetSystemPowerStatus
(LPSYSTEM_POWER_STATUS arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetSystemPowerStatus", "LPSYSTEM_POWER_STATUS", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetTapeParameters
(HANDLE arg0, DWORD arg1, PDWORD arg2, PVOID arg3)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "GetTapeParameters", "HANDLE", arg0, "DWORD", arg1, "PDWORD", arg2, "PVOID", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetTapePosition
(HANDLE arg0, DWORD arg1, PDWORD arg2, PDWORD arg3, PDWORD arg4)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "GetTapePosition", "HANDLE", arg0, "DWORD", arg1, "PDWORD", arg2, "PDWORD", arg3, "PDWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetTapeStatus
(HANDLE arg0)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "GetTapeStatus", "HANDLE", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
GetTempFileNameA
(LPCSTR arg0, LPCSTR arg1, UINT arg2, LPSTR arg3)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "GetTempFileNameA", "LPCSTR", arg0, "LPCSTR", arg1, "UINT", arg2, "LPSTR", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
GetTempFileNameW
(LPCWSTR arg0, LPCWSTR arg1, UINT arg2, LPWSTR arg3)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "GetTempFileNameW", "LPCWSTR", arg0, "LPCWSTR", arg1, "UINT", arg2, "LPWSTR", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetTimeFormatA
(LCID arg0, DWORD arg1, const SYSTEMTIME* arg2, LPCSTR arg3, LPSTR arg4, int arg5)
{
	int rc = -1;
	WIN32API_ENTER("int", "GetTimeFormatA", "LCID", arg0, "DWORD", arg1, "const SYSTEMTIME*", arg2, "LPCSTR", arg3, "LPSTR", arg4, "int", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetTimeFormatW
(LCID arg0, DWORD arg1, const SYSTEMTIME* arg2, LPCWSTR arg3, LPWSTR arg4, int arg5)
{
	int rc = -1;
	WIN32API_ENTER("int", "GetTimeFormatW", "LCID", arg0, "DWORD", arg1, "const SYSTEMTIME*", arg2, "LPCWSTR", arg3, "LPWSTR", arg4, "int", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" VOID WINAPI
GetVDMCurrentDirectories
(LPVOID arg0, LPVOID arg1)
{
	WIN32API_ENTER("VOID", "GetVDMCurrentDirectories", "LPVOID", arg0, "LPVOID", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(0);
}

extern "C" BOOL WINAPI
IsBadCodePtr
(FARPROC arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "IsBadCodePtr", "FARPROC", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
IsBadHugeReadPtr
(PCVOID arg0, UINT arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "IsBadHugeReadPtr", "PCVOID", arg0, "UINT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
IsBadHugeWritePtr
(PVOID arg0, UINT arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "IsBadHugeWritePtr", "PVOID", arg0, "UINT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
IsBadStringPtrA
(LPCSTR arg0, UINT arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "IsBadStringPtrA", "LPCSTR", arg0, "UINT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
IsBadStringPtrW
(LPCWSTR arg0, UINT arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "IsBadStringPtrW", "LPCWSTR", arg0, "UINT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
IsDebuggerPresent
(void)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "IsDebuggerPresent", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
IsProcessorFeaturePresent
(DWORD arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "IsProcessorFeaturePresent", "DWORD", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
LoadModule
(LPCSTR arg0, PVOID arg1)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "LoadModule", "LPCSTR", arg0, "PVOID", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" PVOID WINAPI
MapViewOfFile
(HANDLE arg0, DWORD arg1, DWORD arg2, DWORD arg3, DWORD arg4)
{
	PVOID rc = NULL;
	WIN32API_ENTER("PVOID", "MapViewOfFile", "HANDLE", arg0, "DWORD", arg1, "DWORD", arg2, "DWORD", arg3, "DWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" PVOID WINAPI
MapViewOfFileEx
(HANDLE arg0, DWORD arg1, DWORD arg2, DWORD arg3, DWORD arg4, PVOID arg5)
{
	PVOID rc = NULL;
	WIN32API_ENTER("PVOID", "MapViewOfFileEx", "HANDLE", arg0, "DWORD", arg1, "DWORD", arg2, "DWORD", arg3, "DWORD", arg4, "PVOID", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
MulDiv
(int arg0, int arg1, int arg2)
{
	int rc = -1;
	WIN32API_ENTER("int", "MulDiv", "int", arg0, "int", arg1, "int", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
OpenEventA
(DWORD arg0, BOOL arg1, LPCSTR arg2)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "OpenEventA", "DWORD", arg0, "BOOL", arg1, "LPCSTR", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
OpenEventW
(DWORD arg0, BOOL arg1, LPCWSTR arg2)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "OpenEventW", "DWORD", arg0, "BOOL", arg1, "LPCWSTR", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
OpenFileMappingA
(DWORD arg0, BOOL arg1, LPCSTR arg2)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "OpenFileMappingA", "DWORD", arg0, "BOOL", arg1, "LPCSTR", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
OpenFileMappingW
(DWORD arg0, BOOL arg1, LPCWSTR arg2)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "OpenFileMappingW", "DWORD", arg0, "BOOL", arg1, "LPCWSTR", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
OpenWaitableTimerA
(DWORD arg0, BOOL arg1, LPCSTR arg2)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "OpenWaitableTimerA", "DWORD", arg0, "BOOL", arg1, "LPCSTR", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
OpenWaitableTimerW
(DWORD arg0, BOOL arg1, LPCWSTR arg2)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "OpenWaitableTimerW", "DWORD", arg0, "BOOL", arg1, "LPCWSTR", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" void WINAPI
OutputDebugStringW
(LPCWSTR arg0)
{
	WIN32API_ENTER("void", "OutputDebugStringW", "LPCWSTR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(0);
}

extern "C" BOOL WINAPI
PeekConsoleInputA
(HANDLE arg0, PINPUT_RECORD arg1, DWORD arg2, PDWORD arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "PeekConsoleInputA", "HANDLE", arg0, "PINPUT_RECORD", arg1, "DWORD", arg2, "PDWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
PeekConsoleInputW
(HANDLE arg0, PINPUT_RECORD arg1, DWORD arg2, PDWORD arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "PeekConsoleInputW", "HANDLE", arg0, "PINPUT_RECORD", arg1, "DWORD", arg2, "PDWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
PeekNamedPipe
(HANDLE arg0, PVOID arg1, DWORD arg2, PDWORD arg3, PDWORD arg4, PDWORD arg5)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "PeekNamedPipe", "HANDLE", arg0, "PVOID", arg1, "DWORD", arg2, "PDWORD", arg3, "PDWORD", arg4, "PDWORD", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
PostQueuedCompletionStatus
(HANDLE arg0, DWORD arg1, DWORD arg2, LPOVERLAPPED arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "PostQueuedCompletionStatus", "HANDLE", arg0, "DWORD", arg1, "DWORD", arg2, "LPOVERLAPPED", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
PrepareTape
(HANDLE arg0, DWORD arg1, BOOL arg2)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "PrepareTape", "HANDLE", arg0, "DWORD", arg1, "BOOL", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
PulseEvent
(HANDLE arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "PulseEvent", "HANDLE", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
PurgeComm
(HANDLE arg0, DWORD arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "PurgeComm", "HANDLE", arg0, "DWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
QueryDosDeviceA
(LPCSTR arg0, LPSTR arg1, DWORD arg2)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "QueryDosDeviceA", "LPCSTR", arg0, "LPSTR", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
QueryDosDeviceW
(LPCWSTR arg0, LPWSTR arg1, DWORD arg2)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "QueryDosDeviceW", "LPCWSTR", arg0, "LPWSTR", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
QueueUserAPC
(PAPCFUNC arg0, HANDLE arg1, DWORD arg2)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "QueueUserAPC", "PAPCFUNC", arg0, "HANDLE", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" void WINAPI
RaiseException
(DWORD arg0, DWORD arg1, DWORD arg2, const DWORD* arg3)
{
	WIN32API_ENTER("void", "RaiseException", "DWORD", arg0, "DWORD", arg1, "DWORD", arg2, "const DWORD*", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(0);
}

extern "C" BOOL WINAPI
ReadConsoleA
(HANDLE arg0, PVOID arg1, DWORD arg2, PDWORD arg3, PVOID arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ReadConsoleA", "HANDLE", arg0, "PVOID", arg1, "DWORD", arg2, "PDWORD", arg3, "PVOID", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ReadConsoleInputA
(HANDLE arg0, PINPUT_RECORD arg1, DWORD arg2, PDWORD arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ReadConsoleInputA", "HANDLE", arg0, "PINPUT_RECORD", arg1, "DWORD", arg2, "PDWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ReadConsoleInputW
(HANDLE arg0, PINPUT_RECORD arg1, DWORD arg2, PDWORD arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ReadConsoleInputW", "HANDLE", arg0, "PINPUT_RECORD", arg1, "DWORD", arg2, "PDWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ReadConsoleOutputA
(HANDLE arg0, PCHAR_INFO arg1, COORD arg2, COORD arg3, PSMALL_RECT arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ReadConsoleOutputA", "HANDLE", arg0, "PCHAR_INFO", arg1, "COORD", arg2, "COORD", arg3, "PSMALL_RECT", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ReadConsoleOutputAttribute
(HANDLE arg0, LPWORD arg1, DWORD arg2, COORD arg3, LPDWORD arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ReadConsoleOutputAttribute", "HANDLE", arg0, "LPWORD", arg1, "DWORD", arg2, "COORD", arg3, "LPDWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ReadConsoleOutputCharacterA
(HANDLE arg0, LPSTR arg1, DWORD arg2, COORD arg3, PDWORD arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ReadConsoleOutputCharacterA", "HANDLE", arg0, "LPSTR", arg1, "DWORD", arg2, "COORD", arg3, "PDWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ReadConsoleOutputCharacterW
(HANDLE arg0, LPWSTR arg1, DWORD arg2, COORD arg3, PDWORD arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ReadConsoleOutputCharacterW", "HANDLE", arg0, "LPWSTR", arg1, "DWORD", arg2, "COORD", arg3, "PDWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ReadConsoleOutputW
(HANDLE arg0, PCHAR_INFO arg1, COORD arg2, COORD arg3, PSMALL_RECT arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ReadConsoleOutputW", "HANDLE", arg0, "PCHAR_INFO", arg1, "COORD", arg2, "COORD", arg3, "PSMALL_RECT", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ReadConsoleW
(HANDLE arg0, PVOID arg1, DWORD arg2, PDWORD arg3, PVOID arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ReadConsoleW", "HANDLE", arg0, "PVOID", arg1, "DWORD", arg2, "PDWORD", arg3, "PVOID", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ReadDirectoryChangesW
(HANDLE arg0, PVOID arg1, DWORD arg2, BOOL arg3, DWORD arg4, PDWORD arg5, LPOVERLAPPED arg6, LPOVERLAPPED_COMPLETION_ROUTINE arg7)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ReadDirectoryChangesW", "HANDLE", arg0, "PVOID", arg1, "DWORD", arg2, "BOOL", arg3, "DWORD", arg4, "PDWORD", arg5, "LPOVERLAPPED", arg6, "LPOVERLAPPED_COMPLETION_ROUTINE", arg7, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ResetEvent
(HANDLE arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ResetEvent", "HANDLE", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ScrollConsoleScreenBufferA
(HANDLE arg0, const SMALL_RECT* arg1, const SMALL_RECT* arg2, COORD arg3, const CHAR_INFO* arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ScrollConsoleScreenBufferA", "HANDLE", arg0, "const SMALL_RECT*", arg1, "const SMALL_RECT*", arg2, "COORD", arg3, "const CHAR_INFO*", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ScrollConsoleScreenBufferW
(HANDLE arg0, const SMALL_RECT* arg1, const SMALL_RECT* arg2, COORD arg3, const CHAR_INFO* arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ScrollConsoleScreenBufferW", "HANDLE", arg0, "const SMALL_RECT*", arg1, "const SMALL_RECT*", arg2, "COORD", arg3, "const CHAR_INFO*", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetCommBreak
(HANDLE arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetCommBreak", "HANDLE", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetCommConfig
(HANDLE arg0, LPCOMMCONFIG arg1, DWORD arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetCommConfig", "HANDLE", arg0, "LPCOMMCONFIG", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetCommMask
(HANDLE arg0, DWORD arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetCommMask", "HANDLE", arg0, "DWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetCommState
(HANDLE arg0, LPDCB arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetCommState", "HANDLE", arg0, "LPDCB", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetCommTimeouts
(HANDLE arg0, LPCOMMTIMEOUTS arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetCommTimeouts", "HANDLE", arg0, "LPCOMMTIMEOUTS", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetComputerNameA
(LPCSTR arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetComputerNameA", "LPCSTR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetComputerNameW
(LPCWSTR arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetComputerNameW", "LPCWSTR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetConsoleActiveScreenBuffer
(HANDLE arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetConsoleActiveScreenBuffer", "HANDLE", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetConsoleCP
(UINT arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetConsoleCP", "UINT", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetConsoleCtrlHandler
(PHANDLER_ROUTINE arg0, BOOL arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetConsoleCtrlHandler", "PHANDLER_ROUTINE", arg0, "BOOL", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetConsoleCursorInfo
(HANDLE arg0, const CONSOLE_CURSOR_INFO* arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetConsoleCursorInfo", "HANDLE", arg0, "const CONSOLE_CURSOR_INFO*", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetConsoleCursorPosition
(HANDLE arg0, COORD arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetConsoleCursorPosition", "HANDLE", arg0, "COORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetConsoleMode
(HANDLE arg0, DWORD arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetConsoleMode", "HANDLE", arg0, "DWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetConsoleOutputCP
(UINT arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetConsoleOutputCP", "UINT", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetConsoleScreenBufferSize
(HANDLE arg0, COORD arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetConsoleScreenBufferSize", "HANDLE", arg0, "COORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetConsoleTextAttribute
(HANDLE arg0, WORD arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetConsoleTextAttribute", "HANDLE", arg0, "WORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetConsoleTitleA
(LPCSTR arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetConsoleTitleA", "LPCSTR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetConsoleTitleW
(LPCWSTR arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetConsoleTitleW", "LPCWSTR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetConsoleWindowInfo
(HANDLE arg0, BOOL arg1, const SMALL_RECT* arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetConsoleWindowInfo", "HANDLE", arg0, "BOOL", arg1, "const SMALL_RECT*", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetDefaultCommConfigA
(LPCSTR arg0, LPCOMMCONFIG arg1, DWORD arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetDefaultCommConfigA", "LPCSTR", arg0, "LPCOMMCONFIG", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetDefaultCommConfigW
(LPCWSTR arg0, LPCOMMCONFIG arg1, DWORD arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetDefaultCommConfigW", "LPCWSTR", arg0, "LPCOMMCONFIG", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
SetErrorMode
(UINT arg0)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "SetErrorMode", "UINT", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetEvent
(HANDLE arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetEvent", "HANDLE", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" VOID WINAPI
SetFileApisToANSI
(void)
{
	WIN32API_ENTER("VOID", "SetFileApisToANSI", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(0);
}

extern "C" VOID WINAPI
SetFileApisToOEM
(void)
{
	WIN32API_ENTER("VOID", "SetFileApisToOEM", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(0);
}

extern "C" BOOL WINAPI
SetHandleInformation
(HANDLE arg0, DWORD arg1, DWORD arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetHandleInformation", "HANDLE", arg0, "DWORD", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetMailslotInfo
(HANDLE arg0, DWORD arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetMailslotInfo", "HANDLE", arg0, "DWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetNamedPipeHandleState
(HANDLE arg0, PDWORD arg1, PDWORD arg2, PDWORD arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetNamedPipeHandleState", "HANDLE", arg0, "PDWORD", arg1, "PDWORD", arg2, "PDWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetPriorityClass
(HANDLE arg0, DWORD arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetPriorityClass", "HANDLE", arg0, "DWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetSystemPowerState
(BOOL arg0, BOOL arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetSystemPowerState", "BOOL", arg0, "BOOL", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
SetTapeParameters
(HANDLE arg0, DWORD arg1, PVOID arg2)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "SetTapeParameters", "HANDLE", arg0, "DWORD", arg1, "PVOID", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
SetTapePosition
(HANDLE arg0, DWORD arg1, DWORD arg2, DWORD arg3, DWORD arg4, BOOL arg5)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "SetTapePosition", "HANDLE", arg0, "DWORD", arg1, "DWORD", arg2, "DWORD", arg3, "DWORD", arg4, "BOOL", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LPTOP_LEVEL_EXCEPTION_FILTER WINAPI
SetUnhandledExceptionFilter
(LPTOP_LEVEL_EXCEPTION_FILTER arg0)
{
	LPTOP_LEVEL_EXCEPTION_FILTER rc = NULL;
	WIN32API_ENTER("LPTOP_LEVEL_EXCEPTION_FILTER", "SetUnhandledExceptionFilter", "LPTOP_LEVEL_EXCEPTION_FILTER", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetWaitableTimer
(HANDLE arg0, const LARGE_INTEGER* arg1, LONG arg2, PTIMERAPCROUTINE arg3, PVOID arg4, BOOL arg5)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetWaitableTimer", "HANDLE", arg0, "const LARGE_INTEGER*", arg1, "LONG", arg2, "PTIMERAPCROUTINE", arg3, "PVOID", arg4, "BOOL", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetupComm
(HANDLE arg0, DWORD arg1, DWORD arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetupComm", "HANDLE", arg0, "DWORD", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SignalObjectAndWait
(HANDLE arg0, HANDLE arg1, DWORD arg2, BOOL arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SignalObjectAndWait", "HANDLE", arg0, "HANDLE", arg1, "DWORD", arg2, "BOOL", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" void WINAPI
Sleep
(DWORD dwMilliseconds)
{
	WIN32API_ENTER("void", "Sleep", "DWORD", dwMilliseconds, NULL);
	snooze(dwMilliseconds * 1000);
	WIN32API_LEAVE(0);
}

extern "C" DWORD WINAPI
SleepEx
(DWORD arg0, BOOL arg1)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "SleepEx", "DWORD", arg0, "BOOL", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" void WINAPI
SwitchToFiber
(PVOID arg0)
{
	WIN32API_ENTER("void", "SwitchToFiber", "PVOID", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(0);
}

extern "C" BOOL WINAPI
TransactNamedPipe
(HANDLE arg0, PVOID arg1, DWORD arg2, PVOID arg3, DWORD arg4, PDWORD arg5, LPOVERLAPPED arg6)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "TransactNamedPipe", "HANDLE", arg0, "PVOID", arg1, "DWORD", arg2, "PVOID", arg3, "DWORD", arg4, "PDWORD", arg5, "LPOVERLAPPED", arg6, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
TransmitCommChar
(HANDLE arg0, char arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "TransmitCommChar", "HANDLE", arg0, "char", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
UnmapViewOfFile
(PVOID arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "UnmapViewOfFile", "PVOID", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
VerLanguageNameA
(DWORD arg0, LPSTR arg1, DWORD arg2)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "VerLanguageNameA", "DWORD", arg0, "LPSTR", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
VerLanguageNameW
(DWORD arg0, LPWSTR arg1, DWORD arg2)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "VerLanguageNameW", "DWORD", arg0, "LPWSTR", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
WaitCommEvent
(HANDLE arg0, PDWORD arg1, LPOVERLAPPED arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "WaitCommEvent", "HANDLE", arg0, "PDWORD", arg1, "LPOVERLAPPED", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
WaitForDebugEvent
(LPDEBUG_EVENT arg0, DWORD arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "WaitForDebugEvent", "LPDEBUG_EVENT", arg0, "DWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
WaitNamedPipeA
(LPCSTR arg0, DWORD arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "WaitNamedPipeA", "LPCSTR", arg0, "DWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
WaitNamedPipeW
(LPCWSTR arg0, DWORD arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "WaitNamedPipeW", "LPCWSTR", arg0, "DWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
WriteConsoleA
(HANDLE arg0, PCVOID arg1, DWORD arg2, PDWORD arg3, PVOID arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "WriteConsoleA", "HANDLE", arg0, "PCVOID", arg1, "DWORD", arg2, "PDWORD", arg3, "PVOID", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
WriteConsoleInputA
(HANDLE arg0, const INPUT_RECORD* arg1, DWORD arg2, PDWORD arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "WriteConsoleInputA", "HANDLE", arg0, "const INPUT_RECORD*", arg1, "DWORD", arg2, "PDWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
WriteConsoleInputW
(HANDLE arg0, const INPUT_RECORD* arg1, DWORD arg2, PDWORD arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "WriteConsoleInputW", "HANDLE", arg0, "const INPUT_RECORD*", arg1, "DWORD", arg2, "PDWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
WriteConsoleOutputA
(HANDLE arg0, const CHAR_INFO* arg1, COORD arg2, COORD arg3, PSMALL_RECT arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "WriteConsoleOutputA", "HANDLE", arg0, "const CHAR_INFO*", arg1, "COORD", arg2, "COORD", arg3, "PSMALL_RECT", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
WriteConsoleOutputAttribute
(HANDLE arg0, const WORD* arg1, DWORD arg2, COORD arg3, PDWORD arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "WriteConsoleOutputAttribute", "HANDLE", arg0, "const WORD*", arg1, "DWORD", arg2, "COORD", arg3, "PDWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
WriteConsoleOutputCharacterA
(HANDLE arg0, LPCSTR arg1, DWORD arg2, COORD arg3, PDWORD arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "WriteConsoleOutputCharacterA", "HANDLE", arg0, "LPCSTR", arg1, "DWORD", arg2, "COORD", arg3, "PDWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
WriteConsoleOutputCharacterW
(HANDLE arg0, LPCWSTR arg1, DWORD arg2, COORD arg3, PDWORD arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "WriteConsoleOutputCharacterW", "HANDLE", arg0, "LPCWSTR", arg1, "DWORD", arg2, "COORD", arg3, "PDWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
WriteConsoleOutputW
(HANDLE arg0, const CHAR_INFO* arg1, COORD arg2, COORD arg3, PSMALL_RECT arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "WriteConsoleOutputW", "HANDLE", arg0, "const CHAR_INFO*", arg1, "COORD", arg2, "COORD", arg3, "PSMALL_RECT", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
WriteConsoleW
(HANDLE arg0, PCVOID arg1, DWORD arg2, PDWORD arg3, PVOID arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "WriteConsoleW", "HANDLE", arg0, "PCVOID", arg1, "DWORD", arg2, "PDWORD", arg3, "PVOID", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
WriteTapemark
(HANDLE arg0, DWORD arg1, DWORD arg2, BOOL arg3)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "WriteTapemark", "HANDLE", arg0, "DWORD", arg1, "DWORD", arg2, "BOOL", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

#if defined(_BUILTIN_DLL)

#	define	GetAddressByOrder	Kernel32_GetAddressByOrder
#	define	GetAddressByName	Kernel32_GetAddressByName

#	include "Kernel32/GetAddressByOrder.h"
#	include "Kernel32/GetAddressByName.h"

#endif	// defined(_BUILTIN_DLL)
