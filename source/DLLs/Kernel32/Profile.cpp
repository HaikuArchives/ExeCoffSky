/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: Profile.cpp,v 1.1 2003/05/01 02:57:17 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Profile.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "Profile.h"
#include "Win32Trace.h"
#include "Path.h"

extern "C" UINT WINAPI
GetPrivateProfileIntA
(LPCSTR lpAppName, LPCSTR lpKeyName, INT nDefault, LPCSTR lpFileName)
{
	UINT rc = (UINT)nDefault;
	WIN32API_POINTER(lpAppName);
	WIN32API_POINTER(lpKeyName);
	WIN32API_POINTER(lpFileName);
	WIN32API_ENTER("UINT", "GetPrivateProfileIntA", "LPCSTR", lpAppName, "LPCSTR", lpKeyName, "INT", nDefault, "LPCSTR", lpFileName, NULL);
	WIN32API_INFO("lpAppName: %s\n", lpAppName);
	WIN32API_INFO("lpKeyName: %s\n", lpKeyName);
	WIN32API_INFO("nDefault: %d\n", nDefault);
	WIN32API_INFO("lpFileName: %s\n", lpFileName);
	char def[256];
	snprintf(def, 256, "%d", nDefault);
	char buf[256];
	WIN32API_INTERNAL_START();
	GetPrivateProfileStringA(lpAppName, lpKeyName, def, buf, 256, lpFileName);
	WIN32API_INTERNAL_END();
	rc = atoi(buf);
	if (rc < 0) rc = 0;
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
GetPrivateProfileIntW
(LPCWSTR lpAppName, LPCWSTR lpKeyName, INT nDefault, LPCWSTR lpFileName)
{
	UINT rc = (UINT)nDefault;
	WIN32API_POINTER(lpAppName);
	WIN32API_POINTER(lpKeyName);
	WIN32API_POINTER(lpFileName);
	WIN32API_ENTER("UINT", "GetPrivateProfileIntW", "LPCWSTR", lpAppName, "LPCWSTR", lpKeyName, "INT", nDefault, "LPCWSTR", lpFileName, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetPrivateProfileSectionA
(LPCSTR arg0, LPSTR arg1, DWORD arg2, LPCSTR arg3)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "GetPrivateProfileSectionA", "LPCSTR", arg0, "LPSTR", arg1, "DWORD", arg2, "LPCSTR", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetPrivateProfileSectionW
(LPCWSTR arg0, LPWSTR arg1, DWORD arg2, LPCWSTR arg3)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "GetPrivateProfileSectionW", "LPCWSTR", arg0, "LPWSTR", arg1, "DWORD", arg2, "LPCWSTR", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetPrivateProfileStringA
(LPCSTR lpAppName, LPCSTR lpKeyName, LPCSTR lpDefault, LPSTR lpReturnedString, DWORD nSize, LPCSTR lpFileName)
{
	DWORD rc = 0;
	WIN32API_POINTER(lpAppName);
	WIN32API_POINTER(lpKeyName);
	WIN32API_POINTER(lpDefault);
	WIN32API_POINTER(lpReturnedString);
	WIN32API_POINTER(lpFileName);
	WIN32API_ENTER("DWORD", "GetPrivateProfileStringA", "LPCSTR", lpAppName, "LPCSTR", lpKeyName, "LPCSTR", lpDefault, "LPSTR", lpReturnedString, "DWORD", nSize, "LPCSTR", lpFileName, NULL);
	WIN32API_INFO("\tlpAppName = %s\n", lpAppName);
	WIN32API_INFO("\tlpKeyName = %s\n", lpKeyName);
	WIN32API_INFO("\tlpDefault = %s\n", lpDefault);
	WIN32API_INFO("\tlpReturnedString = %s\n", lpReturnedString);
	WIN32API_INFO("\tlpFileName = %s\n", lpFileName);

	char *buf = NULL;
	int fd = -1;
	if (NULL == lpAppName) {
		WIN32API_INFO("\tsection name enum. not impled. (NULL == lpAppName)\n");
	} else if (NULL == lpKeyName) {
		WIN32API_INFO("\tkey name enum. not impled. (NULL == lpKeyName)\n");
	} else try {
		Path path;
		if ((*lpFileName == '\\') || ((lpFileName[1] == ':') && (lpFileName[2] == '\\'))) {
			path.SetTo(lpFileName);
		} else {
			char winpath[PATH_MAX];
			WIN32API_INTERNAL_START();
			GetWindowsDirectoryA(winpath, PATH_MAX);
			WIN32API_INTERNAL_END();
			BString fullpath(winpath);
			fullpath.Append("\\");
			fullpath.Append(lpFileName);
			path.SetTo(fullpath.String());
		}
		path.ToNativePath(true);
		struct stat st;
		if (0 != stat(path.GetPath(), &st)) throw false;
		buf = new char[st.st_size + 1];
		if (NULL == buf) throw false;
		fd = open(path.GetPath(), O_RDONLY);
		if (fd < 0) throw false;
		if (st.st_size != read(fd, buf, st.st_size)) throw false;
		buf[st.st_size] = 0;
		int offset = 0;
		bool loop = true;
		WIN32API_INFO("\n\tfind section\n");
		while(loop) {
			if ('[' == buf[offset]) {
				// [lpAppName]
				size_t len = strcspn(&buf[offset + 1], "]\r\n");
				if ((len <= 0) || (buf[offset + 1 + len] != ']')) goto next_line;
				BString sect(&buf[offset + 1], len);
				WIN32API_INFO("\t\t%s ... ", sect.String());
				if (0 == sect.Compare(lpAppName)) loop = false;
				WIN32API_INFO("%s\n", loop? "no": "yes");
			} else if (0 == buf[offset]) throw false;
next_line:
			size_t len = strcspn(&buf[offset], "\r\n");
			if (buf[offset + len] == 0) throw false;
			else if (buf[offset + len] == '\n') offset += len + 1;
			else if (buf[offset + len] == '\r') {
				if (buf[offset + len + 1] == '\n') offset++;
				offset += len + 1;
			}
		}
		loop = true;
		BString key(lpKeyName);
		key.Append("=");
		WIN32API_INFO("\tfind key\n");
		while (loop) {
			if ('[' == buf[offset]) throw false;
			else if (0 == buf[offset]) throw false;
			size_t len = strcspn(&buf[offset], "\r\n");
			if (buf[offset + len] == 0) len = strlen(&buf[offset]);
			BString line(&buf[offset], len);
			WIN32API_INFO("\t\t%s\n", line.String());
			if (0 != line.IFindFirst(key)) {
				if (buf[offset + len] == 0) throw false;
				else if (buf[offset + len] == '\n') offset += len + 1;
				else if (buf[offset + len] == '\r') {
					if (buf[offset + len + 1] == '\n') offset++;
					offset += len + 1;
				}
				continue;
			}
			line.Remove(0, key.Length());
			WIN32API_INFO("\t\t\tfound: %s\n", line.String());
			if ((UINT)(line.Length() + 1) > nSize) {
				strncpy(lpReturnedString, line.String(), nSize - 1);
				rc = nSize - 1;
			} else {
				strcpy(lpReturnedString, line.String());
				rc = line.Length();
			}
			throw true;
		}
	} catch (bool e) {
		if (fd >= 0) close(fd);
		if (NULL != buf) delete buf;
		if (!e) {
			if (NULL != lpDefault) rc = snprintf((char *)lpReturnedString, nSize, "%s", lpDefault);
			else rc = 0;
		}
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetPrivateProfileStringW
(LPCWSTR arg0, LPCWSTR arg1, LPCWSTR arg2, LPWSTR arg3, DWORD arg4, LPCWSTR arg5)
{
	DWORD rc = 0;
	WIN32API_ENTER("DWORD", "GetPrivateProfileStringW", "LPCWSTR", arg0, "LPCWSTR", arg1, "LPCWSTR", arg2, "LPWSTR", arg3, "DWORD", arg4, "LPCWSTR", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetPrivateProfileSectionNamesA
(LPSTR arg0, DWORD arg1, LPCSTR arg2)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "GetPrivateProfileSectionNamesA", "LPSTR", arg0, "DWORD", arg1, "LPCSTR", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetPrivateProfileSectionNamesW
(LPWSTR arg0, DWORD arg1, LPCWSTR arg2)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "GetPrivateProfileSectionNamesW", "LPWSTR", arg0, "DWORD", arg1, "LPCWSTR", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetPrivateProfileStructA
(LPCSTR arg0, LPCSTR arg1, PVOID arg2, UINT arg3, LPCSTR arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetPrivateProfileStructA", "LPCSTR", arg0, "LPCSTR", arg1, "PVOID", arg2, "UINT", arg3, "LPCSTR", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetPrivateProfileStructW
(LPCWSTR arg0, LPCWSTR arg1, PVOID arg2, UINT arg3, LPCWSTR arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetPrivateProfileStructW", "LPCWSTR", arg0, "LPCWSTR", arg1, "PVOID", arg2, "UINT", arg3, "LPCWSTR", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
WritePrivateProfileSectionA
(LPCSTR arg0, LPCSTR arg1, LPCSTR arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "WritePrivateProfileSectionA", "LPCSTR", arg0, "LPCSTR", arg1, "LPCSTR", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
WritePrivateProfileSectionW
(LPCWSTR arg0, LPCWSTR arg1, LPCWSTR arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "WritePrivateProfileSectionW", "LPCWSTR", arg0, "LPCWSTR", arg1, "LPCWSTR", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
WritePrivateProfileStringA
(LPCTSTR lpAppName, LPCTSTR lpKeyName, LPCTSTR lpString, LPCTSTR lpFileName)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "WritePrivateProfileStringA", "LPCTSTR", lpAppName, "LPCTSTR", lpKeyName, "LPCTSTR", lpString, "LPCTSTR", lpFileName, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
WritePrivateProfileStringW
(LPCWSTR arg0, LPCWSTR arg1, LPCWSTR arg2, LPCWSTR arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "WritePrivateProfileStringW", "LPCWSTR", arg0, "LPCWSTR", arg1, "LPCWSTR", arg2, "LPCWSTR", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
WritePrivateProfileStructA
(LPCSTR arg0, LPCSTR arg1, PVOID arg2, UINT arg3, LPCSTR arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "WritePrivateProfileStructA", "LPCSTR", arg0, "LPCSTR", arg1, "PVOID", arg2, "UINT", arg3, "LPCSTR", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
WritePrivateProfileStructW
(LPCWSTR arg0, LPCWSTR arg1, PVOID arg2, UINT arg3, LPCWSTR arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "WritePrivateProfileStructW", "LPCWSTR", arg0, "LPCWSTR", arg1, "PVOID", arg2, "UINT", arg3, "LPCWSTR", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
GetProfileIntA
(LPCSTR lpAppName, LPCSTR lpKeyName, INT nDefault)
{
	WIN32API_ENTER("UINT", "GetProfileIntA", "LPCSTR", lpAppName, "LPCSTR", lpKeyName, "INT", nDefault, NULL);
	WIN32API_INTERNAL_START();
	UINT rc = GetPrivateProfileIntA(lpAppName, lpKeyName, nDefault, "win.ini");
	WIN32API_INTERNAL_END();
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
GetProfileIntW
(LPCWSTR arg0, LPCWSTR arg1, INT arg2)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "GetProfileIntW", "LPCWSTR", arg0, "LPCWSTR", arg1, "INT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetProfileSectionA
(LPCSTR arg0, LPSTR arg1, DWORD arg2)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "GetProfileSectionA", "LPCSTR", arg0, "LPSTR", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetProfileSectionW
(LPCWSTR arg0, LPWSTR arg1, DWORD arg2)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "GetProfileSectionW", "LPCWSTR", arg0, "LPWSTR", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetProfileStringA
(LPCSTR arg0, LPCSTR arg1, LPCSTR arg2, LPSTR arg3, DWORD arg4)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "GetProfileStringA", "LPCSTR", arg0, "LPCSTR", arg1, "LPCSTR", arg2, "LPSTR", arg3, "DWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetProfileStringW
(LPCWSTR arg0, LPCWSTR arg1, LPCWSTR arg2, LPWSTR arg3, DWORD arg4)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "GetProfileStringW", "LPCWSTR", arg0, "LPCWSTR", arg1, "LPCWSTR", arg2, "LPWSTR", arg3, "DWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
WriteProfileSectionA
(LPCSTR arg0, LPCSTR arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "WriteProfileSectionA", "LPCSTR", arg0, "LPCSTR", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
WriteProfileSectionW
(LPCWSTR arg0, LPCWSTR arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "WriteProfileSectionW", "LPCWSTR", arg0, "LPCWSTR", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
WriteProfileStringA
(LPCSTR arg0, LPCSTR arg1, LPCSTR arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "WriteProfileStringA", "LPCSTR", arg0, "LPCSTR", arg1, "LPCSTR", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
WriteProfileStringW
(LPCWSTR arg0, LPCWSTR arg1, LPCWSTR arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "WriteProfileStringW", "LPCWSTR", arg0, "LPCWSTR", arg1, "LPCWSTR", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}
