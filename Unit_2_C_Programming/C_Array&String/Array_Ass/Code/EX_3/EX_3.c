/*
 ============================================================================
 Name        : EX_3.c
 Author      : Ibrahim Abo Elhassan.
 Unit_2      : Lesson_4 "Array & String".
 Description : Solution of HM of Array.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int main()
{
	setbuf(stdout,NULL); // to solve buffer in Eclipse.
	int numbers[SIZE][SIZE] , T_M [SIZE][SIZE];
	int row , col;
	int i , j;

	printf("Enter size (row & col) of array: ");
	scanf("%d %d",&row , &col);

	printf("Elements of matrix \n");
	for(i=0 ; i<row ;i++)
	{
		for(j=0 ; j<col ;j++)
		{
			printf("Enter Element numbers%d%d ",(i+1) ,(j+1));
			scanf("%d",&numbers[i][j]);
		}
	}

	printf("Entered matrix: \n");
	for(i=0 ; i<row ;i++)
	{
		for(j=0 ; j<col ;j++)
		{
			printf(" %d ",numbers[i][j]);
		}
		printf("\n");
	}


	for(i=0 ; i<row ;i++)
	{
		for(j=0 ; j<col ;j++)
		{
			T_M[j][i] = numbers[i][j];
		}
	}

	printf("Transpose matrix: \n");
	for(i=0 ; i<col ;i++)
	{
		for(j=0 ; j<row ;j++)
		{
			printf(" %d ",T_M[i][j]);
		}
		printf("\n");
	}

	return 0;
}
