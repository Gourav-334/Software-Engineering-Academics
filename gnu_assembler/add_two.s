	.section .data
a: .quad 8
b: .quad 12



	.section .bss
res: .space 8
result: .space 24



	.section .text
	.globl _start


_start:
	movq a(%rip), %rax 			# RIP is used because: a = Invalid, $a = Address, RIP = Point & send
	addq b(%rip), %rax
	movq %rax, res(%rip)

	movq $10, %rcx				# DIV is performed with value stored in RCX.
	movq $result + 23, %rdi
	movq $0x0a, (%rdi)
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



to_ascii: 					# Kept outside because it interferes the flow (error) when kept in.
	xorq %rdx, %rdx 		# Cleaning RDX

	divq %rcx 				# RAX = RAX / RCX, RDX = RAX % RCX
	addb $0x30, %dl			# Converting remainder at RAX to ASCII.
	movb %dl, (%rdi)		# (RDI) means the memory address it is pointing, not register's address.
	decq %rdi

	cmpq $0, %rax
	jnz to_ascii 			# . before subroutine name denotes "global"
	ret



# Keep an extra newline to avoid that "No newline" warning message.
