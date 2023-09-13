/*
 ============================================================================
 Name        : EX_2.c
 Author      : Ibrahim Abo Elhassan.
 Unit_2      : Lesson_4 "Array & String".
 Description : Solution of HM of Array.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	setbuf(stdout,NULL); // to solve buffer in Eclipse.
	float Matrix[100];
	int n ,i;
	float  Average, sum=0;

	printf("Enter number of elements: ");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		printf("Enter number: ");
		scanf("%f",&Matrix[i]);
		sum += Matrix[i];
	}

	Average = sum / n;

	printf("Average = %0.2f",Average);

return 0;
}
