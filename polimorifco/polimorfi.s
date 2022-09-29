	.file	"polimorfi.c"
	.text
	.section	.rodata
.LC0:
	.string	"Soy un BuenWare"
.LC1:
	.string	"2222222222222222222222"
.LC2:
	.string	"%d %d %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$1, -12(%rbp)
	movl	$2, -8(%rbp)
	movl	$3, -4(%rbp)
#APP
# 24 "polimorfi.c" 1
	nop
# 0 "" 2
# 25 "polimorfi.c" 1
	nop
# 0 "" 2
# 26 "polimorfi.c" 1
	mov $0x12345678aabbccdd,%rax
# 0 "" 2
# 27 "polimorfi.c" 1
	nop
# 0 "" 2
#NO_APP
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	addl	$1, -12(%rbp)
	addl	$1, -8(%rbp)
	addl	$1, -4(%rbp)
	movl	-4(%rbp), %ecx
	movl	-8(%rbp), %edx
	movl	-12(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
#APP
# 46 "polimorfi.c" 1
	nop
# 0 "" 2
# 47 "polimorfi.c" 1
	nop
# 0 "" 2
# 48 "polimorfi.c" 1
	nop
# 0 "" 2
# 49 "polimorfi.c" 1
	nop
# 0 "" 2
#NO_APP
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.2.0-19ubuntu1) 11.2.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
