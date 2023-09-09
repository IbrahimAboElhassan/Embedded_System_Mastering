/*
 ============================================================================
 Name        : EX_6__ASS_2.c
 Author      : Ibrahim Abo_Elhassan
 Description : Solution of ASS_2 on C_Basics.
 ============================================================================
 */

// C code to sum number of natural numbers.

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N , i , sum =0;

	printf("Enter an integer: ");
	fflush(stdin) , fflush(stdout);
	scanf("%d",&N);

	if(N>0)
	{
		for(i=0 ; i<=N ; i++)
		{
			sum +=i;
		}
		printf("Summtion = %d",sum);
	}
	else
	{
		printf("Integer number please, Try Again !!");
	}
	return 0;
}

