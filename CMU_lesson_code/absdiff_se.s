	.file	"absdiff_se.c"
	.text
	.globl	absdiff_se
	.type	absdiff_se, @function
absdiff_se:
.LFB0:
	.cfi_startproc
	cmpq	%rsi, %rdi
	jge	.L2
	addq	$1, lt_cnt(%rip)
	movq	%rsi, %rax
	subq	%rdi, %rax
	ret
.L2:
	addq	$1, ge_cnt(%rip)
	movq	%rdi, %rax
	subq	%rsi, %rax
	ret
	.cfi_endproc
.LFE0:
	.size	absdiff_se, .-absdiff_se
	.globl	ge_cnt
	.bss
	.align 8
	.type	ge_cnt, @object
	.size	ge_cnt, 8
ge_cnt:
	.zero	8
	.globl	lt_cnt
	.align 8
	.type	lt_cnt, @object
	.size	lt_cnt, 8
lt_cnt:
	.zero	8
	.ident	"GCC: (Debian 12.2.0-14) 12.2.0"
	.section	.note.GNU-stack,"",@progbits
