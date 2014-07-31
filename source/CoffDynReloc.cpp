/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000, 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: CoffDynReloc.cpp,v 1.1 2003/05/01 01:33:56 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [CoffDynReloc.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "Coff.h"
#if defined(ENABLE_DYNAMIC_RELOCATION)

#	if defined(DISABLE_DYNRELOC_LOG)
#		if defined(DOUT)
#			undef	DOUT
#		endif	// defined(DOUT)
#		if defined(DOUTR)
#			undef	DOUTR
#		endif	// defined(DOUTR)
static const bool __flag = false;
#		define DOUT __flag && printf
#		define DOUTR __flag && printf
#	endif	// defined(DISABLE_DYNRELOC_LOG)

CoffError
Coff::SetSignal
(void)
{
	CoffError rc = COFF_ERR_UNKNOWN;
	struct sigaction sa;
	sa.sa_handler = (__signal_func_ptr)CoffSigSegv;
	sa.sa_mask = 0;
	sa.sa_flags = 0;
	sa.sa_userdata = (void *)this;
	struct sigaction old;
	if (0 == sigaction(SIGSEGV, &sa, &old)) {
		old_sigsegv = old.sa_handler;
		rc = COFF_ERR_OK;
	}
	return rc;
}

void
Coff::SigSegv
(int no, Coff *obj, vregs *regs, xxxregs *xregs)
{
	obj->mSigSegv(regs, xregs);
}

#define	MOD_MASK	0xc0
#define	REG_MASK	0x38
#define	HREG_MASK	0x20
#define	LREG_MASK	0x18
#define	RM_MASK		0x07
#define	RM_NR_MASK	(HREG_MASK >> 3)

#define	REG_EAX		0
#define	REG_ECX		1
#define	REG_EDX		2
#define	REG_EBX		3
#define	REG_ESP		4
#define	REG_EBP		5
#define	REG_ESI		6
#define	REG_EDI		7

void
Coff::mSigSegv
(vregs *regs, xxxregs *xregs)
{
	DOUT("%s", "*** SIGSEGV (dynamic relocation) ***\n");
	DOUT("eip: %p", regs->eip);
	bool reloc = false;
	if (Relocate(regs->eip)) {
		DOUTR(" => %p", regs->eip);
		reloc = true;
	}
	unsigned char *p = (unsigned char *)regs->eip;
	DOUTR("\t[%02x %02x %02x ...]\n", p[0], p[1], p[2]);
	DOUT("eax: %08x\t ebp: %08x\n", regs->eax, regs->ebp);
	DOUT("edx: %08x\t esi: %08x\n", regs->edx, xregs->esi);
	DOUT("ecx: %08x\t edi: %08x\n", regs->ecx, xregs->edi);
	DOUT("ebx: %08x\t esp: %08x\n", xregs->ebx, regs->esp);
	DOUT("edlags: %08x\n", regs->eflags);
	DOUT("> %08x:\n", Address2Rva((void *)regs->eip) + imageBase);
	bool opdsize = false;
	int count = 100;
retry:
	opdsize = false;
opd_retry:
	count--;
	DOUT("count: %d(%s)", count, reloc? "t": "f");
	DOUTR("\t[%02x %02x %02x ...]\n", p[0], p[1], p[2]);
	if (0 < count) switch(p[0]) {
/* -------------------------------------------------------------------------------------------- */
	/////////
	// ADD //
	case 0x00:	// Eb, Gb
	case 0x01:	// Ev, Gv
	case 0x02:	// Gb, Eb
	case 0x03:	// Gv, Ev
	////////
	// OR //
	case 0x08:	// Eb, Gb
	case 0x09:	// Ev, Gv
	case 0x0a:	// Gb, Eb
	case 0x0b:	// Gv, Ev
	/////////
	// ADC //
	case 0x10:	// Eb, Gb
	case 0x11:	// Ev, Gv
	case 0x12:	// Gb, Eb
	case 0x13:	// Gv, Ev
	/////////
	// SBB //
	case 0x18:	// Eb, Gb
	case 0x19:	// Ev, Gv
	case 0x1a:	// Gb, Eb
	case 0x1b:	// Gv, Ev
	/////////
	// AND //
	case 0x20:	// Eb, Gb
	case 0x21:	// Ev, Gv
	case 0x22:	// Gb, Eb
	case 0x23:	// Gv, Ev
	/////////
	// SUB //
	case 0x28:	// Eb, Gb
	case 0x29:	// Ev, Gv
	case 0x2a:	// Gb, Eb
	case 0x2b:	// Gv, Ev
	/////////
	// XOR //
	case 0x30:	// Eb, Gb
	case 0x31:	// Ev, Gv
	case 0x32:	// Gb, Eb
	case 0x33:	// Gv, Ev
	/////////
	// CMP //
	case 0x38:	// Eb, Gb
	case 0x39:	// Ev, Gv
	case 0x3a:	// Gb, Eb
	case 0x3b:	// Gv, Ev
	//////////
	// TEST //
	case 0x84:	// Eb, Gb
	case 0x85:	// Ev, Gv
	/////////
	// MOV //
	case 0x88:	// Eb, Gb
	case 0x89:	// Ev, Gv
	case 0x8a:	// Gb, Eb
	case 0x8b: {// Gv, Ev
		char *op = NULL;
		switch (p[0] & 0xfd) {
		case 0x00:
			op = "addb";
			break;
		case 0x01:
			op = "addl";
			break;
		case 0x08:
			op = "orb";
			break;
		case 0x09:
			op = "orl";
			break;
		case 0x10:
			op = "adcb";
			break;
		case 0x11:
			op = "adcl";
			break;
		case 0x18:
			op = "sbbb";
			break;
		case 0x19:
			op = "sbbl";
			break;
		case 0x20:
			op = "andb";
			break;
		case 0x21:
			op = "andl";
			break;
		case 0x28:
			op = "subb";
			break;
		case 0x29:
			op = "subl";
			break;
		case 0x30:
			op = "xorb";
			break;
		case 0x31:
			op = "xorl";
			break;
		case 0x38:
			op = "cmpb";
			break;
		case 0x39:
			op = "cmpl";
			break;
		case 0x84:
			op = "testb";
			break;
		case 0x85:
			op = "testl";
			break;
		case 0x88:
			op = "movb";
			break;
		case 0x89:
			op = "movl";
			break;
		}
		const char *reg = RegisterName(p[1], 0 == (p[0] & 1));
		if (0 == (p[1] & (MOD_MASK | RM_NR_MASK))) {
			// 1000_100w: mod(00) reg r/m(reg:0-3)
			// XXX register to memory
			// ex.) cmpl %esi, (%eax)

			// 1000_101w: mod(00) reg r/m(reg:0-3)
			// XXX register to memory
			// ex.) cmpl (%eax), %esi
			const char *reg2 = RegisterName(p[1] << 3);
			unsigned long *rp = RegisterPointer(p[1] << 3, regs, xregs);
			DWORD rva = (DWORD)*rp;
			if (Relocate(*rp)) {
				if (0 == (p[0] & 2)) {
					DOUT("> %s (%s), %s [%s: %p => %p]\n", op, reg2, reg, reg2, rva, *rp);
				} else {
					DOUT("> %s %s, (%s) [%s: %p => %p]\n", op, reg, reg2, reg2, rva, *rp);
				}
				reloc = true;
			}
			p += 2;
			goto retry;
		} else if (4 == (p[1] & (MOD_MASK | RM_MASK))) {
			// 1000_100w: mod(00) reg r/m(100): mod(sz) reg3 reg2
			// XXX register to memory
			// ex.) movl %ecx, (%eax, %edx, sz)
			// 1000_101w: mod(00) reg r/m(100): mod(sz) reg3 reg2
			// XXX register to memory
			// ex.) movl (%eax, %edx, sz), %ecx

			// 1000_10dw: mod(00) reg r/m(100): mod(sz) reg3 reg2(101): immediate
			// XXX register to memory
			// ex.) movl %ecx, 0x01234567(, %edx, 4)
			const char *reg2 = RegisterName(p[2] << 3);
			const char *reg3 = RegisterName(p[2]);
			unsigned long *rp1 = RegisterPointer(p[2] << 3, regs, xregs);
			unsigned long *rp2 = RegisterPointer(p[2], regs, xregs);
			DWORD rva1 = *rp1;
			DWORD rva2 = *rp2;
			int size = 1 << (p[2] >> 6);
			unsigned long *addr = (unsigned long *)&p[3];
			DWORD rva = *addr;
			if ((REG_EBP == (p[2] & (REG_MASK >> 3))) && Relocate(addr)) {
				if (0 == (p[0] & 2)) {
					DOUT("> %s %s, %p(, %s, %d) => %s %s, %p(, %s, %d)\n", op, reg, rva, reg3, size, op, reg, *addr, reg3, size);
				} else {
					DOUT("> %s %p(, %s, %d), %s => %s %p(, %s, %d), %s\n", op, rva, reg3, size, reg, op, *addr, reg3, size, reg);
				}
				reloc = true;
			}
			if (Relocate(*rp1) | Relocate(*rp2)) {
				if (0 == (p[0] & 2)) {
					DOUT("> %s %s, (%s, %s, %d) [%s: %p => %p, %s: %p => %p]\n", op, reg, reg2, reg3, size, reg2, rva1, *rp1, reg3, rva2, *rp2);
				} else {
					DOUT("> %s (%s, %s, %d), %s [%s: %p => %p, %s: %p => %p]\n", op, reg2, reg3, size, reg, reg2, rva1, *rp1, reg3, rva2, *rp2);
				}
				reloc = true;
			}
			if (REG_EBP == (p[2] & (REG_MASK >> 3))) p += 7;
			else p += 3;
			goto retry;
		} else if (5 == (p[1] & (MOD_MASK | RM_MASK))) {
			// 1000_100w: mod(00) reg r/m(101): immediate addr 32
			// XXX register to memory
			// ex.) movl %eax, 0x01234567

			// 1000_101w: mod(00) reg r/m(101): immediate addr 32
			// XXX memory to register
			// ex.) movl 0x01234567, %eax
			unsigned long *addr = (unsigned long *)&p[2];
			DWORD rva = (DWORD)*addr;
			if (Relocate(addr)) {
				if (0 == (p[0] & 2)) {
					DOUT("> %s %s, %p => %s %s, %p\n", op, reg, rva, op, reg, *addr);
				} else {
					DOUT("> %s %p, %s => %s %p, %s\n", op, rva, reg, op, *addr, reg);
				}
				reloc = true;
			}
			p += 6;
			goto retry;
		} else if ((6 == (p[1] & (MOD_MASK | RM_MASK))) ||
			// 1000_100w: mod(00) reg r/m(110:esi)
			// XXX register to memory
			// ex.) movl %eax, (%esi)
			
			// 1000_101w: mod(00) reg r/m(110:esi)
			// XXX memory to register
			// ex.) movl (%esi), %eax
				(7 == (p[1] & (MOD_MASK | RM_MASK)))) {
			// 1000_100w: mod(00) reg r/m(111:edi)
			// XXX register to memory
			// ex.) movl %eax, (%edi)
			
			// 1000_101w: mod(00) reg r/m(111:edi)
			// XXX memory to register
			// ex.) movl (%edi), %eax
			const char *reg2 = RegisterName(p[1] << 3);
			unsigned long *rp = RegisterPointer(p[1] << 3, regs, xregs);
			DWORD rva = (DWORD)*rp;
			if (Relocate(*rp)) {
				if (0 == (p[0] & 2)) {
					DOUT("> %s %s, (%s) [%s: %p => %p]\n", op, reg, reg2, reg2, rva, *rp);
				} else {
					DOUT("> %s (%s), %s [%s: %p => %p]\n", op, reg2, reg, reg2, rva, *rp);
				}
				reloc = true;
			}
			p += 2;
			goto retry;
		} else if (0x44 == (p[1] & (MOD_MASK | RM_MASK))) {
			if (4 == (p[2] & RM_MASK)) {
				// 1000_100w: mod(01) reg2 r/m(100): mod(sz) reg1 r/m(100): imm8
				// XXX memory to register
				// ex.) movl 0x04(%esp, 1), %ecx
				const char *reg1 = RegisterName(p[2]);
				const char *reg2 = RegisterName(p[1]);
				unsigned long *rp = RegisterPointer(p[2], regs, xregs);
				DWORD rva = (DWORD)*rp;
				int size = 1 << (p[2] >> 6);
				if (Relocate(*rp)) {
					if (0 == (p[0] & 2)) {
						DOUT("> %s %02x(%s, %d), %s [%s: %p => %p]\n", op, p[3], reg1, size, reg2, reg2, rva, *rp);
					} else {
						DOUT("> %s %s, %02x(%s, %d) [%s: %p => %p]\n", op, reg2, p[3], reg1, size, reg2, rva, *rp);
					}
					reloc = true;
				}
				p += 4;
				goto retry;
			} else {
				// 1000_100w: mod(01) reg3 r/m(100): mod(sz) reg2 r/m(reg1): imm8
				// ex.) movl -0x00000004(%esi, %ecx, 4), %eax
				const char *reg1 = RegisterName(p[2] << 3);
				const char *reg2 = RegisterName(p[2]);
				const char *reg3 = RegisterName(p[1]);
				unsigned long *rp1 = RegisterPointer(p[2] << 3, regs, xregs);
				unsigned long *rp2 = RegisterPointer(p[2], regs, xregs);
				DWORD rva1 = *rp1;
				DWORD rva2 = *rp2;
				int size = 1 << (p[2] >> 6);
				if (Relocate(*rp1) | Relocate(*rp2)) {
					DOUT("> %s %p(%s, %s, %d), %s [%s: %p => %p, %s: %p => %p]\n", op, p[3], reg1, reg2, size, reg3, reg1, rva1, *rp1, reg2, rva2, *rp2);
					reloc = true;
				}
			}
		} else if (0x40 == (p[1] & MOD_MASK)) {
			// 1000_100w: mod(01) reg2 r/m(reg1:0-3/5-7): immediate data 8
			// XXX register to memory
			// ex.) movl %eax, 0x01(%eax)
			// 1000_101w: mod(01) reg2 r/m(reg1:0-3/5-7): immediate data 8
			// XXX memory to register
			// ex.) movl 0x01(%eax), %eax
			const char *reg1 = RegisterName(p[1] << 3);
			const char *reg2 = RegisterName(p[1]);
			unsigned long *rp = RegisterPointer(p[1] << 3, regs, xregs);
			DWORD rva = (DWORD)*rp;
			if (Relocate(*rp)) {
				if (0 == (p[0] & 2)) {
					DOUT("> %s %s, %02x(%s) [%s: %p => %p]\n", op, reg1, (signed char)p[2], reg2, reg1, rva, *rp);
				} else {
					DOUT("> %s %02x(%s), %s [%s: %p => %p]\n", op, (signed char)p[2], reg1, reg2, reg1, rva, *rp);
				}
				reloc = true;
			}
			p += 3;
			goto retry;
		} else if (0x84 == (p[1] & (MOD_MASK | RM_MASK))) {
			// 1000_100w: mod(10) reg r/m(100): sz reg3 reg2: immediate addr 32
			// XXX register to memory
			// ex.) movl %ebx, 0x01234567(%eax, %eax, 2)

			// 1000_101w: mod(10) reg r/m(100): sz reg3 reg2: immediate addr 32
			// XXX memory to register
			// ex.) movl 0x01234567(%eax, %eax, 2), %ebx
			const char *reg2 = RegisterName(p[2] << 3);
			const char *reg3 = RegisterName(p[2]);
			unsigned long *addr = (unsigned long *)&p[3];
			int size = 1 << (p[2] >> 6);
			DWORD rva = (DWORD)*addr;
			if (Relocate(addr)) {
				if (0 == (p[0] & 2)) {
					DOUT("> %s %s, %p(%s, %s, %d) => %s %s, %p(%s, %s, %d)\n", op, reg, rva, reg2, reg3, size, op, reg, *addr, reg2, reg3, size);
				} else {
					DOUT("> %s %p(%s, %s, %d), %s => %s %p(%s, %s, %d), %s\n", op, rva, reg2, reg3, size, reg, op, *addr, reg2, reg3, size, reg);
				}
				reloc = true;
			}
			p += 7;
			goto retry;
		} else if (0x80 == (p[1] & MOD_MASK)) {
			// 1000_100w: mod(10) reg r/m(reg2:0-3,5-7): immediate addr 32
			// XXX register to memory
			// ex.) movl %eax, 0x01234567(%eax)
			
			// 1000_101w: mod(10) reg r/m(reg2:0-3,5-7): immediate addr 32
			// XXX memory to register
			// ex.) movl 0x01234567(%eax), %eax
			const char *reg2 = RegisterName(p[1] << 3);
			unsigned long *rp = RegisterPointer(p[1] << 3, regs, xregs);
			unsigned long *addr = (unsigned long *)&p[2];
			DWORD rva1 = (DWORD)*addr;
			DWORD rva2 = (DWORD)*rp;
			if (Relocate(addr, *rp)) {
				if (0 == (p[0] & 2)) {
					DOUT("> %s %s, %08x(%s) [%s: %p] => %s %s, %08x(%s) [%s: %p]\n",
						op, reg, rva1, reg2, reg2, rva2,
						op, reg, *addr, reg, reg2, *rp);
				} else {
					DOUT("> %s %08x(%s), %s [%s: %p] => %s %08x(%s), %s [%s: %p]\n",
						op, rva1, reg2, reg, reg2, rva2,
						op, *addr, reg2, reg, reg2, *rp);
				}
				reloc = true;
			}
			p += 6;
			goto retry;
		} else if (0xc0 == (p[1] & MOD_MASK)) {
			// 1000_100w: mod(11) reg r/m(reg)
			// XXX register to register
			// ex.) testl %ecx, %ecx
			p += 2;
			goto retry;
		} else goto ufailed;
		break; }
/* -------------------------------------------------------------------------------------------- */
	///////////////////
	// 2-byte escape //
	case 0x0f:
		switch(p[1]) {
/* -------------------------------------------------------------------------------------------- */
		////////
		// JE //
		case 0x84:
			p += 6;
			goto retry;
/* -------------------------------------------------------------------------------------------- */
		////////
		// JNZ //
		case 0x85:
			p += 6;
			goto retry;
/* -------------------------------------------------------------------------------------------- */
		/////////////////
		// IMUL Gv, Ev //
		case 0xaf:
			if (5 == (p[2] & (MOD_MASK | RM_MASK))) {
				// 00001111: 10101111: mod(00) reg r/m(101): immediate addr 32
				// IMUL register with memory
				// ex.) imull 0x01234567, %eax
				const char *reg = RegisterName(p[2]);
				unsigned long *addr = (unsigned long *)&p[3];
				DWORD rva = *addr;
				if (Relocate(addr)) {
					DOUT("> imull %p, %s => imull %p, %s\n", rva, reg, *addr, reg);
					reloc = true;
				}
				p += 7;
				goto retry;
			} else if (0xc0 == (p[2] & MOD_MASK)) {
				// 00001111: 10101111: mod(11) reg r/m(reg2)
				// IMUL register with register
				// ex.) imul %edx, %esi
				p += 3;
				goto retry;
			} else goto ufailed;
			break;
/* -------------------------------------------------------------------------------------------- */
		///////////
		// MOVZx //
		case 0xb6:	// Gv, Eb
		case 0xb7:	// Gv, Ww
		///////////
		// MOVSx //
		case 0xbe:	// Gv, Eb
		case 0xbf: {// Gv, Ew
			char *op = NULL;
			if (0 == (p[1] & 0x08)) op = "movzx";
			else op = "movsx";
			if (0 == (p[2] & (MOD_MASK | RM_NR_MASK))) {
				// 00001111: 1011111w: mod(00) reg3 r/m(reg:0-3)
				// MOVSX memory to register
				// ex.) movsx (%edx), %edx
				const char *reg1 = RegisterName(p[2]);
				const char *reg2 = RegisterName(p[2] << 3);
				unsigned long *rp = RegisterPointer(p[2] << 3, regs, xregs);
				DWORD rva = *rp;
				if (Relocate(*rp)) {
					DOUT("> %s (%s), %s [%s: %p => %p]\n", op, reg1, reg2, reg1, rva, *rp);
					reloc = true;
				}
				p += 3;
				goto retry;
			} else if (4 == (p[2] & (MOD_MASK | RM_MASK))) {
				// 00001111: 1011111w: mod(00) reg3 r/m(100): mod(size) reg(reg2) r/m(reg1)
				// MOVSX memory to register
				// ex.) movzx (%eax, %esi, 1), %ebx
				const char *reg1 = RegisterName(p[3] << 3);
				const char *reg2 = RegisterName(p[3]);
				const char *reg3 = RegisterName(p[2]);
				unsigned long *rp1 = RegisterPointer(p[3] << 3, regs, xregs);
				unsigned long *rp2 = RegisterPointer(p[3], regs, xregs);
				int size = 1 << (p[3] >> 6);
				DWORD rva1 = *rp1;
				DWORD rva2 = *rp2;
				if (Relocate(*rp1) | Relocate(*rp2)) {
					DOUT("> %s (%s, %s, %d), %s [%s: %p => %p, %s: %p => %p]\n", op, reg1, reg2, size, reg3, reg1, rva1, *rp1, reg2, rva2, *rp2);
					reloc = true;
				}
				p += 4;
				goto retry;
			} else if (5 == (p[2] & (MOD_MASK | RM_MASK))) {
				// 00001111: 1011111w: mod(00) reg r/m(101): immediate addr 32
				// MOVSX memory to register
				// ex.) movsx 0x01234567, %ecx
				const char *reg = RegisterName(p[2]);
				unsigned long *addr = (unsigned long *)&p[3];
				DWORD rva = *addr;
				if (Relocate(addr)) {
					DOUT("> %s %p, %s => %s %p, %s\n", op, rva, reg, op, *addr, reg);
					reloc = true;
				}
				p += 7;
				goto retry;
			} else if (0x40 == (p[2] & MOD_MASK)) {
				// 00001111: 1011111w: mod(10) reg2 r/m(reg1): immediate 8
				// MOVSX memory to register
				// ex.) movsx 0x06(%eax), %eax
				const char *reg1 = RegisterName(p[2] << 3);
				const char *reg2 = RegisterName(p[2]);
				unsigned long *rp = RegisterPointer(p[2] << 3, regs, xregs);
				DWORD rva = *rp;
				if (Relocate(*rp)) {
					DOUT("> %s %p(%s), %s [%s: %p => %p]\n", op, p[3], reg1, reg2, reg1, rva, *rp);
					reloc = true;
				}
				p += 4;
				goto retry;
			} else if (0x80 == (p[2] & MOD_MASK)) {
				if (4 != (p[2] & RM_MASK)) {
					// 00001111: 1011111w: mod(10) reg2 r/m(reg1:0-3/5-7): immediate addr 32
					// MOVSX memory to register
					// ex.) movsx 0x01234567(%edx), %ecx
					const char *reg1 = RegisterName(p[2] << 3);
					const char *reg2 = RegisterName(p[2]);
					unsigned long *addr = (unsigned long *)&p[3];
					DWORD rva = *addr;
					if (Relocate(addr)) {
						DOUT("> %s %p(%s), %s => %s %p(%s), %s\n", op, rva, reg1, reg2, op, *addr, reg1, reg2);
						reloc = true;
					}
					p += 7;
					goto retry;
				} else {
					// 00001111: 1011111w: mod(10) reg3 r/m(100): mod(sz) reg1 r/m(reg2): imm32
					// MOVSX memory to register
					// ex.) movsx 0x0042952c(%esi, %eax, 8), %eax
					const char *reg1 = RegisterName(p[3]);
					const char *reg2 = RegisterName(p[3] << 3);
					const char *reg3 = RegisterName(p[2]);
					unsigned long *rp1 = RegisterPointer(p[3], regs, xregs);
					unsigned long *rp2 = RegisterPointer(p[3] << 3, regs, xregs);
					unsigned long *addr = (unsigned long *)&p[4];
					DWORD rva1 = *rp1;
					DWORD rva2 = *rp2;
					DWORD rva3 = *addr;
					int size = 1 << (p[3] >> 6);
					if (Relocate(*rp1) | Relocate(*rp1)) {
						DOUT("> %s %p(%s, %s, %d), %s [%s: %p => %p, %s: %p => %p]\n", op, rva3, reg1, reg2, size, reg3, reg1, rva1, *rp1, reg2, rva2, *rp2);
						reloc = true;
					}
					if (Relocate(addr)) {
						DOUT("> %s %p(%s, %s, %d), %s => %s %p(%s, %s, %d), %s\n", op, rva3, reg1, reg2, size, reg3, op, *addr, reg1, reg2, size, reg3);
						reloc = true;
					}
					p += 8;
					goto retry;
				}
			} else goto ufailed;
			break; }
		default:
			goto ufailed;
		}
		break;
/* -------------------------------------------------------------------------------------------- */
	/////////
	// AND //
	case 0x25:	// AND eAX, Iv
		p += 5;
		goto retry;
/* -------------------------------------------------------------------------------------------- */
	/////////
	// CMP //
	case 0x3d: {// AL, Ib
		// CMP immediate with AL, AX, or EAX
		// 0011 1101: imm
		// ex.) cmpl $0x01234567, %eax
		unsigned long *addr = (unsigned long *)&p[1];
		DWORD rva = (DWORD)*addr;
		if (Relocate(addr)) {
			DOUT("> cmpl $0x%08x, %s => cmpl $0x%08x, %s\n", rva, "%eax", *addr, "%eax");
			reloc = true;
		}
		p += 5;
		goto retry;
		break; }
/* -------------------------------------------------------------------------------------------- */
	//////////////////////////
	// INC general register //
	case 0x40:
	case 0x41:
	case 0x42:
	case 0x43:
	case 0x44:
	case 0x45:
	case 0x46:
	case 0x47:
		p++;
		goto retry;
		break;
/* -------------------------------------------------------------------------------------------- */
	//////////////////////////
	// DEC general register //
	case 0x48:
	case 0x49:
	case 0x4a:
	case 0x4b:
	case 0x4c:
	case 0x4d:
	case 0x4e:
	case 0x4f:
		p++;
		goto retry;
		break;
/* -------------------------------------------------------------------------------------------- */
	///////////////////////////
	// PUSH general register //
	case 0x50:
	case 0x51:
	case 0x52:
	case 0x53:
	case 0x54:
	case 0x55:
	case 0x56:
	case 0x57:
	///////////////////////////////
	// POP into general register //
	case 0x58:
	case 0x59:
	case 0x5a:
	case 0x5b:
	case 0x5c:
	case 0x5d:
	case 0x5e:
	case 0x5f:
		p++;
		goto retry;
		break;
/* -------------------------------------------------------------------------------------------- */
	//////////////
	// Opd Size //
	case 0x66:
		opdsize = true;
		p++;
		goto opd_retry;
		break;
/* -------------------------------------------------------------------------------------------- */
	/////////////
	// PUSH Iv //
	case 0x68: {
		unsigned long *addr = (unsigned long *)&p[1];
		DWORD rva = (DWORD)*addr;
		if (Relocate(addr)) {
			DOUT("> pushl $0x%08x => pushl $0x%08x\n", rva, *addr);
			reloc = true;
		}
		p += 5;
		goto retry;
		break; }
/* -------------------------------------------------------------------------------------------- */
	/////////////
	// PUSH Ib //
	case 0x6a:
		p += 2;
		goto retry;
		break;
/* -------------------------------------------------------------------------------------------- */
	///////////////////////////////////////////////
	// Jcc - Short displacement jump on conditon //
	case 0x70:
	case 0x71:
	case 0x72:
	case 0x73:
	case 0x74:
	case 0x75:
	case 0x76:
	case 0x77:
	case 0x78:
	case 0x79:
	case 0x7a:
	case 0x7b:
	case 0x7c:
	case 0x7d:
	case 0x7e:
	case 0x7f:
		p += 2;
		goto retry;
		break;
/* -------------------------------------------------------------------------------------------- */
	///////////////////////
	// Immediate Grp 1^2 //
	case 0x80:	// Eb, Ib
	case 0x81:	// Ev, Iv
	case 0x82:	// Ev, Ib
	case 0x83: {// Ev, Ib
		char *op = NULL;
		switch (p[1] & REG_MASK) {
		case 0x00:	// ADD
			if (0 == (p[0] & 1)) op = "addb";
			else op = "addl";
			break;
		case 0x08:	// OR
			if (0 == (p[0] & 1)) op = "orb";
			else op = "orl";
			break;
		case 0x10:	// ADC
			if (0 == (p[0] & 1)) op = "adcb";
			else op = "adcl";
			break;
		case 0x18:	// SBB
			if (0 == (p[0] & 1)) op = "sbbb";
			else op = "sbbl";
			break;
		case 0x20:	// AND
			if (0 == (p[0] & 1)) op = "andb";
			else op = "andl";
			break;
		case 0x28:	// SUB
			if (0 == (p[0] & 1)) op = "subb";
			else op = "subl";
			break;
		case 0x30:	// XOR
			if (0 == (p[0] & 1)) op = "xorb";
			else op = "xorl";
			break;
		case 0x38:	// CMP
			if (0 == (p[0] & 1)) op = "cmpb";
			else op = "cmpl";
			break;
		}
		if ((0 == (p[1] & (MOD_MASK | RM_NR_MASK))) ||
			(7 == (p[1] & (MOD_MASK | RM_MASK)))) {
			// 1000_00sw: mod(00) reg(OP.) r/m(reg:0-3/7): immediate data 8
			// OR/AND/CMP immediate to/with memory
			// ex.) cmpb $0x12, (%eax)
			const char *reg = RegisterName(p[1] << 3);
			unsigned long *rp = RegisterPointer(p[1] << 3, regs, xregs);
			DWORD rva = (DWORD)*rp;
			if (Relocate(*rp)) {
				DOUT("> %s $0x%02x, (%s) [%s: %p => %p]\n", op, p[2], reg, reg, rva, *rp);
				reloc = true;
			}
			p += 3;
			goto retry;
		} else if (4 == (p[1] & (MOD_MASK | RM_MASK))) {
			if (5 != (p[2] & RM_MASK)) {
				// 1000_00sw: mod(00) reg(OP.) r/m(100): mod(sz) reg2 r/m(reg3): immediate data 8
				// OR/AND/CMP immediate to/with memory
				// ex.) cmpb $0x5c, (%ecx, %eax, 1)
				const char *reg1 = RegisterName(p[2]);
				const char *reg2 = RegisterName(p[2] << 3);
				unsigned long *rp1 = RegisterPointer(p[2], regs, xregs);
				unsigned long *rp2 = RegisterPointer(p[2] << 3, regs, xregs);
				DWORD rva1 = (DWORD)*rp1;
				DWORD rva2 = (DWORD)*rp2;
				int size = 1 << (p[2] >> 6);
				if (Relocate(*rp1) | Relocate(*rp2)) {
					DOUT("> %s $0x%02x, (%s, %s, %d) [%s: %p => %p, %s: %p => %p]\n", op, p[3], reg1, reg2, size, reg1, rva1, *rp1, reg2, rva2, *rp2);
					reloc = true;
				}
				p += 4;
				goto retry;
			} else {
				// 1000_00sw: mod(00) reg(OP.) r/m(100): mod(10) reg r/m(101): immediate addr 32: immediate data 8
				// OR/AND/CMP immediate to/with memory
				// ex.) cmpl $0x01, 0x01234567(,%eax,4)
				const char *reg = RegisterName(p[2] << 3);
				unsigned long *addr = (unsigned long *)&p[3];
				DWORD rva = (DWORD)*addr;
				if (Relocate(addr)) {
					DOUT("> %s $0x%02x, 0x%p(, %s, 4) => %s $0x%02x, 0x%p(, %s, 4)\n", op, p[7], rva, reg, op, p[7], *addr, "%eax");
					reloc = true;
				}
				p += 8;
				goto retry;
			}
		} else if (5 == (p[1] & (MOD_MASK | RM_MASK))) {
			// 1000_00sw: mod(00) reg(OP.) r/m(101): immediate addr 32
			// OR/AND/CMP immediate to/with memory
			// ex.) andl $0x01, 0x01234567
			unsigned long *addr = (unsigned long *)&p[2];
			DWORD rva = (DWORD)*addr;
			if (Relocate(addr)) {
				DOUT("> %s $0x%02x, %p => %s $0x%02x, %p\n", op, p[6], rva, op, p[6], *addr);
				reloc = true;
			}
			p += 6;
			goto retry;
		} else if (6 == (p[1] & (MOD_MASK | RM_MASK))) {
			// 1000_00sw: mod(00) reg(OP.) r/m(110): immediate data 8
			// OR/AND/CMP immediate to/with memory
			// ex.) cmpl $0x01, (%esi)
			DWORD rva = (DWORD)xregs->esi;
			if (Relocate(xregs->esi)) {
				DOUT("> %s $0x%02x, (%s) [%s: %p => %p]\n", op, p[2], "%esi", "%esi", rva, xregs->esi);
				reloc = true;
			}
			p += 3;
			goto retry;
		} else if (0x40 == (p[1] & MOD_MASK)) {
			if (4 == (p[1] & RM_MASK)) {
				// 1000_00sw: mod(01) reg(OP.) r/m(100): mod(sz) reg2 r/m(reg1:000) :imm8: imm8
				// OR/AND/CMP immediate to/with memory
				// ex.) cmpb $0x01, 0x01(%eax, %esi, 1)
				const char *reg1 = RegisterName(p[2] << 3);
				const char *reg2 = RegisterName(p[2]);
				unsigned long *rp1 = RegisterPointer(p[2] << 3, regs, xregs);
				unsigned long *rp2 = RegisterPointer(p[2], regs, xregs);
				DWORD rva1 = *rp1;
				DWORD rva2 = *rp2;
				int size = 1 << (p[2] >> 6);
				if (Relocate(*rp1) | Relocate(*rp2)) {
					DOUT("> %s $0x%02x, %02x(%s, %s, %d) [%s: %p => %p, %s: %p => %p]\n", op, p[4], p[3], reg1, reg2, size, reg1, rva1, *rp1, reg2, rva2, *rp2);
					reloc = true;
				}
				p += 5;
				goto retry;
			} else {
				// 1000_00sw: mod(01) reg(OP.) r/m(reg:1-3/5-7): imm8: imm8
				// OR/AND/CMP immediate to/with memory
				// ex.) cmpl $0x01, 0x0c(%eax)
				const char *reg = RegisterName(p[1] << 3);
				unsigned long *rp = RegisterPointer(p[1] << 3, regs, xregs);
				DWORD rva = (DWORD)*rp;
				if (Relocate(*rp)) {
					DOUT(" >%s $0x%02x, 0x%02x(%s) [%s: %p => %p]\n", op, p[2], p[3], reg, reg, rva, *rp);
					reloc = true;
				}
				p += 4;
				goto retry;
			}
		} else if (0x80 == (p[1] & MOD_MASK)) {
			// 1000_00sw: mod(10) reg(OP.) r/m(reg): immediate addr 32: immediate data 8
			// OR/AND/CMP immediate to/with memory
			// ex.) andl $0x01, 0x01234567(%eax)
			const char *reg = RegisterName(p[1] << 3);
			unsigned long *rp = RegisterPointer(p[1] << 3, regs, xregs);
			DWORD rva = (DWORD)*rp;
			unsigned long *addr = (unsigned long *)&p[2];
			if (Relocate(*rp)) {
				DOUT("> %s $0x%02x, %p(%s) [%s: %p => %p]\n", op, p[6], *addr, reg, reg, rva, *rp);
				reloc = true;
			}
			rva = (DWORD)*addr;
			if (Relocate(addr)) {
				DOUT("> %s $0x%02x, %p(%s) => %s $0x%02x, %p(%s)\n", op, p[6], rva, reg, op, p[6], *addr, reg);
				reloc = true;
			}
			p += 7;
			goto retry;
		} else if (0xc0 == (p[1] & MOD_MASK)) {
			if (0x81 != p[0]) {
				// 1000_00sw(0): mod(11) reg(OP.) r/m(reg): immediate data
				// OR/AND/CMP immediate to/with register
				// ex.) addl $0x01, %eax
				p += 3;
				goto retry;
			} else {
				// 1000_00sw(1): mod(11) reg(OP.) r/m(reg): immediate data
				// OR/AND/CMP immediate to/with register
				// ex.) cmpl $0x01234567, %eax
				const char *reg = RegisterName(p[1] << 3);
				unsigned long *addr = (unsigned long *)&p[2];
				DWORD rva = *addr;
				if (Relocate(addr)) {
					DOUT("> %s $%08x, %s => %s $%08x, %s\n", op, rva, reg, op, *addr, reg);
					reloc = true;
				}
				p += 6;
				goto retry;
			}
		} else goto ufailed;
		break; }
/* -------------------------------------------------------------------------------------------- */
	///////////////
	// LEA Gv, M //
	case 0x8d:
		if (0x00 == (p[1] & MOD_MASK)) {
			if (0x04 == (p[1] & RM_MASK)) {
				// 10001101: mod(00) reg3(000) r/m(100): mod(00) reg2 r/m(reg)
				// ex.) lea (%edx, %ebx), %eax
				const char *reg1 = RegisterName(p[2] << 3);
				const char *reg2 = RegisterName(p[2]);
				const char *reg3 = RegisterName(p[1]);
				unsigned long *rp1 = RegisterPointer(p[2] << 3, regs, xregs);
				unsigned long *rp2 = RegisterPointer(p[2], regs, xregs);
				DWORD rva1 = *rp1;
				DWORD rva2 = *rp2;
				if (Relocate(*rp1) | Relocate(*rp2)) {
					DOUT("> lea (%s, %s), %s [%s: %p => %p, %s: %p => %p]\n", reg1, reg2, reg3, reg1, rva1, *rp1, reg2, rva2, *rp2);
					reloc = true;
				}
				p += 3;
				goto retry;
			}
		} else if (0x40 == (p[1] & MOD_MASK)) {
			if (0x04 != (p[1] & RM_MASK)) {
				// 10001101: mod(01) reg2 r/m(reg1): imm8
				// ex.) lea -4(%ebp), %eax
				const char *reg1 = RegisterName(p[1] << 3);
				const char *reg2 = RegisterName(p[1]);
				unsigned long *rp = RegisterPointer(p[1] << 3, regs, xregs);
				DWORD rva = *rp;
				if (Relocate(*rp)) {
					DOUT("> lea %d(%s), %s [%s: %p => %p]\n", p[2], reg1, reg2, reg1, rva, *rp);
					reloc = true;
				}
				p += 3;
				goto retry;
			} else {
				// 10001101: mod(01) reg3 r/m(100): mod(sz) reg1, reg2: immediate 8 
				// LEA
				// ex.) lea 0x01(%edx, %ecx, 1), %esi
				const char *reg1 = RegisterName(p[2]);
				const char *reg2 = RegisterName(p[2] << 3);
				const char *reg3 = RegisterName(p[1]);
				unsigned long *rp1 = RegisterPointer(p[2], regs, xregs);
				unsigned long *rp2 = RegisterPointer(p[2] << 3, regs, xregs);
				int size = 1 << (p[2] >> 6);
				DWORD rva1 = *rp1;
				DWORD rva2 = *rp2;
				if (Relocate(*rp1) | Relocate(*rp2)) {
					DOUT("> lea 0x%02x(%s, %s, %d), %s [%s: %p => %p, %s: %p => %p]\n", p[3], reg1, reg2, size, reg3, reg1, rva1, *rp1, reg2, rva2, *rp2);
					reloc = true;
				}
				p += 4;
				goto retry;
			}
		} else if (0x80 == (p[1] & MOD_MASK)) {
			// 10001101: mod(10) reg2 r/m(reg1): imm32
			// ex.) lea 0x00020001(%edi), %edx
			const char *reg1 = RegisterName(p[1] << 3);
			const char *reg2 = RegisterName(p[1]);
			unsigned long *rp = RegisterPointer(p[1] << 3, regs, xregs);
			DWORD rva = *rp;
			if (Relocate(*rp)) {
				DOUT("> lea %p(%s), %s [%s: %p => %p]\n", *(unsigned long *)&p[2], reg1, reg2, reg1, rva, *rp);
				reloc = true;
			}
			p += 6;
			goto retry;
		} else goto ufailed;
		break;
/* -------------------------------------------------------------------------------------------- */
	/////////
	// NOP //
	case 0x90:
		p++;
		goto retry;
		break;
/* -------------------------------------------------------------------------------------------- */
	case 0xa0:
	case 0xa1:
			// 1010_000w: full displacement
			// MOV memory to AL, AX, or EAX
			// ex.) movl 0x01234567, %eax
	case 0xa2:
	case 0xa3: {
			// 1010_001w: full displacement
			// MOV AL, AX, or EAX to memory
			// ex.) movl %eax, 0x01234567
			char *op = NULL;
			char *reg = NULL;
			if (0 == (p[0] & 1)) {
				op = "movb";
				reg = "%al";
			} else {
				op = "movl";
				reg = "%eax";
			}
			unsigned long *addr = (unsigned long *)&p[1];
			DWORD rva = (DWORD)*addr;
			if (Relocate(addr)) {
				if (0 != (p[0] & 2)) {
					DOUT("> %s %s, %p => %s %s, %p\n", op, reg, rva, op, reg, *addr);
				} else {
					DOUT("> %s %p, %s => %s %p, %s\n", op, rva, reg, op, *addr, reg);
				}
				reloc = true;
			}
			p += 5;
			goto retry;
		break; }
/* -------------------------------------------------------------------------------------------- */
	case 0xa5: {
		// 1010 010w
		// MOVS
		// ex.) movsl %ds:(%edi), %es:(%esi)
		DWORD rva1 = (DWORD)xregs->edi;
		DWORD rva2 = (DWORD)xregs->esi;
		if (Relocate(xregs->edi) | Relocate(xregs->esi)) {
			DOUT("> movsl %s, %s [%s: %p => %p, %s: %p => %p]\n", "%ds:(%edi)", "%es:(%esi)", "%edi", rva1, xregs->edi, "%esi", rva2, xregs->esi);
			reloc = true;
		}
		p++;
		goto retry;
		break; }
/* -------------------------------------------------------------------------------------------- */
	///////////////////////////////////////////////////////////////
	// MOV immediate word or double into word or double register //
	case 0xb8:	// eAX
	case 0xb9:	// eCX
	case 0xba:	// eDX
	case 0xbb:	// eBX
	case 0xbc:	// eSP
	case 0xbd:	// eBP
	case 0xbe:	// eSI
	case 0xbf: {// eDI
		const char *reg = RegisterName((p[0] - 0xb8) << 3);
		unsigned long *addr = (unsigned long *)&p[1];
		DWORD rva = (DWORD)*addr;
		if (Relocate(addr)) {
			DOUT("> movl $0x%08x, %s => movl $0x%08x, %s\n", rva, reg, *addr, reg);
			reloc = true;
		}
		p += 5;
		goto retry;
		break; }
/* -------------------------------------------------------------------------------------------- */
	///////////////////
	// Shift Grp 2^2 //
	case 0xc1:	// Ev, Ib
		if ((0xe0 == (p[1] & (MOD_MASK | REG_MASK))) ||
			// 1100_000w: mod(11) 100 r/m(reg): immediate data 8
			// SHL register by immediate count
			// ex.) shll $0x01, %eax
			(0xe8 == (p[1] & (MOD_MASK | REG_MASK)))) {
			// 1100_000w: mod(11) 101 r/m(reg): immediate data 8
			// SHR register by immediate count
			// ex.) shrl $0x01, %eax
			p += 3;
			goto retry;
		} else if (0x2d == p[1]) {
			// 1100_000w: mod(00) 101 r/m(101): immediate addr 32: immediate data 8
			// SHR memory by immediate count
			// ex.) shrl $0x01, 0x01234567
			unsigned long *addr = (unsigned long *)&p[2];
			DWORD rva = (DWORD)*addr;
			if (Relocate(addr)) {
				DOUT("> shrl $0x%02x, %p => shrl $0x%02x, %p\n", p[6], rva, p[6], *addr);
				reloc = true;
			}
		} else goto ufailed;
		p += 7;
		goto retry;
		break;
/* -------------------------------------------------------------------------------------------- */
	/////////
	// RET //
	case 0xc3:
		p++;
		count = 0;
		goto retry;
		break;
/* -------------------------------------------------------------------------------------------- */
	////////////////////
	// Grp 12^2 - MOV //
	case 0xc6:	// Eb, Ib
	case 0xc7: {// Ev, Iv
		char *op = NULL;
		if (0 == (p[0] & 1)) op = "movb";
		else {
			if (opdsize) op = "movw";
			else op = "movl";
		}
		if (0 == (p[1] & (MOD_MASK | REG_MASK))) {
			if (4 != (p[1] & RM_MASK)) {
				// 1100 011w: mod(00) 000 r/m(reg:0-3/5-7): immediate addr 32
				// ex.) movl $0x01234567, (%edx)
				unsigned long *addr = (unsigned long *)&p[2];
				const char *reg = RegisterName(p[1] << 3);
				unsigned long *rp = RegisterPointer(p[1] << 3, regs, xregs);
				DWORD rva1 = *addr;
				DWORD rva2 = *rp;
				bool rc = false;
				if (Relocate(*rp)) {
					DOUT("> %s $0x%08x, (%s) [%s: %p => %p]\n", op, rva1, reg, reg, rva2, *rp);
					reloc = true;
				}
				if (Relocate(addr)) {
					DOUT("> %s $0x%08x, (%s) => %s $0x%08x, (%s)\n", op, rva1, reg, op, *addr, reg);
					reloc = true;
				}
				p += 6;
				goto retry;
			} else {
				if (5 == (p[2] & RM_MASK)) {
					// 1100 011w: mod(00) reg(000) r/m(100): mod(sz) reg r/m(101): immediate addr 32
					// XXX memory to memory
					// ex.) movl $0x01234567, (%esi, 8)
					const char *reg = RegisterName(p[2]);
					unsigned long *rp = RegisterPointer(p[2], regs, xregs);
					int size = 1 << (p[2] >> 6);
					unsigned long *addr = (unsigned long *)&p[3];
					DWORD rva = *addr;
					if (Relocate(addr)) {
						DOUT("> %s $%p, (, %s, %d) => %s $%p, (, %s, %d)\n", op, rva, reg, size, op, *addr, reg, size);
						reloc = true;
					}
					rva = *rp;
					if (Relocate(*rp)) {
						DOUT("> %s $%p, (, %s, %d) [%s: %p => %p]\n", op,  *addr, reg, size, reg, rva, *rp);
						reloc = true;
					}
					p += 7;
				} else {
					// 1100 011w: mod(00) reg(000) r/m(100): mod(sz) reg1 r/m(reg2): imm8/32
					// XXX memory to memory
					// ex.) movb $0x00, (%eax, %edx, 1)
					const char *reg1 = RegisterName(p[2]);
					const char *reg2 = RegisterName(p[2] << 3);
					unsigned long *rp1 = RegisterPointer(p[2], regs, xregs);
					unsigned long *rp2 = RegisterPointer(p[2] << 3, regs, xregs);
					DWORD rva1 = *rp1;
					DWORD rva2 = *rp2;
					int size = 1 << (p[2] >> 6);
					if (Relocate(*rp1) | Relocate(*rp2)) {
						if (0 == (p[0] & 1)) DOUT("> %s $%02x, (%s, %s, %d) [%s: %p => %p, %s: %p => %p]\n", op, p[3], reg1, reg2, size, reg1, rva1, *rp1, reg2, rva2, *rp2);
						else DOUT("> %s $%08x, (%s, %s, %d) [%s: %p => %p, %s: %p => %p]\n", op, *((long *)&p[3]), reg1, reg2, size, reg1, rva1, *rp1, reg2, rva2, *rp2);
						reloc = true;
					}
					if (0 == (p[0] & 1)) p += 4;
					else p += 7;
				}
			}
			goto retry;
		} else if (5 == p[1]) {
			// 1100 011w: mod(00) 000 r/m(101): immediate addr 32: immediate data 32(16)
			// MOV immediate to memory
			// ex.) movl $0x01234567, 0x01234567
			unsigned long *addr1 = (unsigned long *)&p[2];
			unsigned long *addr2 = (unsigned long *)&p[6];
			DWORD rva1 = (DWORD)*addr1;
			DWORD rva2 = (DWORD)*addr2;
			if (Relocate(addr1) | (!opdsize && Relocate(addr2))) {
				unsigned long imm_old = opdsize? *(unsigned short *)&p[6]: rva2;
				unsigned long imm_new = opdsize? *(unsigned short *)&p[6]: *addr2;
				DOUT("> %s $%p, %p => %s $%p, %p\n", op, imm_old, rva1, op, imm_new, *addr1);
				reloc = true;
			}
			if (opdsize) p += 8;
			p += 10;
			goto retry;
		} else if (0x40 == (p[1] & (MOD_MASK | REG_MASK))) {
			// 1000 011w: mod(01) 000 r/m(reg): imm 8: imm 32
			// MOV immediate to memory
			// ex.) movl $0x00000001, 0x04(%esi)
			const char *reg = "%esi";
			unsigned long *rp = RegisterPointer(p[1] << 3, regs, xregs);
			DWORD rva = (DWORD)*rp;
			if (Relocate(*rp)) {
				DOUT("> %s $0x%08x, 0x%02x(%s) [%s: %p => %p]\n", op, *(unsigned long *)&p[3], p[2], reg, reg, rva, *rp);
				reloc = true;
			}
			p += 7;
			goto retry;
		} else if (0x80 == (p[1] & (MOD_MASK | REG_MASK))) {
			// 1100 011w: mod(10) 000 r/m(reg): immediate data 32: immediate addr 32
			// MOV immediate to memory
			// ex.) movl $0x01234567, 0x01234567(%ebx)
			const char *reg = RegisterName(p[1] << 3);
			unsigned long *rp = RegisterPointer(p[1] << 3, regs, xregs);
			DWORD rva = (DWORD)*rp;
			unsigned long *addr1 = (unsigned long *)&p[2];
			unsigned long *addr2 = (unsigned long *)&p[6];
			DWORD rva1 = (DWORD)*addr1;
			DWORD rva2 = (DWORD)*addr2;
			if (Relocate(*rp) | Relocate(addr1) | (!opdsize && Relocate(addr2))) {
				unsigned long imm_old = opdsize? *(unsigned short *)&p[6]: rva2;
				unsigned long imm_new = opdsize? *(unsigned short *)&p[6]: *addr2;
				DOUT("> %s $%p, %p(%s) => %s $%p, %p(%s)\n", op, imm_old, rva1, reg, op, imm_new, *addr1, reg);
				reloc = true;
			}
			p += 10;
			goto retry;
		} else goto ufailed;
		break; }
/* -------------------------------------------------------------------------------------------- */
	case 0xd8:
	case 0xdc:
		if (0x0d == p[1]) {
			// 11011x00: mod(00) 001 r/m(101): immediate addr 32
			// FMUL 32/64-bit memory
			// ex.) fmul 0x004b222c
			unsigned long *addr = (unsigned long *)&p[2];
			DWORD rva = (DWORD)*addr;
			if (Relocate(addr)) {
				DOUT("> fcomp %p => fmul %p\n", rva, *addr);
				reloc = true;
			}
			p += 6;
			goto retry;
		} else if (0x1d == p[1]) {
			// 11011x00: mod(00) 011 r/m(101): immediate addr 32
			// FCOMP 32/64-bit memory
			// ex.) fcomp 0x01234567
			unsigned long *addr = (unsigned long *)&p[2];
			DWORD rva = (DWORD)*addr;
			if (Relocate(addr)) {
				DOUT("> fcomp %p => fcomp %p\n", rva, *addr);
				reloc = true;
			}
			p += 6;
			goto retry;
		} else goto ufailed;
		break;
/* -------------------------------------------------------------------------------------------- */
	case 0xdd:
		if (0x05 == p[1]) {
			// 11011101: mod(00) 000 r/m(101): immediate addr 32
			// FLD 64-bit memory
			// ex.) fld 0x01234567
			unsigned long *addr = (unsigned long *)&p[2];
			DWORD rva = (DWORD)*addr;
			if (Relocate(addr)) {
				DOUT("> fld %p => fld %p\n", rva, *addr);
				reloc = true;
			}
			p += 6;
			goto retry;
		} else if (0x18 == (p[1] & (MOD_MASK | REG_MASK))) {
			// 11011101: mod(00) 011 r/m(reg)
			// FSTP memory
			// ex.) fstp (%ecx)
			const char *reg = RegisterName(p[1] << 3);
			unsigned long *rp = RegisterPointer(p[1] << 3, regs, xregs);
			DWORD rva = (DWORD)*rp;
			if (Relocate(*rp)) {
				DOUT("> fstp (%s) [%s: %p => %p]\n", reg, reg, rva, *rp);
				reloc = true;
			}
			p += 2;
			goto retry;
		} else goto ufailed;
		break;
/* -------------------------------------------------------------------------------------------- */
	/////////////
	// CALL Jv //
	case 0xe8:
		p += 5;
		goto retry;
/* -------------------------------------------------------------------------------------------- */
	/////////
	// JMP //
	case 0xeb:	// short Jb
		p += 2;
		goto retry;
/* -------------------------------------------------------------------------------------------- */
	case 0xf2:
		// 1111_0010: ...
		// REPNE
		// ex.) repnz
	case 0xf3: {
		// 1111_0011: ...
		// REP
		// ex.) repz
		char *op = NULL;
		if (0xf2 == p[0]) op = "repnz";
		else op = "repz";
		char *op2 = NULL;
		bool dual = false;
		switch (p[1]) {
		case 0xa4:	// 1010010w MOVS
			op2 = "movsb";
			dual = true;
			break;
		case 0xa5:	// 1010010w MOVS
			op2 = "movsl";
			dual = true;
			break;
		case 0xa6:	// 1010011w CMPS
			op2 = "cmpsb";
			dual = true;
			break;
		case 0xa7:	// 1010011w CMPS
			op2 = "cmpsl";
			dual = true;
			break;
		case 0xaa:	// 1010101w STOS
			op2 = "stosb";
			break;
		case 0xab:	// 1010101w STOS
			op2 = "stosl";
			break;
		case 0xae:	// 1010111w SCAS
			op2 = "scasb";
			break;
		case 0xaf:	// 1010111w SCAS
			op2 = "scasl";
			break;
		default:
			goto ufailed;
		}
		DWORD rva1 = xregs->edi;
		DWORD rva2 = xregs->esi;
		if (dual) {
			if (Relocate(xregs->edi) | Relocate(xregs->esi)) {
				DOUT("> %s %s %s, %s [%s: %p => %p, %s: %p => %p]\n", op, op2, "es:(%edi)", "%ds:(%esi)", "%edi", rva1, xregs->edi, "%esi", rva2, xregs->esi);
				reloc = true;
			}
		} else {
			if (Relocate(xregs->edi)) {
				DOUT("> %s %s %s, %s [%s: %p => %p]\n", op, op2, (0 == (p[1] & 1))? "%al": "%eax", "%es:(%edi)", "%edi", rva1, xregs->edi);
				reloc = true;
			}
		}
		p += 2;
		goto retry;
		break; }
/* -------------------------------------------------------------------------------------------- */
	case 0xf6:
	case 0xf7: {
		char *op = NULL;
		if (0 == (p[0] & 1)) op = "testb";
		else op = "testl";
		if (0 == p[1]) {
			// 1111_011w: mod(00) 000 r/m(000): imm32
			// ex.) testl $0x10000000, (%eax)
			const char *reg = RegisterName(0);
			unsigned long *rp = RegisterPointer(0, regs, xregs);
			DWORD rva = *rp;
			if (Relocate(*rp)) {
				DOUT("> %s %p, (%s) [%s: %p => %p]\n", op, *(unsigned long *)&p[2], reg, reg, rva, *rp);
				reloc = true;
			}
			p += 6;
			goto retry;
		} else if (5 == p[1]) {
			// 1111_011w: mod(00) 000 r/m(101): immediate data 32: immediate data 8/32
			// TEST immediate and memory
			// ex.) testb $0x80, 0x01234567
			unsigned long *addr = (unsigned long *)&p[2];
			DWORD rva = (DWORD)*addr;
			if (Relocate(addr)) {
				unsigned long imm = 0;
				if (0 == (p[0] & 1)) imm = p[6];
				else imm = *(unsigned long *)&p[6];
				DOUT("> %s $0x%02x, %p => %s $0x%02x, %p\n", op, imm, rva, op, imm, *addr);
				reloc = true;
			}
			if (0 == (p[0] & 1)) p += 7;
			else p += 10;
			goto retry;
		} else if (0x44 == p[1]) {
			// 1111_011w: mod(01) 000 r/m(100): mod(sz) reg2 reg1: immediate data 8: immediate data 8
			// TEST immediate and memory
			// ex.) testb $0x80, 0x01(%ecx, %eax, 2)
			const char *reg1 = RegisterName(p[2] << 3);
			const char *reg2 = RegisterName(p[2]);
			unsigned long *rp1 = RegisterPointer(p[2] << 3, regs, xregs);
			unsigned long *rp2 = RegisterPointer(p[2], regs, xregs);
			DWORD rva1 = (DWORD)*rp1;
			DWORD rva2 = (DWORD)*rp2;
			int size = 1 << (p[2] >> 6);
			if (Relocate(*rp1) | Relocate(*rp2)) {
				DOUT("> %s $0x%02x, 0x%02x(%s, %s, %d) [%s: %p => %p, %s: %p => %p]\n", op, p[4], p[3], reg1, reg2, size, reg1, rva1, *rp1, reg2, rva2, *rp2);
				reloc = true;
			}
			p += 5;
			goto retry;
		} else if (0x80 == (p[1] & (MOD_MASK | REG_MASK))) {
			// 1111_011w: mod(10) 000 r/m(reg): immediate data 32
			// TEST immediate and memory
			// ex.) testl $0x01, 0x01234567(%eax)
			const char *reg = RegisterName(p[1] << 3);
			unsigned long *rp = RegisterPointer(p[1] << 3, regs, xregs);
			DWORD rva = (DWORD)*rp;
			unsigned long *addr = (unsigned long *)&p[2];
			if (Relocate(*rp)) {
				DOUT("> %s $0x%02x, %p(%s) [%s: %p => %p]\n", op, p[6], *addr, reg, reg, rva, *rp);
				reloc = true;
			}
			rva = (DWORD)*addr;
			if (Relocate(addr)) {
				DOUT("> %s $0x%02x, %p(%s) => %s $0x%02x, %p(%s)\n", op, p[6], rva, reg, op, p[6], *addr, reg);
				reloc = true;
			}
			p += 6;
			goto retry;
		} else if (0xc4 == p[1]) {
			// 1111_011w: mod(11) 000 r/m(100): immediate data 8
			// TEST immediate and memory
			// ex.) testb $0x80,%ah
			p += 3;
			goto retry;
		} else if (0xd8 == p[1]) {
			// ex.) neg %eax
			p += 2;
			goto retry;
		} else goto ufailed;
		break; }
/* -------------------------------------------------------------------------------------------- */
	case 0xff:
		if (0x05 == p[1]) {
			// 1111_111w: mod(00) 000 r/m(101): immediate data 32
			// INC memory
			// ex.) incl 0x01234567
			unsigned long *addr = (unsigned long *)&p[2];
			DWORD rva = (DWORD)*addr;
			if (Relocate(addr)) {
				DOUT("> incl %p => incl %p\n", rva, *addr);
				reloc = true;
			}
			p += 6;
			goto retry;
		} else if (0x0d == p[1]) {
			// 1111_1111: mod(00) 001 r/m(101)
			// DEC memory
			// ex.) decl 0x0048d854
			unsigned long *addr = (unsigned long *)&p[2];
			DWORD rva = (DWORD)*addr;
			if (Relocate(addr)) {
				DOUT("> decl %p => decl %p\n", rva, *addr);
				reloc = true;
			}
			p += 6;
			goto retry;
		} else if (0x15 == p[1]) {
			// 1111_1111: mod(00) 010 r/m(101)
			// CALL memory indirect
			// ex.) call 0x01234567
			unsigned long *addr = (unsigned long *)&p[2];
			DWORD rva = (DWORD)*addr;
			if (Relocate(addr)) {
				DOUT("> call *%p => call *%p\n", rva, *addr);
				reloc = true;
			}
			p += 6;
			goto retry;
		} else if (((0x24 == p[1]) || (0x34 == p[1])) && (0x85 == (p[2] & (MOD_MASK | RM_MASK)))) {
			// 1111_1111: mod(00) 100 r/m(100): mod(10) reg r/m(101): immediate 32
			// JMP memory indirect
			// ex.) jmp 0x01234567(,%eax,4)
			
			// 1111_1111: mod(01) 100 r/m(100): mod(10) reg r/m(101): immediate 32
			// PUSH memory indirect
			// ex.) pushl 0x01234567(,%eax,4)
			char *op = NULL;
			if (0x24 == p[1]) op = "jmp";
			else op = "pushl";
			const char *reg = RegisterName(p[2]);
			unsigned long *addr = (unsigned long *)&p[3];
			DWORD rva = (DWORD)*addr;
			if (Relocate(addr)) {
				DOUT("> %s %p(, %s, 4) => %s %p(, %s, 4)\n", op, rva, reg, op, *addr, reg);
				reloc = true;
			}
			p += 7;
			goto retry;
		} else if (0x25 == p[1]) {
			// 1111_1111: mod(00) 100 r/m(101): immediate 32
			// JMP memory indirect
			// ex.) jmp 0x01234567
			unsigned long *addr = (unsigned long *)&p[2];
			DWORD rva = (DWORD)*addr;
			if (Relocate(addr)) {
				DOUT("> jmp %p => jmp %p\n", rva, *addr);
				reloc = true;
			}
			p += 6;
			goto retry;
		} else if (0x30 == p[1]) {
			// 1111_1111: mod(00) 110 r/m(000)
			// PUSH memory
			// ex.) pushl (%eax)
			const char *reg = RegisterName(p[1] << 3);
			unsigned long *rp = RegisterPointer(p[1] << 3, regs, xregs);
			DWORD rva = (DWORD)*rp;
			if (Relocate(*rp)) {
				DOUT("> pushl (%s) [%s: %p => %p]\n", reg, reg, rva, *rp);
				reloc = true;
			}
			p += 2;
			goto retry;
		} else if (0x35 == p[1]) {
			// 1111_1111: mod(00) 110 r/m(101): immediate 32
			// PUSH memory
			// ex.) push. 0x01234567
			unsigned long *addr = (unsigned long *)&p[2];
			DWORD rva = (DWORD)*addr;
			if (Relocate(addr)) {
				DOUT("> pushl %p => pushl %p\n", rva, *addr);
				reloc = true;
			}
			p += 6;
			goto retry;
		} else if (0x36 == p[1]) {
			// 1111_1111: mod(00) 110 r/m(110)
			DWORD rva = (DWORD)xregs->esi;
			if (Relocate(xregs->esi)) {
				DOUT("> pushl (%s) [%s: %p => %p]\n", "%esi", "%esi", rva, xregs->esi);
				reloc = true;
			}
			p += 2;
			goto retry;
		} else if (0x50 == (p[1] & (MOD_MASK | REG_MASK))) {
			// 1111_1111: mod(01) 010 r/m(reg): imm 8
			// ex.) call 0x04(%eax)
			const char *reg = RegisterName(p[1] << 3);
			unsigned long *rp = RegisterPointer(p[1] << 3, regs, xregs);
			DWORD rva = (DWORD)*rp;
			if (Relocate(*rp)) {
				DOUT("> call %02x(%s) [%s: %p => %p]\n", p[2], reg, reg, rva, *rp);
				reloc = true;
			}
			p += 3;
			goto retry;
		} else if (0xd0 == (p[1] & (MOD_MASK | REG_MASK))) {
			// 1111_1111: mod(11) 010 r/m(reg)
			// ex.) call esi
			const char *reg = RegisterName(p[1] << 3);
			unsigned long *rp = RegisterPointer(p[1] << 3, regs, xregs);
			DWORD rva = (DWORD)*rp;
			if (Relocate(*rp)) {
				DOUT("> call %s [%s: %p => %p]\n", reg, reg, rva, *rp);
				reloc = true;
			}
			p += 2;
			goto retry;
		} else goto ufailed;
		break;
/* -------------------------------------------------------------------------------------------- */
	default:
		goto ufailed;
	}
	goto failed;
ufailed:
	DOUT("!!! unknown instruction !!!\n");
failed:
	if (reloc) goto ret;
	signal(SIGSEGV, SIG_DFL);
	DOUT("!!! relocation failed !!!\n");
ret:
	DOUT("\n");
	return;
}

bool
Coff::Relocate
(unsigned long *addr)
{
	unsigned long new_addr = (unsigned long)Rva2Address(*addr - imageBase);
	if (0 == new_addr) return false;
	area_id id = area_for((void *)addr);
	if (id < B_OK) return false;
	area_info info;
	status_t rc = get_area_info(id, &info);
	if (rc != B_OK) return false;
	bool change = false;
	uint32 old_prot = 0;
	if (0 == (info.protection & B_WRITE_AREA)) {
		old_prot = info.protection;
		change = true;
		rc = set_area_protection(id, old_prot | B_WRITE_AREA);
		if (rc != B_OK) return false;
	}
	*addr = new_addr;
	if (change) return B_OK == set_area_protection(id, old_prot);
	return true;
}

bool
Coff::Relocate
(unsigned long &reg)
{
	unsigned long new_addr = (unsigned long)Rva2Address(reg - imageBase);
	if (0 == new_addr) {
		if (0 != (0x80000000 & reg)) return false;
		int32 n = varea_addr.CountItems();
		int32 i;
		new_addr = reg | 0x80000000;
		for (i = 0; i < n; i++) {
			unsigned long addr = (unsigned long)varea_addr.ItemAt(i);
			unsigned long size = (unsigned long)varea_size.ItemAt(i);
			DOUT("varea check: %2d %08x < %08x < %08x\n", i, addr, new_addr, addr + size);
			if ((addr <= new_addr) && (new_addr < (addr + size))) break;
		}
		if (i == n) return false;
	}
	reg = new_addr;
	return true;
}

bool
Coff::Relocate
(unsigned long *addr, unsigned long &reg)
{
	unsigned long address = *addr + reg;
	unsigned long new_addr = (unsigned long)Rva2Address(address - imageBase);
	if (0 == new_addr) return false;
	area_id id = area_for((void *)addr);
	if (id < B_OK) return false;
	area_info info;
	status_t rc = get_area_info(id, &info);
	if (rc != B_OK) return false;
	bool change = false;
	uint32 old_prot = 0;
	if (0 == (info.protection & B_WRITE_AREA)) {
		old_prot = info.protection;
		change = true;
		rc = set_area_protection(id, old_prot | B_WRITE_AREA);
		if (rc != B_OK) return false;
	}
	*addr = new_addr - reg;
	if (change) return B_OK == set_area_protection(id, old_prot);
	return true;
}

void
Coff::VAreaAdd
(void *addr, int size)
{
	varea_addr.AddItem(addr);
	varea_size.AddItem((void *)size);
}

void
Coff::VAreaRemove
(void *addr)
{
	int i = varea_addr.IndexOf(addr);
	if (i < 0) return;
	varea_addr.RemoveItem(i);
	varea_size.RemoveItem(i);
}

const char *
Coff::RegisterName
(int reg, bool byte) const
{
	int i = (reg & REG_MASK) >> 3;
	static char *names_e[] = {
		"%eax", "%ecx", "%edx", "%ebx", "%esp", "%ebp", "%esi", "%edi",
	};
	static char *names_b[] = {
		"%al", "%cl", "%dl", "%bl", "%ah", "%ch", "%dh", "%bh",
	};
	if (byte) return names_b[i];
	return names_e[i];
}

unsigned long *
Coff::RegisterPointer
(int reg, vregs *regs, xxxregs *xregs) const
{
	int i = (reg & REG_MASK) >> 3;
	switch(i) {
	case 0:
		return &regs->eax;
	case 1:
		return &regs->ecx;
	case 2:
		return &regs->edx;
	case 3:
		return &xregs->ebx;
	case 4:
		return &regs->esp;
	case 5:
		return &regs->ebp;
	case 6:
		return &xregs->esi;
	case 7:
		return &xregs->edi;
	}
	return NULL;
}

#endif	// defined (ENABLE_DYNAMIC_RELOCATION)
