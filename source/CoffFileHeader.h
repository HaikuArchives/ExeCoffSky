/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 ‚Æ‚æ‚µ‚Ü
 *  $Id: CoffFileHeader.h,v 1.1 2003/05/01 01:53:05 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [CoffFileHeader.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__CoffFileHeader_h__)
#	define	__CoffFileHeader_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

// COFF file header
typedef struct _CoffFileHeader {
	PACKED(WORD machine);
	PACKED(WORD numberOfSections);
	PACKED(DWORD timeDateStamp);
	PACKED(DWORD pointerToSymbolTable);
	PACKED(DWORD numberOfSymbols);
	PACKED(WORD sizeOfOptionalHeader);
	PACKED(WORD characteristics);
} CoffFileHeader, *LpCoffFileHeader;

// signature
#define	PE_SIGNATURE		"PE\0\0"
#define	PE_SIGNATURE_SIZE	4

// machine
typedef enum _CoffMachineType {
	IMAGE_FILE_MACHINE_UNKNOWN		= 0x0000,
	IMAGE_FILE_MACHINE_ALPHA		= 0x0184,
	IMAGE_FILE_MACHINE_ARM			= 0x01c0,
	IMAGE_FILE_MACHINE_ALPHA64		= 0x0284,
	IMAGE_FILE_MACHINE_I386			= 0x014c,
	IMAGE_FILE_MACHINE_IA64			= 0x0200,
	IMAGE_FILE_MACHINE_M68K			= 0x0268,
	IMAGE_FILE_MACHINE_MIPS16		= 0x0266,
	IMAGE_FILE_MACHINE_MIPSFPU		= 0x0366,
	IMAGE_FILE_MACHINE_MIPSFPU16	= 0x0466,
	IMAGE_FILE_MACHINE_POWERPC		= 0x01f0,
	IMAGE_FILE_MACHINE_R3000		= 0x0162,
	IMAGE_FILE_MACHINE_R4000		= 0x0166,
	IMAGE_FILE_MACHINE_R10000		= 0x0168,
	IMAGE_FILE_MACHINE_SH3			= 0x01a2,
	IMAGE_FILE_MACHINE_SH4			= 0x01a6,
	IMAGE_FILE_MACHINE_THUMB		= 0x01c2,
} CoffMachineType;

// characteristics
typedef enum CoffCharacteristics {
	IMAGE_FILE_RELOCS_STRIPPED		= 0x0001,
	IMAGE_FILE_EXECUTABLE_IMAGE		= 0x0002,
	IMAGE_FILE_LINE_NUMS_STRIPPED	= 0x0004,
	IMAGE_FILE_LOCAL_SYMS_STRIPPED	= 0x0008,
	IMAGE_FILE_AGGRESSIVE_WS_TRIM	= 0x0010,
	IMAGE_FILE_LARGE_ADDRESS_AWARE	= 0x0020,
	IMAGE_FILE_16BIT_MACHINE		= 0x0040,
	IMAGE_FILE_BYTES_REVERSED_LO	= 0x0080,
	IMAGE_FILE_32BIT_MACHINE		= 0x0100,
	IMAGE_FILE_DEBUG_STRIPPED		= 0x0200,
	IMAGE_FILE_REMOVABLE_RUN_FROM_SWAP	= 0x0400,
	IMAGE_FILE_SYSTEM				= 0x1000,
	IMAGE_FILE_DLL					= 0x2000,
	IMAGE_FILE_UP_SYSTEM_ONLY		= 0x4000,
	IMAGE_FILE_BYTES_REVERSED_HI	= 0x8000,
} CoffCharacteristics;

#	if !defined(__CoffFileHeader__)
#		define	__CoffFileHeader__
#	endif	// !defined(__CoffFileHeader__)

#endif	// !defined(__CoffFileHeader_h__)
