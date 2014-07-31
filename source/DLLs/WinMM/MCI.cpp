/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: MCI.cpp,v 1.1 2003/05/01 06:06:00 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [MCI.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "MCI.h"
#include "WinMM.h"
#include "Win32Trace.h"

extern "C" MCIERROR WINAPI
mciSendCommandA
(MCIDEVICEID IDDevice, UINT uMsg, DWORD fdwCommand, DWORD dwParam)
{
	static BFileGameSound *fgs = NULL;
	char fname[16];
	MCIERROR rc = (MCIERROR)-1;
	WIN32API_ENTER("MCIERROR", "mciSendCommandA", "MCIDEVICEID", IDDevice, "UINT", uMsg, "DWORD", fdwCommand, "DWORD", dwParam, NULL);
	switch (uMsg) {
	case MCI_OPEN:
	case MCI_CLOSE:
	case MCI_SEEK:
		rc = 0;
		break;
	case MCI_PLAY:
		rc = 0;
		if (NULL != fgs) delete fgs;
		snprintf(fname, 16, "track%02d.mp3", (int)((LPMCI_PLAY_PARAMS)dwParam)->dwFrom);
		fgs = new BFileGameSound(fname);
		if (NULL != fgs) fgs->StartPlaying();
		break;
	case MCI_STOP:
		rc = 0;
		if (NULL != fgs) {
			delete fgs;
			fgs = NULL;
		}
		break;
	case MCI_SET:
		rc = 0;
		if (0 != dwParam) {
			LPMCI_SET_PARAMS set = (LPMCI_SET_PARAMS)dwParam;
			WIN32API_INFO("\tdwCallback: %p\n", set->dwCallback);
			WIN32API_INFO("\tdwTimeFormat: %08x\n", set->dwTimeFormat);
			WIN32API_INFO("\tdwAudio: %08x\n", set->dwAudio);
		}
	case MCI_STATUS:
		rc = 0;
		if (0 != (MCI_STATUS_ITEM & fdwCommand)) {
			LPMCI_STATUS_PARAMS st = (LPMCI_STATUS_PARAMS)dwParam;
			WIN32API_INFO("\tdwCallback: %p\n", st->dwCallback);
			WIN32API_INFO("\tdwReturn: %08x\n", st->dwReturn);
			WIN32API_INFO("\tdwItem: %08x\n", st->dwItem);
			WIN32API_INFO("\tdwTrack: %08x\n", st->dwTrack);
		}
		break;
	default:
		break;
	}
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
mciGetErrorStringA
(DWORD fdwError, LPTSTR lpszErrorText, UINT cchErrorText)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "mciGetErrorStringA", "DWORD", fdwError, "LPTSTR", lpszErrorText, "UINT", cchErrorText, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HTASK WINAPI
mciGetCreatorTask
(MCIDEVICEID arg0)
{
	HTASK rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HTASK", "mciGetCreatorTask", "MCIDEVICEID", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MCIDEVICEID WINAPI
mciGetDeviceIDA
(LPCSTR arg0)
{
	MCIDEVICEID rc = (MCIDEVICEID)-1;
	WIN32API_ENTER("MCIDEVICEID", "mciGetDeviceIDA", "LPCSTR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MCIDEVICEID WINAPI
mciGetDeviceIDFromElementIDA
(DWORD arg0, LPCSTR arg1)
{
	MCIDEVICEID rc = (MCIDEVICEID)-1;
	WIN32API_ENTER("MCIDEVICEID", "mciGetDeviceIDFromElementIDA", "DWORD", arg0, "LPCSTR", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MCIDEVICEID WINAPI
mciGetDeviceIDFromElementIDW
(DWORD arg0, LPCWSTR arg1)
{
	MCIDEVICEID rc = (MCIDEVICEID)-1;
	WIN32API_ENTER("MCIDEVICEID", "mciGetDeviceIDFromElementIDW", "DWORD", arg0, "LPCWSTR", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MCIDEVICEID WINAPI
mciGetDeviceIDW
(LPCWSTR arg0)
{
	MCIDEVICEID rc = (MCIDEVICEID)-1;
	WIN32API_ENTER("MCIDEVICEID", "mciGetDeviceIDW", "LPCWSTR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
mciGetErrorStringW
(MCIERROR arg0, LPWSTR arg1, UINT arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "mciGetErrorStringW", "MCIERROR", arg0, "LPWSTR", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" YIELDPROC WINAPI
mciGetYieldProc
(MCIDEVICEID arg0, PDWORD arg1)
{
	YIELDPROC rc = (YIELDPROC)NULL;
	WIN32API_ENTER("YIELDPROC", "mciGetYieldProc", "MCIDEVICEID", arg0, "PDWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MCIERROR WINAPI
mciSendCommandW
(MCIDEVICEID arg0, UINT arg1, DWORD arg2, DWORD arg3)
{
	MCIERROR rc = (MCIERROR)-1;
	WIN32API_ENTER("MCIERROR", "mciSendCommandW", "MCIDEVICEID", arg0, "UINT", arg1, "DWORD", arg2, "DWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MCIERROR WINAPI
mciSendStringA
(LPCSTR arg0, LPSTR arg1, UINT arg2, HWND arg3)
{
	MCIERROR rc = (MCIERROR)-1;
	WIN32API_POINTER(arg0);
	WIN32API_ENTER("MCIERROR", "mciSendStringA", "LPCSTR", arg0, "LPSTR", arg1, "UINT", arg2, "HWND", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_INFO("\tlpszCommand: %s\n", arg0);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MCIERROR WINAPI
mciSendStringW
(LPCWSTR arg0, LPWSTR arg1, UINT arg2, HWND arg3)
{
	MCIERROR rc = (MCIERROR)-1;
	WIN32API_ENTER("MCIERROR", "mciSendStringW", "LPCWSTR", arg0, "LPWSTR", arg1, "UINT", arg2, "HWND", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
mciSetYieldProc
(MCIDEVICEID arg0, YIELDPROC arg1, DWORD arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "mciSetYieldProc", "MCIDEVICEID", arg0, "YIELDPROC", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}
