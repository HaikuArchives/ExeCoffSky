/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 ‚Æ‚æ‚µ‚Ü
 *  $Id: Win32Trace.cpp,v 1.1 2003/05/01 02:55:03 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Win32Trace.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "Win32Trace.h"
#include "Process.h"
#include "Coff.h"

BLocker
Win32Trace::lk;

int
Win32Trace::logcount = 0;

int
Win32Trace::infoflag = 0;

void
Win32Trace::Enter
(const char *rtype, ...)
{
	Lock();
	if (0 == logcount) {
		va_list ap;
		void *a, *b;
		va_start(ap, rtype);
		a = va_arg(ap, void *);
		if (NULL == a) {
			fprintf(stderr, "%s\n", rtype);
			Unlock();
			return;
		}
		fprintf(stderr, "%s %s(", rtype, (char *)a);
		bool first = true;
		for (;;) {
			a = va_arg(ap, void *);
			if (NULL == a) break;
			if (first) first = false;
			else fprintf(stderr, "%s", ", ");
			if (0 == strcasecmp("VOID", (char *)a)) {
				fprintf(stderr, "%s", "VOID");
				break;
			}
			b = va_arg(ap, void *);
			fprintf(stderr, "%s $%08x", (char *)a, (int)b);
		}
		fprintf(stderr, ")\n");
		fflush(stderr);
		va_end(ap);
	}
	Unlock();
}

void
Win32Trace::Leave
(void *rc)
{
	Lock();
	if (0 == logcount) {
		fprintf(stderr, "  -> $%08x\n", (int)rc);
		fflush(stderr);
	}
	Unlock();
}

void
Win32Trace::Information
(const char *fmt, ...)
{
	Lock();
	if (0 == infoflag) {
		va_list list;
		va_start(list, fmt);
		vfprintf(stderr, fmt, list);
		fflush(stderr);
		va_end(list);
	}
	Unlock();
}

void
Win32Trace::Relocate
(void **ptr)
{
	Lock();
	unsigned long addr = (unsigned long)*ptr;
	Process *process = Process::GetCurrentProcessObject();
	if (NULL == process) return;
	Coff *coff = Coff::InstanceToCoff(process->GetInstance());
	if (NULL == coff) return;
	if (coff->Relocate(addr)) *ptr = (void *)addr;
	Unlock();
}

void
Win32Trace::Logging
(bool on)
{
	Lock();
	if (on) logcount++;
	else logcount--;
	Unlock();
}

int
Win32Trace::Logging
(int count)
{
	Lock();
	int rc = logcount;
	logcount = count;
	Unlock();
	return rc;
}

void
Win32Trace::InformationMode
(bool on)
{
	Lock();
	if (on) {
		if (0 != infoflag) infoflag--;
	} else infoflag++;
	Unlock();
}
