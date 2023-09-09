/*
 ============================================================================
 Name        : EX_7__ASS_2.c
 Author      : Ibrahim Abo_Elhassan
 Description : Solution of ASS_2 on C_Basics.
 ============================================================================
 */

// C code to find factorial of integer number.

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x , i , res =1;

	printf("Enter a positive number: ");
	fflush(stdin) , fflush(stdout);
	scanf("%d",&x);

	if(x>0)
	{
		for(i =1 ; i<=x ; i++)
		{
			res = res * i;
		}
		printf("Factorial = %d",res);
	}
	else
	{
		printf("Error !!, Factorial for Negative number is not exist.");
	}

	return 0;
}
