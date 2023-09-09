/*
 ============================================================================
 Name        : Ex_5.c
 Author      : Ibrahim Abo Elhassan
 Unit        : 2, lesson_6
 Description : C program to Add complex numbers by passing structure to function.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct SNumbers
{
    float real;
    float imaginary;
}N_1, N_2, sum;

struct SNumbers Add_Com(struct SNumbers x , struct SNumbers y);

int main()
{
	setbuf(stdout,NULL);
    printf("for 1st complex number\n");
    printf("Enter real and imaginary: ");
    scanf("%f %f",&N_1.real ,&N_1.imaginary);

    printf("for 2nd complex number\n");
    printf("Enter real and imaginary: ");
    scanf("%f %f",&N_2.real ,&N_2.imaginary);

    sum = Add_Com(N_1 , N_2);

    printf("Sum = %0.1f+%0.1fi",sum.real , sum.imaginary);

    return 0;
}

struct SNumbers Add_Com(struct SNumbers x , struct SNumbers y)
{
    struct SNumbers z;

    z.real = x.real + y.real;
    z.imaginary = x.imaginary + y.imaginary;

    return z;
}

