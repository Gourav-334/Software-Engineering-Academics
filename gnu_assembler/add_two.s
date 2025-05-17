# Data declaration

	.section .data
a: .long 8
b: .long 12
res: .space 10		# 10 bytes free space



# Main function

	.section .text
	.globl _start


_start:
	
	# Loading both numbers.

	movl a, %eax
	movl b, %ebx


	# Adding both numbers.

	addl %ebx, %eax


	to_ascii:
		