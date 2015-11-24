.data

.balign 4
input_r: .asciz "Enter Fibonacci term: "

.balign 4
input_f: .asciz "%d"

.balign 4
input_t: .word 0

.balign 4
output_f: .asciz "Fibonacci term is: %d\n"





.text

.func fib_func
fib_func:
	push {r4, r5, lr}
	

	mov r1, #1

	
	cmp r0, #2
	ble fib_end
	sub r0, r0, #1
	mov r4, r0

	bl fib_func

	mov r5, r1
	sub r4, r4, #1
	mov r0, r4

	bl fib_func

	add r1, r1, r5

fib_end:
	pop {r4, r5, lr}
	bx lr	



.global main

main:
	push {lr}
	
	ldr r0, address_input_r
	bl printf

	ldr r0, address_input_f
	ldr r1, address_input_t
	bl scanf

	ldr r1, address_input_t
	ldr r1, [r1]
	mov r0, r1
	
	bl fib_func
	
	ldr r0, address_output_f
	bl printf



end:
	pop {pc}
	bx lr



address_input_r: .word input_r
address_input_f: .word input_f
address_input_t: .word input_t
address_output_f: .word output_f
