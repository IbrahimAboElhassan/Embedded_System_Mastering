/*
 ============================================================================
 Name        : EX_3.c
 Author      : Ibrahim Abo Elhassan.
 Unit_2      : Lesson_5 "Functions".
 Description : Solution of HM of Functions.
 ============================================================================
 */

#include <stdio.h>
#include <string.h>

void reverse_str();

int main()
{
	setbuf(stdout,NULL);
    printf("Enter a string: ");
    reverse_str();
    return 0;
}

void reverse_str() {
    char ch;
    scanf("%c", &ch);

    if (ch != '\n')
    {
    	reverse_str();
        printf("%c", ch);
    }
}
