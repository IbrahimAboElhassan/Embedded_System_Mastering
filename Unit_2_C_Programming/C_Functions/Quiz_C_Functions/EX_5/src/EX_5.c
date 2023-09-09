/*
 ============================================================================
 Name        : EX_5.c
 Author      : Ibrahim Abo Elhassan
 Unit        : 2 lesson"5" --> Functions.
 Description : Solution part code in C_function quiz.
 ============================================================================
 */

// C function that clears a specified bit in a given number.

#include <stdio.h>

int clear_specified_bit(int n, int bit);
int main()
{
	setbuf(stdout,NULL);
    int n, bit;
    printf("Input Number: ");
    scanf("%d", &n);
    printf("Bit Position: ");
    scanf("%d", &bit);
    printf("Result = %d", clear_specified_bit(n, bit));
}

int clear_specified_bit(int n, int bit)
{
    return n & ~(1 << bit);
}
