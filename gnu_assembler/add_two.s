	.section .data
a: .long 8
b: .long 12
c: .long 0

res: .space 10		# Allocating 10 bytes.
ptr: .long 0
newline: .ascii "\n"


	.section .text
	.globl _start

_start:
	movl $a, %eax
	movl $b, %ebx
	addl %ebx, %eax
	movl %eax, c

	movl res, $ptr

	to_ascii:
		divl $10, $c 		# Doubtful
		addl 0x30, %eax
		addl $1, ptr
		movl %eax, ptr

		cmpl $0, $c
		jz to_ascii

	movl $newline, ptr

	movl $1, %eax
	movl $1, %ebx
	movl $res, %ecx
	movl $4, %edx
	int 0x80

	movl $1, %eax
	movl $0, %ebx
	int 0x80