# --------------------------------------------------------------------------------------------
#  ExeCoffSky for BeOS
#  (C) 2000, 2001 ‚Æ‚æ‚µ‚Ü
#  $Id: CoffSigSegv.s,v 1.1 2003/05/01 02:26:46 toyoshim Exp $
# --------------------------------------------------------------------------------------------
#  [CoffSigSegv.s]
# --------------------------------------------------------------------------------------------
.section	.rodata
.text
	.p2align	2

.global		CoffSigSegv
	.type	main, @function

CoffSigSegv:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$0x0c, %esp
	movl	%ebx, -0x04(%ebp)
	movl	%esi, -0x08(%ebp)
	movl	%edi, -0x0c(%ebp)
	lea		-0x0c(%ebp), %eax
	pushl	%eax
	movl	0x10(%ebp), %eax
	pushl	%eax
	movl	0x0c(%ebp), %eax
	pushl	%eax
	movl	0x08(%ebp), %eax
	pushl	%eax
	call	SigSegv__4CoffiP4CoffP5vregsP8_xxxregs
	movl	-0x04(%ebp),%ebx
	movl	-0x08(%ebp),%esi
	movl	-0x0c(%ebp),%edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	nop
.Lfel:

	.size	CoffSigSegv,.Lfel - main
