void *
GetAddressByOrder
(int order)
{
	switch (order) {
	case 101:	return (void*)ChooseColorA;
	case 102:	return (void*)ChooseColorW;
	case 103:	return (void*)ChooseFontA;
	case 104:	return (void*)ChooseFontW;
	case 105:	return (void*)CommDlgExtendedError;
	case 106:	return (void*)FindTextA;
	case 107:	return (void*)FindTextW;
	case 108:	return (void*)GetFileTitleA;
	case 109:	return (void*)GetFileTitleW;
	case 110:	return (void*)GetOpenFileNameA;
	case 111:	return (void*)GetOpenFileNameW;
	case 112:	return (void*)GetSaveFileNameA;
	case 113:	return (void*)GetSaveFileNameW;
//	case 114:	return (void*)LoadAlterBitmap;
	case 115:	return (void*)PageSetupDlgA;
	case 116:	return (void*)PageSetupDlgW;
	case 117:	return (void*)PrintDlgA;
//	case 118:	return (void*)PrintDlgExA;
//	case 119:	return (void*)PrintDlgExW;
	case 120:	return (void*)PrintDlgW;
	case 121:	return (void*)ReplaceTextA;
	case 122:	return (void*)ReplaceTextW;
//	case 123:	return (void*)Ssync_ANSI_UNICODE_Struct_For_WOW;
//	case 124:	return (void*)WantArrows;
//	case 125:	return (void*)dwLBSubclass;
//	case 126:	return (void*)dwOKSubclass;
	}
	return NULL;
}
