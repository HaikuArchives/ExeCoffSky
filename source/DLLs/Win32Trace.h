/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 ‚Æ‚æ‚µ‚Ü
 *  $Id: Win32Trace.h,v 1.1 2003/05/01 02:43:55 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Win32Trace.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__Win32Trace_h__)
#	define	__Win32Trace_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if !defined(__LastError_h__)
#		include "LastError.h"
#	endif	// !defined(__LastError_h__)

#	if !defined(__Coff_h__)
#		include "Coff.h"
#	endif	// !defined(__Coff_h__)

#	if defined(ENABLE_DYNAMIC_RELOCATION)
static const bool ___dynreloc = true;
#	else	// defined(ENABLE_DYNAMIC_RELOCATION)
static const bool ___dynreloc = false;
#	endif	// defined(ENABLE_DYNAMIC_RELOCATION)

#	if defined(_DEBUG)
static const bool ___debug = true;
#	else	// defined(_DEBUG)
static const bool ___debug = false;
#	endif	// defined(_DEBUG)

class Win32Trace {
private:
	static BLocker lk;
	static int logcount;
	static int infoflag;
public:
	static void Enter(const char *rtype, ...);
	static void Leave(void *rc);
	static void Information(const char *fmt, ...);
	static void Relocate(void **ptr);
	static void Logging(bool on = true);
	static int Logging(int count);
	static void InformationMode(bool on = true);
private:
	static inline void Lock(void) { lk.Lock(); };
	static inline void Unlock(void) { lk.Unlock(); };
};

#	if !defined(__Win32Trace__)
#		define	__Win32Trace__
#	endif	// !defined(__Win32Trace__)

#	define	WIN32API_ENTER	if (___debug) Win32Trace::Enter
#	define	WIN32API_LEAVE(rc)	if (___debug) Win32Trace::Leave((void *)rc)
#	define	WIN32API_INFO	if (___debug) Win32Trace::Information
#	define	WIN32API_POINTER(ptr)	if (___dynreloc) Win32Trace::Relocate((void **)&ptr)
#	define	WIN32API_INTERNAL_START()	if (___debug) Win32Trace::Logging(false)
#	define	WIN32API_INTERNAL_END()	if (___debug) Win32Trace::Logging(true)
#	define	WIN32API_INTERNAL_GET(x)	if (___debug) x = Win32Trace::Logging(0)
#	define	WIN32API_INTERNAL_SET(x)	if (___debug) Win32Trace::Logging(x)
#	define	WIN32API_ERROR(x)	{ WIN32API_INTERNAL_START(); SetLastError(x); WIN32API_INTERNAL_END(); }
#	define	WIN32API_INFO_ON()	if (___debug) Win32Trace::InformationMode(true)
#	define	WIN32API_INFO_OFF()	if (___debug) Win32Trace::InformationMode(false)

#endif	// !defined(__Win32Trace_h__)
