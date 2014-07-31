# --------------------------------------------------------------------------------------------
#  ExeCoffSky for BeOS
#  (C) 2000, 2001 ‚Æ‚æ‚µ‚Ü
#  $Id: CallWindowProcAsm.s,v 1.1 2003/05/01 03:34:13 toyoshim Exp $
# --------------------------------------------------------------------------------------------
#  [CallWindowProcAsm.s]
# --------------------------------------------------------------------------------------------
.section	.rodata
.text
	.p2align	2

.global		CallWindowProcAsm
	.type	main, @function

#
# CallWindowProcAsm(WNDPROC, HWND, UINT, WPARAM, LPARAM, long regbuf[3])
#                   4(esp)  8(esp) c(esp) 10(esp) 14(esp) 18(esp)
#
CallWindowProcAsm:
	pushl	%ebp
	movl	0x1c(%esp), %ebp
	movl	%edi, 0x00(%ebp)
	movl	%esi, 0x04(%ebp)
	movl	%ebx, 0x08(%ebp)
	movl	0x08(%esp), %eax
	pushl	0x18(%esp)	# push LPARAM
	pushl	0x18(%esp)	# push WPARAM
	pushl	0x18(%esp)	# push UINT
	pushl	0x18(%esp)	# push HWND
	call	*%eax		# WNDPROC()
	movl	0x1c(%esp), %ebp
	movl	0x00(%ebp), %edi
	movl	0x04(%ebp), %esi
	movl	0x08(%ebp), %ebx
	popl	%ebp
	ret
	nop
.Lfel:

	.size	CallWindowProcAsm,.Lfel - main
