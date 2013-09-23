/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000, 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: Coff.cpp,v 1.1 2003/05/01 01:33:55 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Coff.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "Coff.h"
#include "ImportDirectoryTable.h"
#include "ExportDirectoryTable.h"
#include "RelocationTable.h"
#include "ResourceTable.h"
#include "Win32Trace.h"
#include "Win32String.h"

static void
nullfunc
(void)
{
	WIN32API_INFO("*** import failed func. (stack will be destroyed.)\n");
}

extern "C" HMODULE WINAPI LoadLibraryA(LPCSTR lpFileName);
extern "C" BOOL WINAPI FreeLibrary(HMODULE hModule);
extern "C" FARPROC WINAPI GetProcAddress(HMODULE hModule, LPCSTR lpProcName);

Image::Image
(void):
ref(0)
{
}

Image::~Image
(void)
{
}

int
Image::AddRef
(void)
{
	return ++ref;
}

int
Image::ReleaseRef
(void)
{
	return --ref;
}

Coff::Coff
(const char *fname):
fd(-1),
type(COFF_TYPE_UNKNOWN),
error(COFF_ERR_OK),
opthdrptr(NULL),
scthdr(NULL),
sctmem(NULL),
sctarea(NULL),
nDllInstances(0),
dllInstances(NULL),
hInstance(NULL),
#if defined(ENABLE_DYNAMIC_RELOCATION)
old_sigsegv(NULL),
#endif	// defined(ENABLE_DYNAMIC_RELOCATION)
imageBase(0)
{
	snprintf(this->fname, PATH_MAX, "%s", fname);
	fd = open(fname, O_RDONLY);
	if (fd < 0) {
		error = COFF_ERR_IMAGE_NOT_FOUND;
		DOUT("not found: '%s'\n", fname);
	} else DOUT("open: '%s'\n", fname);
}

Coff::~Coff
(void)
{
	if (fd >= 0) close(fd);
	if (NULL != opthdrptr) free(opthdrptr);
	if (NULL != scthdr) free(scthdr);
	if (NULL != sctmem) free(sctmem);
	if (NULL != sctarea) {
		for (int i = 0; i <= sctcnt; i++) if (sctarea[i] >= B_OK) delete_area(sctarea[i]);
		free(sctarea);
	}
	if (NULL != dllInstances) {
		for (int32 i = 0; i < nDllInstances; i++) FreeLibrary(dllInstances[i]);
		free(dllInstances);
	}
}

CoffError
Coff::Load
(bool relocate)
{
	try {
		if (error != COFF_ERR_OK) throw error;
		if (0x003c != lseek(fd, 0x003c, SEEK_SET)) throw COFF_ERR_IMAGE_SEEK;
		long addr;
		CoffError err;
		err = ReadLong(addr);
		if (COFF_ERR_OK != err) throw COFF_ERR_IMAGE_READ;
		DOUT("COFF file header offset: $%08x\n", addr);
		if (addr != lseek(fd, addr, SEEK_SET)) throw COFF_ERR_IMAGE_SEEK;
		char signature[PE_SIGNATURE_SIZE];
		if (PE_SIGNATURE_SIZE != read(fd, signature, PE_SIGNATURE_SIZE)) throw COFF_ERR_IMAGE_READ;
		if (0 != memcmp(signature, PE_SIGNATURE, PE_SIGNATURE_SIZE)) throw COFF_ERR_INVALID_IMAGE;
		if (sizeof(CoffFileHeader) != read(fd, (void *)&cfhdr, sizeof(CoffFileHeader))) throw COFF_ERR_IMAGE_READ;
		err = CheckCoffFileHeader();
		if (COFF_ERR_OK != err) throw err;
		opthdrptr = (LpOptionalHeader)malloc(cfhdr.sizeOfOptionalHeader);
		if (NULL == opthdrptr) throw COFF_ERR_NO_MEMORY;
		if (cfhdr.sizeOfOptionalHeader != read(fd, (void *)opthdrptr, cfhdr.sizeOfOptionalHeader)) throw COFF_ERR_IMAGE_READ;
		err = CheckOptionalHeader(cfhdr.sizeOfOptionalHeader);
		if (COFF_ERR_OK != err) throw err;
		err = CheckDataDirectory();
		if (COFF_ERR_OK != err) throw err;
		int sctsize = sctcnt * sizeof(SectionHeader);
		scthdr = (LpSectionHeader)malloc(sctsize);
		sctmem = (void **)malloc(sctcnt * sizeof(void *));
		sctarea = (area_id *)malloc((sctcnt + 1)* sizeof(area_id));
		if ((NULL == scthdr) || (NULL == sctmem) || (NULL == sctarea)) throw COFF_ERR_NO_MEMORY;
		if (sctsize != read(fd, (void *)scthdr, sctsize)) throw COFF_ERR_IMAGE_READ;
		memset(sctmem, 0, sctcnt * sizeof(void *));
		memset(sctarea, 0xff, (sctcnt + 1) * sizeof(area_id));
		void *headaddr = (void *)imageBase;
		sctarea[0] = create_area("coff_seg_0", &headaddr, B_ANY_ADDRESS, 0x1000, B_NO_LOCK, B_READ_AREA | B_WRITE_AREA);
		if (sctarea[0] < B_OK) throw COFF_ERR_NO_MEMORY;
		lseek(fd, 0, SEEK_SET);
		read(fd, headaddr, 0x1000);
		*(Image **)&((char *)headaddr)[0x1000 - sizeof(Image *)] = this;
		hInstance = (HINSTANCE)headaddr;
		err = CheckSection();
		if (COFF_ERR_OK != err) throw err;
//		err = CheckResource();
//		if (COFF_ERR_OK != err) throw err;
		err = DoExport();
		if (COFF_ERR_OK != err) throw err;
		if (relocate) {
			err = DoRelocate();
			if (COFF_ERR_OK != err) throw err;
		} else SetSignal();
	} catch(CoffError e) {
		error = e;
		return error;
	}
	return COFF_ERR_OK;
}

CoffError
Coff::Import
(void)
{
	error = DoImport();
	if (COFF_ERR_OK != error) return error;
	error = DoWriteProtection();
	return error;
}

const char *
Coff::GetFileName
(void) const
{
	return fname;
}

void *
Coff::GetAddressByOrder
(int order) const
{
	order -= exOrdinalBase;
	for (int i = 0; i < exCount; i++) {
		if (order != exOrdinalTable[i]) continue;
		return Rva2Address(exAddressTable[i]);
	}
	return NULL;
}

void *
Coff::GetAddressByName
(const char *name) const
{
	for (int i = 0; i < exCount; i++) {
		if (0 != strcmp((char *)Rva2Address(exNameTable[i]), name)) continue;
		return Rva2Address(exAddressTable[i]);
	}
	return NULL;
}

void *
Coff::GetEntryPoint
(void) const
{
	return Rva2Address(stdfldptr->addressOfEntryPoint);
}

HINSTANCE
Coff::GetInstance
(void) const
{
	return hInstance;
}

DWORD
Coff::GetVersion
(void) const
{
	// XXX
	return 0;
}

Coff *
Coff::InstanceToCoff
(HINSTANCE hInstance)
{
	if (NULL == hInstance) return NULL;
	char *head = (char *)hInstance;
	return *(Coff **)&head[0x1000 - sizeof(Coff *)];
}

void *
Coff::GetResourceAddress
(void) const
{
	if (RVA_RESOURCE_TABLE >= ddcnt) return NULL;
	if ((ddptr[RVA_RESOURCE_TABLE].rva == 0) || (ddptr[RVA_RESOURCE_TABLE].size == 0)) return NULL;
	return Rva2Address(ddptr[RVA_RESOURCE_TABLE].rva);
}

LpResourceDataEntry
Coff::FindResource
(int type, int id) const
{
	DOUT("type = %d / id = %d\n", type, id);
	if (RVA_RESOURCE_TABLE >= ddcnt) return NULL;
	if ((ddptr[RVA_RESOURCE_TABLE].rva == 0) || (ddptr[RVA_RESOURCE_TABLE].size == 0)) return NULL;
	LpResourceDirectoryTable rdt = (LpResourceDirectoryTable)Rva2Address(ddptr[RVA_RESOURCE_TABLE].rva);
	if (NULL == rdt) return NULL;
	if (0 != rdt->NumberOfNameEntries) {
		DOUT("name type noy supported\n");
		return NULL;
	}
	LpResourceDirectoryEntry rde = (LpResourceDirectoryEntry)&rdt[1];
	int i;
	for (i = 0; i < rdt->NumberOfIDEntries; i++) {
		DOUT("...type = %d\n", rde->IntegerId);
		if (rde->IntegerId == (DWORD)type) {
			DOUT("type %d found\n", type);
			break;
		}
		rde++;
	}
	if (i == rdt->NumberOfIDEntries) return NULL;
	rdt = (LpResourceDirectoryTable)Rva2Address(ddptr[RVA_RESOURCE_TABLE].rva + (rde->SubdirectoryRva & 0x7fffffff));
	rde = (LpResourceDirectoryEntry)&rdt[1];
	for (i = 0; i < rdt->NumberOfNameEntries; i++) rde++;
	for (i = 0; i < rdt->NumberOfIDEntries; i++) {
		DOUT("...id = %d\n", rde->IntegerId);
		if (rde->IntegerId == (DWORD)id) {
			DOUT("id %d found\n", id);
			break;
		}
		rde++;
	}
	if (i == rdt->NumberOfIDEntries) return NULL;
	rdt = (LpResourceDirectoryTable)Rva2Address(ddptr[RVA_RESOURCE_TABLE].rva + (rde->SubdirectoryRva & 0x7fffffff));
	rde = (LpResourceDirectoryEntry)&rdt[1];
	for (i = 0; i < rdt->NumberOfNameEntries; i++) rde++;
	DOUT("language = %d\n", rde->IntegerId);
	return (LpResourceDataEntry)Rva2Address(ddptr[RVA_RESOURCE_TABLE].rva + rde->SubdirectoryRva);
}

bool
Coff::ProcessAttach
(void)
{
	BOOL WINAPI (*DllMain)(HINSTANCE, DWORD, LPVOID);
	DllMain = (BOOL (*)(HINSTANCE, DWORD, LPVOID))GetEntryPoint();
	if (NULL == DllMain) return false;
	return (TRUE == DllMain((HINSTANCE)((DWORD)sctmem[0] - winfldptr->imageBase), 1, NULL));
}

bool
Coff::ThreadAttach
(void)
{
	BOOL WINAPI (*DllMain)(HINSTANCE, DWORD, LPVOID);
	DllMain = (BOOL (*)(HINSTANCE, DWORD, LPVOID))GetEntryPoint();
	return (TRUE == DllMain((HINSTANCE)((DWORD)sctmem[0] - winfldptr->imageBase), 2, NULL));
}

bool
Coff::ThreadDetach
(void)
{
	BOOL WINAPI (*DllMain)(HINSTANCE, DWORD, LPVOID);
	DllMain = (BOOL (*)(HINSTANCE, DWORD, LPVOID))GetEntryPoint();
	return (TRUE == DllMain((HINSTANCE)((DWORD)sctmem[0] - winfldptr->imageBase), 3, NULL));
}

bool
Coff::ProcessDetach
(void)
{
	BOOL WINAPI (*DllMain)(HINSTANCE, DWORD, LPVOID);
	DllMain = (BOOL (*)(HINSTANCE, DWORD, LPVOID))GetEntryPoint();
	return (TRUE == DllMain((HINSTANCE)((DWORD)sctmem[0] - winfldptr->imageBase), 4, NULL));
}

CoffError
Coff::CheckCoffFileHeader
(void)
{
	try {
		DOUT("\n");
		DOUT("=== COFF File Header ===\n");
		if (cfhdr.machine != IMAGE_FILE_MACHINE_I386) {
			DOUT("!!! this binary is not for intel x86 architecture !!!\n");
			throw COFF_ERR_UNSUPPORTED_ARCHITECTURE;
		} else {
			DOUT("machine type: MACHINE_I386\n");
		}
		sctcnt = cfhdr.numberOfSections;
		DOUT("number of sections: %d\n", cfhdr.numberOfSections);
		DOUT("time date stamp: $%08x\n", cfhdr.timeDateStamp);
		DOUT("pointer to symbol table: %08x\n", cfhdr.pointerToSymbolTable);
		DOUT("number of Symbols: %d\n", cfhdr.numberOfSymbols);
		DOUT("size of optional header: %d\n", cfhdr.sizeOfOptionalHeader);
		DOUT("characteristics: $%08x\n", cfhdr.characteristics);
		if (0 != (cfhdr.characteristics & IMAGE_FILE_DLL)) type = COFF_TYPE_DLL;
		else if (0 != (cfhdr.characteristics & IMAGE_FILE_EXECUTABLE_IMAGE)) type = COFF_TYPE_EXE;
		else {
			DOUT("!!! unknown binary type !!!\n");
			throw COFF_ERR_UNKNOWN_BINARY_TYPE;
		}
		if (0 != (cfhdr.characteristics & IMAGE_FILE_RELOCS_STRIPPED)) DOUT("\tRELOCS_STRIPPED\n");
		if (0 != (cfhdr.characteristics & IMAGE_FILE_EXECUTABLE_IMAGE)) DOUT("\tEXECUTABLE_IMAGE\n");
		if (0 != (cfhdr.characteristics & IMAGE_FILE_LINE_NUMS_STRIPPED)) DOUT("\tLINE_NUMS_STRIPPED\n");
		if (0 != (cfhdr.characteristics & IMAGE_FILE_LOCAL_SYMS_STRIPPED)) DOUT("\tLOCAL_SYMS_STRIPPED\n");
		if (0 != (cfhdr.characteristics & IMAGE_FILE_AGGRESSIVE_WS_TRIM)) DOUT("\tAGRESSIVE_WS_TRIM\n");
		if (0 != (cfhdr.characteristics & IMAGE_FILE_LARGE_ADDRESS_AWARE)) DOUT("\tLARGE_ADDRESS_AWARE\n");
		if (0 != (cfhdr.characteristics & IMAGE_FILE_16BIT_MACHINE)) DOUT("\t16BIT_MACHINE\n");
		if (0 != (cfhdr.characteristics & IMAGE_FILE_BYTES_REVERSED_LO)) DOUT("\tBYTES_REVERSED_LO\n");
		if (0 != (cfhdr.characteristics & IMAGE_FILE_32BIT_MACHINE)) DOUT("\t32BIT_MACHINE\n");
		if (0 != (cfhdr.characteristics & IMAGE_FILE_DEBUG_STRIPPED)) DOUT("\tDEBUG_STRIPPED\n");
		if (0 != (cfhdr.characteristics & IMAGE_FILE_REMOVABLE_RUN_FROM_SWAP)) DOUT("\tREMOVABLE_RUN_FROM_SWAP\n");
		if (0 != (cfhdr.characteristics & IMAGE_FILE_SYSTEM)) DOUT("\tSYSTEM\n");
		if (0 != (cfhdr.characteristics & IMAGE_FILE_DLL)) DOUT("\tDLL\n");
		if (0 != (cfhdr.characteristics & IMAGE_FILE_UP_SYSTEM_ONLY)) DOUT("\tUP_SYSTEM_ONLY\n");
		if (0 != (cfhdr.characteristics & IMAGE_FILE_BYTES_REVERSED_HI)) DOUT("\tBYTE_REVERSED_HI\n");
	} catch (CoffError e) {
		return e;
	}
	return COFF_ERR_OK;
}

CoffError
Coff::CheckOptionalHeader
(int size)
{
	try {
		if (opthdrptr->pe32.standardFields.magic != MAGIC_PE32) {
			if (opthdrptr->pe32plus.standardFieldsPlus.magic == MAGIC_PE32PLUS) DOUT("!!! PE32+ is not supported !!!\n");
			else DOUT("!!! this binary is not PE32 !!!\n");
			throw COFF_ERR_UNSUPPORTED_ARCHITECTURE;
		}
		DOUT("\n");
		DOUT("=== Optional Header (Standard Fields) ===\n");
		LpStandardFields stdhdr = stdfldptr = &opthdrptr->pe32.standardFields;
		DOUT("linker version: %2d.%02d\n", stdhdr->majorLinkerVersion, stdhdr->minorLinkerVersion);
		DOUT("size of code: %d\n", stdhdr->sizeOfCode);
		DOUT("size of initialized data: %d\n", stdhdr->sizeOfInitializedData);
		DOUT("size of uninitialized data: %d\n", stdhdr->sizeOfUninitializedData);
		DOUT("address of entry point: $%08x\n", stdhdr->addressOfEntryPoint);
		DOUT("base of code: $%08x\n", stdhdr->baseOfCode);
		DOUT("base of data: $%08x\n", stdhdr->baseOfData);

		DOUT("\n");
		DOUT("=== Optional Header (Windows Specific Fields) ===\n");
		LpWindowsSpecificFields winhdr = winfldptr = &opthdrptr->pe32.windowsSpecificFields;
		DOUT("image base: $%08x\n", winhdr->imageBase);
		imageBase = winhdr->imageBase;
		DOUT("section alignment: %d\n", winhdr->sectionAlignment);
		DOUT("file alignment: %d\n", winhdr->fileAlignment);
		DOUT("OS version: %2d.%02d\n", winhdr->majorOperatingSystemVersion, winhdr->minorOperatingSystemVersion);
		DOUT("image version: %2d.%02d\n", winhdr->majorImageVersion, winhdr->minorImageVersion);
		DOUT("subsystem version: %2d.%02d\n", winhdr->majorSubsystemVersion, winhdr->minorSubsystemVersion);
		DOUT("size of image: %d\n", winhdr->sizeOfImage);
		DOUT("size of headers: %d\n", winhdr->sizeOfHeaders);
		DOUT("check sum: $%08x\n", winhdr->checkSum);
#if defined(_DEBUG)
		char *subsystems[] = {
			"unknown",
			"Windows NT native",
			"Windows GUI",
			"Windows CUI",
			"-",
			"-",
			"-",
			"POSIX",
			"-",
			"Windows CE GUI",
			"EFI Application",			// IA64
			"EFI Boot Service Driver",	// IA64
			"EFI Runtime Driver",		// IA64
		};
		DOUT("subsystem: %d (%s)\n", winhdr->subsystem, subsystems[winhdr->subsystem]);
#endif	// defined(_DEBUG)
		DOUT("dll characteristics: $%04x\n", winhdr->dllCharacteristics);
		if (0 != (winhdr->dllCharacteristics & IMAGE_DLLCHARACTERISTICS_NO_BIND)) DOUT("\tNO_BIND\n");
		if (0 != (winhdr->dllCharacteristics & IMAGE_DLLCHARACTERISTICS_WDM_DRIVER)) DOUT("\tWDM_DRIVER\n");
		if (0 != (winhdr->dllCharacteristics & IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE)) DOUT("\tSERVER_AWARE\n");
		DOUT("size of stack reserve: %d\n", winhdr->sizeOfStackReserve);
		DOUT("size of stack commit: %d\n", winhdr->sizeOfStackCommit);
		DOUT("size of heap reserve: %d\n", winhdr->sizeOfHeapReserve);
		DOUT("size of heap commit: %d\n", winhdr->sizeOfHeapCommit);
		DOUT("loader flags: $%08x\n", winhdr->loaderFlags);
		DOUT("number of rva and sizes: %d\n", winhdr->numberOfRvaAndSizes);
		ddptr = &opthdrptr->pe32.dataDirectories;
		ddcnt = winhdr->numberOfRvaAndSizes;
	} catch (CoffError e) {
		return e;
	}
	return COFF_ERR_OK;
}

CoffError
Coff::CheckDataDirectory
(void)
{
	DOUT("\n");
	DOUT("=== Optional Header (DataDirectory) ===\n");
#if defined(_DEBUG)
	char *rvatypes[] = {
		"export table",
		"import table",
		"resource table",
		"exception table",
		"attribute certificate table",
		"base relocation table",
		"debug data",
		"architecture specific data",
		"global pointer",
		"thread local storage table",
		"load config table",
		"boud import",
		"import address table",
		"delay import descriptor",
		"COM+ runtime header",
		"reserved",
	};
	for (int i = 0; i < ddcnt; i++) {
		DOUT("%3d: $%08x, $%08x [%s]\n", i, ddptr[i].rva, ddptr[i].size, rvatypes[i]);
	}
#endif	// defined(_DEBUG)
	return COFF_ERR_OK;
}

CoffError
Coff::CheckSection
(void)
{
	try {
		for (int i = 0; i < sctcnt; i++) {
#if defined(_DEBUG)
			DOUT("\n");
			DOUT("=== Section Table #%d ===\n", i);
			char name[9];
			memcpy(name, scthdr[i].name, 8);
			name[8] = 0;
			DOUT("name: %s\n", name);
			DOUT("virtual size: $%08x\n", scthdr[i].virtualSize);
			DOUT("virtual address: $%08x\n", scthdr[i].virtualAddress);
			DOUT("size of raw data: $%08x\n", scthdr[i].sizeOfRawData);
			DOUT("pointer to raw data: $%08x\n", scthdr[i].pointerToRawData);
			DOUT("pointer to relocations: $%08x\n", scthdr[i].pointerToRelocations);
			DOUT("pointer to line numbers: $%08x\n", scthdr[i].pointerToLinenumbers);
			DOUT("number of relocations: $%04x\n", scthdr[i].numberOfRelocations);
			DOUT("number of linenumbers: $%04x\n", scthdr[i].numberOfLinenumbers);
			DOUT("characteristics: $%08x\n", scthdr[i].characteristics);
			if (0 != (scthdr[i].characteristics & IMAGE_SCN_TYPE_REG)) DOUT("\tTYPE REG\n");
			if (0 != (scthdr[i].characteristics & IMAGE_SCN_TYPE_DSECT)) DOUT("\tTYPE DSECT\n");
			if (0 != (scthdr[i].characteristics & IMAGE_SCN_TYPE_NOLOAD)) DOUT("\tTYPE NOLOAD\n");
			if (0 != (scthdr[i].characteristics & IMAGE_SCN_TYPE_GROUP)) DOUT("\tTYPE GROUP\n");
			if (0 != (scthdr[i].characteristics & IMAGE_SCN_TYPE_NO_PAD)) DOUT("\tTYPE NO PAD\n");
			if (0 != (scthdr[i].characteristics & IMAGE_SCN_TYPE_COPY)) DOUT("\tTYPE COPY\n");
			if (0 != (scthdr[i].characteristics & IMAGE_SCN_TYPE_OVER)) DOUT("\tTYPE OVER\n");

			if (0 != (scthdr[i].characteristics & IMAGE_SCN_CNT_CODE)) DOUT("\tCNT CODE\n");
			if (0 != (scthdr[i].characteristics & IMAGE_SCN_CNT_INITIALIZED_DATA)) DOUT("\tINITIALIZED DATA\n");
			if (0 != (scthdr[i].characteristics & IMAGE_SCN_CNT_UNINITIALIZED_DATA)) DOUT("\tUNINITIALIZED DATA\n");

			if (0 != (scthdr[i].characteristics & IMAGE_SCN_LNK_OTHER)) DOUT("\tLNK OTHER\n");
			if (0 != (scthdr[i].characteristics & IMAGE_SCN_LNK_INFO)) DOUT("\tLNK INFO\n");
			if (0 != (scthdr[i].characteristics & IMAGE_SCN_LNK_REMOVE)) DOUT("\tLNK REMOVE\n");
			if (0 != (scthdr[i].characteristics & IMAGE_SCN_LNK_COMDAT)) DOUT("\tLNK COMDAT\n");
			if (0 != (scthdr[i].characteristics & IMAGE_SCN_LNK_NRELOC_OVFL)) DOUT("\tLNK NRELOC OVFL\n");

			if (0 != (scthdr[i].characteristics & IMAGE_SCN_MEM_FARDATA)) DOUT("\tMEM FARDATA\n");
			if (0 != (scthdr[i].characteristics & IMAGE_SCN_MEM_PURGEABLE)) DOUT("\tMEM PURGEABLE\n");
			if (0 != (scthdr[i].characteristics & IMAGE_SCN_MEM_16BIT)) DOUT("\tMEM_16BIT\n");
			if (0 != (scthdr[i].characteristics & IMAGE_SCN_MEM_LOCKED)) DOUT("\tMEM LOCKED\n");
			if (0 != (scthdr[i].characteristics & IMAGE_SCN_MEM_PRELOAD)) DOUT("\tMEM PRELOAD\n");
			if (0 != (scthdr[i].characteristics & IMAGE_SCN_MEM_DISCARDABLE)) DOUT("\tMEM DISCARDABLE\n");
			if (0 != (scthdr[i].characteristics & IMAGE_SCN_MEM_NOT_CACHED)) DOUT("\tMEM NOT CACHED\n");
			if (0 != (scthdr[i].characteristics & IMAGE_SCN_MEM_NOT_PAGED)) DOUT("\tMEM NOT PAGED\n");
			if (0 != (scthdr[i].characteristics & IMAGE_SCN_MEM_SHARED)) DOUT("\tMEM SHARED\n");
			if (0 != (scthdr[i].characteristics & IMAGE_SCN_MEM_EXECUTE)) DOUT("\tMEM EXECUTE\n");
			if (0 != (scthdr[i].characteristics & IMAGE_SCN_MEM_READ)) DOUT("\tMEM READ\n");
			if (0 != (scthdr[i].characteristics & IMAGE_SCN_MEM_WRITE)) DOUT("\tMEM WRITE\n");

			int align = (1 << ((scthdr[i].characteristics & 0x00f00000) >> 20)) >> 1;
			DOUT("\tALIGN %d BYTES\n", align);
#endif	// defined(_DEBUG)
			if (scthdr[i].sizeOfRawData > scthdr[i].virtualSize) scthdr[i].virtualSize = scthdr[i].sizeOfRawData;
			char seg_name[256];
			snprintf(seg_name, 256, "coff_seg_%d", i + 1);
			void *addr = (void *)(imageBase + scthdr[i].virtualAddress);
			DOUT("mapping to %p (%08x) ... \n", addr, ((scthdr[i].virtualSize + B_PAGE_SIZE - 1) / B_PAGE_SIZE) * B_PAGE_SIZE);
			sctarea[i + 1] = create_area(seg_name, &addr, B_ANY_ADDRESS,
				((scthdr[i].virtualSize + B_PAGE_SIZE - 1) / B_PAGE_SIZE) * B_PAGE_SIZE,
				B_NO_LOCK, B_READ_AREA | B_WRITE_AREA);
			if (sctarea[i + 1] < B_OK) {
				DOUT("can not create area\n");
				throw COFF_ERR_NO_MEMORY;
			}
			sctmem[i] = addr;
			DOUT("mapped to %p\n", addr);
			if (NULL == sctmem[i]) {
				DOUT("null address\n");
				throw COFF_ERR_NO_MEMORY;
			}
			if (scthdr[i].pointerToRawData != lseek(fd, scthdr[i].pointerToRawData, SEEK_SET)) throw COFF_ERR_IMAGE_SEEK;
			if (scthdr[i].sizeOfRawData != (DWORD)read(fd, sctmem[i], scthdr[i].sizeOfRawData)) throw COFF_ERR_IMAGE_READ;
		}
	} catch (CoffError e) {
		DOUT("COFF load error: %d\n", e);
		return e;
	}
	return COFF_ERR_OK;
}

CoffError
Coff::CheckResource
(int offset, int depth)
{
	if (RVA_RESOURCE_TABLE >= ddcnt) return COFF_ERR_OK;
	if ((ddptr[RVA_RESOURCE_TABLE].rva == 0) || (ddptr[RVA_RESOURCE_TABLE].size == 0)) return COFF_ERR_OK;
	LpResourceDirectoryTable rdt = (LpResourceDirectoryTable)Rva2Address(ddptr[RVA_RESOURCE_TABLE].rva + offset);
	if (NULL == rdt) return COFF_ERR_INVALID_IMAGE;
	if (0 == depth) {
		DOUT("\n");
		DOUT("=== Resource ===\n");
	}
	DOUT("\tcharacteristics: $%08x\n", rdt->Characteristics);
	DOUT("\ttime date stamp: $%08x\n", rdt->TimeDateStamp);
	DOUT("\tversion %2d.%02d\n", rdt->MajorVersion, rdt->MinorVersion);
	DOUT("\tnumber of name entries: $%04x\n", rdt->NumberOfNameEntries);
	DOUT("\tnumber of id entries: $%04x\n", rdt->NumberOfIDEntries);
	LpResourceDirectoryEntry rde = (LpResourceDirectoryEntry)&rdt[1];
	char *groups[] = { "Type", "Name", "Language" };
	if (0 != rdt->NumberOfNameEntries) {
		DOUT("[name entries]\n");
		for (int i = 0; i < rdt->NumberOfNameEntries; i++) {
			LpResourceDirectoryString rds = (LpResourceDirectoryString)Rva2Address(ddptr[RVA_RESOURCE_TABLE].rva + (rde->NameRva & 0x7fffffff));
			Win32String str;
			str.SetToW(rds->UnicodeString, rds->Length);
			DOUT("\tname rva: $%08x (%s %s)\n", rde->NameRva, groups[depth], str.StringU());
			DOUT("\tdata entry rva: $%08x\n", rde->DataEntryRva);
			rde++;
		}
	}
	if (0 != rdt->NumberOfIDEntries) {
		DOUT("[id entries]\n");
		for (int i = 0; i < rdt->NumberOfIDEntries; i++) {
			DOUT("\tinteger id: $%08x (%s #%d)\n", rde->IntegerId, groups[depth], rde->IntegerId);
			DOUT("\tsubdirectory rva: $%08x\n", rde->SubdirectoryRva);
			CoffError err = CheckResource(rde->SubdirectoryRva & 0x7fffffff, depth + 1);
			if (COFF_ERR_OK != err) return err;
			rde++;
		}
	}
	DOUT("\t---\n");
	return COFF_ERR_OK;
}

CoffError
Coff::ReadLong
(long &data)
{
	ssize_t readsize = read(fd, (void *)&data, sizeof(long));
	if (readsize != sizeof(long)) return COFF_ERR_IMAGE_READ;
	return COFF_ERR_OK;
}

CoffError
Coff::DoExport
(void)
{
	if (RVA_EXPORT_TABLE >= ddcnt) return COFF_ERR_OK;
	if ((ddptr[RVA_EXPORT_TABLE].rva == 0) || (ddptr[RVA_EXPORT_TABLE].size == 0)) return COFF_ERR_OK;
	LpExportDirectoryTable edtbl = (LpExportDirectoryTable)Rva2Address(ddptr[RVA_EXPORT_TABLE].rva);
	if (NULL == edtbl) return COFF_ERR_INVALID_IMAGE;
	DOUT("\n");
	DOUT("=== Export ===\n");
	DOUT("\texport flags: $%08x\n", edtbl->exportFlags);
	DOUT("\ttime date stamp: $%08x\n", edtbl->timeDateStamp);
	DOUT("\tversion: %2d.%02d\n", edtbl->majorVersion, edtbl->minorVersion);
	DOUT("\tname rva: $%08x\n", edtbl->nameRva);
	DOUT("\tordinal base: $%08x\n", edtbl->ordinalBase);
	DOUT("\taddress table entries: $%08x\n", edtbl->addressTableEntries);
	DOUT("\tnumber of name pointers: $%08x\n", edtbl->numberOfNamePointers);
	DOUT("\texport address table rva: $%08x\n", edtbl->exportAddressTableRva);
	DOUT("\tname pointer rva: $%08x\n", edtbl->namePointerRva);
	DOUT("\tordinal table rva: $%08x\n", edtbl->ordinalTableRva);
	char *dllname = (char *)Rva2Address(edtbl->nameRva);
	DOUT("[%s]\n", dllname);
	exOrdinalBase = edtbl->ordinalBase;
	exAddressTable = (LPDWORD)Rva2Address(edtbl->exportAddressTableRva);
	exNameTable = (LPDWORD)Rva2Address(edtbl->namePointerRva);
	exOrdinalTable = (LPWORD)Rva2Address(edtbl->ordinalTableRva);
	exCount = edtbl->numberOfNamePointers;
	for (int i = 0; i < exCount; i++) {
		DOUT("\t$%08x %s, %d\n", exAddressTable[i], Rva2Address(exNameTable[i]), exOrdinalBase + exOrdinalTable[i]);
	}
	return COFF_ERR_OK;
}

CoffError
Coff::DoImport
(void)
{
	if (RVA_IMPORT_TABLE >= ddcnt) return COFF_ERR_OK;
	if ((ddptr[RVA_IMPORT_TABLE].rva == 0) || (ddptr[RVA_IMPORT_TABLE].size == 0)) return COFF_ERR_OK;
	int tables = ddptr[RVA_IMPORT_TABLE].size / sizeof(ImportDirectoryTable);
	LpImportDirectoryTable idtbl = (LpImportDirectoryTable)Rva2Address(ddptr[RVA_IMPORT_TABLE].rva);
	dllInstances = (HINSTANCE *)malloc(sizeof(HINSTANCE) * tables);
	if (NULL == dllInstances) return COFF_ERR_NO_MEMORY;
	nDllInstances = 0;
	DOUT("\n");
	DOUT("=== Import ===\n");
	for (int n = 0; n < tables; n++, idtbl++) {
		if (0 == idtbl->importAddressTableRva) break;	// Borland
		DOUT("import lookup table: $%08x\n", idtbl->importLookupTableRva);
		DOUT("time date stamp: $%08x\n", idtbl->timeDateStamp);
		DOUT("fowarder chain: $%08x\n", idtbl->fowarderChain);
		DOUT("name rva: $%08x\n", idtbl->nameRva);
		DOUT("import address table rva: $%08x\n", idtbl->importAddressTableRva);
		char *dllname = (char *)Rva2Address(idtbl->nameRva);
		int ct;
		WIN32API_INTERNAL_GET(ct);
		HINSTANCE dllInstance = LoadLibraryA(dllname);
		WIN32API_INTERNAL_SET(ct);
		dllInstances[nDllInstances++] = dllInstance;
		LPDWORD lookup = NULL;
		if (0 != idtbl->importLookupTableRva) lookup = (LPDWORD)Rva2Address(idtbl->importLookupTableRva);	// MS
		else lookup = (LPDWORD)Rva2Address(idtbl->importAddressTableRva);	// Borland
		for (LPDWORD address = (LPDWORD)Rva2Address(idtbl->importAddressTableRva); 0 != *lookup; address++) {
			LpHintNameTable hntbl = (LpHintNameTable)Rva2Address(*lookup);
			bool order = (0 != (0x80000000 & *lookup));
			if (!order) DOUT("\t%s:%s, %d # ", dllname, &hntbl->name, hntbl->hint);
			else DOUT("\t%s:, %d # ", dllname, 0x7fffffff & *lookup);
			if (NULL != dllInstance) {
				FARPROC proc = NULL;
				WIN32API_INTERNAL_START();
				WIN32API_INFO_OFF();
				if (order) *address = (DWORD)GetProcAddress(dllInstance, (char *)(0x0000ffff & *lookup));
				else *address = (DWORD)GetProcAddress(dllInstance, &hntbl->name);
				WIN32API_INFO_ON();
				WIN32API_INTERNAL_END();
			} else {
				*address = 0;
			}
			if (0 == *address) {
				*address = (long)nullfunc;
				DOUTR("import failed\n");
			} else {
				DOUTR("$%08x <= $%08x\n", address, *address);
			}
			if (NULL != lookup) lookup++;
		}
	}
	return COFF_ERR_OK;
}

CoffError
Coff::DoRelocate
(void)
{
	if (RVA_BASE_RELOCATION_TABLE >= ddcnt) return COFF_ERR_OK;
	if ((ddptr[RVA_BASE_RELOCATION_TABLE].rva == 0) || (ddptr[RVA_BASE_RELOCATION_TABLE].size == 0)) {
		DOUT("*** base relocation table not found ***\n");
#if defined(ENABLE_DYNAMIC_RELOCATION)
		DOUT("****** use dynamic relocation ;) ******\n");
		return SetSignal();
#else	// !defined(ENABLE_DYNAMIC_RELOCATION)
		DOUT("***** this binary can not execute *****\n");
		return COFF_ERR_MAP_MEMORY;
#endif	// defined(ENABLE_DYNAMIC_RELOCATION)
	}
	LpRelocationTable rt = (LpRelocationTable)Rva2Address(ddptr[RVA_BASE_RELOCATION_TABLE].rva);
	if (NULL == rt) return COFF_ERR_INVALID_IMAGE;
	DOUT("\n");
	DOUT("=== Relocate ===\n");
	for (int restsize = ddptr[RVA_BASE_RELOCATION_TABLE].size - sizeof(RelocationTable); restsize > 0; restsize -= sizeof(RelocationTable)) {
		DOUT("\tpage rva: $%08x\n", rt->pageRva);
		DOUT("\tblock size: $%08x\n", rt->blockSize);
		LpFixupBlock fb = (LpFixupBlock)&rt[1];
		if (rt->blockSize <= sizeof(RelocationTable)) return COFF_ERR_OK;
		int blocks = (rt->blockSize - sizeof(RelocationTable)) / sizeof(FixupBlock);
#if defined(_DEBUG)
			char *types[] = {
			"absolute  ",
			"high      ",
			"low       ",
			"high low  ",
			"high adj  ",
			"mips jmp  ",
			"section   ",
			"rel32     ",
			"mips jmp16",
			"dir64     ",
			"high3 adj ",
		};
#endif	// defined(_DEBUG)
		for (int i = 0; i < blocks; i++, restsize -= 2) {
			switch (fb[i].type) {
			case IMAGE_REL_BASED_ABSOLUTE:
#if defined(_DEBUG)
				DOUT("\t%3d: [%s] $%04x ... ", i, types[fb[i].type], fb[i].offset);
				DOUTR("ignored\n");
#endif	// defined(_DEBUG)
				break;
			case IMAGE_REL_BASED_HIGHLOW:{
				LPDWORD addr = (LPDWORD)Rva2Address(rt->pageRva + fb[i].offset);
//				DOUTR("fixed $%08x -> ", *addr);
				*addr = (DWORD)Rva2Address(*addr - winfldptr->imageBase);
//				DOUTR("$%08x\n", *addr);
				break;}
			default:
#if defined(_DEBUG)
				DOUT("\t%3d: [%s] $%04x ... ", i, types[fb[i].type], fb[i].offset);
				DOUTR("not support\n");
#endif	// defined(_DEBUG)
				return COFF_ERR_UNSUPPORTED_RELOC;
			}
		}
		rt = (LpRelocationTable)&fb[blocks];
	}
	return COFF_ERR_OK;
}

CoffError
Coff::DoWriteProtection
(void)
{
	for (int i = 0; i < sctcnt; i++) {
		if (0 == (scthdr[i].characteristics & IMAGE_SCN_MEM_WRITE)) {
			area_id id = area_for(sctmem[i]);
			if (id < B_OK) return COFF_ERR_UNKNOWN;
			if (B_OK != set_area_protection(id, B_READ_AREA)) return COFF_ERR_UNKNOWN;
		}
	}
	return COFF_ERR_OK;
}

void *
Coff::Rva2Address
(DWORD rva) const
{
	for (int i = 0; i < sctcnt; i++) {
		if ((scthdr[i].virtualAddress <= rva) && (rva < (scthdr[i].virtualAddress + scthdr[i].virtualSize))) {
			return (void *)((unsigned long)sctmem[i] - scthdr[i].virtualAddress + rva);
		}
	}
	return NULL;
}

DWORD
Coff::Address2Rva
(void *address) const
{
	DWORD addr = (DWORD)address;
	for (int i = 0; i < sctcnt; i++) {
		if (((DWORD)sctmem[i] <= addr) && (addr < ((DWORD)sctmem[i] + scthdr[i].virtualSize))) {
			return scthdr[i].virtualAddress - (DWORD)sctmem[i] + addr;
		}
	}
	return 0;
}
