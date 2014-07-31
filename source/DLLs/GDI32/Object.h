/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 とよしま
 *  $Id: Object.h,v 1.1 2003/05/01 03:05:18 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Object.h]
 *  DeleteObjectで破棄できるオブジェクトはObjectを継承している必要がある。
 * -------------------------------------------------------------------------------------------- */

#if !defined(__Object_h__)
#	define	__Object_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	define	OBJECT_MAGIC	'_GOb'

class Object {
public:
	DWORD magic;
public:
	Object(void);
	virtual ~Object(void);
	
	static Object *HandleToObject(HGDIOBJ hObject);
};

#	if !defined(__Object__)
#		define	__Object__
#	endif	// !defined(__Object__)

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

BOOL WINAPI DeleteObject(HGDIOBJ hObject);
HGDIOBJ WINAPI SelectObject(HDC hDc, HGDIOBJ hgdiobj);

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__Object_h__)
