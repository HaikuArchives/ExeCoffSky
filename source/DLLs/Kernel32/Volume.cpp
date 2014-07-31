/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000, 2001 とよしま
 *  $Id: Volume.cpp,v 1.1 2003/05/01 02:57:17 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Volume.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "Volume.h"
#include "Process.h"
#include "Path.h"
#include "Win32Trace.h"
#include "Win32String.h"
#include "Win32Error.h"

static int
GetDriveNumber
(LPCTSTR lpRootPathName)
{
	int drive = 0;
	if (NULL == lpRootPathName) {
		DWORD size = GetCurrentDirectoryA(0, NULL);
		char *cwd = new char[size];
		if (NULL != cwd) {
			size = GetCurrentDirectoryA(size, cwd);
			if (0 != size) drive = (*cwd | 0x20) - 'a';
			delete cwd;
		}
	} else {
		drive = (*lpRootPathName | 0x20) - 'a';
	}
	return drive;
}

static int
GetValidDriveInfo
(dev_t dev, fs_info *info)
{
	int rc = fs_stat_dev(dev, info);
	if (B_OK != rc) return rc;
	if (0 == strcmp(info->fsh_name, "rootfs")) return B_ERROR;
	if (0 == strcmp(info->fsh_name, "devfs")) return B_ERROR;
	if (0 == strcmp(info->fsh_name, "pipefs")) return B_ERROR;
	return B_OK;
}

int
GetNativePathFromDrive
(int drive, char *buffer, int size)
{
	BString path;
	if (0 == drive) path.SetTo("/");
	else if (1 == drive) {
		BPath apl(Process::GetCurrentProcessObject()->GetStartupDirectory());
		path.SetTo(apl.Path());
		path << "/";
	} else {
		BVolumeRoster vr;
		BVolume vol;
		drive--;
		while (B_OK == vr.GetNextVolume(&vol)) {
			fs_info info;
			if (B_OK != GetValidDriveInfo(vol.Device(), &info)) continue;
			drive--;
			if (0 != drive) continue;
			BDirectory dir;
			vol.GetRootDirectory(&dir);
			BEntry entry;
			dir.GetEntry(&entry);
			BPath drivepath;
			entry.GetPath(&drivepath);
			path.SetTo(drivepath.Path());
			path << "/";
			break;
		}
		if (0 != drive) return 0;
	}
	if ((NULL == buffer) || (size <= path.Length())) return path.Length() + 1;
	return snprintf(buffer, size, "%s", path.String());
}

static BOOL
GetDiskFreeSpaceU
(LPCSTR lpRootPathName, LPDWORD lpSectorPerCluster, LPDWORD lpBytesPerSector,
	LPDWORD lpNumberOfFreeClusters, LPDWORD lpTotalNumberOfClusters)
{
	BOOL rc = FALSE;
	WIN32API_INFO("\tlpRootPathName: %s\n", lpRootPathName);
	int drive = GetDriveNumber(lpRootPathName);
	WIN32API_INFO("\tdrive number = %d\n", drive);
	char drivepath[PATH_MAX];
	// A:\ については、全体の情報を返すことが難しいため、/bootについての
	// 情報を返すようにしている。
	if (0 != drive) GetNativePathFromDrive(drive, drivepath, PATH_MAX);
	else snprintf(drivepath, PATH_MAX, "%s", "/boot");
	WIN32API_INFO("\tdrive path = %s\n", drivepath);
	dev_t dev = dev_for_path(drivepath);
	WIN32API_INFO("\tnative device id = %d\n", dev);
	fs_info info;
	if (0 == fs_stat_dev(dev, &info)) {
		if (NULL != lpSectorPerCluster) *lpSectorPerCluster = 1;
		if (NULL != lpBytesPerSector) *lpBytesPerSector = info.block_size;
		if (NULL != lpNumberOfFreeClusters) *lpNumberOfFreeClusters = info.free_blocks;
		if (NULL != lpTotalNumberOfClusters) *lpTotalNumberOfClusters = info.total_blocks;
		WIN32API_INFO("\tSectorPerCluster: %d (dummy)\n", 1);
		WIN32API_INFO("\tBytesPerSector: %d\n", info.block_size);
		WIN32API_INFO("\tNumberOfFreeClusters: %d\n", info.free_blocks);
		WIN32API_INFO("\tTotalNumberOfClusters: %d\n", info.total_blocks);
		rc = TRUE;
	}
	return rc;
}

extern "C" UINT WINAPI
GetDriveTypeA
(LPCTSTR lpRootPathName)
{
	UINT rc = DRIVE_NO_ROOT_DIR;
	WIN32API_POINTER(lpRootPathName);
	WIN32API_ENTER("UINT", "GetDriveTypeA", "LPCTSTR", lpRootPathName, NULL);
	WIN32API_INFO("\tRootPathName = %s\n", lpRootPathName);
	int drive = GetDriveNumber(lpRootPathName);
	if (0 == drive) rc = DRIVE_FIXED;
	else if (1 == drive) rc = DRIVE_CDROM;
	else {
		BVolumeRoster vr;
		BVolume vol;
		drive--;
		while (B_OK == vr.GetNextVolume(&vol)) {
			fs_info info;
			if (B_OK != GetValidDriveInfo(vol.Device(), &info)) continue;
			drive--;
			if (0 != drive) continue;
			if (0 != (info.flags & B_FS_IS_SHARED)) rc = DRIVE_REMOTE;
			if (0 != (info.flags & B_FS_IS_REMOVABLE)) rc = DRIVE_REMOVABLE;
			rc = DRIVE_FIXED;
			if (0 == strcmp(info.fsh_name, "iso9660")) rc = DRIVE_CDROM;
			break;
		}
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
GetDriveTypeW
(LPCWSTR lpRootPathName)
{
	UINT rc = DRIVE_NO_ROOT_DIR;
	WIN32API_ENTER("UINT", "GetDriveTypeW", "LPCWSTR", lpRootPathName, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetLogicalDriveStringsA
(DWORD nBufferLength, LPSTR lpBuffer)
{
	DWORD rc = 0;
	WIN32API_POINTER(lpBuffer);
	WIN32API_ENTER("DWORD", "GetLogicalDriveStringsA", "DWORD", nBufferLength, "LPSTR", lpBuffer, NULL);
	if (nBufferLength >= 8) {
		strcpy(lpBuffer, "a:\\0b:\\0");
		rc = 8;
	}
	BVolumeRoster vr;
	BVolume vol;
	char drive = 'a';
	while (B_OK == vr.GetNextVolume(&vol)) {
		fs_info info;
		if (B_OK != GetValidDriveInfo(vol.Device(), &info)) continue;
		if (rc + 4 <= nBufferLength) {
			lpBuffer[rc + 0] = drive++;
			lpBuffer[rc + 1] = ':';
			lpBuffer[rc + 2] = '\\';
			lpBuffer[rc + 3] = '\0';
		}
		rc += 4;
	}
	if (rc <= nBufferLength) lpBuffer[rc] = '\0';
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetLogicalDriveStringsW
(DWORD nBufferLength, LPWSTR lpBuffer)
{
	DWORD rc = 0;
	WIN32API_ENTER("DWORD", "GetLogicalDriveStringsW", "DWORD", nBufferLength, "LPWSTR", lpBuffer, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetLogicalDrives
(void)
{
	DWORD rc = 0;
	WIN32API_ENTER("DWORD", "GetLogicalDrives", "void", 0, NULL);
	rc |= 3;	// a, b
	char drive = 4;	// c
	BVolumeRoster vr;
	BVolume vol;
	while (B_OK == vr.GetNextVolume(&vol)) {
		fs_info info;
		if (B_OK != fs_stat_dev(vol.Device(), &info)) continue;
		if (0 == strcmp(info.fsh_name, "rootfs")) continue;
		if (0 == strcmp(info.fsh_name, "devfs")) continue;
		if (0 == strcmp(info.fsh_name, "pipefs")) continue;
		rc |= drive;
		drive <<= 1;
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetVolumeInformationA
(LPCSTR lpRootPathName, LPSTR lpVolumeNameBuffer, DWORD nVolumeNameSize, LPDWORD lpVolumeSerialNumber, LPDWORD lpMaximumComponentLength,
	LPDWORD lpFileSystemFlags, LPSTR lpFileSystemNameBuffer, DWORD nFileSystemNameSize)
{
	BOOL rc = FALSE;
	WIN32API_POINTER(lpRootPathName);
	WIN32API_POINTER(lpVolumeNameBuffer);
	WIN32API_POINTER(lpVolumeSerialNumber);
	WIN32API_POINTER(lpMaximumComponentLength);
	WIN32API_POINTER(lpFileSystemFlags);
	WIN32API_POINTER(lpFileSystemNameBuffer);
	WIN32API_ENTER("BOOL", "GetVolumeInformationA", "LPCSTR", lpRootPathName, "LPSTR", lpVolumeNameBuffer,
		"DWORD", nVolumeNameSize, "LPDWORD", lpVolumeSerialNumber, "LPDWORD", lpMaximumComponentLength,
		"LPDWORD", lpFileSystemFlags, "LPSTR", lpFileSystemNameBuffer, "DWORD", nFileSystemNameSize, NULL);
	WIN32API_INFO("\tRootPathName: %s\n", lpRootPathName);
	int drive = GetDriveNumber(lpRootPathName);
	if (0 == drive) {
		if (NULL != lpVolumeNameBuffer) snprintf(lpVolumeNameBuffer, nVolumeNameSize, "BeOS root");
		if (NULL != lpVolumeSerialNumber) *lpVolumeSerialNumber = 0;
		if (NULL != lpMaximumComponentLength) *lpMaximumComponentLength = 255;	// vfat's MAX
		if (NULL != lpFileSystemFlags) *lpFileSystemFlags = FS_CASE_IS_PRESERVED | FS_CASE_SENSITIVE | FS_UNICODE_STORED_ON_DISK;
		if (NULL != lpFileSystemNameBuffer) snprintf(lpFileSystemNameBuffer, nFileSystemNameSize, "rootfs");
		rc = TRUE;
	} else if (1 == drive) {
		rc = TRUE;
		if (NULL != lpVolumeNameBuffer) {
			BPath path(Process::GetCurrentProcessObject()->GetStartupDirectory());
			snprintf(lpVolumeNameBuffer, nVolumeNameSize, "%s", path.Leaf());
		}
		if (NULL != lpVolumeSerialNumber) *lpVolumeSerialNumber = 0;
		if (NULL != lpMaximumComponentLength) *lpMaximumComponentLength = 255;	// vfat's MAX
		if (NULL != lpFileSystemFlags) *lpFileSystemFlags = FS_CASE_IS_PRESERVED | FS_CASE_SENSITIVE | FS_UNICODE_STORED_ON_DISK;
		if (NULL != lpFileSystemNameBuffer) snprintf(lpFileSystemNameBuffer, nFileSystemNameSize, "appfs");
	} else {
		BVolumeRoster vr;
		BVolume vol;
		drive--;
		while (B_OK == vr.GetNextVolume(&vol)) {
			fs_info info;
			if (B_OK != GetValidDriveInfo(vol.Device(), &info)) continue;
			drive--;
			if (0 != drive) continue;
			rc = TRUE;
			if (NULL != lpVolumeNameBuffer) {
				char name[PATH_MAX];
				if (B_OK == vol.GetName(name)) snprintf(lpVolumeNameBuffer, nVolumeNameSize, name);
				else rc = FALSE;
			}
			if (NULL != lpVolumeSerialNumber) *lpVolumeSerialNumber = 0;
			if (NULL != lpMaximumComponentLength) *lpMaximumComponentLength = 255;	// vfat's MAX
			if (NULL != lpFileSystemFlags) *lpFileSystemFlags = FS_CASE_IS_PRESERVED | FS_CASE_SENSITIVE | FS_UNICODE_STORED_ON_DISK;
			if (NULL != lpFileSystemNameBuffer) snprintf(lpFileSystemNameBuffer, nFileSystemNameSize, info.fsh_name);
			break;
		}
	}
	if (NULL != lpVolumeNameBuffer) WIN32API_INFO("\tlpVolumeNameBuffer = %s\n", lpVolumeNameBuffer);
	if (NULL != lpVolumeSerialNumber) WIN32API_INFO("\tlpVolumeSerialNumber = %08x\n", *lpVolumeSerialNumber);
	if (NULL != lpMaximumComponentLength) WIN32API_INFO("\tlpMaximumComponentLength = %d\n", *lpMaximumComponentLength);
	if (NULL != lpFileSystemFlags) WIN32API_INFO("\tlpFileSystemFlags = %08x\n", *lpFileSystemFlags);
	if (NULL != lpFileSystemNameBuffer) WIN32API_INFO("\tlpFileSystemNameBuffer = %s\n", lpFileSystemNameBuffer);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetVolumeInformationW
(LPCWSTR lpRootPathName, LPWSTR lpVolumeNameBuffer, DWORD nVolumeNameSize, LPDWORD lpVolumeSerialNumber, LPDWORD lpMaximumComponentLength,
	LPDWORD lpFileSystemFlags, LPWSTR lpFileSystemNameBuffer, DWORD nFileSystemNameSize)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetVolumeInformationW", "LPCWSTR", lpRootPathName, "LPWSTR", lpVolumeNameBuffer,
		"DWORD", nVolumeNameSize, "LPDWORD", lpVolumeSerialNumber, "LPDWORD", lpMaximumComponentLength,
		"LPDWORD", lpFileSystemFlags, "LPWSTR", lpFileSystemNameBuffer, "DWORD", nFileSystemNameSize, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetVolumeLabelA
(LPCSTR lpRootPathName, LPCSTR lpVolumeName)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetVolumeLabelA", "LPCSTR", lpRootPathName, "LPCSTR", lpVolumeName, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetVolumeLabelW
(LPCWSTR lpRootPathName, LPCWSTR lpVolumeName)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetVolumeLabelW", "LPCWSTR", lpRootPathName, "LPCWSTR", lpVolumeName, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetDiskFreeSpaceA
(LPCSTR lpRootPathName, LPDWORD lpSectorPerCluster, LPDWORD lpBytesPerSector,
	LPDWORD lpNumberOfFreeClusters, LPDWORD lpTotalNumberOfClusters)
{
	WIN32API_POINTER(lpRootPathName);
	WIN32API_ENTER("BOOL", "GetDiskFreeSpaceA", "LPCSTR", lpRootPathName, "LPDWORD", lpSectorPerCluster,
		"LPDWORD", lpBytesPerSector, "LPDWORD", lpNumberOfFreeClusters, "LPDWORD", lpTotalNumberOfClusters, NULL);
	Win32String root;
	root.SetToA(lpRootPathName);
	BOOL rc = GetDiskFreeSpaceU(root.StringU(), lpSectorPerCluster, lpBytesPerSector,
		lpNumberOfFreeClusters, lpTotalNumberOfClusters);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetDiskFreeSpaceW
(LPCWSTR lpRootPathName, LPDWORD lpSectorPerCluster, LPDWORD lpBytesPerSector,
	LPDWORD lpNumberOfFreeClusters, LPDWORD lpTotalNumberOfClusters)
{
	WIN32API_POINTER(lpRootPathName);
	WIN32API_ENTER("BOOL", "GetDiskFreeSpaceW", "LPCWSTR", lpRootPathName, "LPDWORD", lpSectorPerCluster,
		"LPDWORD", lpBytesPerSector, "LPDWORD", lpNumberOfFreeClusters, "LPDWORD", lpTotalNumberOfClusters, NULL);
	Win32String root;
	root.SetToW(lpRootPathName);
	BOOL rc = GetDiskFreeSpaceU(root.StringU(), lpSectorPerCluster, lpBytesPerSector,
		lpNumberOfFreeClusters, lpTotalNumberOfClusters);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetDiskFreeSpaceExA
(LPCSTR arg0, PULARGE_INTEGER arg1, PULARGE_INTEGER arg2, PULARGE_INTEGER arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetDiskFreeSpaceExA", "LPCSTR", arg0, "PULARGE_INTEGER", arg1, "PULARGE_INTEGER", arg2, "PULARGE_INTEGER", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetDiskFreeSpaceExW
(LPCWSTR arg0, PULARGE_INTEGER arg1, PULARGE_INTEGER arg2, PULARGE_INTEGER arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetDiskFreeSpaceExW", "LPCWSTR", arg0, "PULARGE_INTEGER", arg1, "PULARGE_INTEGER", arg2, "PULARGE_INTEGER", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}
