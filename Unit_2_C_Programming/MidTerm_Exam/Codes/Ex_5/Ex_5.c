/*
 ============================================================================

 Author      : Ibrahim Abo Elhassan

 Description : C Program to count number of ones in any binary number.

 ============================================================================
 */

#include <stdio.h>

int count_ones(int x);

int main()
{
	setbuf(stdout,NULL);
    int Num;
    printf("Enter a number: ");
    scanf("%d", &Num);

    printf("Number of ones in %d binary = %d\n", Num, count_ones(Num));

    return 0;
}

int count_ones(int x)
{
    int result = 0;
    unsigned int ux = (unsigned int)x; // Convert x to unsigned to avoid sign extension

    while (ux != 0)
    {
        result += ux & 1;
        ux >>= 1;
    }

    return result;
}
