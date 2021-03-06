void *
GetAddressByOrder
(int order)
{
	switch (order) {
	case 2:		return (void *)PlaySoundA;
	case 3:		return (void *)CloseDriver;
	case 4:		return (void *)DefDriverProc;
//	case 5:		return (void *)DriverCallback;
	case 6:		return (void *)DrvGetModuleHandle;
	case 7:		return (void *)GetDriverModuleHandle;
//	case 8:		return (void *)MigrateAllDrivers;
//	case 9:		return (void *)MigrateMidiUser;
//	case 10:	return (void *)MigrateSoundEvents;
//	case 11:	return (void *)NotifyCallbackData;
	case 12:	return (void *)OpenDriver;
//	case 13:	return (void *)PlaySound;
	case 14:	return (void *)PlaySoundA;
	case 15:	return (void *)PlaySoundW;
	case 16:	return (void *)SendDriverMessage;
//	case 17:	return (void *)WOW32DriverCallback;
//	case 18:	return (void *)WOW32ResolveMultiMediaHandle;
//	case 19:	return (void *)WOWAppExit;
//	case 20:	return (void *)WinmmLogoff;
//	case 21:	return (void *)WinmmLogon;
//	case 22:	return (void *)aux32Message;
	case 23:	return (void *)auxGetDevCapsA;
	case 24:	return (void *)auxGetDevCapsW;
	case 25:	return (void *)auxGetNumDevs;
	case 26:	return (void *)auxGetVolume;
	case 27:	return (void *)auxOutMessage;
	case 28:	return (void *)auxSetVolume;
//	case 29:	return (void *)joy32Message;
//	case 30:	return (void *)joyConfigChanged;
	case 31:	return (void *)joyGetDevCapsA;
	case 32:	return (void *)joyGetDevCapsW;
	case 33:	return (void *)joyGetNumDevs;
	case 34:	return (void *)joyGetPos;
	case 35:	return (void *)joyGetPosEx;
	case 36:	return (void *)joyGetThreshold;
	case 37:	return (void *)joyReleaseCapture;
	case 38:	return (void *)joySetCapture;
	case 39:	return (void *)joySetThreshold;
//	case 40:	return (void *)mci32Message;
//	case 41:	return (void *)mciDriverNotify;
//	case 42:	return (void *)mciDriverYield;
//	case 43:	return (void *)mciExecute;
//	case 44:	return (void *)mciFreeCommandResource;
	case 45:	return (void *)mciGetCreatorTask;
	case 46:	return (void *)mciGetDeviceIDA;
	case 47:	return (void *)mciGetDeviceIDFromElementIDA;
	case 48:	return (void *)mciGetDeviceIDFromElementIDW;
	case 49:	return (void *)mciGetDeviceIDW;
//	case 50:	return (void *)mciGetDriverData;
	case 51:	return (void *)mciGetErrorStringA;
	case 52:	return (void *)mciGetErrorStringW;
	case 53:	return (void *)mciGetYieldProc;
//	case 54:	return (void *)mciLoadCommandResource;
	case 55:	return (void *)mciSendCommandA;
	case 56:	return (void *)mciSendCommandW;
	case 57:	return (void *)mciSendStringA;
	case 58:	return (void *)mciSendStringW;
//	case 59:	return (void *)mciSetDriverData;
	case 60:	return (void *)mciSetYieldProc;
//	case 61:	return (void *)mid32Message;
	case 62:	return (void *)midiConnect;
	case 63:	return (void *)midiDisconnect;
	case 64:	return (void *)midiInAddBuffer;
	case 65:	return (void *)midiInClose;
	case 66:	return (void *)midiInGetDevCapsA;
	case 67:	return (void *)midiInGetDevCapsW;
	case 68:	return (void *)midiInGetErrorTextA;
	case 69:	return (void *)midiInGetErrorTextW;
	case 70:	return (void *)midiInGetID;
	case 71:	return (void *)midiInGetNumDevs;
	case 72:	return (void *)midiInMessage;
	case 73:	return (void *)midiInOpen;
	case 74:	return (void *)midiInPrepareHeader;
	case 75:	return (void *)midiInReset;
	case 76:	return (void *)midiInStart;
	case 77:	return (void *)midiInStop;
	case 78:	return (void *)midiInUnprepareHeader;
	case 79:	return (void *)midiOutCacheDrumPatches;
	case 80:	return (void *)midiOutCachePatches;
	case 81:	return (void *)midiOutClose;
	case 82:	return (void *)midiOutGetDevCapsA;
	case 83:	return (void *)midiOutGetDevCapsW;
	case 84:	return (void *)midiOutGetErrorTextA;
	case 85:	return (void *)midiOutGetErrorTextW;
	case 86:	return (void *)midiOutGetID;
	case 87:	return (void *)midiOutGetNumDevs;
	case 88:	return (void *)midiOutGetVolume;
	case 89:	return (void *)midiOutLongMsg;
	case 90:	return (void *)midiOutMessage;
	case 91:	return (void *)midiOutOpen;
	case 92:	return (void *)midiOutPrepareHeader;
	case 93:	return (void *)midiOutReset;
	case 94:	return (void *)midiOutSetVolume;
	case 95:	return (void *)midiOutShortMsg;
	case 96:	return (void *)midiOutUnprepareHeader;
	case 97:	return (void *)midiStreamClose;
	case 98:	return (void *)midiStreamOpen;
	case 99:	return (void *)midiStreamOut;
	case 100:	return (void *)midiStreamPause;
	case 101:	return (void *)midiStreamPosition;
	case 102:	return (void *)midiStreamProperty;
	case 103:	return (void *)midiStreamRestart;
	case 104:	return (void *)midiStreamStop;
	case 105:	return (void *)mixerClose;
	case 106:	return (void *)mixerGetControlDetailsA;
	case 107:	return (void *)mixerGetControlDetailsW;
	case 108:	return (void *)mixerGetDevCapsA;
	case 109:	return (void *)mixerGetDevCapsW;
	case 110:	return (void *)mixerGetID;
	case 111:	return (void *)mixerGetLineControlsA;
	case 112:	return (void *)mixerGetLineControlsW;
	case 113:	return (void *)mixerGetLineInfoA;
	case 114:	return (void *)mixerGetLineInfoW;
	case 115:	return (void *)mixerGetNumDevs;
	case 116:	return (void *)mixerMessage;
	case 117:	return (void *)mixerOpen;
	case 118:	return (void *)mixerSetControlDetails;
//	case 119:	return (void *)mmDrvInstall;
//	case 120:	return (void *)mmGetCurrentTask;
//	case 121:	return (void *)mmTaskBlock;
//	case 122:	return (void *)mmTaskCreate;
//	case 123:	return (void *)mmTaskSignal;
//	case 124:	return (void *)mmTaskYield;
	case 125:	return (void *)mmioAdvance;
	case 126:	return (void *)mmioAscend;
	case 127:	return (void *)mmioClose;
	case 128:	return (void *)mmioCreateChunk;
	case 129:	return (void *)mmioDescend;
	case 130:	return (void *)mmioFlush;
	case 131:	return (void *)mmioGetInfo;
	case 132:	return (void *)mmioInstallIOProcA;
	case 133:	return (void *)mmioInstallIOProcW;
	case 134:	return (void *)mmioOpenA;
	case 135:	return (void *)mmioOpenW;
	case 136:	return (void *)mmioRead;
	case 137:	return (void *)mmioRenameA;
	case 138:	return (void *)mmioRenameW;
	case 139:	return (void *)mmioSeek;
	case 140:	return (void *)mmioSendMessage;
	case 141:	return (void *)mmioSetBuffer;
	case 142:	return (void *)mmioSetInfo;
	case 143:	return (void *)mmioStringToFOURCCA;
	case 144:	return (void *)mmioStringToFOURCCW;
	case 145:	return (void *)mmioWrite;
	case 146:	return (void *)mmsystemGetVersion;
//	case 147:	return (void *)mod32Message;
//	case 148:	return (void *)mxd32Message;
	case 149:	return (void *)sndPlaySoundA;
	case 150:	return (void *)sndPlaySoundW;
//	case 151:	return (void *)tid32Message;
	case 152:	return (void *)timeBeginPeriod;
	case 153:	return (void *)timeEndPeriod;
	case 154:	return (void *)timeGetDevCaps;
	case 155:	return (void *)timeGetSystemTime;
	case 156:	return (void *)timeGetTime;
	case 157:	return (void *)timeKillEvent;
	case 158:	return (void *)timeSetEvent;
	case 159:	return (void *)waveInAddBuffer;
	case 160:	return (void *)waveInClose;
	case 161:	return (void *)waveInGetDevCapsA;
	case 162:	return (void *)waveInGetDevCapsW;
	case 163:	return (void *)waveInGetErrorTextA;
	case 164:	return (void *)waveInGetErrorTextW;
	case 165:	return (void *)waveInGetID;
	case 166:	return (void *)waveInGetNumDevs;
	case 167:	return (void *)waveInGetPosition;
	case 168:	return (void *)waveInMessage;
	case 169:	return (void *)waveInOpen;
	case 170:	return (void *)waveInPrepareHeader;
	case 171:	return (void *)waveInReset;
	case 172:	return (void *)waveInStart;
	case 173:	return (void *)waveInStop;
	case 174:	return (void *)waveInUnprepareHeader;
	case 175:	return (void *)waveOutBreakLoop;
	case 176:	return (void *)waveOutClose;
	case 177:	return (void *)waveOutGetDevCapsA;
	case 178:	return (void *)waveOutGetDevCapsW;
	case 179:	return (void *)waveOutGetErrorTextA;
	case 180:	return (void *)waveOutGetErrorTextW;
	case 181:	return (void *)waveOutGetID;
	case 182:	return (void *)waveOutGetNumDevs;
	case 183:	return (void *)waveOutGetPitch;
	case 184:	return (void *)waveOutGetPlaybackRate;
	case 185:	return (void *)waveOutGetPosition;
	case 186:	return (void *)waveOutGetVolume;
	case 187:	return (void *)waveOutMessage;
	case 188:	return (void *)waveOutOpen;
	case 189:	return (void *)waveOutPause;
	case 190:	return (void *)waveOutPrepareHeader;
	case 191:	return (void *)waveOutReset;
	case 192:	return (void *)waveOutRestart;
	case 193:	return (void *)waveOutSetPitch;
	case 194:	return (void *)waveOutSetPlaybackRate;
	case 195:	return (void *)waveOutSetVolume;
	case 196:	return (void *)waveOutUnprepareHeader;
	case 197:	return (void *)waveOutWrite;
//	case 198:	return (void *)wid32Message;
//	case 199:	return (void *)winmmDbgOut;
//	case 200:	return (void *)winmmSetDebugLevel;
//	case 201:	return (void *)wod32Message;
	}
	return NULL;
}
