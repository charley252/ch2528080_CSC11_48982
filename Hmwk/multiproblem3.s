/* find the radius^2 given the area */

	.global _start

_start:
	ldr r1, #113.4		@BP0 WD8
	ldr r2, =0x51745D	@BP-24 WD24
	mul r0, r1, r2		@BP-24 WD32
	lsr r0, #24		@BP0 WD8 bit point shift
	mov r7, #1
	swi 0
