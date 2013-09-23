/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 とよしま
 *  $Id: OptionalHeader.h,v 1.1 2003/05/01 01:53:05 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [OptionalHeader.h]
 *   PE32+は定義だけでサポートしていない。
 * -------------------------------------------------------------------------------------------- */

#if !defined(__OptionalHeader_h__)
#	define	__OptionalHeader_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

// standard fields for PE32
typedef struct _StandardFields {
	PACKED(WORD magic);
	PACKED(BYTE majorLinkerVersion);
	PACKED(BYTE minorLinkerVersion);
	PACKED(DWORD sizeOfCode);
	PACKED(DWORD sizeOfInitializedData);
	PACKED(DWORD sizeOfUninitializedData);
	PACKED(DWORD addressOfEntryPoint);
	PACKED(DWORD baseOfCode);
	PACKED(DWORD baseOfData);
} StandardFields, *LpStandardFields;

// standard fields for PE32+
typedef struct _StandardFieldsPlus {
	PACKED(WORD magic);
	PACKED(BYTE majorLinkerVersion);
	PACKED(BYTE minorLinkerVersion);
	PACKED(DWORD sizeOfCode);
	PACKED(DWORD sizeOfInitializedData);
	PACKED(DWORD sizeOfUninitializedData);
	PACKED(DWORD addressOfEntryPoint);
	PACKED(DWORD baseOfCode);
} StandardFieldsPlus, *LpStandardFieldsPlus;

// windows specific fields for PE32
typedef struct _WindowsSpecificFields {
	PACKED(DWORD imageBase);
	PACKED(DWORD sectionAlignment);
	PACKED(DWORD fileAlignment);
	PACKED(WORD majorOperatingSystemVersion);
	PACKED(WORD minorOperatingSystemVersion);
	PACKED(WORD majorImageVersion);
	PACKED(WORD minorImageVersion);
	PACKED(WORD majorSubsystemVersion);
	PACKED(WORD minorSubsystemVersion);
	PACKED(DWORD Reserved);
	PACKED(DWORD sizeOfImage);
	PACKED(DWORD sizeOfHeaders);
	PACKED(DWORD checkSum);
	PACKED(WORD subsystem);
	PACKED(WORD dllCharacteristics);
	PACKED(DWORD sizeOfStackReserve);
	PACKED(DWORD sizeOfStackCommit);
	PACKED(DWORD sizeOfHeapReserve);
	PACKED(DWORD sizeOfHeapCommit);
	PACKED(DWORD loaderFlags);
	PACKED(DWORD numberOfRvaAndSizes);
} WindowsSpecificFields, *LpWindowsSpecificFields;

// windows specific fields for PE32+
typedef struct _WindowsSpecificFieldsPlus {
	PACKED(QWORD imageBase);
	PACKED(DWORD sectionAlignment);
	PACKED(DWORD fileAlignment);
	PACKED(WORD majorOperatingSystemVersion);
	PACKED(WORD minorOperatingSystemVersion);
	PACKED(WORD majorImageVersion);
	PACKED(WORD minorImageVersion);
	PACKED(WORD majorSubsystemVersion);
	PACKED(WORD minorSubsystemVersion);
	PACKED(DWORD Reserved);
	PACKED(DWORD sizeOfImage);
	PACKED(DWORD sizeOfHeaders);
	PACKED(DWORD checkSum);
	PACKED(WORD subsystem);
	PACKED(WORD dllCharacteristics);
	PACKED(QWORD sizeOfStackReserve);
	PACKED(QWORD sizeOfStackCommit);
	PACKED(QWORD sizeOfHeapReserve);
	PACKED(QWORD sizeOfHeapCommit);
	PACKED(DWORD loaderFlags);
	PACKED(DWORD numberOfRvaAndSizes);
} WindowsSpecificFieldsPlus, *LpWindowsSpecificFieldsPlus;

// data directory
typedef struct _DataDirectory {
	PACKED(DWORD rva);
	PACKED(DWORD size);
} DataDirectory, *LpDataDirectory;

// optional header for PE32
typedef struct _OptionalHeaderPE32 {
	StandardFields standardFields;
	WindowsSpecificFields windowsSpecificFields;
	DataDirectory dataDirectories;
} OptionalHeaderPE32, *LpOptionalHeaderPE32;

// optional header for PE32+
typedef struct _OptionalHeaderPE32plus {
	StandardFieldsPlus standardFieldsPlus;
	WindowsSpecificFieldsPlus windowsSpecificFields;
	DataDirectory dataDirectories;
} OptionalHeaderPE32plus, *LpOptionalHeaderPE32plus;

// optional header
typedef struct _OptionalHeader {
	union {
		OptionalHeaderPE32 pe32;
		OptionalHeaderPE32plus pe32plus;
	};
} OptionalHeader, *LpOptionalHeader;

// magic number
typedef enum _PeMagicNumber {
	MAGIC_PE32										= 0x010b,
	MAGIC_PE32PLUS									= 0x020b,
} PeMagicNumber;

// windows subsystem
typedef enum _WindowsSubsystems {
	IMAGE_SUBSYSTEM_UNKNOWN							= 0,
	IMAGE_SUBSYSTEM_NATIVE,
	IMAGE_SUBSYSTEM_WINDOWS_GUI,
	IMAGE_SUBSYSTEM_WINDOWS_CUI,
	IMAGE_SUBSYSTEM_POSIX_CUI						= 7,
	IMAGE_SUBSYSTEM_WINDOWS_CE_GUI					= 9,
	IMAGE_SUBSYSTEM_EFI_APPLICATION,
	IMAGE_SUBSYSTEM_EFI_BOOT_SERVICE_DRIVER,
	IMAGE_SUBSYSTEM_EFI_RUNTIME_DRIVER,
} WindowsSubsystems;

// dll characteristics
typedef enum _DllCharacteristics {
	IMAGE_DLLCHARACTERISTICS_NO_BIND				= 0x0800,
	IMAGE_DLLCHARACTERISTICS_WDM_DRIVER				= 0x2000,
	IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE	= 0x8000,
} DllCharacteristics;

// rva entries
typedef enum _RvaEntryTypes {
	RVA_EXPORT_TABLE								= 0,
	RVA_IMPORT_TABLE,
	RVA_RESOURCE_TABLE,
	RVA_EXCEPTION_TABLE,
	RVA_CERTIFICATE_TABLE,
	RVA_BASE_RELOCATION_TABLE,
	RVA_DEBUG_DATA,
	RVA_ARCHITECTURE_SPECIFIC_DATA,
	RVA_GLOBAL_POINTER,
	RVA_THREAD_LOCAL_STORAGE_TABLE,
	RVA_LOAD_CONFIG_TABLE,
	RVA_BOUND_IMPORT,
	RVA_INPORT_ADDRESS_TABLE,
	RVA_DELAY_IMPORT_DESCRIPTOR,
	RVA_COMPLUS_RUNTIME_HEADER,
	RVA_RESERVED,
} RvaRntryTypes;

#	if !defined(__OptionalHeader__)
#		define	__OptionalHeader__
#	endif	// !defined(__OptionalHeader__)

#endif	// !defioned(__OptionalHeader_h__)
