/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 ‚Æ‚æ‚µ‚Ü
 *  $Id: load_dll.cpp,v 1.1 2003/05/01 01:33:56 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [load_dll.c]
 * -------------------------------------------------------------------------------------------- */
#define	__Main__
#include "Common.h"
#undef	__Main__
#define	LD_DLL	__declspec(dllexport)
#include "load_dll.h"
#include "Coff.h"
#include "File32.h"
#include "Process.h"

void
ShiftProcess
(const char *path, bool dynreloc)
{
	// load image
	Coff coff(path);
	if (COFF_ERR_OK != coff.Load(!dynreloc)) return;

	// create process information
	STARTUPINFOA info;
	memset(&info, 0, sizeof(STARTUPINFOA));
	info.cb = sizeof(STARTUPINFOA);
	info.dwFlags = STARTF_USESTDHANDLES;
	File stdin(STDIN_FILENO);
	File stdout(STDOUT_FILENO);
	File stderr(STDERR_FILENO);
	info.hStdInput = (HANDLE)&stdin;
	info.hStdOutput = (HANDLE)&stdout;
	info.hStdError = (HANDLE)&stderr;

	Process process;
	process.SetStartupInfoA(&info);
	process.SetInstance(coff.GetInstance());
	
	BPath bpath(path);
	bpath.GetParent(&bpath);
	process.SetStartupDirectory(bpath.Path());

	// import external functions
	if (COFF_ERR_OK != coff.Import()) return;
	
	// process start
	coff.ProcessAttach();
	return;
}
