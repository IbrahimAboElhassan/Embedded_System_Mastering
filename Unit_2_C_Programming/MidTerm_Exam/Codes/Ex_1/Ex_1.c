/*
 ============================================================================

 Author      : Ibrahim Abo Elhassan

 Description : C program that take a number and sum all its individual digits.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int sum_digits(int a);

int main()
{
    setbuf(stdout,NULL);
    int x, result;
    printf("Enter a number: ");
    scanf("%d",&x);
    result = sum_digits(x);
    printf("sum of this number's digits = %d",result);

    return 0;
}
int sum_digits(int a)
{
    int sum = 0;
    while(a !=0)
    {
       sum+=(a%10);
        a/=10;
    }
    return sum;
}

