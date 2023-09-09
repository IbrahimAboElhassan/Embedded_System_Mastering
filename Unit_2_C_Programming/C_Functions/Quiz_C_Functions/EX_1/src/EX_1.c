/*
 ============================================================================
 Name        : EX_1.c
 Author      : Ibrahim Abo Elhassan
 Unit        : 2 lesson"5" --> Functions.
 Description : Solution part code in C_function quiz.
 ============================================================================
 */

//C program takes string from the user and check if it the same USERNAME or not.

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int main()
{
	setbuf(stdout,NULL);
    char name1[SIZE] , name2[SIZE];

    printf("Enter your name: ");
    scanf("%s",name1);
    printf("Enter Username: ");
    scanf("%s",name2);

    if(strcmp(name1,name2)==0)
        printf("Same Name.");
    else
        printf("Not same !!");

    return 0;
}
