/*
 ============================================================================
 Name        : EX_6__ASS_1.c
 Author      : Ibrahim Abo_Elhassan
 Description : Solution of ASS_1 on C_Basics
 ============================================================================
 */

// C Code to Swap Two Numbers.

#include <stdio.h>
#include <stdlib.h>

int main()
{
	float a;
	float b;
	float temp;

	printf("Enter value of a: ");
	fflush(stdin) , fflush(stdout);
	scanf("%f",&a);
	printf("Enter value of b: ");
	fflush(stdin) , fflush(stdout);
	scanf("%f",&b);

	temp = a;
	a = b;
	b = temp;

	printf("After swap value of a : %0.2f \n",a);
	printf("After swap value of a : %0.2f \n",b);

	return 0;
}
