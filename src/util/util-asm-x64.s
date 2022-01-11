.text

.global rs_math_clock64

rs_math_clock64:

	push %rdx

	rdtsc
	mov %edx, 4(%rsp)
	mov %eax, (%rsp)
	mov (%rsp), %rax

	pop %rdx

	ret
