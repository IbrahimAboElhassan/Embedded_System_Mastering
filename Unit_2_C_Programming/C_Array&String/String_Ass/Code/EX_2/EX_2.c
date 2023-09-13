/*
 ============================================================================
 Name        : EX_2.c
 Author      : Ibrahim Abo Elhassan.
 Unit_2      : Lesson_4 "Array & String".
 Description : Solution of HM of String.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int main()
{
	setbuf(stdout,NULL);
    char STR[SIZE];
    int i , Length = 0;

    printf("Enter a string: ");
    gets(STR);

    for(i=0; STR[i] != '\0';i++)
    {
    	Length++;
    }

    printf("Length os string: %d",Length);

    return 0;
}
