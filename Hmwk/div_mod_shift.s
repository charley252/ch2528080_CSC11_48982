/* division using bit shifting technique */

	.global _start

_start:
	mov r0, #0		@to contain answer(quotient), via accumulate
	mov r1, #45		@dividend
	mov r2, #6		@divisor
	mov r3, #1		@bit to shift - keep count

_loop:				@stops looping till r2 is > r1
	cmp   r2, r1		@compare divisor and dividend, set flag
	movls r2, r2, lsl#1	@if r2 is <= to r1, shift left
	movls r3, r3, lsl#1	@r3, keeps count of shift
	bls   _loop		@keep shifting left till r2 <= r1


_sub:				@shift back loop	
	cmp	r1, r2		@compare, set flag
	subcs	r1, r1, r2	@subtract r2 from r1
	addcs	r0, r0, r3	@add the bit shift count to r0(quotient)
	movs	r3, r3, lsr#1	@shift back count track, set flag(see if it's 0)
	movcc	r2, r2, lsr#1	@shift as long as carry is clear
	bcc	_sub		@repeat as long as carry is clear

_exit:
	mov r7, #1
	swi 0



