/* swith statement branch */

	.global _start

_start:
	mov r1, #1
	mov r2, #2
	mov r3, #3
	mov r4, #4
	mov r5, #5
	mov r6, #6		@user input stand in

_switch:
	cmp r6, r1
	beq _mon_wed
	cmp r6, r2
	beq _tue_thur
	cmp r6, r3
	beq _mon_wed
	cmp r6, r4
	beq _tue_thur
	cmp r6, r5
	beq _fri
	bne _nada		@last 'else' condition		

_mon_wed:			@case 1 and case 2
	mov r0, #11		@statement
	b _exit			@break
	
_tue_thur:			@case 3 and case 4
	mov r0, #5		@statement
	b _exit			@break

_fri:				@case 5
	mov r0, #1		@statement
	b _exit			@break

_nada:				@default
	mov r0, #0		@statement

_exit:
	mov r7, #1
	swi 0
