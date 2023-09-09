/*
 ============================================================================
 Name        : EX_3.c
 Author      : Ibrahim Abo Elhassan.
 Unit_2      : Lesson_4 "Array & String".
 Description : Solution of HM of String.
 ============================================================================
 */

#include <stdio.h>
#include <string.h>
#define SIZE 100

int main()
{
	setbuf(stdout,NULL);
    char str[SIZE], temp;
    int i, j = 0;

    printf("Enter the string: ");
    gets(str);

    i = 0;
    j = strlen(str) - 1;

    while (i < j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }

    printf("Reverse string is: %s", str);

    return 0;
}
