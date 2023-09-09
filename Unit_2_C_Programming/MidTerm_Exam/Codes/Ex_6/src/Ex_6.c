/*
 ============================================================================

 Author      : Ibrahim Abo Elhassan

 Description : C program that return the unique number in an array with one loop.

 ============================================================================
 */

#include <stdio.h>

int get_Uni(int arr[], int n) ;

int main()
{
	setbuf(stdout,NULL);

	int size;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    int uniqueNumber = get_Uni(arr, size);
    printf("The unique number in the array is: %d\n", uniqueNumber);

    return 0;
}

int get_Uni(int arr[], int n)
{
    int Uni_number = 0;

    for (int i = 0; i < n; i++)
    {
    	Uni_number ^= arr[i];
    }

    return Uni_number;
}

