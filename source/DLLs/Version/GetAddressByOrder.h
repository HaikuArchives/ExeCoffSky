void *
GetAddressByOrder
(int order)
{
	switch (order) {
	case 1:		return (void*)GetFileVersionInfoA;
	case 2:		return (void*)GetFileVersionInfoSizeA;
	case 3:		return (void*)GetFileVersionInfoSizeW;
	case 4:		return (void*)GetFileVersionInfoW;
	case 5:		return (void*)VerFindFileA;
	case 6:		return (void*)VerFindFileW;
	case 7:		return (void*)VerInstallFileA;
	case 8:		return (void*)VerInstallFileW;
	case 9:		return (void*)_VerLanguageNameA;
	case 10:	return (void*)_VerLanguageNameW;
	case 11:	return (void*)VerQueryValueA;
//	case 12:	return (void*)VerQueryValueIndexA;
//	case 13:	return (void*)VerQueryValueIndexW;
	case 14:	return (void*)VerQueryValueW;
	}
	return NULL;
}
