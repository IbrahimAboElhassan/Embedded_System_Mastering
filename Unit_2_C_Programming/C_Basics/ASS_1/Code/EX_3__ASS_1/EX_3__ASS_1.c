/*
 ============================================================================
 Name        : EX_3__ASS_1.c
 Author      : Ibrahim Abo_Elhassan
 Description : Solution of ASS_1 on C_Basics
 ============================================================================
 */

// C code to Add Two Integers.

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int NUM1;
	int NUM2;
	int sum;

	printf("Enter two integers: ");
	fflush(stdin) , fflush(stdout);
	scanf("%d %d",&NUM1 ,&NUM2);
	sum = NUM1 + NUM2;
	printf("Sum : %d",sum);

	return 0;
}
