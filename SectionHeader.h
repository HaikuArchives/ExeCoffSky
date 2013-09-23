/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 ‚Æ‚æ‚µ‚Ü
 *  $Id: SectionHeader.h,v 1.1 2003/05/01 01:53:05 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [SectionHeader.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__SectionHeader_h__)
#	define	__SectionHeader_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

// section table
typedef struct _SectionHeader {
	PACKED(CHAR name[8]);
	PACKED(DWORD virtualSize);
	PACKED(DWORD virtualAddress);
	PACKED(DWORD sizeOfRawData);
	PACKED(DWORD pointerToRawData);
	PACKED(DWORD pointerToRelocations);
	PACKED(DWORD pointerToLinenumbers);
	PACKED(WORD numberOfRelocations);
	PACKED(WORD numberOfLinenumbers);
	PACKED(DWORD characteristics);
} SectionHeader, *LpSectionHeader;

// characteristics
typedef enum _SectionCharacteristics {
	IMAGE_SCN_TYPE_REG					= 0x00000000,
	IMAGE_SCN_TYPE_DSECT				= 0x00000001,
	IMAGE_SCN_TYPE_NOLOAD				= 0x00000002,
	IMAGE_SCN_TYPE_GROUP				= 0x00000004,
	IMAGE_SCN_TYPE_NO_PAD				= 0x00000008,
	IMAGE_SCN_TYPE_COPY					= 0x00000010,

	IMAGE_SCN_CNT_CODE					= 0x00000020,
	IMAGE_SCN_CNT_INITIALIZED_DATA		= 0x00000040,
	IMAGE_SCN_CNT_UNINITIALIZED_DATA	= 0x00000080,

	IMAGE_SCN_LNK_OTHER					= 0x00000100,
	IMAGE_SCN_LNK_INFO					= 0x00000200,

	IMAGE_SCN_TYPE_OVER					= 0x00000400,

	IMAGE_SCN_LNK_REMOVE				= 0x00000800,
	IMAGE_SCN_LNK_COMDAT				= 0x00001000,

	IMAGE_SCN_MEM_FARDATA				= 0x00008000,
	IMAGE_SCN_MEM_PURGEABLE				= 0x00010000,
	IMAGE_SCN_MEM_16BIT					= 0x00020000,
	IMAGE_SCN_MEM_LOCKED				= 0x00040000,
	IMAGE_SCN_MEM_PRELOAD				= 0x00080000,

	IMAGE_SCN_ALIGN_1BYTES				= 0x00100000,
	IMAGE_SCN_ALIGN_2BYTES				= 0x00200000,
	IMAGE_SCN_ALIGN_4BYTES				= 0x00300000,
	IMAGE_SCN_ALIGN_8BYTES				= 0x00400000,
	IMAGE_SCN_ALIGN_16BYTES				= 0x00500000,
	IMAGE_SCN_ALIGN_32BYTES				= 0x00600000,
	IMAGE_SCN_ALIGN_64BYTES				= 0x00700000,
	IMAGE_SCN_ALIGN_128BYTES			= 0x00800000,
	IMAGE_SCN_ALIGN_256BYTES			= 0x00900000,
	IMAGE_SCN_ALIGN_512BYTES			= 0x00a00000,
	IMAGE_SCN_ALIGN_1024BYTES			= 0x00b00000,
	IMAGE_SCN_ALIGN_2048BYTES			= 0x00c00000,
	IMAGE_SCN_ALIGN_4096BYTES			= 0x00d00000,
	IMAGE_SCN_ALIGN_8192BYTES			= 0x00e00000,

	IMAGE_SCN_LNK_NRELOC_OVFL			= 0x01000000,

	IMAGE_SCN_MEM_DISCARDABLE			= 0x02000000,
	IMAGE_SCN_MEM_NOT_CACHED			= 0x04000000,
	IMAGE_SCN_MEM_NOT_PAGED				= 0x08000000,
	IMAGE_SCN_MEM_SHARED				= 0x10000000,
	IMAGE_SCN_MEM_EXECUTE				= 0x20000000,
	IMAGE_SCN_MEM_READ					= 0x40000000,
	IMAGE_SCN_MEM_WRITE					= 0x80000000,
} SectionCharacteristics;

#	if !defined(__SectionHeader__)
#		define	__SectionHeader__
#	endif	// !defined(__SectionHeader__)

#endif	// !defined(__SectionHeader_h__)
