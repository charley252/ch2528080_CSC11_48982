/* do-while loop summation of first 10 natural number */

	.global _start

_start:
	mov r1, #10		@summation number
	mov r2, #1		@increment
	mov r3, #0		@sum tally

_do:				@loop
	add r3, r3, r2		@sum up
	add r2, r2, #1		@increment
	cmp r2, r1		@condition parameter
	ble _do			@check loop condition
	b   _exit		@out of loop

_exit:
	mov r0, r3		@move answer to r0 for echo
	mov r7, #1
	swi 0


