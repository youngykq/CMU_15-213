	.file	"store_uprod_3_5_5.c"
	.text
	.globl	store_uprod
	.type	store_uprod, @function
store_uprod:
.LFB0:
	.cfi_startproc
	movq	%rsi, %rax
	mulq	%rdx
	movq	%rax, (%rdi)
	movq	%rdx, 8(%rdi)
	ret
	.cfi_endproc
.LFE0:
	.size	store_uprod, .-store_uprod
	.ident	"GCC: (Debian 12.2.0-14) 12.2.0"
	.section	.note.GNU-stack,"",@progbits
