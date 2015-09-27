/* Divide 16 by 3 and get quotient */

	.global _start

_start:
	mov r0, #0		@counter set
	mov r1, #16		@dividend
_loop:
	mov r2, #3		@divisor
	sub r1, r1, r2		@subtraction method
	cmp r1, #0		@compare - like loop
	add r0, r0, #1		@count increment
	bgt _loop		@loop 
_sub:
	sub r0, r0, #1		@subtract one from counter - our answer

_exit:
	mov r7, #1
	swi 0

