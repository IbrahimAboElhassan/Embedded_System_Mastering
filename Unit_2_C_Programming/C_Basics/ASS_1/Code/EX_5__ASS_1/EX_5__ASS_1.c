/*
 ============================================================================
 Name        : EX_5__ASS_1.c
 Author      : Ibrahim Abo_Elhassan
 Description : Solution of ASS_1 on C_Basics
 ============================================================================
 */

// C code to Find ASCII Value of a Character.

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char alpha;

	printf("Enter a character: ");
	fflush(stdin) , fflush(stdout);
	scanf("%c",&alpha);
	printf("ASCII value of %c = %d",alpha ,alpha);

	return 0;
}
