/*
 ============================================================================
 Name        : EX_7.c
 Author      : Ibrahim Abo Elhassan
 Unit        : 2 lesson"5" --> Functions.
 Description : Solution part code in C_function quiz.
 ============================================================================
 */

//C function that return 0 if a given number is a power of 3, otherwise return 1 (except 3 to the power 0).

#include <stdio.h>
#include <math.h>

int checkPowerof3(unsigned n);
int main()
{
    unsigned n;
    printf("Enter a number: ");
    fflush(stdout);
    scanf("%u", &n);
    checkPowerof3(n) ? printf("%u ==> 1", n) : printf("%u ==> 0", n);
}

int checkPowerof3(unsigned n)
{
    double i = log(n) / log(3);

    return i == trunc(i);
}
