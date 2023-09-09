/*
 ============================================================================
 Name        : EX_4__ASS_2.c
 Author      : Ibrahim Abo_Elhassan
 Description : Solution of ASS_2 on C_Basics
 ============================================================================
 */

//C code to check number is positive or not.

#include <stdio.h>
#include <stdlib.h>

int main()
{
	float x;

	printf("Enter a number for checking: ");
	fflush(stdin) , fflush(stdout);
	scanf("%f",&x);

	if(x>0)
	{
		printf("This number (%f) is Positive.",x);
	}
	else if (x<0)
	{
		printf("This number (%f) is Negative.",x);
	}
	else
	{
		printf("You entered zero !");
	}

	return 0;
}
