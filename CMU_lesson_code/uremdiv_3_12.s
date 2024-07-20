	.file	"uremdiv_3_12.c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB11:
	.cfi_startproc
	movl	$0, %eax
	ret
	.cfi_endproc
.LFE11:
	.size	main, .-main
	.globl	uremdiv
	.type	uremdiv, @function
uremdiv:
.LFB12:
	.cfi_startproc
	movq	%rdi, %rax
	movq	%rdx, %r8
	movl	$0, %edx
	divq	%rsi
	movq	%rax, (%r8)
	movq	%rdx, (%rcx)
	ret
	.cfi_endproc
.LFE12:
	.size	uremdiv, .-uremdiv
	.ident	"GCC: (Debian 12.2.0-14) 12.2.0"
	.section	.note.GNU-stack,"",@progbits
