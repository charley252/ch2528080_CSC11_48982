/* division and remainder */

	.global _start

_start:
	mov r1, #55		@dividend
	mov r2, #6		@divisor

	mov r4, r2		@put the divisor in r4
	cmp r4, r1, lsr #1	@then double it until
				@2xr4 > divisor.
_div1:
	movls r4, r4, lsl #1	
	cmp r4, r1, lsr #1
	bls _div1
	mov r3, #0		@initialize the quotient

_div2:
	cmp r1, r4		@can we subtract r4?
	subcs r1, r1, r4	@if we can , do so
	adc r3, r3, r3		@double the quotient & add new bit	

	mov r4, r4, lsr #1	@halve r4
	cmp r4, r2		@loop until we've gone
	bhs _div2		@past the original divisor

_exit:
	mov r0, r3
	mov r7, #1
	swi 0
