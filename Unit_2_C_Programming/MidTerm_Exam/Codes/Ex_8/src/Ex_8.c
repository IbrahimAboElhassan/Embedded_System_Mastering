/*
 ============================================================================
 Author      : Ibrahim Abo Elhassan

 Description : C Function to take an Array and reverse its element.
 ============================================================================
 */

#include <stdio.h>

void reverse(int aa[], int n);

int main()
{
	setbuf(stdout,NULL);

    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    reverse(arr, size);
    return 0;
}

void reverse(int origin[], int n)
{
    int Reversed[n];
    printf("Reversed one: ");
    for (int i = 0; i < n; i++)
    {
    	Reversed[i] = origin[n - 1 - i];
        printf("%d ", Reversed[i]);
    }
}

