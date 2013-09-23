void *
GetAddressByOrder
(int order)
{
	switch (order) {
//	case 1:		return (void*)ImmActivateLayout;
	case 2:		return (void*)ImmAssociateContext;
	case 3:		return (void*)ImmAssociateContextEx;
//	case 4:		return (void*)ImmCallImeConsoleIME;
	case 5:		return (void*)ImmConfigureIMEA;
	case 6:		return (void*)ImmConfigureIMEW;
	case 7:		return (void*)ImmCreateContext;
//	case 8:		return (void*)ImmCreateIMCC;
//	case 9:		return (void*)ImmCreateSoftKeyboard;
	case 10:	return (void*)ImmDestroyContext;
//	case 11:	return (void*)ImmDestroyIMCC;
//	case 12:	return (void*)ImmDestroySoftKeyboard;
	case 13:	return (void*)ImmDisableIME;
//	case 14:	return (void*)ImmDisableIme;
//	case 15:	return (void*)ImmEnumInputContext;
	case 16:	return (void*)ImmEnumRegisterWordA;
	case 17:	return (void*)ImmEnumRegisterWordW;
	case 18:	return (void*)ImmEscapeA;
	case 19:	return (void*)ImmEscapeW;
//	case 20:	return (void*)ImmFreeLayout;
//	case 21:	return (void*)ImmGenerateMessage;
	case 22:	return (void*)ImmGetCandidateListA;
	case 23:	return (void*)ImmGetCandidateListCountA;
	case 24:	return (void*)ImmGetCandidateListCountW;
	case 25:	return (void*)ImmGetCandidateListW;
	case 26:	return (void*)ImmGetCandidateWindow;
	case 27:	return (void*)ImmGetCompositionFontA;
	case 28:	return (void*)ImmGetCompositionFontW;
	case 29:	return (void*)ImmGetCompositionStringA;
	case 30:	return (void*)ImmGetCompositionStringW;
	case 31:	return (void*)ImmGetCompositionWindow;
	case 32:	return (void*)ImmGetContext;
	case 33:	return (void*)ImmGetConversionListA;
	case 34:	return (void*)ImmGetConversionListW;
	case 35:	return (void*)ImmGetConversionStatus;
	case 36:	return (void*)ImmGetDefaultIMEWnd;
	case 37:	return (void*)ImmGetDescriptionA;
	case 38:	return (void*)ImmGetDescriptionW;
	case 39:	return (void*)ImmGetGuideLineA;
	case 40:	return (void*)ImmGetGuideLineW;
//	case 41:	return (void*)ImmGetHotKey;
//	case 42:	return (void*)ImmGetIMCCLockCount;
//	case 43:	return (void*)ImmGetIMCCSize;
//	case 44:	return (void*)ImmGetIMCLockCount;
	case 45:	return (void*)ImmGetIMEFileNameA;
	case 46:	return (void*)ImmGetIMEFileNameW;
//	case 47:	return (void*)ImmGetImeInfoEx;
	case 48:	return (void*)ImmGetImeMenuItemsA;
	case 49:	return (void*)ImmGetImeMenuItemsW;
	case 50:	return (void*)ImmGetOpenStatus;
	case 51:	return (void*)ImmGetProperty;
	case 52:	return (void*)ImmGetRegisterWordStyleA;
	case 53:	return (void*)ImmGetRegisterWordStyleW;
	case 54:	return (void*)ImmGetStatusWindowPos;
	case 55:	return (void*)ImmGetVirtualKey;
//	case 56:	return (void*)ImmIMPGetIMEA;
//	case 57:	return (void*)ImmIMPGetIMEW;
//	case 58:	return (void*)ImmIMPQueryIMEA;
//	case 59:	return (void*)ImmIMPQueryIMEW;
//	case 60:	return (void*)ImmIMPSetIMEA;
//	case 61:	return (void*)ImmIMPSetIMEW;
	case 62:	return (void*)ImmInstallIMEA;
	case 63:	return (void*)ImmInstallIMEW;
	case 64:	return (void*)ImmIsIME;
	case 65:	return (void*)ImmIsUIMessageA;
	case 66:	return (void*)ImmIsUIMessageW;
//	case 67:	return (void*)ImmLoadIME;
//	case 68:	return (void*)ImmLoadLayout;
//	case 69:	return (void*)ImmLockClientImc;
//	case 70:	return (void*)ImmLockIMC;
//	case 71:	return (void*)ImmLockIMCC;
//	case 72:	return (void*)ImmLockImeDpi;
	case 73:	return (void*)ImmNotifyIME;
//	case 74:	return (void*)ImmPenAuxInput;
//	case 75:	return (void*)ImmProcessKey;
//	case 76:	return (void*)ImmPutImeMenuItemsIntoMappedFile;
//	case 77:	return (void*)ImmReSizeIMCC;
//	case 78:	return (void*)ImmRegisterClient;
	case 79:	return (void*)ImmRegisterWordA;
	case 80:	return (void*)ImmRegisterWordW;
	case 81:	return (void*)ImmReleaseContext;
//	case 82:	return (void*)ImmRequestMessageA;
//	case 83:	return (void*)ImmRequestMessageW;
//	case 84:	return (void*)ImmSendIMEMessageExA;
//	case 85:	return (void*)ImmSendIMEMessageExW;
//	case 86:	return (void*)ImmSendMessageToActiveDefImeWndW;
//	case 87:	return (void*)ImmSetActiveContext;
//	case 88:	return (void*)ImmSetActiveContextConsoleIME;
	case 89:	return (void*)ImmSetCandidateWindow;
	case 90:	return (void*)ImmSetCompositionFontA;
	case 91:	return (void*)ImmSetCompositionFontW;
	case 92:	return (void*)ImmSetCompositionStringA;
	case 93:	return (void*)ImmSetCompositionStringW;
	case 94:	return (void*)ImmSetCompositionWindow;
	case 95:	return (void*)ImmSetConversionStatus;
//	case 96:	return (void*)ImmSetHotKey;
	case 97:	return (void*)ImmSetOpenStatus;
	case 98:	return (void*)ImmSetStatusWindowPos;
//	case 99:	return (void*)ImmShowSoftKeyboard;
	case 100:	return (void*)ImmSimulateHotKey;
//	case 101:	return (void*)ImmSystemHandler;
//	case 102:	return (void*)ImmTranslateMessage;
//	case 103:	return (void*)ImmUnlockClientImc;
//	case 104:	return (void*)ImmUnlockIMC;
//	case 105:	return (void*)ImmUnlockIMCC;
//	case 106:	return (void*)ImmUnlockImeDpi;
	case 107:	return (void*)ImmUnregisterWordA;
	case 108:	return (void*)ImmUnregisterWordW;
//	case 109:	return (void*)ImmWINNLSEnableIME;
//	case 110:	return (void*)ImmWINNLSGetEnableStatus;
//	case 111:	return (void*)ImmWINNLSGetIMEHotkey;
	}
	return NULL;
}
