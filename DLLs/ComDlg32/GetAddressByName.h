void *
GetAddressByName
(const char *name)
{
	if (NULL == name) return NULL;
	else if (0 == strcmp(name, "ChooseColorA")) return (void *)ChooseColorA;
	else if (0 == strcmp(name, "ChooseColorW")) return (void *)ChooseColorW;
	else if (0 == strcmp(name, "ChooseFontA")) return (void *)ChooseFontA;
	else if (0 == strcmp(name, "ChooseFontW")) return (void *)ChooseFontW;
	else if (0 == strcmp(name, "CommDlgExtendedError")) return (void *)CommDlgExtendedError;
	else if (0 == strcmp(name, "FindTextA")) return (void *)FindTextA;
	else if (0 == strcmp(name, "FindTextW")) return (void *)FindTextW;
	else if (0 == strcmp(name, "GetFileTitleA")) return (void *)GetFileTitleA;
	else if (0 == strcmp(name, "GetFileTitleW")) return (void *)GetFileTitleW;
	else if (0 == strcmp(name, "GetOpenFileNameA")) return (void *)GetOpenFileNameA;
	else if (0 == strcmp(name, "GetOpenFileNameW")) return (void *)GetOpenFileNameW;
	else if (0 == strcmp(name, "GetSaveFileNameA")) return (void *)GetSaveFileNameA;
	else if (0 == strcmp(name, "GetSaveFileNameW")) return (void *)GetSaveFileNameW;
//	else if (0 == strcmp(name, "LoadAlterBitmap")) return (void *)LoadAlterBitmap;
	else if (0 == strcmp(name, "PageSetupDlgA")) return (void *)PageSetupDlgA;
	else if (0 == strcmp(name, "PageSetupDlgW")) return (void *)PageSetupDlgW;
	else if (0 == strcmp(name, "PrintDlgA")) return (void *)PrintDlgA;
//	else if (0 == strcmp(name, "PrintDlgExA")) return (void *)PrintDlgExA;
//	else if (0 == strcmp(name, "PrintDlgExW")) return (void *)PrintDlgExW;
	else if (0 == strcmp(name, "PrintDlgW")) return (void *)PrintDlgW;
	else if (0 == strcmp(name, "ReplaceTextA")) return (void *)ReplaceTextA;
	else if (0 == strcmp(name, "ReplaceTextW")) return (void *)ReplaceTextW;
//	else if (0 == strcmp(name, "Ssync_ANSI_UNICODE_Struct_For_WOW")) return (void *)Ssync_ANSI_UNICODE_Struct_For_WOW;
//	else if (0 == strcmp(name, "WantArrows")) return (void *)WantArrows;
//	else if (0 == strcmp(name, "dwLBSubclass")) return (void *)dwLBSubclass;
//	else if (0 == strcmp(name, "dwOKSubclass")) return (void *)dwOKSubclass;
	return NULL;
}
