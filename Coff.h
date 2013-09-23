/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 ‚Æ‚æ‚µ‚Ü
 *  $Id: Coff.h,v 1.1 2003/05/01 01:53:05 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Coff.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__Coff_h__)
#	define	__Coff_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if !defined(__CoffFileHeader_h__)
#		include "CoffFileHeader.h"
#	endif	// !defined(__CoffFileHeader_h__)

#	if !defined(__OptionalHeader_h__)
#		include "OptionalHeader.h"
#	endif	// !defined(__OptionalHeader_h__)

#	if !defined(__SectionHeader_h__)
#		include "SectionHeader.h"
#	endif	// !defined(__SectionHeader_h__)

#	if !defined(__CoffSigSegv_h__)
#		include "CoffSigSegv.h"
#	endif	// !defined(__CoffSigSegv_h__)

#	if !defined(__ResourceTable_h__)
#		include "ResourceTable.h"
#	endif	// !defined(__ResourceTable_h__)

#	define	ENABLE_DYNAMIC_RELOCATION

typedef enum _CoffError {
	COFF_ERR_OK							= 0,
	COFF_ERR_UNKNOWN,
	COFF_ERR_INVALID_IMAGE,
	COFF_ERR_UNSUPPORTED_ARCHITECTURE,
	COFF_ERR_UNKNOWN_BINARY_TYPE,
	COFF_ERR_NO_MEMORY,
	COFF_ERR_MAP_MEMORY,
	COFF_ERR_IMAGE_NOT_FOUND,
	COFF_ERR_UNSUPPORTED_RELOC,
	COFF_ERR_MISSING_LIBRARY,
	COFF_ERR_IMAGE_READ,
	COFF_ERR_IMAGE_SEEK,
} CoffError;

typedef enum _CoffType {
	COFF_TYPE_UNKNOWN					= 0,
	COFF_TYPE_EXE,
	COFF_TYPE_DLL,
} CoffType;

abstract class Image {
private:
	int ref;
public:
	Image(void);
	virtual ~Image(void);
	virtual int AddRef(void);
	virtual int ReleaseRef(void);
	virtual const char *GetFileName(void) const = NULL;
	virtual void *GetAddressByOrder(int order) const = NULL;
	virtual void *GetAddressByName(const char *name) const = NULL;
	virtual void *GetEntryPoint(void) const = NULL;
	virtual HINSTANCE GetInstance(void) const = NULL;
	virtual DWORD GetVersion(void) const = NULL;

	virtual void *GetResourceAddress(void) const = NULL;
	virtual LpResourceDataEntry FindResource(int type, int id) const = NULL;

	virtual bool ProcessAttach(void) = NULL;
	virtual bool ThreadAttach(void) = NULL;
	virtual bool ThreadDetach(void) = NULL;
	virtual bool ProcessDetach(void) = NULL;
};

#	if !defined(__Image__)
#		define	__Image__
#	endif	// !defined(__Image__)

class Coff: public Image {
private:
	int fd;
	char fname[PATH_MAX];
	CoffType type;
	CoffError error;
	CoffFileHeader cfhdr;
	LpOptionalHeader opthdrptr;
	LpStandardFields stdfldptr;
	LpWindowsSpecificFields winfldptr;
	LpDataDirectory ddptr;
	int ddcnt;
	LpSectionHeader scthdr;
	void **sctmem;
	area_id *sctarea;
	int sctcnt;
	
	int exOrdinalBase;
	LPDWORD exAddressTable;
	LPDWORD exNameTable;
	LPWORD exOrdinalTable;
	int exCount;
	
	int32 nDllInstances;
	HINSTANCE *dllInstances;
	HINSTANCE hInstance;
	
#if defined(ENABLE_DYNAMIC_RELOCATION)
	__signal_func_ptr old_sigsegv;
	BList varea_addr;
	BList varea_size;
#endif	// defined(ENABLE_DYNAMIC_RELOCATION)
	unsigned long imageBase;
public:
	Coff(const char *fname);
	virtual ~Coff(void);
	
	CoffError Load(bool relocate = true);
	CoffError Import(void);
	
	const char *GetFileName(void) const;	// Image
	void *GetAddressByOrder(int order) const;	// Image
	void *GetAddressByName(const char *name) const;	// Image
	void *GetEntryPoint(void) const;	// Image
	HINSTANCE GetInstance(void) const;	// Image
	DWORD GetVersion(void) const;	// Image
	static Coff *InstanceToCoff(HINSTANCE hInstance);	// Image

	void *GetResourceAddress(void) const;	// Image
	LpResourceDataEntry FindResource(int type, int id) const;	// Image

	bool ProcessAttach(void);	// Image
	bool ThreadAttach(void);	// Image
	bool ThreadDetach(void);	// Image
	bool ProcessDetach(void);	// Image

private:
	CoffError CheckCoffFileHeader(void);
	CoffError CheckOptionalHeader(int size);
	CoffError CheckDataDirectory(void);
	CoffError CheckSection(void);
	CoffError CheckResource(int offset = 0, int depth = 0);

	CoffError ReadLong(long &data);

	CoffError DoExport(void);
	CoffError DoImport(void);
	CoffError DoRelocate(void);
	CoffError DoWriteProtection(void);

	void *Rva2Address(DWORD rva) const;
	DWORD Address2Rva(void *address) const;

#if defined(ENABLE_DYNAMIC_RELOCATION)
	CoffError SetSignal(void);
	
	static void SigSegv(int no, Coff *obj, vregs *regs, xxxregs *xregs);
	void mSigSegv(vregs *regs, xxxregs *xregs);
public:
	bool Relocate(unsigned long *addr);
	bool Relocate(unsigned long &reg);
	bool Relocate(unsigned long *addr, unsigned long &reg);
	void VAreaAdd(void *addr, int size);
	void VAreaRemove(void *addr);
private:
	const char *RegisterName(int reg, bool byte = false) const;
	unsigned long *RegisterPointer(int reg, vregs *regs, xxxregs *xregs) const;
#endif	// defined(ENABLE_DYNAMIC_RELOCATION)
};

#	if !defined(__Coff__)
#		define	__Coff__
#	endif	// !defined(__Coff__)

#endif	// !defined(__Coff_h__)
