/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 とよしま
 *  $Id: Volume.h,v 1.1 2003/05/01 02:57:17 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Volume.h]
 *  BeOSとWindowsのドライブの対応関係は、
 *  A: => rootfs
 *  B: => Application Path (as CD-ROM)
 *  C:, D:, ... => volumes
 * -------------------------------------------------------------------------------------------- */

#if !defined(__Volume_h__)
#	define	__Volume_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if !defined(__Win32Structures_h__)
#		include "Win32Structures.h"
#	endif	// !defined(__Win32Structures_h__)

#	define	DRIVE_UNKNOWN					0
#	define	DRIVE_NO_ROOT_DIR				1
#	define	DRIVE_REMOVABLE					2
#	define	DRIVE_FIXED						3
#	define	DRIVE_REMOTE					4
#	define	DRIVE_CDROM						5
#	define	DRIVE_RAMDISK					6

#	define	FILE_CASE_SENSITIVE_SEARCH		0x00000001
#	define	FILE_CASE_PRESERVED_NAMES		0x00000002
#	define	FILE_UNICODE_ON_DISK			0x00000004
#	define	FILE_PERSISTENT_ACLS			0x00000008
#	define	FILE_FILE_COMPRESSION			0x00000010
#	define	FILE_VOLUME_QUOTAS				0x00000020
#	define	FILE_SUPPORTS_SPARSE_FILES		0x00000040
#	define	FILE_SUPPORTS_REPARSE_FILES		0x00000080
#	define	FILE_SUPPORTS_REMOTE_STORAGE	0x00000100
#	define	FILE_VOLUME_IS_COMPRESSED		0x00008000
#	define	FILE_SUPPORTS_OBJECT_IDS		0x00010000
#	define	FILE_SUPPORTS_ENCRYPTION		0x00020000

#	define	FS_CASE_IS_PRESERVED		FILE_CASE_PRESERVED_NAMES
#	define	FS_CASE_SENSITIVE			FILE_CASE_SENSITIVE_SEARCH
#	define	FS_UNICODE_STORED_ON_DISK	FILE_UNICODE_ON_DISK
#	define	FS_PERSISTENT_ACLS			FILE_PERSISTENT_ACLS
#	define	FS_FILE_COMPRESSION			FILE_FILE_COMPRESSION
#	define	FS_VOL_IS_COMPRESSED		FILE_VOLUME_IS_COMPRESSED

static int GetDriveNumber(LPCTSTR lpRootPathName);
static int GetValidDriveInfo(dev_t dev, fs_info *info);
int GetNativePathFromDrive(int drive, char *buffer, int size);

static BOOL GetDiskFreeSpaceU(LPCSTR lpRootPathName, LPDWORD lpSectorPerCluster,
	LPDWORD lpBytesPerSector, LPDWORD lpNumberOfFreeClusters, LPDWORD lpTotalNumberOfClusters);

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

UINT WINAPI GetDriveTypeA(LPCSTR lpRootPathName);
UINT WINAPI GetDriveTypeW(LPCWSTR lpRootPathName);
DWORD WINAPI GetLogicalDriveStringsA(DWORD nBufferLength, LPSTR lpBuffer);
DWORD WINAPI GetLogicalDriveStringsW(DWORD nBufferLength, LPWSTR lpBuffer);
DWORD WINAPI GetLogicalDrives(void);
BOOL WINAPI GetVolumeInformationA(LPCSTR lpRootPathName, LPSTR lpVolumeNameBuffer, DWORD nVolumeNameSize, LPDWORD lpVolueSerialNumber,
	LPDWORD lpMaximumComponentLength, LPDWORD lpFileSystemFlags, LPSTR lpFileSystemNameBuffer, DWORD nFileSystemNameSize);
BOOL WINAPI GetVolumeInformationW(LPCWSTR lpRootPathName, LPWSTR lpVolumeNameBuffer, DWORD nVolumeNameSize, LPDWORD lpVolumeSerialNumber,
	LPDWORD lpMaximumComponentLength, LPDWORD lpFileSystemFlags, LPWSTR lpFileSystemNameBuffer, DWORD nFileSystemNameSize);
BOOL WINAPI SetVolumeLabelA(LPCSTR lpRootPathName, LPCSTR lpVolumeName);
BOOL WINAPI SetVolumeLabelW(LPCWSTR lpRootPathName, LPCWSTR lpVolumeName);

BOOL WINAPI GetDiskFreeSpaceA(LPCSTR lpRootPathName, LPDWORD lpSectorPerCluster,
	LPDWORD lpBytesPerSector, LPDWORD lpNumberOfFreeClusters, LPDWORD lpTotalNumberOfClusters);
BOOL WINAPI GetDiskFreeSpaceW(LPCWSTR lpRootPathName, LPDWORD lpSectorPerCluster,
	LPDWORD lpBytesPerSector, LPDWORD lpNumberOfFreeClusters, LPDWORD lpTotalNumberOfClusters);
BOOL WINAPI GetDiskFreeSpaceExA(LPCSTR lpRootPathName, PULARGE_INTEGER lpFreeBytesAvailable,
	PULARGE_INTEGER lpTotalNumberOfBytes, PULARGE_INTEGER lpTotalNumberOfFreeBytes);
BOOL WINAPI GetDiskFreeSpaceExW(LPCWSTR lpRootPathName, PULARGE_INTEGER lpFreeBytesAvailable,
	PULARGE_INTEGER lpTotalNumberOfBytes, PULARGE_INTEGER lpTotalNumberOfFreeBytes);

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__Volume_h__)
