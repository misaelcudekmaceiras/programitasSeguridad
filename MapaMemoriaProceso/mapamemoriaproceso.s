	.file	"mapamemoriaproceso.c"
	.intel_syntax noprefix
# GNU C11 (Ubuntu 7.5.0-3ubuntu1~18.04) version 7.5.0 (x86_64-linux-gnu)
#	compiled by GNU C version 7.5.0, GMP version 6.1.2, MPFR version 4.0.1, MPC version 1.1.0, isl version isl-0.19-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed:  -imultiarch x86_64-linux-gnu mapamemoriaproceso.c
# -masm=intel -mtune=generic -march=x86-64 -fverbose-asm
# -fstack-protector-strong -Wformat -Wformat-security
# options enabled:  -fPIC -fPIE -faggressive-loop-optimizations
# -fasynchronous-unwind-tables -fauto-inc-dec -fchkp-check-incomplete-type
# -fchkp-check-read -fchkp-check-write -fchkp-instrument-calls
# -fchkp-narrow-bounds -fchkp-optimize -fchkp-store-bounds
# -fchkp-use-static-bounds -fchkp-use-static-const-bounds
# -fchkp-use-wrappers -fcommon -fdelete-null-pointer-checks
# -fdwarf2-cfi-asm -fearly-inlining -feliminate-unused-debug-types
# -ffp-int-builtin-inexact -ffunction-cse -fgcse-lm -fgnu-runtime
# -fgnu-unique -fident -finline-atomics -fira-hoist-pressure
# -fira-share-save-slots -fira-share-spill-slots -fivopts
# -fkeep-static-consts -fleading-underscore -flifetime-dse
# -flto-odr-type-merging -fmath-errno -fmerge-debug-strings -fpeephole
# -fplt -fprefetch-loop-arrays -freg-struct-return
# -fsched-critical-path-heuristic -fsched-dep-count-heuristic
# -fsched-group-heuristic -fsched-interblock -fsched-last-insn-heuristic
# -fsched-rank-heuristic -fsched-spec -fsched-spec-insn-heuristic
# -fsched-stalled-insns-dep -fschedule-fusion -fsemantic-interposition
# -fshow-column -fshrink-wrap-separate -fsigned-zeros
# -fsplit-ivs-in-unroller -fssa-backprop -fstack-protector-strong
# -fstdarg-opt -fstrict-volatile-bitfields -fsync-libcalls -ftrapping-math
# -ftree-cselim -ftree-forwprop -ftree-loop-if-convert -ftree-loop-im
# -ftree-loop-ivcanon -ftree-loop-optimize -ftree-parallelize-loops=
# -ftree-phiprop -ftree-reassoc -ftree-scev-cprop -funit-at-a-time
# -funwind-tables -fverbose-asm -fzero-initialized-in-bss
# -m128bit-long-double -m64 -m80387 -malign-stringops
# -mavx256-split-unaligned-load -mavx256-split-unaligned-store
# -mfancy-math-387 -mfp-ret-in-387 -mfxsr -mglibc -mieee-fp
# -mlong-double-80 -mmmx -mno-sse4 -mpush-args -mred-zone -msse -msse2
# -mstv -mtls-direct-seg-refs -mvzeroupper

	.text
	.globl	enterogloblal
	.bss
	.align 4
	.type	enterogloblal, @object
	.size	enterogloblal, 4
enterogloblal:
	.zero	4
	.globl	charglobal
	.data
	.type	charglobal, @object
	.size	charglobal, 1
charglobal:
	.byte	71
	.section	.rodata
.LC0:
	.string	"Hola Mundo!!"
.LC1:
	.string	"dir enterogloblal: %p\n"
.LC2:
	.string	"dir charglobal: %p\n"
.LC3:
	.string	"dir enterodelmain: %p\n"
.LC4:
	.string	"dir chardelmain: %p\n"
.LC5:
	.string	"dir &pInt: %p\n"
.LC6:
	.string	"dir pInt: %p\n"
.LC7:
	.string	"dir prinf: %p\n"
.LC8:
	.string	"dir main: %p\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB5:
	.cfi_startproc
	push	rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp	#,
	.cfi_def_cfa_register 6
	sub	rsp, 32	#,
# mapamemoriaproceso.c:25: {
	mov	rax, QWORD PTR fs:40	# tmp97,
	mov	QWORD PTR -8[rbp], rax	# D.2952, tmp97
	xor	eax, eax	# tmp97
# mapamemoriaproceso.c:26:     int enterodelmain=1;
	mov	DWORD PTR -20[rbp], 1	# enterodelmain,
# mapamemoriaproceso.c:27:     char chardelmain='M';
	mov	BYTE PTR -21[rbp], 77	# chardelmain,
# mapamemoriaproceso.c:29:     int * pInt=(int*)malloc(4097);
	mov	edi, 4097	#,
	call	malloc@PLT	#
	mov	QWORD PTR -16[rbp], rax	# pInt, _1
# mapamemoriaproceso.c:31:     printf("Hola Mundo!!\n");
	lea	rdi, .LC0[rip]	#,
	call	puts@PLT	#
# mapamemoriaproceso.c:33:     printf("dir enterogloblal: %p\n",&enterogloblal);
	lea	rsi, enterogloblal[rip]	#,
	lea	rdi, .LC1[rip]	#,
	mov	eax, 0	#,
	call	printf@PLT	#
# mapamemoriaproceso.c:34:     printf("dir charglobal: %p\n",&charglobal);
	lea	rsi, charglobal[rip]	#,
	lea	rdi, .LC2[rip]	#,
	mov	eax, 0	#,
	call	printf@PLT	#
# mapamemoriaproceso.c:36:     printf("dir enterodelmain: %p\n",&enterodelmain);
	lea	rax, -20[rbp]	# tmp92,
	mov	rsi, rax	#, tmp92
	lea	rdi, .LC3[rip]	#,
	mov	eax, 0	#,
	call	printf@PLT	#
# mapamemoriaproceso.c:37:     printf("dir chardelmain: %p\n",&chardelmain);
	lea	rax, -21[rbp]	# tmp93,
	mov	rsi, rax	#, tmp93
	lea	rdi, .LC4[rip]	#,
	mov	eax, 0	#,
	call	printf@PLT	#
# mapamemoriaproceso.c:39:     printf("dir &pInt: %p\n",&pInt);
	lea	rax, -16[rbp]	# tmp94,
	mov	rsi, rax	#, tmp94
	lea	rdi, .LC5[rip]	#,
	mov	eax, 0	#,
	call	printf@PLT	#
# mapamemoriaproceso.c:40:     printf("dir pInt: %p\n",pInt);
	mov	rax, QWORD PTR -16[rbp]	# pInt.0_2, pInt
	mov	rsi, rax	#, pInt.0_2
	lea	rdi, .LC6[rip]	#,
	mov	eax, 0	#,
	call	printf@PLT	#
# mapamemoriaproceso.c:42:     printf("dir prinf: %p\n",printf);
	mov	rax, QWORD PTR printf@GOTPCREL[rip]	# tmp95,
	mov	rsi, rax	#, tmp95
	lea	rdi, .LC7[rip]	#,
	mov	eax, 0	#,
	call	printf@PLT	#
# mapamemoriaproceso.c:43:     printf("dir main: %p\n",main);
	lea	rsi, main[rip]	#,
	lea	rdi, .LC8[rip]	#,
	mov	eax, 0	#,
	call	printf@PLT	#
# mapamemoriaproceso.c:46:     getchar();//para que no finalice el programa
	call	getchar@PLT	#
	mov	eax, 0	# _21,
# mapamemoriaproceso.c:48: }
	mov	rdx, QWORD PTR -8[rbp]	# tmp98, D.2952
	xor	rdx, QWORD PTR fs:40	# tmp98,
	je	.L3	#,
	call	__stack_chk_fail@PLT	#
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
