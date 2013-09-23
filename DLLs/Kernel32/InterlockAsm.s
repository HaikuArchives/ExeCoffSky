# --------------------------------------------------------------------------------------------
#  ExeCoffSky for BeOS
#  (C) 2000, 2001 ‚Æ‚æ‚µ‚Ü
#  $Id: InterlockAsm.s,v 1.1 2003/05/01 02:57:16 toyoshim Exp $
# --------------------------------------------------------------------------------------------
#  [InterlockAsm.s]
# --------------------------------------------------------------------------------------------
.section	.rodata
.text
	.p2align	2

.global		InterlockedCompareExchangeAsm
	.type	main, @function
.global		InterlockedExchangeAsm
	.type	main, @function
.global		InterlockedExchangeAddAsm
	.type	main, @function

InterlockedCompareExchangeAsm:
	mov		0x04(%esp, 1), %ecx
	mov		0x08(%esp, 1), %edx
	mov		0x0c(%esp, 1), %eax
	nop
	cmpxchg	%edx, (%ecx)
	ret
	nop

InterlockedExchangeAsm:
	mov		0x04(%esp, 1), %ecx
	mov		0x08(%esp, 1), %edx
_retry:
	mov		(%ecx), %eax
	nop
	cmpxchg	%edx, (%ecx)
	jne		_retry
	ret
	nop

InterlockedExchangeAddAsm:
	mov		0x04(%esp, 1), %ecx
	mov		0x08(%esp, 1), %eax
	nop
	xadd	%eax, (%ecx)
	ret
	nop
