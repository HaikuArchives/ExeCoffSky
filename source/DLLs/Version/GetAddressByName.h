void *
GetAddressByName
(const char *name)
{
	if (NULL == name) return NULL;
	else if (0 == strcmp(name, "GetFileVersionInfoA")) return (void *)GetFileVersionInfoA;
	else if (0 == strcmp(name, "GetFileVersionInfoSizeA")) return (void *)GetFileVersionInfoSizeA;
	else if (0 == strcmp(name, "GetFileVersionInfoSizeW")) return (void *)GetFileVersionInfoSizeW;
	else if (0 == strcmp(name, "GetFileVersionInfoW")) return (void *)GetFileVersionInfoW;
	else if (0 == strcmp(name, "VerFindFileA")) return (void *)VerFindFileA;
	else if (0 == strcmp(name, "VerFindFileW")) return (void *)VerFindFileW;
	else if (0 == strcmp(name, "VerInstallFileA")) return (void *)VerInstallFileA;
	else if (0 == strcmp(name, "VerInstallFileW")) return (void *)VerInstallFileW;
	else if (0 == strcmp(name, "VerLanguageNameA")) return (void *)_VerLanguageNameA;
	else if (0 == strcmp(name, "VerLanguageNameW")) return (void *)_VerLanguageNameW;
	else if (0 == strcmp(name, "VerQueryValueA")) return (void *)VerQueryValueA;
//	else if (0 == strcmp(name, "VerQueryValueIndexA")) return (void *)VerQueryValueIndexA;
//	else if (0 == strcmp(name, "VerQueryValueIndexW")) return (void *)VerQueryValueIndexW;
	else if (0 == strcmp(name, "VerQueryValueW")) return (void *)VerQueryValueW;
	return NULL;
}
