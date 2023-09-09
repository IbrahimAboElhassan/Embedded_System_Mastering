/*
 ============================================================================
 Name        : EX_2__Assignment_1.c
 Author      : Ibrahim Abo_Elhassan
 Description : Solution of ASS_1 on C_Basics
 ============================================================================
 */

// C code to Print a Integer Entered by a User.

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int number;

	printf("Enter an integer: ");
	fflush(stdin) , fflush(stdout);
	scanf("%d",&number);
	printf("You entered: %d",number);

	return 0;
}

