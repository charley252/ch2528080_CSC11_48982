/* Convert to binary for printing */

	.global _start

_start:
	mov r6, #15		@number to print in r6
	mov r10, #1		@setup mask
	mov r9, r10, lsl #31
	ldr r1, = string	@point r1 to string

_bits:
	tst r6, r9		@tst no, mask
	moveq r0, #48		@ascii '0'
	movne r0, #49		@ascii '1'
	str r0, [r1]		@store '1' in string
	mov r8, r6		@mov preserve, no
	bl _write		@write to screen
	mov r6, r8		@mov no, preserve

	movs r9, r9, lsr #1	@shuffle mask bits
	bne _bits

_exit:
	mov r7, #1
	swi 0

_write:
	mov r0, #1
	mov r2, #1
	mov r7, #4
	swi 0
	bx lr

.data
string: .ascii " "
