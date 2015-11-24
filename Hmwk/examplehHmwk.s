	

.data

.balign 4
range: .asciz "Input begining and end of temperature range."

.balign 4
beg: .asciz "Input beginning of temperature range: "

.balign 4
end: .asciz "Input end of temperature range: "

.balign 4
choice: .asciz  "If range is degree Centigrade, press1.\n If range is degree Fahrenheit, press2.\n"

.balign 4
outmessage: .asciz "Display degree Centirgrade to degree Fahrenheit:\n Fahrenheit		Centigrade\n"

.balign 4
read_beg: .word 0

.balign 4
read_end: .word 0

.balign 4
read_choice: .word 0

.balign 4
scan_format: .asciz "%d"

.balign 4
return: .word 0


.text

.global main
@.func main

main:
	ldr r1, address_of_return
	str lr, [r1]

	ldr r0, address_of_range
	bl printf
	b menu

menu:	
	ldr r0, address_of_beg
	bl printf

	ldr r0, address_of_scan_format
	ldr r1, address_of_read_beg		@beginning of range r1
	bl scanf

	ldr r0, address_of_end
	bl printf
	
	ldr r0, address_of_scan_format
	ldr r2, address_of_read_end		@end of range in r2
	bl scanf

	ldr r0, address_of_choice
	ldr r3, address_of_read_choice		@menu choice made in r3
	bl scanf

	cmp r3, #1				@do-while loop
	beq prob1
	cmp r3, #2
	beq prob2
	b menu

prob1:
	bl funct1				@function call





prob2:
	bl funct2				@function call






	ldr r1, address_of_return
	ldr lr, [r1]
	bx lr
address_of_range: .word range
address_of_beg: .word beg
address_of_end: .word end
address_of_choice: .word choice
address_of_outmessage: .word outmessage
address_of_read_beg: .word read_beg
address_of_read_end: .word read_end
address_of_scan_format: .word scan_format
address_of_return: .word return

.global printf
.global scanf
@.global puts
