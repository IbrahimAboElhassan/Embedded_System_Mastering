/*
 ============================================================================
 Author      : Ibrahim Abo Elhassan

 Description : C Program to find all prime numbers between two numbers.

 ============================================================================
 */

#include <stdio.h>

int get_prime(int n);

int main()
{
	setbuf(stdout,NULL);
    int start, end;
    printf("Enter 1st number: ");
    scanf("%d", &start);

    printf("Enter 2nd number: ");
    scanf("%d", &end);


    printf("Prime numbers between %d and %d are: ", start, end);
    for (int i = start; i <= end; i++)
    {
        if (get_prime(i))
        {
            printf("%d ", i);
        }
    }

    return 0;
}

int get_prime(int n)
{
    if (n <= 1)
    {
        return 0;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
