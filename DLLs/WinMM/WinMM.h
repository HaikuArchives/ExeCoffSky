/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 �Ƃ悵��
 *  $Id: WinMM.h,v 1.1 2003/05/01 06:06:00 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [WinMM.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__WinMM_h__)
#	define	__WinMM_h__

#	if defined(__cplusplus)
#		if !defined(__Common_h__)
#			include "Common.h"
#		endif	// !defined(__Common_h__)
extern "C" {
#	endif	// defined(__cplusplus)

#	if !defined(__Win32Structures_h__)
#		include "Win32Structures.h"
#	endif	// !defined(__Win32Structures_h__)

// MCI
HTASK WINAPI mciGetCreatorTask(MCIDEVICEID);
MCIDEVICEID WINAPI mciGetDeviceIDA(LPCSTR);
MCIDEVICEID WINAPI mciGetDeviceIDFromElementIDA(DWORD,LPCSTR);
MCIDEVICEID WINAPI mciGetDeviceIDFromElementIDW(DWORD,LPCWSTR);
MCIDEVICEID WINAPI mciGetDeviceIDW(LPCWSTR);
BOOL WINAPI mciGetErrorStringA(DWORD fdwError, LPTSTR lpszErrorText, UINT cchErrorText);
BOOL WINAPI mciGetErrorStringW(MCIERROR,LPWSTR,UINT);
YIELDPROC WINAPI mciGetYieldProc(MCIDEVICEID,PDWORD);
MCIERROR WINAPI mciSendCommandA(MCIDEVICEID IDDevice, UINT uMsg, DWORD fdwCommand, DWORD dwParam);
MCIERROR WINAPI mciSendCommandW(MCIDEVICEID,UINT,DWORD,DWORD);
MCIERROR WINAPI mciSendStringA(LPCSTR,LPSTR,UINT,HWND);
MCIERROR WINAPI mciSendStringW(LPCWSTR,LPWSTR,UINT,HWND);
BOOL WINAPI mciSetYieldProc(MCIDEVICEID,YIELDPROC,DWORD);

MMRESULT WINAPI waveOutReset(HWAVEOUT hwo);
MMRESULT WINAPI waveOutOpen(LPHWAVEOUT phwo, UINT uDeviceID, LPWAVEFORMATEX pwfx, DWORD dwCallback, DWORD dwCallbackInstance, DWORD fdwOpen);
MMRESULT WINAPI waveOutPrepareHeader(HWAVEOUT hwo, LPWAVEHDR pwh, UINT cbwh);
MMRESULT WINAPI waveOutWrite(HWAVEOUT hwo, LPWAVEHDR pwh, UINT cbwh);
MMRESULT WINAPI waveOutUnprepareHeader(HWAVEOUT hwo, LPWAVEHDR pwh, UINT cbwh);
MMRESULT WINAPI waveOutClose(HWAVEOUT hwo);
MMRESULT WINAPI timeGetSystemTime(LPMMTIME pmmt, UINT cbmmt);
MMRESULT WINAPI auxSetVolume(UINT uDeviceID, DWORD dwVolume);
UINT WINAPI auxGetNumDevs(VOID);
MMRESULT WINAPI auxGetDevCapsA(UINT uDeviceID, LPAUXCAPSA lpCaps, UINT cbCaps);
MMRESULT WINAPI auxGetVolume(UINT uDeviceID, LPDWORD lpdwVolume);
LRESULT WINAPI CloseDriver(HDRVR,LONG,LONG);
LRESULT WINAPI DefDriverProc(DWORD,HDRVR,UINT,LPARAM,LPARAM);
HMODULE WINAPI DrvGetModuleHandle(HDRVR);
HMODULE WINAPI GetDriverModuleHandle(HDRVR);
HDRVR WINAPI OpenDriver(LPCWSTR,LPCWSTR,LONG);
BOOL WINAPI PlaySoundA(LPCSTR,HMODULE,DWORD);
BOOL WINAPI PlaySoundW(LPCWSTR,HMODULE,DWORD);
LRESULT WINAPI SendDriverMessage(HDRVR,UINT,LONG,LONG);
UINT WINAPI auxGetNumDevs(void);
MMRESULT WINAPI auxGetVolume(UINT,PDWORD);
MMRESULT WINAPI auxOutMessage(UINT,UINT,DWORD,DWORD);
MMRESULT WINAPI auxSetVolume(UINT,DWORD);
MMRESULT WINAPI joyGetDevCapsA(UINT,LPJOYCAPSA,UINT);
MMRESULT WINAPI joyGetDevCapsW(UINT,LPJOYCAPSW,UINT);
UINT WINAPI joyGetNumDevs(void);
MMRESULT WINAPI joyGetPos(UINT,LPJOYINFO);
MMRESULT WINAPI joyGetPosEx(UINT,LPJOYINFOEX);
MMRESULT WINAPI joyGetThreshold(UINT,LPUINT);
MMRESULT WINAPI joyReleaseCapture(UINT);
MMRESULT WINAPI joySetCapture(HWND,UINT,UINT,BOOL);
MMRESULT WINAPI joySetThreshold(UINT,UINT);
MMRESULT WINAPI midiConnect(HMIDI,HMIDIOUT,PVOID);
MMRESULT WINAPI midiDisconnect(HMIDI,HMIDIOUT,PVOID);
MMRESULT WINAPI midiInAddBuffer(HMIDIIN,LPMIDIHDR,UINT);
MMRESULT WINAPI midiInClose(HMIDIIN);
MMRESULT WINAPI midiInGetDevCapsA(UINT,LPMIDIINCAPSA,UINT);
MMRESULT WINAPI midiInGetDevCapsW(UINT,LPMIDIINCAPSW,UINT);
MMRESULT WINAPI midiInGetErrorTextA(MMRESULT,LPSTR,UINT);
MMRESULT WINAPI midiInGetErrorTextW(MMRESULT,LPWSTR,UINT);
MMRESULT WINAPI midiInGetID(HMIDIIN,LPUINT);
UINT WINAPI midiInGetNumDevs(void);
MMRESULT WINAPI midiInMessage(HMIDIIN,UINT,DWORD,DWORD);
MMRESULT WINAPI midiInOpen(LPHMIDIIN,UINT,DWORD,DWORD,DWORD);
MMRESULT WINAPI midiInPrepareHeader(HMIDIIN,LPMIDIHDR,UINT);
MMRESULT WINAPI midiInReset(HMIDIIN);
MMRESULT WINAPI midiInStart(HMIDIIN);
MMRESULT WINAPI midiInStop(HMIDIIN);
MMRESULT WINAPI midiInUnprepareHeader(HMIDIIN,LPMIDIHDR,UINT);
MMRESULT WINAPI midiOutCacheDrumPatches(HMIDIOUT,UINT,LPWORD,UINT);
MMRESULT WINAPI midiOutCachePatches(HMIDIOUT,UINT,LPWORD,UINT);
MMRESULT WINAPI midiOutClose(HMIDIOUT);
MMRESULT WINAPI midiOutGetDevCapsA(UINT,LPMIDIOUTCAPSA,UINT);
MMRESULT WINAPI midiOutGetDevCapsW(UINT,LPMIDIOUTCAPSW,UINT);
MMRESULT WINAPI midiOutGetErrorTextA(MMRESULT,LPSTR,UINT);
MMRESULT WINAPI midiOutGetErrorTextW(MMRESULT,LPWSTR,UINT);
MMRESULT WINAPI midiOutGetID(HMIDIOUT,LPUINT);
UINT WINAPI midiOutGetNumDevs(void);
MMRESULT WINAPI midiOutGetVolume(HMIDIOUT,PDWORD);
MMRESULT WINAPI midiOutLongMsg(HMIDIOUT,LPMIDIHDR,UINT);
MMRESULT WINAPI midiOutMessage(HMIDIOUT,UINT,DWORD,DWORD);
MMRESULT WINAPI midiOutOpen(LPHMIDIOUT,UINT,DWORD,DWORD,DWORD);
MMRESULT WINAPI midiOutPrepareHeader(HMIDIOUT,LPMIDIHDR,UINT);
MMRESULT WINAPI midiOutReset(HMIDIOUT);
MMRESULT WINAPI midiOutSetVolume(HMIDIOUT,DWORD);
MMRESULT WINAPI midiOutShortMsg(HMIDIOUT,DWORD);
MMRESULT WINAPI midiOutUnprepareHeader(HMIDIOUT,LPMIDIHDR,UINT);
MMRESULT WINAPI midiStreamClose(HMIDISTRM);
MMRESULT WINAPI midiStreamOpen(LPHMIDISTRM,LPUINT,DWORD,DWORD,DWORD,DWORD);
MMRESULT WINAPI midiStreamOut(HMIDISTRM,LPMIDIHDR,UINT);
MMRESULT WINAPI midiStreamPause(HMIDISTRM);
MMRESULT WINAPI midiStreamPosition(HMIDISTRM,LPMMTIME,UINT);
MMRESULT WINAPI midiStreamProperty(HMIDISTRM,LPBYTE,DWORD);
MMRESULT WINAPI midiStreamRestart(HMIDISTRM);
MMRESULT WINAPI midiStreamStop(HMIDISTRM);
MMRESULT WINAPI mixerClose(HMIXER);
MMRESULT WINAPI mixerGetControlDetailsA(HMIXEROBJ,LPMIXERCONTROLDETAILS,DWORD);
MMRESULT WINAPI mixerGetControlDetailsW(HMIXEROBJ,LPMIXERCONTROLDETAILS,DWORD);
MMRESULT WINAPI mixerGetDevCapsA(UINT,LPMIXERCAPSA,UINT);
MMRESULT WINAPI mixerGetDevCapsW(UINT,LPMIXERCAPSW,UINT);
MMRESULT WINAPI mixerGetID(HMIXEROBJ,PUINT,DWORD);
MMRESULT WINAPI mixerGetLineControlsA(HMIXEROBJ,LPMIXERLINECONTROLSA,DWORD);
MMRESULT WINAPI mixerGetLineControlsW(HMIXEROBJ,LPMIXERLINECONTROLSW,DWORD);
MMRESULT WINAPI mixerGetLineInfoA(HMIXEROBJ,LPMIXERLINEA,DWORD);
MMRESULT WINAPI mixerGetLineInfoW(HMIXEROBJ,LPMIXERLINEW,DWORD);
UINT WINAPI mixerGetNumDevs(void);
DWORD WINAPI mixerMessage(HMIXER,UINT,DWORD,DWORD);
MMRESULT WINAPI mixerOpen(LPHMIXER,UINT,DWORD,DWORD,DWORD);
MMRESULT WINAPI mixerSetControlDetails(HMIXEROBJ,LPMIXERCONTROLDETAILS,DWORD);
MMRESULT WINAPI mmioAdvance(HMMIO,LPMMIOINFO,UINT);
MMRESULT WINAPI mmioAscend(HMMIO,LPMMCKINFO,UINT);
MMRESULT WINAPI mmioClose(HMMIO,UINT);
MMRESULT WINAPI mmioCreateChunk(HMMIO,LPMMCKINFO,UINT);
MMRESULT WINAPI mmioDescend(HMMIO,LPMMCKINFO,const MMCKINFO*,UINT);
MMRESULT WINAPI mmioFlush(HMMIO,UINT);
MMRESULT WINAPI mmioGetInfo(HMMIO,LPMMIOINFO,UINT);
LPMMIOPROC WINAPI mmioInstallIOProcA(FOURCC,LPMMIOPROC,DWORD);
LPMMIOPROC WINAPI mmioInstallIOProcW(FOURCC,LPMMIOPROC,DWORD);
HMMIO WINAPI mmioOpenA(LPSTR,LPMMIOINFO,DWORD);
HMMIO WINAPI mmioOpenW(LPWSTR,LPMMIOINFO,DWORD);
LONG WINAPI mmioRead(HMMIO,HPSTR,LONG);
MMRESULT WINAPI mmioRenameA(LPCSTR,LPCSTR,LPCMMIOINFO,DWORD);
MMRESULT WINAPI mmioRenameW(LPCWSTR,LPCWSTR,LPCMMIOINFO,DWORD);
LONG WINAPI mmioSeek(HMMIO,LONG,int);
LRESULT WINAPI mmioSendMessage(HMMIO,UINT,LPARAM,LPARAM);
MMRESULT WINAPI mmioSetBuffer(HMMIO,LPSTR,LONG,UINT);
MMRESULT WINAPI mmioSetInfo(HMMIO,LPCMMIOINFO,UINT);
FOURCC WINAPI mmioStringToFOURCCA(LPCSTR,UINT);
FOURCC WINAPI mmioStringToFOURCCW(LPCWSTR,UINT);
LONG WINAPI mmioWrite(HMMIO,LPCSTR,LONG);
UINT WINAPI mmsystemGetVersion(void);
BOOL WINAPI sndPlaySoundA(LPCSTR,UINT);
BOOL WINAPI sndPlaySoundW(LPCWSTR,UINT);
MMRESULT WINAPI timeBeginPeriod(UINT);
MMRESULT WINAPI timeEndPeriod(UINT);
MMRESULT WINAPI timeGetDevCaps(LPTIMECAPS,UINT);
MMRESULT WINAPI timeGetSystemTime(LPMMTIME,UINT);
DWORD WINAPI timeGetTime(void);
MMRESULT WINAPI timeKillEvent(UINT);
MMRESULT WINAPI timeSetEvent(UINT,UINT,LPTIMECALLBACK,DWORD,UINT);
MMRESULT WINAPI waveInAddBuffer(HWAVEIN,LPWAVEHDR,UINT);
MMRESULT WINAPI waveInClose(HWAVEIN);
MMRESULT WINAPI waveInGetDevCapsA(UINT,LPWAVEINCAPSA,UINT);
MMRESULT WINAPI waveInGetDevCapsW(UINT,LPWAVEINCAPSW,UINT);
MMRESULT WINAPI waveInGetErrorTextA(MMRESULT,LPSTR,UINT);
MMRESULT WINAPI waveInGetErrorTextW(MMRESULT,LPWSTR,UINT);
MMRESULT WINAPI waveInGetID(HWAVEIN,LPUINT);
UINT WINAPI waveInGetNumDevs(void);
MMRESULT WINAPI waveInGetPosition(HWAVEIN,LPMMTIME,UINT);
MMRESULT WINAPI waveInMessage(HWAVEIN,UINT,DWORD,DWORD);
MMRESULT WINAPI waveInOpen(LPHWAVEIN,UINT,LPCWAVEFORMATEX,DWORD,DWORD,DWORD);
MMRESULT WINAPI waveInPrepareHeader(HWAVEIN,LPWAVEHDR,UINT);
MMRESULT WINAPI waveInReset(HWAVEIN);
MMRESULT WINAPI waveInStart(HWAVEIN);
MMRESULT WINAPI waveInStop(HWAVEIN);
MMRESULT WINAPI waveInUnprepareHeader(HWAVEIN,LPWAVEHDR,UINT);
MMRESULT WINAPI waveOutBreakLoop(HWAVEOUT);
MMRESULT WINAPI waveOutClose(HWAVEOUT);
MMRESULT WINAPI waveOutGetDevCapsA(UINT,LPWAVEOUTCAPSA,UINT);
MMRESULT WINAPI waveOutGetDevCapsW(UINT,LPWAVEOUTCAPSW,UINT);
MMRESULT WINAPI waveOutGetErrorTextA(MMRESULT,LPSTR,UINT);
MMRESULT WINAPI waveOutGetErrorTextW(MMRESULT,LPWSTR,UINT);
MMRESULT WINAPI waveOutGetID(HWAVEOUT,LPUINT);
UINT WINAPI waveOutGetNumDevs(void);
MMRESULT WINAPI waveOutGetPitch(HWAVEOUT,PDWORD);
MMRESULT WINAPI waveOutGetPlaybackRate(HWAVEOUT,PDWORD);
MMRESULT WINAPI waveOutGetPosition(HWAVEOUT,LPMMTIME,UINT);
MMRESULT WINAPI waveOutGetVolume(HWAVEOUT,PDWORD);
MMRESULT WINAPI waveOutMessage(HWAVEOUT,UINT,DWORD,DWORD);
MMRESULT WINAPI waveOutPause(HWAVEOUT);
MMRESULT WINAPI waveOutPrepareHeader(HWAVEOUT,LPWAVEHDR,UINT);
MMRESULT WINAPI waveOutReset(HWAVEOUT);
MMRESULT WINAPI waveOutRestart(HWAVEOUT);
MMRESULT WINAPI waveOutSetPitch(HWAVEOUT,DWORD);
MMRESULT WINAPI waveOutSetPlaybackRate(HWAVEOUT,DWORD);
MMRESULT WINAPI waveOutSetVolume(HWAVEOUT,DWORD);
MMRESULT WINAPI waveOutUnprepareHeader(HWAVEOUT,LPWAVEHDR,UINT);
MMRESULT WINAPI waveOutWrite(HWAVEOUT,LPWAVEHDR,UINT);

#	if defined(_BUILTIN_DLL)
void *WinMM_GetAddressByOrder(int order);
void *WinMM_GetAddressByName(const char *name);
#	endif	// defined(_BUILTIN_DLL)

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__WinMM_h__)
