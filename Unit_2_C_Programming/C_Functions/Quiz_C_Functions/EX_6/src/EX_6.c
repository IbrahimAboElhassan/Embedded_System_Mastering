/*
 ============================================================================
 Name        : EX_6.c
 Author      : Ibrahim Abo Elhassan
 Unit        : 2 lesson"5" --> Functions.
 Description : Solution part code in C_function quiz.
 ============================================================================
 */

//C progarm to know the value of the 4th least significant bit in num's binary representation.

#include<stdio.h>

int main()
{
	setbuf(stdout,NULL);
    int n, c, k;
    printf("Enter an integer in decimal number system : \n");
    scanf ("%d", &n);
    printf("%d in binary number system is : ", n);
    for (c = 31; c >= 0; c--)
    {
        k = n >> c;
        if (k & 1)
            printf("1");
        else
            printf("0");
    }
    printf("\n");
    k= n>>3;
    if (k&1)
        printf("4th least significant bit is 1\n");
    else
        printf("4th least significant bit is 0\n");

    return 0;
}
