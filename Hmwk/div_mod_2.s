/* mod 16 by 3 */

	.global _start

_start:
	mov r0, #16		@dividend
	mov r2, #3		@divisor
	
_loop:
	sub r0, r0, r2		@subtraction method
	cmp r0, r2		@compare
	bge _loop		@loop - r0 contains answer after loop

_exit:
	mov r7, #1
	swi 0
