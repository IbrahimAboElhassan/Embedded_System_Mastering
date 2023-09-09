/*
 ============================================================================
 Name        : EX_1.c
 Author      : Ibrahim Abo Elhassan.
 Unit_2      : Lesson_5 "Functions".
 Description : Solution of HM of Functions.
 ============================================================================
 */

#include <stdio.h>

int Prime_check(int n);

int main()
{
	setbuf(stdout,NULL);
    int start, end;
    printf("Enter two numbers (intervals): ");
    scanf("%d %d", &start, &end);

    printf("Prime numbers between %d and %d are: ", start, end);
    for (int i = start; i <= end; i++)
    {
        if (Prime_check(i))
        {
            printf("%d ", i);
        }
    }

    return 0;
}

int Prime_check(int n)
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
