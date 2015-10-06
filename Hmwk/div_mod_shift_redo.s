/* division by bit shift redo */

	.global _start

_start:
	mov r0, #55		@start with numerator, end with mod
	mov r1, #0		@start with 0, end with quotient
	mov r2, #1		@increment  - bit shift
	mov r3, #6		@drecrement, start with denominator
	mov r4, #6		@denominator
	mov r5, #55		@numerator

_initial:
	mov r0, r5
	mov r1, #0
	mov r2, #1
	mov r3, r4		@denominator

_loop1:				@bit shift left
	mov r3, r3, lsl #1
	mov r4, r4, lsl #1
	cmp r0, r3
	bgt _loop1

_shift:				@shift right one time
	mov r3, r3, lsr #1
	mov r4, r4, lsr #1


	/* --------start of nested loop---------- */
_loop2:				@outer while loop
	cmp r0, r3
	blt _else


_add:
	add r1, r1, r2
	sub r0, r0, r3
	bal  _shiftloop

_shiftloop:			@inner shift loop
	cmp r2, #1
	beq _loop2
	cmp r3, r0
	ble _loop2
	
	
_execute:
	mov r2, r2, lsr #1
	mov r3, r3, lsr #1
	bal _shiftloop
	
	
	/* -----------output--------------- */
_else:
	mov r0, r1		@move quotient to print
	mov r7, #1
	swi 0
	
