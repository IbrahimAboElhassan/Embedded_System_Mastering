/*
 ============================================================================
 Name        : Ex_4.c
 Author      : Ibrahim Abo Elhassan
 Unit        : 2 lesson "8".
 Description : C program to print the elements of an array in reverse order.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	setbuf(stdout,NULL);
    int* ptr = NULL;
    int test[100];
    int NUM, counter;

    printf("Enter size of array: ");
    scanf("%d", &NUM);

    printf("Enter elements of array:\n");
    for (counter = 0; counter < NUM; counter++)
    {
        printf("Element - %d: ", counter + 1);
        scanf("%d", &test[counter]);
    }
    printf("===========================\n");
    printf("Reversed Array:\n");

    for (counter = NUM - 1; counter >= 0; counter--)
    {
        ptr = test + counter;
        printf("Element - %d: %d\n", counter + 1, *ptr);
    }

    return 0;
}



