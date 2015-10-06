/* if/else statement branch */

	.global _start

_start:
	mov r1, #1
	mov r2, #2
	mov r3, #3
	mov r4, #4
	mov r5, #5
	mov r6, #5		@user input stand in

_ifelse:
	cmp r6, r1
	moveq r0, #11
	bne _else1
_else1:
	cmp r6, r2
	moveq r0, #5
	bne _else2
_else2:
	cmp r6, r3
	moveq r0, #11
	bne _else3
_else3:
	cmp r6, r4
	moveq r0, #5
	bne _else4
_else4:
	cmp r6, r5
	moveq r0, #1
	bne _else5
_else5:
	cmp r6, r1
	movlt r0, #0
	cmp r6, r5
	movgt r0, #0

_exit:
	mov r7, #1
	swi 0
