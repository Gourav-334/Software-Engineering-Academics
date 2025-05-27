	.section .data
msg: .asciz "Enter a number: "



	.section .bss
n: .space 8
res: .space 8
result: .space 24



	.section .text
	.globl _start


_start:
	movq $1, %rax
	movq $1, %rdi
	movq $msg, %rsi
	movq $17, %rdx
	syscall

	movq $0, %rax
	movq $0, %rdi
	movq $n, %rsi
	movq $8, %rdx
	syscall

	movq $1, %rax
	movzbq n(%rip), %rcx 		# Move with zero-extension from byte to quadword.
	subq $0x30, %rcx 			# Converting the ASCII to integer.
	callq fact

	movq $res, %rdi
	movq %rax, (%rdi)

	movq $10, %rcx
	movq $result + 23, %rdi
	movq $0x0a, (%rdi) 			# DIL not used because that's an incomplete memory address.
	decq %rdi
	call to_ascii

	movq $1, %rax
	movq $1, %rdi
	movq $result, %rsi
	movq $24, %rdx
	syscall

	movq $60, %rax
	movq $0, %rdi
	syscall


fact:
	xorq %rdx, %rdx

	mulq %rcx 				# Product is stored in RDX:RAX (128-bit long).
	decq %rcx

	cmpq $0, %rcx
	jnz fact
	ret


to_ascii:
	xorq %rdx, %rdx

	divq %rcx
	addb $0x30, %dl
	movb %dl, (%rdi)
	decq %rdi

	cmpq $0, %rax
	jnz to_ascii
	ret
