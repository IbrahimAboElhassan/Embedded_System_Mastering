/*
 ============================================================================
 Name        : EX_5__ASS_2.c
 Author      : Ibrahim Abo_Elhassan
 Description : Solution of ASS_2 on C_Basics
 ============================================================================
 */

// C code to detemine if character or NOT.

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char x;

	printf("Enter a character: ");
	fflush(stdin) , fflush(stdout);
	scanf("%c",&x);

	if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
	{
		printf("%c is an alphabet.", x);
	}
	else
	{
		printf("%c is not an alphabet.", x);
	}
	return 0;
}
