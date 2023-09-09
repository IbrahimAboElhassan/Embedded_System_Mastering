/*
 ============================================================================
 Name        : EX_1__ASS_2.c
 Author      : Ibrahim Abo_Elhassan
 Description : Solution of ASS_2 on C_Basics
 ============================================================================
 */

// C code to check if number is Even or Odd.

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int number;

	printf("Enter an integer to check: ");
	fflush(stdin), fflush(stdout);
	scanf("%d",&number);

	if(number %2 == 0)
	{
		printf("%d is Even",number);
	}else
	{
		printf("%d is Odd",number);
	}

	return 0;
}
