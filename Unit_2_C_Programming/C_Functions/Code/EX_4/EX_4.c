/*
 ============================================================================
 Name        : EX_4.c
 Author      : Ibrahim Abo Elhassan.
 Unit_2      : Lesson_5 "Functions".
 Description : Solution of HM of Functions.
 ============================================================================
 */

#include <stdio.h>

int power(int base, int exponent);

int main()
{
	setbuf(stdout,NULL);
    int base, exponent, result;
    printf("Enter base number: ");
    scanf("%d", &base);
    printf("Enter power number (positive number): ");
    scanf("%d", &exponent);
    result = power(base, exponent);
    printf("%d^%d = %d", base, exponent, result);
    return 0;
}

int power(int base, int exponent)
{
    if (exponent == 0)
        return 1;
    else
        return base * power(base, exponent - 1);
}
