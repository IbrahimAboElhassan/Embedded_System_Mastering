/*
 ============================================================================
 Name        : EX_4.c
 Author      : Ibrahim Abo Elhassan
 Unit        : 2 lesson"5" --> Functions.
 Description : Solution part code in C_function quiz.
 ============================================================================
 */

// C function to convert a decimal number stored as an ASCII array to an unsigned integer.

#include <stdio.h>

unsigned int ascii_to_uint(char *str) {
    unsigned int result = 0;
    while (*str) {
        result = result * 10 + (*str - '0');
        str++;
    }
    return result;
}

int main()
{
	setbuf(stdout,NULL);
    char str[100];

    printf("Enter a string representing an unsigned integer: ");
    scanf("%s", str); // Read the input string from the user

    unsigned int num = ascii_to_uint(str);
    printf("Converted unsigned integer: %u\n", num);

    return 0;
}
