/*
 ============================================================================
 Name        : EX_8__ASS_2.c
 Author      : Ibrahim Abo_Elhassan
 Description : Solution of ASS_2 on C_Basics.
 ============================================================================
 */

// C code for simple calculator.

#include <stdio.h>
#include <stdlib.h>

int main()
{
	float N_1 , N_2;
	char c;

	printf("Enter Two Numbers: ");
	fflush(stdin) , fflush(stdout);
	scanf("%f %f",&N_1 , &N_2);

	printf("Enter sign of operation \"(+) => add , (-) => subtract, (*) => multiply, (/) => division\" : ");
	fflush(stdin) , fflush(stdout);
	scanf(" %c",&c);

	switch(c){
	case '+':
		printf("Add      = %f", (N_1 + N_2));
		break;
	case '-':
		printf("Subtract = %f", (N_1 - N_2));
		break;
	case '*':
		printf("Multiply = %f", (N_1 * N_2));
		break;
	case '/':
		printf("Division = %f", (N_1 / N_2));
		break;
	default:
		printf("Wrong sign operation !!");
	}

	return 0;
}
