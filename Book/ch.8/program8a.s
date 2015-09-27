/* Using ORR to goggle a character case */

	.global _start

_start:
_read:				@read syscall
	mov r7, #3		@Syscall number
	mov r0, #0		@Stdout is monitor
	mov r2, #1		@read one character only
	ldr r1, =string		@string at string:
	swi 0

_togglcase:
	ldr r1, =string		@address of char
	ldr r0, [r1]		@load it into r0
	orr r0, r0, #0x20	@toggle case
	str r0, [r1]		@write char back

_write:				@write syscall
	mov r7, #4		@Syscall number
	mov r0, #1		@Stdout is monitor
	mov r2, #1		@string is 1 char long
	ldr r1, =string		@string at start:
	swi 0

_exit:
	@ exit syscall
	mov r7, #1
	swi 0

.data
string: .ascii " "
