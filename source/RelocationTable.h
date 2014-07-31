/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 ‚Æ‚æ‚µ‚Ü
 *  $Id: RelocationTable.h,v 1.1 2003/05/01 01:53:05 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [RelocationTable.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__RelocationTable_h__)
#	define	__RelocationTable_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

// fixup block header
typedef struct _RelocationTable {
	PACKED(DWORD pageRva);
	PACKED(DWORD blockSize);
} RelocationTable, *LpRelocationTable;

// fixup block
typedef struct _FixupBlock {
	PACKED(WORD offset:12);
	PACKED(WORD type:4);
} FixupBlock, *LpFixupBlock;

// fixup type
typedef enum _FixupType {
	IMAGE_REL_BASED_ABSOLUTE	= 0,
	IMAGE_REL_BASED_HIGH,
	IMAGE_REL_BASED_LOW,
	IMAGE_REL_BASED_HIGHLOW,
	IMAGE_REL_BASED_HIGHADJ,
	IMAGE_REL_BASED_MIPS_JMPADDR,
	IMAGE_REL_BASED_SECTION,
	IMAGE_REL_BASED_REL32,
	IMAGE_REL_BASED_MIPS_JMPADDR16,
	IMAGE_REL_BASED_DIR64,
	IMAGE_REL_BASED_HIGH3ADJ,
} FixupType;

#	if !defined(__RelocationTable__)
#		define	__RelocationTable__
#	endif	// !defined(__RelocationTable__)

#endif	// !defined(__RelocationTable_h__)
