/*
 ============================================================================
 Name        : EX_3__ASS__2.c
 Author      : Ibrahim Abo_Elhassan
 Description : Solution of ASS_2 on C_Basics.
 ============================================================================
 */

// C code to find largest number.

#include <stdio.h>
#include <stdlib.h>

int main()
{
	float x , y , z;

	printf("Enter Three Numbers: ");
	fflush(stdin) , fflush(stdout);
	scanf("%f %f %f",&x ,&y ,&z);

	if(x>y && x>z)
	{
		printf("%f is largest",x);
	}
	else if (y>x && y>z)
	{
		printf("%f is largest",y);
	}
	else
	{
		printf("%f is largest",z);
	}

	return 0;
}
