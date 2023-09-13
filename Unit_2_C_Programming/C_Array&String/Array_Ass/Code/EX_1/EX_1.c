/*
 ============================================================================
 Name        : EX_1.c
 Author      : Ibrahim Abo Elhassan.
 Unit_2      : Lesson_4 "Array & String".
 Description : Solution of HM of Array.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


int main() {

	setbuf(stdout,NULL); // to solve buffer in Eclipse.
	float a[2][2];
	float b[2][2];
	float SUM[2][2];
	int i, j;

	printf("Enter elements of first matrix: \n");
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			printf("Element a%d%d ",(i+1) ,(j+1));
			scanf("%f", &a[i][j]);
		}
	}

	printf("Enter elements of second matrix: \n");
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			printf("Element b%d%d ",(i+1) ,(j+1));
			scanf("%f", &b[i][j]);
		}
	}

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			SUM[i][j] = a[i][j] + b[i][j];
		}
	}

	printf("Sum of Two matrices: \n");
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			printf("%0.1f\t", SUM[i][j]);
		}
		printf("\n");
	}

	return 0;
}
