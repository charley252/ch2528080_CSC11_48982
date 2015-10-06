/* while loop summation of first 10 natural number */

	.global _start

_start:
	mov r1, #10		@summation number
	mov r2, #1		@increment
	mov r3, #0		@sum tally

_while:				@loop
	cmp r2, r1		@condition parameter
	ble _sum		@check condition
	b   _exit		@exit loop

_sum:
	add r3, r3, r2		@sum up
	add r2, r2, #1		@increment
	bal _while		@loop back

_exit:
	mov r0, r3		@move anser to r0 for echo
	mov r7, #1
	swi 0
