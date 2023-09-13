/*
 ============================================================================
 Name        : EX_4.c
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
	int arr[SIZE];
	int n, i, location, val;

	printf("Enter size of array: ");
	scanf("%d", &n);

	printf("Enter the elements of the array: ");
	for(i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	printf("Enter the value to insert: ");
	scanf("%d", &val);

	printf("Enter the location for inserted element: ");
	scanf("%d", &location);

	for(i = n; i >= location; i--)
	{
		arr[i] = arr[i-1];
	}

	arr[location-1] = val;

	printf("The array after insertion: ");
	for(i = 0; i <= n; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}
