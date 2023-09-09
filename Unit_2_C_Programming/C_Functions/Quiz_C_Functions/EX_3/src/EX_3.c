/*
 ============================================================================
 Name        : EX_3.c
 Author      : Ibrahim Abo Elhassan
 Unit        : 2 lesson"5" --> Functions.
 Description : Solution part code in C_function quiz.
 ============================================================================
 */

//C function that reverse an input array.

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
void reverse_str(int arr[] , int size);

int main()
{
	setbuf(stdout,NULL);
    int arr[SIZE] ,size , i;

    printf("Enter size of arr: ");
    scanf("%d",&size);

    for(i=0; i<size; i++)
    {
        printf("Enter element %d ",i+1);
        scanf("%d",&arr[i]);
    }
    reverse_str(arr,size);


    return 0;
}

void reverse_str(int arr[] , int size)
{
    int x;

    for(x=size-1 ; x>=0 ; x--)
    {
        printf("%d ",arr[x]);
    }
}
