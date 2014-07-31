/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: WinMM.cpp,v 1.1 2003/05/01 06:06:00 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [WinMM.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "WinMM.h"
#include "Win32Trace.h"

extern "C" MMRESULT WINAPI
waveOutReset
(HWAVEOUT hwo)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "waveOutReset", "HWAVEOUT", hwo, NULL);
	WIN32API_INFO("\tnot impl.\n");	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
waveOutOpen
(LPHWAVEOUT phwo, UINT uDeviceID, LPWAVEFORMATEX pwfx, DWORD dwCallback, DWORD dwCallbackInstance, DWORD fdwOpen)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "waveOutOpen", "LPHWAVEOUT", phwo, "UINT", uDeviceID, "LPWAVEFORMATEX", pwfx, "DWORD", dwCallback, "DWORD", dwCallbackInstance, "DWORD", fdwOpen, NULL);
	WIN32API_INFO("\tnot impl.\n");	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
waveOutPrepareHeader
(HWAVEOUT hwo, LPWAVEHDR pwh, UINT cbwh)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "waveOutPrepareHeader", "HWAVEOUT", hwo, "LPWAVEHDR", pwh, "UINT", cbwh, NULL);
	WIN32API_INFO("\tnot impl.\n");	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
waveOutWrite
(HWAVEOUT hwo, LPWAVEHDR pwh, UINT cbwh)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "waveOutWrite", "HWAVEOUT", hwo, "LPWAVEHDR", pwh, "UINT", cbwh, NULL);
	WIN32API_INFO("\tnot impl.\n");	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
waveOutUnprepareHeader
(HWAVEOUT hwo, LPWAVEHDR pwh, UINT cbwh)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "waveOutUnprepareHeader", "HWAVEOUT", hwo, "LPWAVEHDR", pwh, "UINT", cbwh, NULL);
	WIN32API_INFO("\tnot impl.\n");	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
waveOutClose
(HWAVEOUT hwo)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "waveOutClose", "HWAVEOUT", hwo, NULL);
	WIN32API_INFO("\tnot impl.\n");	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
timeGetSystemTime
(LPMMTIME pmmt, UINT cbmmt)
{
	MMRESULT rc = 0;
	WIN32API_ENTER("MMRESULT", "timeGetSystemTime", "LPMMTIME", pmmt, "UINT", cbmmt, NULL);
	pmmt->wType = 1;	// TIME_MS
	pmmt->u.ms = system_time() / 1000;
	long *p = (long *)pmmt;
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
auxGetDevCapsA
(UINT arg0, LPAUXCAPSA arg1, UINT arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "auxGetDevCapsA", "UINT", arg0, "LPAUXCAPSA", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
auxSetVolume
(UINT uDeviceID, DWORD dwVolume)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "auxSetVolume", "UINT", uDeviceID, "DWORD", dwVolume, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
auxGetNumDevs
(VOID)
{
	UINT rc = 0;
	WIN32API_ENTER("UINT", "auxGetNumDevs", NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
auxGetVolume
(UINT uDeviceID, LPDWORD lpdwVolume)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "auxGetVolume", "UINT", uDeviceID, "LPDWORD", lpdwVolume, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LRESULT WINAPI
CloseDriver
(HDRVR arg0, LONG arg1, LONG arg2)
{
	LRESULT rc = (LRESULT)-1;
	WIN32API_ENTER("LRESULT", "CloseDriver", "HDRVR", arg0, "LONG", arg1, "LONG", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LRESULT WINAPI
DefDriverProc
(DWORD arg0, HDRVR arg1, UINT arg2, LPARAM arg3, LPARAM arg4)
{
	LRESULT rc = (LRESULT)-1;
	WIN32API_ENTER("LRESULT", "DefDriverProc", "DWORD", arg0, "HDRVR", arg1, "UINT", arg2, "LPARAM", arg3, "LPARAM", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HMODULE WINAPI
DrvGetModuleHandle
(HDRVR arg0)
{
	HMODULE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HMODULE", "DrvGetModuleHandle", "HDRVR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HMODULE WINAPI
GetDriverModuleHandle
(HDRVR arg0)
{
	HMODULE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HMODULE", "GetDriverModuleHandle", "HDRVR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HDRVR WINAPI
OpenDriver
(LPCWSTR arg0, LPCWSTR arg1, LONG arg2)
{
	HDRVR rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HDRVR", "OpenDriver", "LPCWSTR", arg0, "LPCWSTR", arg1, "LONG", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
PlaySoundA
(LPCSTR arg0, HMODULE arg1, DWORD arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "PlaySoundA", "LPCSTR", arg0, "HMODULE", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
PlaySoundW
(LPCWSTR arg0, HMODULE arg1, DWORD arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "PlaySoundW", "LPCWSTR", arg0, "HMODULE", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LRESULT WINAPI
SendDriverMessage
(HDRVR arg0, UINT arg1, LONG arg2, LONG arg3)
{
	LRESULT rc = (LRESULT)-1;
	WIN32API_ENTER("LRESULT", "SendDriverMessage", "HDRVR", arg0, "UINT", arg1, "LONG", arg2, "LONG", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
auxGetDevCapsW
(UINT arg0, LPAUXCAPSW arg1, UINT arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "auxGetDevCapsW", "UINT", arg0, "LPAUXCAPSW", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
auxOutMessage
(UINT arg0, UINT arg1, DWORD arg2, DWORD arg3)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "auxOutMessage", "UINT", arg0, "UINT", arg1, "DWORD", arg2, "DWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
joyGetDevCapsA
(UINT arg0, LPJOYCAPSA arg1, UINT arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "joyGetDevCapsA", "UINT", arg0, "LPJOYCAPSA", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
joyGetDevCapsW
(UINT arg0, LPJOYCAPSW arg1, UINT arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "joyGetDevCapsW", "UINT", arg0, "LPJOYCAPSW", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
joyGetNumDevs
(void)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "joyGetNumDevs", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
joyGetPos
(UINT arg0, LPJOYINFO arg1)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "joyGetPos", "UINT", arg0, "LPJOYINFO", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
joyGetPosEx
(UINT arg0, LPJOYINFOEX arg1)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "joyGetPosEx", "UINT", arg0, "LPJOYINFOEX", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
joyGetThreshold
(UINT arg0, LPUINT arg1)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "joyGetThreshold", "UINT", arg0, "LPUINT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
joyReleaseCapture
(UINT arg0)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "joyReleaseCapture", "UINT", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
joySetCapture
(HWND arg0, UINT arg1, UINT arg2, BOOL arg3)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "joySetCapture", "HWND", arg0, "UINT", arg1, "UINT", arg2, "BOOL", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
joySetThreshold
(UINT arg0, UINT arg1)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "joySetThreshold", "UINT", arg0, "UINT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
midiConnect
(HMIDI arg0, HMIDIOUT arg1, PVOID arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "midiConnect", "HMIDI", arg0, "HMIDIOUT", arg1, "PVOID", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
midiDisconnect
(HMIDI arg0, HMIDIOUT arg1, PVOID arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "midiDisconnect", "HMIDI", arg0, "HMIDIOUT", arg1, "PVOID", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
midiInAddBuffer
(HMIDIIN arg0, LPMIDIHDR arg1, UINT arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "midiInAddBuffer", "HMIDIIN", arg0, "LPMIDIHDR", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
midiInClose
(HMIDIIN arg0)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "midiInClose", "HMIDIIN", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
midiInGetDevCapsA
(UINT arg0, LPMIDIINCAPSA arg1, UINT arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "midiInGetDevCapsA", "UINT", arg0, "LPMIDIINCAPSA", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
midiInGetDevCapsW
(UINT arg0, LPMIDIINCAPSW arg1, UINT arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "midiInGetDevCapsW", "UINT", arg0, "LPMIDIINCAPSW", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
midiInGetErrorTextA
(MMRESULT arg0, LPSTR arg1, UINT arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "midiInGetErrorTextA", "MMRESULT", arg0, "LPSTR", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
midiInGetErrorTextW
(MMRESULT arg0, LPWSTR arg1, UINT arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "midiInGetErrorTextW", "MMRESULT", arg0, "LPWSTR", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
midiInGetID
(HMIDIIN arg0, LPUINT arg1)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "midiInGetID", "HMIDIIN", arg0, "LPUINT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
midiInGetNumDevs
(void)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "midiInGetNumDevs", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
midiInMessage
(HMIDIIN arg0, UINT arg1, DWORD arg2, DWORD arg3)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "midiInMessage", "HMIDIIN", arg0, "UINT", arg1, "DWORD", arg2, "DWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
midiInOpen
(LPHMIDIIN arg0, UINT arg1, DWORD arg2, DWORD arg3, DWORD arg4)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "midiInOpen", "LPHMIDIIN", arg0, "UINT", arg1, "DWORD", arg2, "DWORD", arg3, "DWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
midiInPrepareHeader
(HMIDIIN arg0, LPMIDIHDR arg1, UINT arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "midiInPrepareHeader", "HMIDIIN", arg0, "LPMIDIHDR", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
midiInReset
(HMIDIIN arg0)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "midiInReset", "HMIDIIN", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
midiInStart
(HMIDIIN arg0)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "midiInStart", "HMIDIIN", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
midiInStop
(HMIDIIN arg0)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "midiInStop", "HMIDIIN", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
midiInUnprepareHeader
(HMIDIIN arg0, LPMIDIHDR arg1, UINT arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "midiInUnprepareHeader", "HMIDIIN", arg0, "LPMIDIHDR", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
midiOutCacheDrumPatches
(HMIDIOUT arg0, UINT arg1, LPWORD arg2, UINT arg3)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "midiOutCacheDrumPatches", "HMIDIOUT", arg0, "UINT", arg1, "LPWORD", arg2, "UINT", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
midiOutCachePatches
(HMIDIOUT arg0, UINT arg1, LPWORD arg2, UINT arg3)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "midiOutCachePatches", "HMIDIOUT", arg0, "UINT", arg1, "LPWORD", arg2, "UINT", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
midiOutClose
(HMIDIOUT arg0)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "midiOutClose", "HMIDIOUT", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
midiOutGetDevCapsA
(UINT arg0, LPMIDIOUTCAPSA arg1, UINT arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "midiOutGetDevCapsA", "UINT", arg0, "LPMIDIOUTCAPSA", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
midiOutGetDevCapsW
(UINT arg0, LPMIDIOUTCAPSW arg1, UINT arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "midiOutGetDevCapsW", "UINT", arg0, "LPMIDIOUTCAPSW", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
midiOutGetErrorTextA
(MMRESULT arg0, LPSTR arg1, UINT arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "midiOutGetErrorTextA", "MMRESULT", arg0, "LPSTR", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
midiOutGetErrorTextW
(MMRESULT arg0, LPWSTR arg1, UINT arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "midiOutGetErrorTextW", "MMRESULT", arg0, "LPWSTR", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
midiOutGetID
(HMIDIOUT arg0, LPUINT arg1)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "midiOutGetID", "HMIDIOUT", arg0, "LPUINT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
midiOutGetNumDevs
(void)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "midiOutGetNumDevs", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
midiOutGetVolume
(HMIDIOUT arg0, PDWORD arg1)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "midiOutGetVolume", "HMIDIOUT", arg0, "PDWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
midiOutLongMsg
(HMIDIOUT arg0, LPMIDIHDR arg1, UINT arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "midiOutLongMsg", "HMIDIOUT", arg0, "LPMIDIHDR", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
midiOutMessage
(HMIDIOUT arg0, UINT arg1, DWORD arg2, DWORD arg3)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "midiOutMessage", "HMIDIOUT", arg0, "UINT", arg1, "DWORD", arg2, "DWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
midiOutOpen
(LPHMIDIOUT arg0, UINT arg1, DWORD arg2, DWORD arg3, DWORD arg4)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "midiOutOpen", "LPHMIDIOUT", arg0, "UINT", arg1, "DWORD", arg2, "DWORD", arg3, "DWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
midiOutPrepareHeader
(HMIDIOUT arg0, LPMIDIHDR arg1, UINT arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "midiOutPrepareHeader", "HMIDIOUT", arg0, "LPMIDIHDR", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
midiOutReset
(HMIDIOUT arg0)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "midiOutReset", "HMIDIOUT", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
midiOutSetVolume
(HMIDIOUT arg0, DWORD arg1)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "midiOutSetVolume", "HMIDIOUT", arg0, "DWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
midiOutShortMsg
(HMIDIOUT arg0, DWORD arg1)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "midiOutShortMsg", "HMIDIOUT", arg0, "DWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
midiOutUnprepareHeader
(HMIDIOUT arg0, LPMIDIHDR arg1, UINT arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "midiOutUnprepareHeader", "HMIDIOUT", arg0, "LPMIDIHDR", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
midiStreamClose
(HMIDISTRM arg0)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "midiStreamClose", "HMIDISTRM", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
midiStreamOpen
(LPHMIDISTRM arg0, LPUINT arg1, DWORD arg2, DWORD arg3, DWORD arg4, DWORD arg5)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "midiStreamOpen", "LPHMIDISTRM", arg0, "LPUINT", arg1, "DWORD", arg2, "DWORD", arg3, "DWORD", arg4, "DWORD", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
midiStreamOut
(HMIDISTRM arg0, LPMIDIHDR arg1, UINT arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "midiStreamOut", "HMIDISTRM", arg0, "LPMIDIHDR", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
midiStreamPause
(HMIDISTRM arg0)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "midiStreamPause", "HMIDISTRM", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
midiStreamPosition
(HMIDISTRM arg0, LPMMTIME arg1, UINT arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "midiStreamPosition", "HMIDISTRM", arg0, "LPMMTIME", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
midiStreamProperty
(HMIDISTRM arg0, LPBYTE arg1, DWORD arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "midiStreamProperty", "HMIDISTRM", arg0, "LPBYTE", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
midiStreamRestart
(HMIDISTRM arg0)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "midiStreamRestart", "HMIDISTRM", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
midiStreamStop
(HMIDISTRM arg0)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "midiStreamStop", "HMIDISTRM", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
mixerClose
(HMIXER arg0)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "mixerClose", "HMIXER", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
mixerGetControlDetailsA
(HMIXEROBJ arg0, LPMIXERCONTROLDETAILS arg1, DWORD arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "mixerGetControlDetailsA", "HMIXEROBJ", arg0, "LPMIXERCONTROLDETAILS", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
mixerGetControlDetailsW
(HMIXEROBJ arg0, LPMIXERCONTROLDETAILS arg1, DWORD arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "mixerGetControlDetailsW", "HMIXEROBJ", arg0, "LPMIXERCONTROLDETAILS", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
mixerGetDevCapsA
(UINT arg0, LPMIXERCAPSA arg1, UINT arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "mixerGetDevCapsA", "UINT", arg0, "LPMIXERCAPSA", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
mixerGetDevCapsW
(UINT arg0, LPMIXERCAPSW arg1, UINT arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "mixerGetDevCapsW", "UINT", arg0, "LPMIXERCAPSW", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
mixerGetID
(HMIXEROBJ arg0, PUINT arg1, DWORD arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "mixerGetID", "HMIXEROBJ", arg0, "PUINT", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
mixerGetLineControlsA
(HMIXEROBJ arg0, LPMIXERLINECONTROLSA arg1, DWORD arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "mixerGetLineControlsA", "HMIXEROBJ", arg0, "LPMIXERLINECONTROLSA", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
mixerGetLineControlsW
(HMIXEROBJ arg0, LPMIXERLINECONTROLSW arg1, DWORD arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "mixerGetLineControlsW", "HMIXEROBJ", arg0, "LPMIXERLINECONTROLSW", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
mixerGetLineInfoA
(HMIXEROBJ arg0, LPMIXERLINEA arg1, DWORD arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "mixerGetLineInfoA", "HMIXEROBJ", arg0, "LPMIXERLINEA", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
mixerGetLineInfoW
(HMIXEROBJ arg0, LPMIXERLINEW arg1, DWORD arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "mixerGetLineInfoW", "HMIXEROBJ", arg0, "LPMIXERLINEW", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
mixerGetNumDevs
(void)
{
	UINT rc = (UINT)0;
	WIN32API_ENTER("UINT", "mixerGetNumDevs", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
mixerMessage
(HMIXER arg0, UINT arg1, DWORD arg2, DWORD arg3)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "mixerMessage", "HMIXER", arg0, "UINT", arg1, "DWORD", arg2, "DWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
mixerOpen
(LPHMIXER arg0, UINT arg1, DWORD arg2, DWORD arg3, DWORD arg4)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "mixerOpen", "LPHMIXER", arg0, "UINT", arg1, "DWORD", arg2, "DWORD", arg3, "DWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
mixerSetControlDetails
(HMIXEROBJ arg0, LPMIXERCONTROLDETAILS arg1, DWORD arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "mixerSetControlDetails", "HMIXEROBJ", arg0, "LPMIXERCONTROLDETAILS", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
mmioAdvance
(HMMIO arg0, LPMMIOINFO arg1, UINT arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "mmioAdvance", "HMMIO", arg0, "LPMMIOINFO", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
mmioAscend
(HMMIO arg0, LPMMCKINFO arg1, UINT arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "mmioAscend", "HMMIO", arg0, "LPMMCKINFO", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
mmioClose
(HMMIO arg0, UINT arg1)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "mmioClose", "HMMIO", arg0, "UINT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
mmioCreateChunk
(HMMIO arg0, LPMMCKINFO arg1, UINT arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "mmioCreateChunk", "HMMIO", arg0, "LPMMCKINFO", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
mmioDescend
(HMMIO arg0, LPMMCKINFO arg1, const MMCKINFO* arg2, UINT arg3)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "mmioDescend", "HMMIO", arg0, "LPMMCKINFO", arg1, "const MMCKINFO*", arg2, "UINT", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
mmioFlush
(HMMIO arg0, UINT arg1)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "mmioFlush", "HMMIO", arg0, "UINT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
mmioGetInfo
(HMMIO arg0, LPMMIOINFO arg1, UINT arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "mmioGetInfo", "HMMIO", arg0, "LPMMIOINFO", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LPMMIOPROC WINAPI
mmioInstallIOProcA
(FOURCC arg0, LPMMIOPROC arg1, DWORD arg2)
{
	LPMMIOPROC rc = (LPMMIOPROC)NULL;
	WIN32API_ENTER("LPMMIOPROC", "mmioInstallIOProcA", "FOURCC", arg0, "LPMMIOPROC", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LPMMIOPROC WINAPI
mmioInstallIOProcW
(FOURCC arg0, LPMMIOPROC arg1, DWORD arg2)
{
	LPMMIOPROC rc = (LPMMIOPROC)NULL;
	WIN32API_ENTER("LPMMIOPROC", "mmioInstallIOProcW", "FOURCC", arg0, "LPMMIOPROC", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HMMIO WINAPI
mmioOpenA
(LPSTR arg0, LPMMIOINFO arg1, DWORD arg2)
{
	HMMIO rc = (HMMIO)INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HMMIO", "mmioOpenA", "LPSTR", arg0, "LPMMIOINFO", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HMMIO WINAPI
mmioOpenW
(LPWSTR arg0, LPMMIOINFO arg1, DWORD arg2)
{
	HMMIO rc = (HMMIO)INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HMMIO", "mmioOpenW", "LPWSTR", arg0, "LPMMIOINFO", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
mmioRead
(HMMIO arg0, HPSTR arg1, LONG arg2)
{
	LONG rc = (LONG)-1;
	WIN32API_ENTER("LONG", "mmioRead", "HMMIO", arg0, "HPSTR", arg1, "LONG", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
mmioRenameA
(LPCSTR arg0, LPCSTR arg1, LPCMMIOINFO arg2, DWORD arg3)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "mmioRenameA", "LPCSTR", arg0, "LPCSTR", arg1, "LPCMMIOINFO", arg2, "DWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
mmioRenameW
(LPCWSTR arg0, LPCWSTR arg1, LPCMMIOINFO arg2, DWORD arg3)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "mmioRenameW", "LPCWSTR", arg0, "LPCWSTR", arg1, "LPCMMIOINFO", arg2, "DWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
mmioSeek
(HMMIO arg0, LONG arg1, int arg2)
{
	LONG rc = (LONG)-1;
	WIN32API_ENTER("LONG", "mmioSeek", "HMMIO", arg0, "LONG", arg1, "int", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LRESULT WINAPI
mmioSendMessage
(HMMIO arg0, UINT arg1, LPARAM arg2, LPARAM arg3)
{
	LRESULT rc = (LRESULT)-1;
	WIN32API_ENTER("LRESULT", "mmioSendMessage", "HMMIO", arg0, "UINT", arg1, "LPARAM", arg2, "LPARAM", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
mmioSetBuffer
(HMMIO arg0, LPSTR arg1, LONG arg2, UINT arg3)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "mmioSetBuffer", "HMMIO", arg0, "LPSTR", arg1, "LONG", arg2, "UINT", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
mmioSetInfo
(HMMIO arg0, LPCMMIOINFO arg1, UINT arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "mmioSetInfo", "HMMIO", arg0, "LPCMMIOINFO", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" FOURCC WINAPI
mmioStringToFOURCCA
(LPCSTR arg0, UINT arg1)
{
	FOURCC rc = (FOURCC)-1;
	WIN32API_ENTER("FOURCC", "mmioStringToFOURCCA", "LPCSTR", arg0, "UINT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" FOURCC WINAPI
mmioStringToFOURCCW
(LPCWSTR arg0, UINT arg1)
{
	FOURCC rc = (FOURCC)-1;
	WIN32API_ENTER("FOURCC", "mmioStringToFOURCCW", "LPCWSTR", arg0, "UINT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
mmioWrite
(HMMIO arg0, LPCSTR arg1, LONG arg2)
{
	LONG rc = (LONG)-1;
	WIN32API_ENTER("LONG", "mmioWrite", "HMMIO", arg0, "LPCSTR", arg1, "LONG", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
mmsystemGetVersion
(void)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "mmsystemGetVersion", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
sndPlaySoundA
(LPCSTR arg0, UINT arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "sndPlaySoundA", "LPCSTR", arg0, "UINT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
sndPlaySoundW
(LPCWSTR arg0, UINT arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "sndPlaySoundW", "LPCWSTR", arg0, "UINT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
timeBeginPeriod
(UINT arg0)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "timeBeginPeriod", "UINT", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
timeEndPeriod
(UINT arg0)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "timeEndPeriod", "UINT", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
timeGetDevCaps
(LPTIMECAPS arg0, UINT arg1)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "timeGetDevCaps", "LPTIMECAPS", arg0, "UINT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
timeGetTime
(void)
{
	DWORD rc = system_time() / 1000;
	WIN32API_ENTER("DWORD", "timeGetTime", "void", 0, NULL);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
timeKillEvent
(UINT arg0)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "timeKillEvent", "UINT", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
timeSetEvent
(UINT arg0, UINT arg1, LPTIMECALLBACK arg2, DWORD arg3, UINT arg4)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "timeSetEvent", "UINT", arg0, "UINT", arg1, "LPTIMECALLBACK", arg2, "DWORD", arg3, "UINT", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
waveInAddBuffer
(HWAVEIN arg0, LPWAVEHDR arg1, UINT arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "waveInAddBuffer", "HWAVEIN", arg0, "LPWAVEHDR", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
waveInClose
(HWAVEIN arg0)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "waveInClose", "HWAVEIN", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
waveInGetDevCapsA
(UINT arg0, LPWAVEINCAPSA arg1, UINT arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "waveInGetDevCapsA", "UINT", arg0, "LPWAVEINCAPSA", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
waveInGetDevCapsW
(UINT arg0, LPWAVEINCAPSW arg1, UINT arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "waveInGetDevCapsW", "UINT", arg0, "LPWAVEINCAPSW", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
waveInGetErrorTextA
(MMRESULT arg0, LPSTR arg1, UINT arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "waveInGetErrorTextA", "MMRESULT", arg0, "LPSTR", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
waveInGetErrorTextW
(MMRESULT arg0, LPWSTR arg1, UINT arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "waveInGetErrorTextW", "MMRESULT", arg0, "LPWSTR", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
waveInGetID
(HWAVEIN arg0, LPUINT arg1)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "waveInGetID", "HWAVEIN", arg0, "LPUINT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
waveInGetNumDevs
(void)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "waveInGetNumDevs", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
waveInGetPosition
(HWAVEIN arg0, LPMMTIME arg1, UINT arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "waveInGetPosition", "HWAVEIN", arg0, "LPMMTIME", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
waveInMessage
(HWAVEIN arg0, UINT arg1, DWORD arg2, DWORD arg3)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "waveInMessage", "HWAVEIN", arg0, "UINT", arg1, "DWORD", arg2, "DWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
waveInOpen
(LPHWAVEIN arg0, UINT arg1, LPCWAVEFORMATEX arg2, DWORD arg3, DWORD arg4, DWORD arg5)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "waveInOpen", "LPHWAVEIN", arg0, "UINT", arg1, "LPCWAVEFORMATEX", arg2, "DWORD", arg3, "DWORD", arg4, "DWORD", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
waveInPrepareHeader
(HWAVEIN arg0, LPWAVEHDR arg1, UINT arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "waveInPrepareHeader", "HWAVEIN", arg0, "LPWAVEHDR", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
waveInReset
(HWAVEIN arg0)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "waveInReset", "HWAVEIN", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
waveInStart
(HWAVEIN arg0)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "waveInStart", "HWAVEIN", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
waveInStop
(HWAVEIN arg0)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "waveInStop", "HWAVEIN", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
waveInUnprepareHeader
(HWAVEIN arg0, LPWAVEHDR arg1, UINT arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "waveInUnprepareHeader", "HWAVEIN", arg0, "LPWAVEHDR", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
waveOutBreakLoop
(HWAVEOUT arg0)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "waveOutBreakLoop", "HWAVEOUT", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
waveOutGetDevCapsA
(UINT arg0, LPWAVEOUTCAPSA arg1, UINT arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "waveOutGetDevCapsA", "UINT", arg0, "LPWAVEOUTCAPSA", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
waveOutGetDevCapsW
(UINT arg0, LPWAVEOUTCAPSW arg1, UINT arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "waveOutGetDevCapsW", "UINT", arg0, "LPWAVEOUTCAPSW", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
waveOutGetErrorTextA
(MMRESULT arg0, LPSTR arg1, UINT arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "waveOutGetErrorTextA", "MMRESULT", arg0, "LPSTR", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
waveOutGetErrorTextW
(MMRESULT arg0, LPWSTR arg1, UINT arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "waveOutGetErrorTextW", "MMRESULT", arg0, "LPWSTR", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
waveOutGetID
(HWAVEOUT arg0, LPUINT arg1)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "waveOutGetID", "HWAVEOUT", arg0, "LPUINT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
waveOutGetNumDevs
(void)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "waveOutGetNumDevs", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
waveOutGetPitch
(HWAVEOUT arg0, PDWORD arg1)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "waveOutGetPitch", "HWAVEOUT", arg0, "PDWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
waveOutGetPlaybackRate
(HWAVEOUT arg0, PDWORD arg1)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "waveOutGetPlaybackRate", "HWAVEOUT", arg0, "PDWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
waveOutGetPosition
(HWAVEOUT arg0, LPMMTIME arg1, UINT arg2)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "waveOutGetPosition", "HWAVEOUT", arg0, "LPMMTIME", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
waveOutGetVolume
(HWAVEOUT arg0, PDWORD arg1)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "waveOutGetVolume", "HWAVEOUT", arg0, "PDWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
waveOutMessage
(HWAVEOUT arg0, UINT arg1, DWORD arg2, DWORD arg3)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "waveOutMessage", "HWAVEOUT", arg0, "UINT", arg1, "DWORD", arg2, "DWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
waveOutPause
(HWAVEOUT arg0)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "waveOutPause", "HWAVEOUT", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
waveOutRestart
(HWAVEOUT arg0)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "waveOutRestart", "HWAVEOUT", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
waveOutSetPitch
(HWAVEOUT arg0, DWORD arg1)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "waveOutSetPitch", "HWAVEOUT", arg0, "DWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
waveOutSetPlaybackRate
(HWAVEOUT arg0, DWORD arg1)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "waveOutSetPlaybackRate", "HWAVEOUT", arg0, "DWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" MMRESULT WINAPI
waveOutSetVolume
(HWAVEOUT arg0, DWORD arg1)
{
	MMRESULT rc = (MMRESULT)-1;
	WIN32API_ENTER("MMRESULT", "waveOutSetVolume", "HWAVEOUT", arg0, "DWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

#if defined(_BUILTIN_DLL)

#	define	GetAddressByOrder	WinMM_GetAddressByOrder
#	define	GetAddressByName	WinMM_GetAddressByName

#	include "WinMM/GetAddressByOrder.h"
#	include "WinMM/GetAddressByName.h"

#endif	// defined(_BUILTIN_DLL)
