/* for-loop summation for the first 10 natural numbers */

	.global _start

_start:
	mov r1, #10		@summation numbers
	mov r2, #1		@increment
	mov r3, #0		@sum tally

_for:				@loop
	cmp r2, r1		@condition parameter
	ble _sum		@check loop condition
	b   _exit		@exit loop
_sum:
	add r3, r3, r2		@sum up
	add r2, r2, #1		@increment
	bal _for		@loop back

_exit:
	mov r0, r3		@move answer to r0 for echo out
	mov r7, #1
	swi 0
