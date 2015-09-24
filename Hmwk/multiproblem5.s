/* find area given the radius */

	.global _start

_start:
	ldr r1, #6.5		@BP0 WD8
	ldr r2, #6.5		@BP0 WD8
	mul r3, r1, r2		@BP0 WD8
	ldr r4, =0x323D70A	@BP-24 WD24
	mul r0, r3, r4		@BP-24 WD32
	lsr r0, #24		@BP0 WD8 bit point shift
	mov r7, #1
	swi 0
