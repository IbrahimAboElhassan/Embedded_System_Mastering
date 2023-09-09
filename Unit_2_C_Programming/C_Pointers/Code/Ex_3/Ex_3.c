/*
 ============================================================================
 Name        : Ex_3.c
 Author      : Ibrahim Abo Elhassan
 Unit        : 2 lesson "8".
 Description : C program to print a string in reverse using a pointer.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int main()
{
	setbuf(stdout,NULL);
    char* ptr = NULL;
    char test[SIZE];

    printf("Enter a string: ");
    scanf("%s", test);

    for (int i = 0; test[i] != '\0'; i++)
    {
        ptr = &test[i];
    }


    while (ptr >= test)
    {
        printf("%c", *ptr);
        ptr--;
    }

    return 0;
}

