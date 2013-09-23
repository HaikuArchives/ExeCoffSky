/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: Path.cpp,v 1.1 2003/05/01 02:57:17 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Path.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "Path.h"
#include "Volume.h"
#include "Win32Trace.h"
#include "Win32Error.h"
#include "Win32String.h"

Path::Path
(void)
{
}

Path::Path
(const char *_path)
{
	SetTo(_path);
}

void
Path::SetTo
(const char *_path)
{
	DOUT("%s\n", _path);
	path.SetTo(_path);
}

bool
Path::ToWin32Path
(int drive)
{
	WIN32API_INFO("\tpath conversion\n");
	WIN32API_INFO("\tfrom: %s\n", path.String());
	path.ReplaceAll('\\', '/');
	if ('/' == path.ByteAt(0)) {
		if (0 == drive) {
			path.Prepend("A:");
		} else {
			int size = GetNativePathFromDrive(drive, NULL, 0);
			char *buf = new char[size];
			if (NULL == buf) return false;
			try {
				if (size < GetNativePathFromDrive(drive, buf, size)) throw false;
				if (0 != path.FindFirst(buf)) throw false;
				char drivepath[4];
				snprintf(drivepath, 4, "%c:/", drive + 'A');
				path.ReplaceFirst(path.String(), drivepath);
			} catch (bool e) {
				if (NULL != buf) delete buf;
				return e;
			}
		}
	}
	path.ReplaceAll('/', '\\');
	WIN32API_INFO("\tto: %s\n", path.String());
	return true;
}

bool
Path::ToNativePath
(bool fixcase)
{
	WIN32API_INFO("\tpath conversion\n");
	WIN32API_INFO("\tfrom: %s\n", path.String());
	path.ReplaceAll('\\', '/');
	if (path.ByteAt(0) == '/') {
		DWORD cwdsize = GetCurrentDirectoryU(0, NULL);
		char *buf = new char[cwdsize];
		if (NULL != buf) {
			GetCurrentDirectoryU(cwdsize, buf);
			char drivepath[3];
			snprintf(drivepath, 3, "%c:", buf[0]);
			delete buf;
			path.Prepend(drivepath);
		} else {
			WIN32API_ERROR(ERROR_NOT_ENOUGH_MEMORY);
			return false;
		}
	}
	while (path.ByteAt(1) == ':') {
		unsigned char drive = path.ByteAt(0) | 0x20;
		if ((drive < 'a') || ('z' < drive)) break;
		drive -= 'a';
		WIN32API_INFO("\tdrive number: %d\n", drive);
		char drivepath[4];
		snprintf(drivepath, 4, "%c:", path.ByteAt(0));
		path.RemoveFirst(drivepath);
		path.RemoveFirst("/");
		int size = GetNativePathFromDrive(drive, NULL, 0);
		char *buf = new char[size];
		if (NULL == buf) return false;
		if (size < GetNativePathFromDrive(drive, buf, size)) {
			delete buf;
			return false;
		}
		path.Prepend(buf);
		delete buf;
		break;
	}
	WIN32API_INFO("\tto: %s\n", path.String());
	if (fixcase) MatchCharCase();
	return true;
}

void
Path::MatchCharCase
(void)
{
	WIN32API_INFO("\tcase conversion\n");
	WIN32API_INFO("\tfrom: %s\n", path.String());
	// path shold be native
	BString newpath;
	if ('/' == path.ByteAt(0)) {
		newpath.SetTo("/");
		path.RemoveFirst("/");
	}
	for (;;) {
		WIN32API_INFO("\t... %s\n", newpath.String());
		int32 slash_offset = path.FindFirst('/');
		if (B_ERROR == slash_offset) {
			// leaf
			BString fname(newpath);
			fname += path;
			struct stat st;
			if (0 != stat(fname.String(), &st)) {
				DIR *dir = opendir((0 == newpath.Length())? ".": newpath.String());
				if (NULL != dir) {
					struct dirent *ent;
					while (NULL != (ent = readdir(dir))) {
						WIN32API_INFO("\t\t(%s) ... ", ent->d_name);
						if (0 == strcasecmp(ent->d_name, path.String())) {
							WIN32API_INFO("match\n");
							path.SetTo(ent->d_name);
							break;
						} else {
							WIN32API_INFO("\n");
						}
					}
					closedir(dir);
				} else {
					WIN32API_INFO("\tcan not opendir: %s\n", newpath.String());
				}
			}
			newpath.Append(path);
			break;
		} else {
			// path
			BString cur(path.String(), slash_offset);
			path.RemoveFirst(cur.String());
			path.RemoveFirst("/");
			BString fname(newpath);
			fname += cur;
			struct stat st;
			if (0 != stat(fname.String(), &st)) {
				DIR *dir;
				if (newpath.Length() == 0) dir = opendir(".");
				else dir = opendir(newpath.String());
				WIN32API_INFO("\t\tfind %s\n", cur.String());
				if (NULL != dir) {
					struct dirent *ent;
					while (NULL != (ent = readdir(dir))) {
						WIN32API_INFO("\t\t(%s) ... ", ent->d_name);
						if (0 == strcasecmp(ent->d_name, cur.String())) {
							WIN32API_INFO("match\n");
							cur.SetTo(ent->d_name);
							break;
						} else {
							WIN32API_INFO("\n");
						}
					}
					closedir(dir);
				}
			} else {
				WIN32API_INFO("\tcan not opendir: %s\n", newpath.String());
			}
			newpath.Append(cur);
			newpath.Append("/");
		}
	}
	path.SetTo(newpath);
	WIN32API_INFO("\tto: %s\n", path.String());
}

const char *
Path::GetPath
(void)
{
	return path.String();
}

int32
Path::GetPathLength
(void)
{
	return path.Length();
}

static UINT
GetWindowsDirectoryU
(LPSTR lpBuffer, UINT uSize)
{
	UINT rc = 0;
	static const char *npath = "/boot/home/config/windows";
	struct stat st;
	if (0 != stat(npath, &st)) mkdir(npath, 0777);
	static const char *path = "A:\\boot\\home\\config\\windows";
	if (NULL != lpBuffer) {
		rc = snprintf(lpBuffer, uSize, "%s", path);
		WIN32API_INFO("\tlpBuffer: %s\n", lpBuffer);
		if (rc >= uSize) rc++;
	} else {
		rc = strlen(path) + 1;
	}
	return rc;
}

static UINT
GetSystemDirectoryU
(LPSTR lpBuffer, UINT uSize)
{
	UINT rc = 0;
	static const char *npath1 = "/boot/home/config/windows";
	static const char *npath2 = "/boot/home/config/windows/system32";
	struct stat st;
	if (0 != stat(npath1, &st)) mkdir(npath1, 0777);
	if (0 != stat(npath2, &st)) mkdir(npath2, 0777);
	static const char *path = "A:\\boot\\home\\config\\windows\\system32";
	if (NULL != lpBuffer) {
		rc = snprintf(lpBuffer, uSize, "%s", path);
		WIN32API_INFO("\tlpBuffer: %s\n", lpBuffer);
		if (rc >= uSize) rc++;
	} else {
		rc = strlen(path) + 1;
	}
	return rc;
}

static DWORD
GetCurrentDirectoryU
(DWORD nBufferLength, LPSTR lpBuffer)
{
	DWORD rc = 0;
	char path[PATH_MAX];
	getcwd(path, PATH_MAX);
	Path cwd(path);
	cwd.ToWin32Path();
	DWORD size = cwd.GetPathLength();
	if ((NULL != lpBuffer) && (size < nBufferLength)) {
		rc = snprintf(lpBuffer, nBufferLength, "%s", cwd.GetPath());
	} else {
		rc = size + 1;
	}
	return rc;
}

static bool
GetFullPathNameU
(LPCSTR lpFileName, Win32String &sBuffer)
{
	WIN32API_INFO("\tlpFileName: %s\n", lpFileName);
	Path path(lpFileName);
	path.ToNativePath(true);
	BPath bpath(path.GetPath());
	path.SetTo(bpath.Path());
	path.ToWin32Path();
	sBuffer.SetToU(path.GetPath());
	WIN32API_ERROR(ERROR_SUCCESS);
	WIN32API_INFO("\tFullPath: %s\n", sBuffer.StringU());
	return true;
}

static bool
SearchPathU
(LPCSTR lpPath, LPCSTR lpFileName, LPCSTR lpExtension, Win32String &sBuffer)
{
	WIN32API_INFO("\tlpPath: %s\n", lpPath);
	WIN32API_INFO("\tlpFileName: %s\n", lpFileName);
	WIN32API_INFO("\tlpExtension: %s\n", lpExtension);
	return false;
}

static LPCSTR
FindFilePartA
(LPCSTR lpPath)
{
	LPCSTR part = lpPath;
	if ((0 != lpPath[0]) && (':' == lpPath[1])) part = &lpPath[2];
	for (LPCSTR p = part; 0 != *p; p++) if (*p == '\\') part = &p[1];
	return part;
}

static LPCWSTR
FindFilePartW
(LPCWSTR lpPath)
{
	LPCWSTR part = lpPath;
	if ((0 != lpPath[0]) && (':' == lpPath[1])) part = &lpPath[2];
	for (LPCWSTR p = part; 0 != *p; p++) if (*p == '\\') part = &p[1];
	return part;
}

extern "C" UINT WINAPI
GetWindowsDirectoryA
(LPSTR lpBuffer, UINT uSize)
{
	UINT rc = 0;
	WIN32API_POINTER(lpBuffer);
	WIN32API_ENTER("UINT", "GetWindowsDirectoryA", "LPSTR", lpBuffer, "UINT", uSize, NULL);
	UINT size = GetWindowsDirectoryU(NULL, 0);
	char *buf = new char[size];
	if (NULL != buf) {
		GetWindowsDirectoryU(buf, size);
		Win32String str;
		str.SetToU(buf);
		if ((NULL != lpBuffer) && (str.LengthA() < uSize)) {
			strcpy(lpBuffer, str.StringA());
			WIN32API_INFO("lpBuffer: %s\n", lpBuffer);
			rc = str.LengthA();
			WIN32API_ERROR(ERROR_SUCCESS);
		} else {
			rc = str.LengthA() + 1;
			WIN32API_ERROR(ERROR_MORE_DATA);
		}
		delete buf;
	} else {
		WIN32API_ERROR(ERROR_NOT_ENOUGH_MEMORY);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
GetWindowsDirectoryW
(LPWSTR lpBuffer, UINT uSize)
{
	UINT rc = 0;
	WIN32API_POINTER(lpBuffer);
	WIN32API_ENTER("UINT", "GetWindowsDirectoryW", "LPWSTR", lpBuffer, "UINT", uSize, NULL);
	UINT size = GetWindowsDirectoryU(NULL, 0);
	char *buf = new char[size];
	if (NULL != buf) {
		GetWindowsDirectoryU(buf, size);
		Win32String str;
		str.SetToU(buf);
		if ((NULL != lpBuffer) && (str.LengthW() < uSize)) {
			Win32String::strcpyW(lpBuffer, str.StringW());
			rc = str.LengthW();
			WIN32API_ERROR(ERROR_SUCCESS);
		} else {
			rc = str.LengthW() + 1;
			WIN32API_ERROR(ERROR_MORE_DATA);
		}
		delete buf;
	} else {
		WIN32API_ERROR(ERROR_NOT_ENOUGH_MEMORY);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
GetSystemDirectoryA
(LPSTR lpBuffer, UINT uSize)
{
	UINT rc = 0;
	WIN32API_POINTER(lpBuffer);
	WIN32API_ENTER("UINT", "GetSystemDirectoryA", "LPSTR", lpBuffer, "UINT", uSize, NULL);
	UINT size = GetSystemDirectoryU(NULL, 0);
	char *buf = new char[size];
	if (NULL != buf) {
		GetSystemDirectoryU(buf, size);
		Win32String str;
		str.SetToU(buf);
		if ((NULL != lpBuffer) && (str.LengthA() < uSize)) {
			strcpy(lpBuffer, str.StringA());
			rc = str.LengthA();
			WIN32API_ERROR(ERROR_SUCCESS);
		} else {
			rc = str.LengthA() + 1;
			WIN32API_ERROR(ERROR_MORE_DATA);
		}
		delete buf;
	} else {
		WIN32API_ERROR(ERROR_NOT_ENOUGH_MEMORY);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
GetSystemDirectoryW
(LPWSTR lpBuffer, UINT uSize)
{
	UINT rc = 0;
	WIN32API_POINTER(lpBuffer);
	WIN32API_ENTER("UINT", "GetSystemDirectoryW", "LPWSTR", lpBuffer, "UINT", uSize, NULL);
	UINT size = GetSystemDirectoryU(NULL, 0);
	char *buf = new char[size];
	if (NULL != buf) {
		GetSystemDirectoryU(buf, size);
		Win32String str;
		str.SetToU(buf);
		if ((NULL != lpBuffer) && (str.LengthW() < uSize)) {
			Win32String::strcpyW(lpBuffer, str.StringW());
			rc = str.LengthW();
			WIN32API_ERROR(ERROR_SUCCESS);
		} else {
			rc = str.LengthW() + 1;
			WIN32API_ERROR(ERROR_MORE_DATA);
		}
		delete buf;
	} else {
		WIN32API_ERROR(ERROR_NOT_ENOUGH_MEMORY);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetCurrentDirectoryA
(DWORD nBufferLength, LPSTR lpBuffer)
{
	DWORD rc = 0;
	WIN32API_POINTER(lpBuffer);
	WIN32API_ENTER("DWORD", "GetCurrentDirectoryA", "DWORD", nBufferLength, "LPTSTR", lpBuffer, NULL);
	DWORD size = GetCurrentDirectoryU(0, NULL);
	char *buf = new char[size];
	if (NULL != buf) {
		GetCurrentDirectoryU(size, buf);
		Win32String str;
		str.SetToU(buf);
		if ((NULL != lpBuffer) && (str.LengthA() < nBufferLength)) {
			strcpy(lpBuffer, str.StringA());
			rc = str.LengthA();
			WIN32API_ERROR(ERROR_SUCCESS);
		} else {
			rc = str.LengthA() + 1;
			WIN32API_ERROR(ERROR_MORE_DATA);
		}
		delete buf;
	} else {
		WIN32API_ERROR(ERROR_NOT_ENOUGH_MEMORY);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetCurrentDirectoryW
(DWORD nBufferLength, LPWSTR lpBuffer)
{
	DWORD rc = 0;
	WIN32API_POINTER(lpBuffer);
	WIN32API_ENTER("DWORD", "GetCurrentDirectoryW", "DWORD", nBufferLength, "LPWSTR", lpBuffer, NULL);
	DWORD size = GetCurrentDirectoryU(0, NULL);
	char *buf = new char[size];
	if (NULL != buf) {
		GetCurrentDirectoryU(size, buf);
		Win32String str;
		str.SetToU(buf);
		if ((NULL != lpBuffer) && (str.LengthW() < nBufferLength)) {
			Win32String::strcpyW(lpBuffer, str.StringW());
			rc = str.LengthW();
			WIN32API_ERROR(ERROR_SUCCESS);
		} else {
			rc = str.LengthW() + 1;
			WIN32API_ERROR(ERROR_MORE_DATA);
		}
		delete buf;
	} else {
		WIN32API_ERROR(ERROR_NOT_ENOUGH_MEMORY);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetCurrentDirectoryA
(LPCSTR lpPathName)
{
	BOOL rc = FALSE;
	WIN32API_POINTER(lpPathName);
	WIN32API_ENTER("BOOL", "SetCurrentDirectoryA", "LPCSTR", lpPathName, NULL);
	WIN32API_INFO("\t%s\n", lpPathName);
	Path cwd(lpPathName);
	cwd.ToNativePath(true);
	rc = 0 == chdir(cwd.GetPath());
	WIN32API_INFO("\tSetTo: %s ... %s\n", cwd.GetPath(), (TRUE == rc)? "ok": "failed");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetCurrentDirectoryW
(LPCWSTR lpPathName)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetCurrentDirectoryW", "LPCWSTR", lpPathName, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CreateDirectoryA
(LPCSTR lpPathName, LPSECURITY_ATTRIBUTES lpSecurityAttributes)
{
	BOOL rc = FALSE;
	WIN32API_POINTER(lpPathName);
	WIN32API_POINTER(lpSecurityAttributes);
	WIN32API_ENTER("BOOL", "CreateDirectoryA", "LPCSTR", lpPathName, "LPSECURITY_ATTRIBUTES", lpSecurityAttributes, NULL);
	Path path(lpPathName);
	path.ToNativePath(true);
	BString str(path.GetPath());
	if ('/' == str.ByteAt(str.Length() - 1)) str.RemoveLast("/");
	rc = (0 == mkdir(str.String(), 0777))? TRUE: FALSE;
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CreateDirectoryW
(LPCWSTR lpPathName, LPSECURITY_ATTRIBUTES lpSecurityAttributes)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CreateDirectoryW", "LPCWSTR", lpPathName, "LPSECURITY_ATTRIBUTES", lpSecurityAttributes, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CreateDirectoryExA
(LPCSTR lpTemplateDirectory, LPCSTR lpNewDirectory, LPSECURITY_ATTRIBUTES lpSecurityAttributes)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CreateDirectoryExA", "LPCSTR", lpTemplateDirectory, "LPCSTR", lpNewDirectory, "LPSECURITY_ATTRIBUTES", lpSecurityAttributes, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CreateDirectoryExW
(LPCWSTR lpTemplateDirectory, LPCWSTR lpNewDirectory, LPSECURITY_ATTRIBUTES lpSecurityAttributes)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CreateDirectoryExW", "LPCWSTR", lpTemplateDirectory, "LPCWSTR", lpNewDirectory, "LPSECURITY_ATTRIBUTES", lpSecurityAttributes, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
RemoveDirectoryA
(LPCSTR lpPathName)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "RemoveDirectoryA", "LPCSTR", lpPathName, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
RemoveDirectoryW
(LPCWSTR lpPathName)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "RemoveDirectoryW", "LPCWSTR", lpPathName, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetTempPathA
(DWORD nBufferLength, LPSTR lpBuffer)
{
	DWORD rc = 0;
	WIN32API_ENTER("DWORD", "GetTempPathA", "DWORD", nBufferLength, "LPSTR", lpBuffer, NULL);
	rc = snprintf(lpBuffer, nBufferLength, "%s", "A:\\tmp");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetTempPathW
(DWORD nBufferLength, LPWSTR lpBuffer)
{
	DWORD rc = 0;
	WIN32API_ENTER("DWORD", "GetTempPathW", "DWORD", nBufferLength, "LPWSTR", lpBuffer, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetShortPathNameA
(LPCSTR lpszLongPath, LPSTR lpszShortPath, DWORD cchBuffer)
{
	DWORD rc = 0;
	WIN32API_POINTER(lpszLongPath);
	WIN32API_POINTER(lpszShortPath);
	WIN32API_ENTER("DWORD", "GetShortPathNameA", "LPCSTR", lpszLongPath, "LPSTR", lpszShortPath, "DWORD", cchBuffer, NULL);
	WIN32API_INFO("\tlpszLongPath: %s\n", lpszLongPath);
	DWORD len = strlen(lpszLongPath);
	if (cchBuffer <= len) {
		rc = len + 1;
		WIN32API_ERROR(ERROR_MORE_DATA);
	} else {
		strcpy(lpszShortPath, lpszLongPath);
		rc = len;
		WIN32API_ERROR(ERROR_SUCCESS);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetShortPathNameW
(LPCWSTR lpszLongPath, LPWSTR lpszShortPath, DWORD cchBuffer)
{
	DWORD rc = 0;
	WIN32API_POINTER(lpszLongPath);
	WIN32API_POINTER(lpszShortPath);
	WIN32API_ENTER("DWORD", "GetShortPathNameW", "LPCWSTR", lpszLongPath, "LPWSTR", lpszShortPath, "DWORD", cchBuffer, NULL);
	DWORD len = Win32String::strlenW(lpszLongPath);
	if (cchBuffer <= len) {
		rc = len + 1;
		WIN32API_ERROR(ERROR_MORE_DATA);
	} else {
		Win32String::strcpyW(lpszShortPath, lpszLongPath);
		rc = len;
		WIN32API_ERROR(ERROR_SUCCESS);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetFullPathNameA
(LPCSTR lpFileName, DWORD nBufferLength, LPSTR lpBuffer, LPSTR *lpFilePart)
{
	DWORD rc = 0;
	WIN32API_POINTER(lpFileName);
	WIN32API_POINTER(lpBuffer);
	WIN32API_POINTER(lpFilePart);
	WIN32API_ENTER("DWORD", "GetFullPathNameA", "LPCSTR", lpFileName, "DWORD", nBufferLength, "LPSTR", lpBuffer, "LPSTR *", lpFilePart, NULL);
	Win32String filename(lpFileName);
	Win32String buffer;
	if (GetFullPathNameU(filename.StringU(), buffer)) {
		if (nBufferLength <= buffer.LengthA()) {
			rc = buffer.LengthA() + 1;
			WIN32API_ERROR(ERROR_MORE_DATA);
		} else {
			strcpy(lpBuffer, buffer.StringA());
			rc = buffer.LengthA();
			if (NULL != lpFilePart) {
				*lpFilePart = (LPSTR)FindFilePartA(lpBuffer);
				WIN32API_INFO("\tlpFilePart = %s\n", Win32String(*lpFilePart).StringU());
			}
		}
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetFullPathNameW
(LPCWSTR lpFileName, DWORD nBufferLength, LPWSTR lpBuffer, LPWSTR *lpFilePart)
{
	DWORD rc = 0;
	WIN32API_POINTER(lpFileName);
	WIN32API_POINTER(lpBuffer);
	WIN32API_POINTER(lpFilePart);
	WIN32API_ENTER("DWORD", "GetFullPathNameW", "LPCWSTR", lpFileName, "DWORD", nBufferLength, "LPWSTR", lpBuffer, "LPWSTR *", lpFilePart, NULL);
	Win32String filename(lpFileName);
	Win32String buffer;
	if (GetFullPathNameU(filename.StringU(), buffer)) {
		if (nBufferLength <= buffer.LengthW()) {
			rc = buffer.LengthW() + 1;
			WIN32API_ERROR(ERROR_MORE_DATA);
		} else {
			Win32String::strcpyW(lpBuffer, buffer.StringW());
			rc = buffer.LengthW();
			if (NULL != lpFilePart) {
				*lpFilePart = (LPWSTR)FindFilePartW(lpBuffer);
				WIN32API_INFO("\tlpFilePart = %s\n", Win32String(*lpFilePart).StringU());
			}
		}
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetLongPathNameA
(LPCSTR lpszShortPath, LPSTR lpszLongPath, DWORD cchBuffer)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "GetLongPathNameA", "LPCSTR", lpszShortPath, "LPSTR", lpszLongPath, "DWORD", cchBuffer, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetLongPathNameW
(LPCWSTR lpszShortPath, LPWSTR lpszLongPath, DWORD cchBuffer)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "GetLongPathNameW", "LPCWSTR", lpszShortPath, "LPWSTR", lpszLongPath, "DWORD", cchBuffer, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
SearchPathA
(LPCSTR lpPath, LPCSTR lpFileName, LPCSTR lpExtension, DWORD nBufferLength, LPSTR lpBuffer, LPSTR *lpFilePart)
{
	DWORD rc = 0;
	WIN32API_POINTER(lpPath);
	WIN32API_POINTER(lpFileName);
	WIN32API_POINTER(lpExtension);
	WIN32API_POINTER(lpBuffer);
	WIN32API_POINTER(lpFilePart);
	WIN32API_ENTER("DWORD", "SearchPathA", "LPCSTR", lpPath, "LPCSTR", lpFileName, "LPCSTR", lpExtension, "DWORD", nBufferLength, "LPSTR", lpBuffer, "LPSTR*", lpFilePart, NULL);
	Win32String path(lpPath);
	Win32String filename(lpFileName);
	Win32String extension(lpExtension);
	Win32String buffer;
	if (SearchPathU(path.StringU(), filename.StringU(), extension.StringU(), buffer)) {
		if (nBufferLength <= buffer.LengthA()) {
			rc = buffer.LengthA() + 1;
			WIN32API_ERROR(ERROR_MORE_DATA);
		} else {
			strcpy(lpBuffer, buffer.StringA());
			rc = buffer.LengthA();
			if (NULL != lpFilePart) *lpFilePart = (LPSTR)FindFilePartA(lpBuffer);
		}
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
SearchPathW
(LPCWSTR lpPath, LPCWSTR lpFileName, LPCWSTR lpExtension, DWORD nBufferLength, LPWSTR lpBuffer, LPWSTR *lpFilePart)
{
	DWORD rc = 0;
	WIN32API_POINTER(lpPath);
	WIN32API_POINTER(lpFileName);
	WIN32API_POINTER(lpExtension);
	WIN32API_POINTER(lpBuffer);
	WIN32API_POINTER(lpFilePart);
	WIN32API_ENTER("DWORD", "SearchPathW", "LPCWSTR", lpPath, "LPCWSTR", lpFileName, "LPCWSTR", lpExtension, "DWORD", nBufferLength, "LPWSTR", lpBuffer, "LPWSTR*", lpFilePart, NULL);
	Win32String path(lpPath);
	Win32String filename(lpFileName);
	Win32String extension(lpExtension);
	Win32String buffer;
	if (SearchPathU(path.StringU(), filename.StringU(), extension.StringU(), buffer)) {
		if (nBufferLength <= buffer.LengthW()) {
			rc = buffer.LengthW() + 1;
			WIN32API_ERROR(ERROR_MORE_DATA);
		} else {
			Win32String::strcpyW(lpBuffer, buffer.StringW());
			rc = buffer.LengthW();
			if (NULL != lpFilePart) *lpFilePart = (LPWSTR)FindFilePartW(lpBuffer);
		}
	}
	WIN32API_LEAVE(rc);
	return rc;
}
