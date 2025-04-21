	.file	"remdiv_3_5_5.c"
	.text
	.globl	remdiv
	.type	remdiv, @function
remdiv:
.LFB0:
	.cfi_startproc
	movq	%rdx, %r8
	movq	%rdi, %rax
	cqto
	idivq	%rsi
	andq	%rsi, %rdi
	movq	%rax, (%r8)
	movq	%rdi, (%rcx)
	ret
	.cfi_endproc
.LFE0:
	.size	remdiv, .-remdiv
	.ident	"GCC: (Debian 12.2.0-14) 12.2.0"
	.section	.note.GNU-stack,"",@progbits
