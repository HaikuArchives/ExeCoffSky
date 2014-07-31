/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 ‚Æ‚æ‚µ‚Ü
 *  $Id: wtrace.cpp,v 1.1 2003/05/01 02:41:08 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [wtrace.cpp]
 * -------------------------------------------------------------------------------------------- */
#define	__Main__
#include "Common.h"
#undef	__Main__
#include "load_dll.h"

class WTrace: public BApplication {
private:
	const char *path;
	bool dynreloc;
public:
	WTrace(const char *path, bool dynreloc):
		BApplication("application/x-vnd.toyoshima-house.wtrace"),
		path(path),
		dynreloc(dynreloc) {};
	void ReadyToRun(void) {
		thread_id id = spawn_thread(Main, "win32 trace", B_NORMAL_PRIORITY, (void *)this);
		if (id >= B_OK) resume_thread(id);
	};
	static int32 Main(void *arg) {
		ShiftProcess(((WTrace *)arg)->path, ((WTrace *)arg)->dynreloc);
		exit(0);
	};
};

int
main(int argc, char **argv)
{
	if ((argc != 2) && (argc != 3)) {
		fprintf(stderr, "Usage: wtrace [-d] <exefile>\n\n");
		exit(1);
	}
	const char *fname = argv[1];
	bool dynreloc = false;
	if (3 == argc) {
		fname = argv[2];
		if (0 == strcmp(argv[1], "-d")) dynreloc = true;
	} 
	dup2(STDOUT_FILENO, STDERR_FILENO);	// 2>&1
	BEntry entry(fname);
	BPath path;
	entry.GetPath(&path);
	WTrace wt(path.Path(), dynreloc);
	wt.Run();
	exit(0);
}
