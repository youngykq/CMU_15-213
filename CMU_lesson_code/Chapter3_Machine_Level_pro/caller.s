	.file	"caller.c"
	.text
	.globl	swap_add
	.type	swap_add, @function
swap_add:
.LFB0:
	.cfi_startproc
	movq	(%rdi), %rax
	movq	(%rsi), %rdx
	movq	%rdx, (%rdi)
	movq	%rax, (%rsi)
	addq	%rdx, %rax
	ret
	.cfi_endproc
.LFE0:
	.size	swap_add, .-swap_add
	.globl	caller
	.type	caller, @function
caller:
.LFB1:
	.cfi_startproc
	subq	$16, %rsp
	.cfi_def_cfa_offset 24
	movq	$534, 8(%rsp)
	movq	$1057, (%rsp)
	movq	%rsp, %rsi
	leaq	8(%rsp), %rdi
	call	swap_add
	movq	8(%rsp), %rdx
	subq	(%rsp), %rdx
	imulq	%rdx, %rax
	addq	$16, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE1:
	.size	caller, .-caller
	.ident	"GCC: (Debian 12.2.0-14) 12.2.0"
	.section	.note.GNU-stack,"",@progbits
