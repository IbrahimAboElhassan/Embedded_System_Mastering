/*
 ============================================================================
 Name        : EX_5.c
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
	setbuf(stdout,NULL);
	int Arr[SIZE];
	int n, val , i;

	printf("Enter size of array: ");
	scanf("%d", &n);

	printf("Enter the elements of the array: ");
	for(i = 0; i < n; i++)
		scanf("%d", &Arr[i]);

	printf("Enter the value to search: ");
	scanf("%d", &val);

	for(i=1; i<n ; i++)
	{
		if(val == Arr[i])
		{
			printf("This value is at location %d",(i+1));
			break;
		}
	}
	if(val == n)
	{
		printf("NOT exist in this array !!");
	}

	return 0;
}

