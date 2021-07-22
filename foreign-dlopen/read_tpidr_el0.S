	.text
	.align	4
	.globl	read_tpidr_el0
	.type	read_tpidr_el0,%function
	.globl	write_tpidr_el0
	.type	write_tpidr_el0,%function
read_tpidr_el0:
	mrs	x0, tpidr_el0
	ret

write_tpidr_el0:
	msr	tpidr_el0, x0
	ret
