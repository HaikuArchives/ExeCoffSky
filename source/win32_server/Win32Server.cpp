/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 とよしま
 *  $Id: Win32Server.cpp,v 1.1 2003/05/01 02:41:08 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Win32Server.cpp]
 * TODO: 子プロセスが死んだ際の、グローバルリソースの開放。
 * -------------------------------------------------------------------------------------------- */
#include "Win32Server.h"
#include "Win32Client.h"

Win32Server::Win32Server
(void):
BApplication(WIN32SERVER_TYPE),
port(-1),
thread(-1)
{
}

void
Win32Server::ReadyToRun
(void)
{
	port = create_port(100, "win32 server");
	DOUT("win32 server port: %d\n", port);
	thread = spawn_thread(ServiceLoop, "win32 service", B_NORMAL_PRIORITY, (void *)port);
	if (thread >= B_OK) {
		resume_thread(thread);
	}
	SetMIME();
}

bool
Win32Server::QuitRequested
(void)
{
	if (port >= B_OK) {
		delete_port(port);
		status_t ev;
		if (thread >= B_OK) wait_for_thread(thread, &ev);
	}
	return true;
}

void
Win32Server::RefsReceived
(BMessage *msg)
{
	uint32 type;
	int32 count;
	if (B_OK == msg->GetInfo("refs", &type, &count)) {
		if (type != B_REF_TYPE) return;
		entry_ref ref;
		for (int i = 0; i < count; i++) {
			if (B_OK != msg->FindRef("refs", 0, &ref)) continue;
			BEntry entry;
			if (B_OK != entry.SetTo(&ref)) continue;
			BPath path;
			if (B_OK != entry.GetPath(&path)) continue;
			DOUT("launch %s\n", path.Path());
			Launch(&path);
		}
	}
}

void
Win32Server::Launch
(BPath *path)
{
	if (NULL == path) return;
	app_info info;
	if (B_OK != be_app->GetAppInfo(&info)) return;
	struct stat st;
	bool make = true;
	if (0 == stat("/tmp/.win32_server/Windows", &st)) {
		struct stat s_st;
		BEntry entry;
		if ((B_OK == entry.SetTo(&info.ref)) && (B_OK == entry.GetStat(&s_st)) &&
				(st.st_size == s_st.st_size) && (st.st_mtime > s_st.st_mtime)) {
			make = false;
		}
	}
	if (make) {
		if (0 != stat("/tmp", &st)) mkdir("/tmp", 0777);
		if (0 != stat("/tmp/.win32_server", &st)) mkdir("/tmp/.win32_server", 0777);
		BFile dst("/tmp/.win32_server/Windows", B_READ_WRITE | B_CREATE_FILE | B_ERASE_FILE);
		BFile src(&info.ref, B_READ_ONLY);
		off_t size;
		if (B_OK != src.GetSize(&size)) return;
		char *buf = new char[size];
		if (NULL == buf) return;
		try {
			ssize_t readsize = src.Read(buf, size);
			if (readsize != size) throw false;
			ssize_t writtensize = dst.Write(buf, size);
			if (writtensize != size) throw false;
			} catch (bool e) {
		delete buf;
			return;
		}
		delete buf;
		BResources res;
		if (B_OK == res.SetTo(&dst)) {
			res.AddResource(B_MIME_STRING_TYPE, 1,
				WIN32CLIENT_TYPE, sizeof(WIN32CLIENT_TYPE), "BEOS:APP_SIG");
			res.AddResource('APPF', 1, "\1\0\0\0", 4, "BEOS:APP_FLAGS");
		}
		update_mime_info("/tmp/.win32_server/Windows", true, false, 2);
	}
	int argc = 3;
	const char *argv[] = {
		"/tmp/.win32_server/Windows",
		"!e",
		path->Path(),
		NULL,
	};
	thread_id id = load_image(argc, (const char **)argv, (const char **)environ);
	if (id >= B_OK) resume_thread(id);
}

void
Win32Server::SetMIME
(void)
{
	BMimeType mime("application/x-win32-pe");
	BMessage ext;
	ext.AddString("extensions", "exe");
	ext.AddString("extensions", "EXE");
	mime.SetFileExtensions(&ext);
	mime.SetShortDescription("Win32 Executable");
	mime.SetLongDescription("Win32 PE Executable");
	mime.SetPreferredApp(WIN32SERVER_TYPE);

	BMimeType mime2("application/x-vnd.Be-peexecutable");
	mime2.SetPreferredApp(WIN32SERVER_TYPE);
};

int32
Win32Server::ServiceLoop
(void *data)
{
	port_id port = (port_id)data;
	char buf[MAX_REQUEST_SIZE];
	int32 code;
	ssize_t size;
	while (0 < (size = read_port(port, &code, (void *)buf, MAX_REQUEST_SIZE))) {
		DOUT("read_port: %d\n", size);
	}
	return 0;
}
