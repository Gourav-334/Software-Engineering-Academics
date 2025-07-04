	.section .data
i_msg: .asciz "Please enter a number: "
o_msg0: .asciz "Number is not prime.\n"
o_msg1: .asciz "Number is indeed prime.\n"

res: .byte 1



	.section .bss
num_str: .space 4
num: .space 8



	.section .text
	.globl _start


_start:
	
	# Asking for input.

	movq $1, %rax
	movq $1, %rdi
	movq $i_msg, %rsi
	movq $24, %rdx
	syscall


	# Taking the input.

	movq $0, %rax
	movq $0, %rdi
	movq $num_str, %rsi
	movq $4, %rdx
	syscall


	# Adding newline character.

	movq $1, %rax
	movq $1, %rdi
	movq $0x0a, %rsi
	movq $1, %rdx
	syscall


	# Converting string 'num_str' to integer.

	movq $num_str, %rdi
	xorq %rax, %rax
	movq $10, %rcx
	callq to_int


	# Copying 'num' to RAX for division by RCX (also 'num').

	movq $num, %rdi
	movq %rax, (%rdi)
	movq %rax, %rcx
	decq %rcx


	# Call subroutine to check prime or not.

	callq check_prime


	# Printing message for "Not Prime".

	movq $1, %rax
	movq $1, %rdi
	movq $o_msg0, %rsi
	movq $22, %rdx
	syscall


	# Interrupt to halt the program.

	movq $60, %rax
	movq $0, %rdi
	syscall



to_int:
	addb (%rdi), %al
	subq $0x30, %rax
	mulq %rcx
	incq %rdi

	cmpq $0x0a, (%rdi)
	jne to_int
	divq %rcx

	ret



check_prime:

	# Clearing RDI to hold remainder later.

	xorq %rdx, %rdx


	# Divide-checking for prime.

	divq %rcx
	decq %rcx


	# Declaring "Prime" is remainder in RDX>0

	cmpq $0, %rdx
	jnz is_prime


	# If RDX<=0 & RCX has reached 1 then return.
	
	cmpq $1, %rcx
	jnz check_prime
	ret



is_prime:

	# Displaying "Is a prime" message on STDOUT.

	movq $1, %rax
	movq $1, %rdi
	movq $o_msg1, %rsi
	movq $25, %rdx
	syscall


	# Interrupt to halt the program.

	movq $60, %rax
	movq $0, %rdi
	syscall
