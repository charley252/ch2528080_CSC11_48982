/* convert months to years */

	.global _start

_start:
	mov r1, #88		@BP0 WD7
	ldr r2, =0x155556	@BP-24 WD24
	mul r0, r1, r2		@BP-24 WD31
	lsr r0, #24		@BP0 WD7, bit point shift
	mov r7, #1
	swi 0
