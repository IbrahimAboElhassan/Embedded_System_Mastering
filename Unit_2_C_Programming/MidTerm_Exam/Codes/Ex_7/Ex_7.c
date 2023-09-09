/*
 ============================================================================
 Author      : Ibrahim Abo Elhassan

 Description : C function to sum numbers from 1 To 100 (Without Loop)
 ============================================================================
 */

#include <stdio.h>

int sum(int n);

int main()
{
	setbuf(stdout,NULL);

    int n = 100;
    int summution = sum(n);

    printf("The sum of numbers from 1 to %d is: %d\n", n, summution);

    return 0;
}

int sum(int n)
{

    if (n == 1)
    {
        return 1;
    } else
    {

        return n + sum(n - 1);
    }
}
