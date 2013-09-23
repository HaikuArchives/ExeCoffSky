/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: Win32Client.cpp,v 1.1 2003/05/01 02:41:08 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Win32Client.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "Win32Client.h"
#include "load_dll.h"

Win32Client::Win32Client
(const char *path):
BApplication(WIN32CLIENT_TYPE),
thread(-1)
{
	this->path = strdup(path);
}

Win32Client::~Win32Client
(void)
{
	if (NULL != path) free(path);
}

void
Win32Client::ReadyToRun
(void)
{
	thread = spawn_thread(Win32Main, "win32 main", B_NORMAL_PRIORITY, (void *)path);
	if (thread > B_OK) resume_thread(thread);
}

int32
Win32Client::Win32Main
(void *data)
{
	const char *path = (const char *)data;
	BEntry entry;
	BPath p;
	if ((B_OK == entry.SetTo(path)) && (B_OK == entry.GetPath(&p))) {
		BString str(path);
		str.RemoveLast(p.Leaf());
		str.RemoveLast("/");
		chdir(str.String());
		path = p.Leaf();
	}
	ShiftProcess(path);
	return 0;
}
