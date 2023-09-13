/*
 ============================================================================
 Name        : EX_1.c
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
    char text[SIZE] , ch;
    int i , frequency = 0;

    printf("Enter a string: ");
    gets(text);

    printf("Enter a character to know number of repeats: ");
    scanf("%c",&ch);

    for(i=0; i<sizeof(text); i++)
    {
        if(ch==text[i])
        {
        	frequency++;
        }
    }

    printf("The character (%c) repeated %d times",ch ,frequency);

    return 0;
}
