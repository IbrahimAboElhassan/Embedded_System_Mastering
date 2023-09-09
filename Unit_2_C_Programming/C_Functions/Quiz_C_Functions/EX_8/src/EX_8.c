/*
 ============================================================================
 Name        : EX_8.c
 Author      : Ibrahim Abo Elhassan
 Unit        : 2 lesson"5" --> Functions.
 Description : Solution part code in C_function quiz.
 ============================================================================
 */

//C function to return the index of LAST occurrence of a number in a given array.

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
int Last_occu(int s[ ] , int size);

int main()
{
	setbuf(stdout,NULL);
    int size , arr[SIZE] , i;
    printf("Enter size of array: ");
    scanf("%d",&size);

    for(i=0; i<size ; i++)
    {
        printf("Enter Number %d ",i+1);
        scanf("%d",&arr[i]);
    }

    printf("res = %d" ,Last_occu(arr , size));


    return 0;
}

int Last_occu(int s[] , int size)
{
    int num , i;

    printf("Enter the number you want to check: ");
    scanf("%d",&num);

    for(i=size; i>0 ; i--)
    {
        if(num == s[i])
            return i+1;
    }

    return -1;
}
