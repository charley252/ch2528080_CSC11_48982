/*Han, Charley - Project 1 - CSC11, 48982*/

/*STMIA SP!, {R0-R12, LR} @push registers onto stack*/
/*LDMDB SP!, {R0-R12, PC} @pull registers from stack*/
/*stack  pointers will not be updated without 'write back'*/

/*stack can be implemented with two pointers, one for base point or the 
start of the stack and one for the top of the stack.*/


/*base pointers is/has static address and the stack pointer can be an offset
from it. You can use different addressing mode to implemented different
kinds of stack organization.*/

/*LINUX ARM stack goes downward, or descending. So we need to sub SP, SP, #8
and to 'pop' or return, do add SP, SP, #8. (8 Byte aligned  according to AAPCS
convention).*/



.data


/********************Introduction********************/
.balign 4
welcome: .asciz "Welcome to Hangman!\n"

.balign 4
rules: .asciz "Here are the rules: words are from the assembly class.\n"

.balign 4
ruleone: .asciz "1). There are three levels to choose from.\n"

.balign 4
ruletwo: .asciz	"2). You get 4 letter calls and 2 guesses.\n"

.balign 4
rulethree: .asciz "3). More points for quicker guesses.\n"

.balign 4
rulefour: .asciz "4). 1st call and correct guess = 5 points.\n"

.balign 4
rulefive: .asciz "    2nd call and correct guess = 4 points.\n"

.balign 4
rulesix: .asciz	"    3rd call and correct guess = 3 points.\n"

.balign 4
ruleseven: .asciz "    4th call and correct guess = 1 point.\n"

.balign 4
chooselevel: .asciz "Let's start! Choose your level(1-3): \n"

/********************Get level input********************/
.balign 4
level_f: .asciz "%d"

.balign 4
level_r: .word 0


/********************Keep track of array index for levels********************/
.balign 4
track1: .word 0

.balign 4
track2: .word 0

.balign 4
track3: .word 0

.balign 4
points: .word 0

/********************End of main() loop********************/

.balign 4
points_out: .asciz "Your points so far: %d.\n"

.balign 4
continue: .asciz "Would you like to continue?(y/n): "

.balign 4
play_f: .asciz "%c"

.balign 4
play_r: .word 0

/********************Used in functions********************/

.balign 4
question1: .asciz "Would you like to guess or pick a letter?(g/l): "

.balign 4
guess: .asciz "Take a guess: "

.balign 4
guess_f: .asciz " "

.balign 4
guess_r: .word 0

.balign 4
letter: .asciz "Enter letter: "

.balign 4
letter_f: .asciz "%c"

.balign 4
letter_r: .word 0

.balign 4
ranout: .asciz "You ran out of guesses and calls. The end."

/********************Test arrays and labels********************/

.balign 4
textone: .asciz "array"

texttwo: .asciz "gpio"

.balign 4
array: .skip 20






.text

/********************Functions********************/

levelone:
	
	push {lr}

	ldr r0, address_textone
	@ldr r1, address_track1
	@ldr r2, address_points

	ldr r0, [r0]
	@ldr r1, [r1]
	@ldr r2, [r2]

	push {r0}

	ldr r0, address_question1
	bl printf	
	
	ldr r0, address_letter_f
	ldr r1, address_letter_r
	bl scanf

	ldrb r2, [sp]
	cmp r1, r2
	beq same
	b end
same:
	ldr r0, address_question1
	bl printf

end:
	pop {r0}
	pop {pc}			

	bx lr

address_textone: .word textone
address_track1: .word track1
address_points: .word points
address_question1: .word question1



leveltwo:







levelthree:



.global main
.func main

main:
	push {lr}



	ldr r0, address_welcome
	bl printf

	ldr r0, address_rules
	bl printf

	ldr r0, address_ruleone
	bl printf

	ldr r0, address_ruletwo
	bl printf

	ldr r0, address_rulethree
	bl printf

	ldr r0, address_rulefour
	bl printf

	ldr r0, address_rulefive
	bl printf

	ldr r0, address_rulesix
	bl printf

	ldr r0, address_ruleseven
	bl printf

	@bl time
	@bl srand



	bl levelone




	pop {pc}




exit:

	bx lr






address_welcome: .word welcome
address_rules: .word rules
address_ruleone: .word ruleone
address_ruletwo: .word ruletwo
address_rulethree: .word rulethree
address_rulefour: .word rulefour
address_rulefive: .word rulefive
address_rulesix: .word rulesix
address_ruleseven: .word ruleseven

address_chooselevel: .word chooselevel
address_level_f: .word level_f
address_level_r: .word level_r

@address_track1: .word track1
address_track2: .word track2
address_track3: .word track3
@address_points: .word points

address_points_out: .word points_out
address_continue: .word continue
address_play_f: .word play_f
address_play_r: .word play_r

@address_question1: .word question1
address_guess: .word guess
address_guess_f: .word guess_f
address_guess_r: .word guess_r
address_letter: .word letter
address_letter_f: .word letter_f
address_letter_r: .word letter_r
address_ranout: .word ranout


@address_textone: .word textone
address_texttwo: .word texttwo

address_array: .word array
