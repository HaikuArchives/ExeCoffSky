/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: COM.h,v 1.1 2003/05/01 02:42:02 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [COM.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__COM_h__)
#	define __COM_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if defined(__cplusplus)
#		define	EXTERN_C	extern "C"
#	else
#		define	EXTERN_C
#	endif	// defined(__cplusplus)

#	if !defined(INITGUID)
#		define DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
			EXTERN_C const GUID name
#	else
#		define DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
			EXTERN_C const GUID name = \
				{ l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }
#	endif // !defined(INITGUID)

#	if !defined(interface)
#		define	interface	struct
#	endif	// !defined(interface)

#	if !defined(BEGIN_INTERFACE)
#		define	BEGIN_INTERFACE
#	endif	// !defined(BEGIN_INTERFACE)

#	if !defined(END_INTERFACE)
#		define	END_INTERFACE
#	endif	// !defined(ENT_INTERFACE)

#	if !defined(STDMETHODCALLTYPE)
#		define	STDMETHODCALLTYPE	WINAPI
#	endif	// !defined(STDMETHODCALLTYPE)

#	if !defined(STDMETHOD)
#		define	STDMETHOD(method)	virtual HRESULT STDMETHODCALLTYPE method
#	endif	// defined(STDMETHOD)

#	if !defined(STDMETHOD_)
#		define	STDMETHOD_(r, method)	virtual r STDMETHODCALLTYPE method
#	endif	// !defined(STDMETHOD_)

#	if !defined(PURE)
#		define	PURE	= NULL
#	endif	// !defined(PURE)

#	if defined(_DEBUG)
#		define	WIN32API_GUID(name, riid) \
			WIN32API_INFO("\t%s = {%08x-%04x-%04x-%02x%02x-%02x%02x%02x&02x}\n", name, \
			((REFIID)(riid))->x, ((REFIID)(riid))->s1, ((REFIID)(riid))->s2, \
			((REFIID)(riid))->c[0], ((REFIID)(riid))->c[1], \
			((REFIID)(riid))->c[2], ((REFIID)(riid))->c[3], ((REFIID)(riid))->c[4], \
			((REFIID)(riid))->c[5], ((REFIID)(riid))->c[6], ((REFIID)(riid))->c[7])
#	else // defined(_DEBUG)
#		define	WIN32API_GUID(name, riid)
#		define	WIN32API_IID(riid)
#	endif	// defined(_DEBUG)

#endif	// !defined(__COM_h__)
