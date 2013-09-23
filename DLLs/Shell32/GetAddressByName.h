void *
GetAddressByName
(const char *name)
{
	if (NULL == name) return NULL;
	else if (0 == strcmp(name, "Shell_NotifyIconW")) return (void *)Shell_NotifyIconW;
	else if (0 == strcmp(name, "Shell_NotifyIconA")) return (void *)Shell_NotifyIconA;
	else if (0 == strcmp(name, "ShellExecuteW")) return (void *)ShellExecuteW;
	else if (0 == strcmp(name, "ShellExecuteExW")) return (void *)ShellExecuteExW;
	else if (0 == strcmp(name, "ShellExecuteExA")) return (void *)ShellExecuteExA;
	else if (0 == strcmp(name, "ShellExecuteA")) return (void *)ShellExecuteA;
	else if (0 == strcmp(name, "ShellAboutW")) return (void *)ShellAboutW;
	else if (0 == strcmp(name, "ShellAboutA")) return (void *)ShellAboutA;
	else if (0 == strcmp(name, "SHLoadInProc")) return (void *)SHLoadInProc;
	else if (0 == strcmp(name, "SHGetSpecialFolderLocation")) return (void *)SHGetSpecialFolderLocation;
	else if (0 == strcmp(name, "SHGetPathFromIDList")) return (void *)SHGetPathFromIDList;
	else if (0 == strcmp(name, "SHGetMalloc")) return (void *)SHGetMalloc;
	else if (0 == strcmp(name, "SHGetInstanceExplorer")) return (void *)SHGetInstanceExplorer;
	else if (0 == strcmp(name, "SHGetFileInfoW")) return (void *)SHGetFileInfoW;
	else if (0 == strcmp(name, "SHGetFileInfoA")) return (void *)SHGetFileInfoA;
	else if (0 == strcmp(name, "SHGetDesktopFolder")) return (void *)SHGetDesktopFolder;
	else if (0 == strcmp(name, "SHFreeNameMappings")) return (void *)SHFreeNameMappings;
	else if (0 == strcmp(name, "SHFileOperationW")) return (void *)SHFileOperationW;
	else if (0 == strcmp(name, "SHFileOperationA")) return (void *)SHFileOperationA;
	else if (0 == strcmp(name, "SHChangeNotify")) return (void *)SHChangeNotify;
	else if (0 == strcmp(name, "SHBrowseForFolder")) return (void *)SHBrowseForFolder;
	else if (0 == strcmp(name, "SHAppBarMessage")) return (void *)SHAppBarMessage;
	else if (0 == strcmp(name, "SHAddToRecentDocs")) return (void *)SHAddToRecentDocs;
	else if (0 == strcmp(name, "FindExecutableW")) return (void *)FindExecutableW;
	else if (0 == strcmp(name, "FindExecutableA")) return (void *)FindExecutableA;
	else if (0 == strcmp(name, "ExtractIconW")) return (void *)ExtractIconW;
	else if (0 == strcmp(name, "ExtractIconExW")) return (void *)ExtractIconExW;
	else if (0 == strcmp(name, "ExtractIconExA")) return (void *)ExtractIconExA;
	else if (0 == strcmp(name, "ExtractIconA")) return (void *)ExtractIconA;
	else if (0 == strcmp(name, "ExtractAssociatedIconW")) return (void *)ExtractAssociatedIconW;
	else if (0 == strcmp(name, "ExtractAssociatedIconA")) return (void *)ExtractAssociatedIconA;
	else if (0 == strcmp(name, "DragQueryPoint")) return (void *)DragQueryPoint;
	else if (0 == strcmp(name, "DragQueryFileW")) return (void *)DragQueryFileW;
	else if (0 == strcmp(name, "DragQueryFileA")) return (void *)DragQueryFileA;
	else if (0 == strcmp(name, "DragFinish")) return (void *)DragFinish;
	else if (0 == strcmp(name, "DragAcceptFiles")) return (void *)DragAcceptFiles;
	return NULL;
}
