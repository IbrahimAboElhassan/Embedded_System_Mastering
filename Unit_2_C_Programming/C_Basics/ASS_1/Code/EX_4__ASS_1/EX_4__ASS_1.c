/*
 ============================================================================
 Name        : EX_4__ASS_1.c
 Author      : Ibrahim Abo_Elhassan
 Description : Solution of ASS_1 on C_Basics
 ============================================================================
 */

// C code to Multiply two Floating Point Numbers.

#include <stdio.h>
#include <stdlib.h>

int main()
{
	float N_one;
	float N_two;

	printf("Enter two numbers: ");
	fflush(stdin) , fflush(stdout);
	scanf("%f %f",&N_one ,&N_two);
	printf("Product : %f", (N_one * N_two));

	return 0;
}
