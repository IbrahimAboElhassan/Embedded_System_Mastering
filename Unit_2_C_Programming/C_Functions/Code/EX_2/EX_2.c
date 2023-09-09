/*
 ============================================================================
 Name        : EX_2.c
 Author      : Ibrahim Abo Elhassan.
 Unit_2      : Lesson_5 "Functions".
 Description : Solution of HM of Functions.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int factorial (int x);

int main()
{
	setbuf(stdout,NULL);
	int NUM;
	printf("Enter a positive number: ");
	scanf("%d",&NUM);

	if (NUM < 0)
		{
	        printf("Factorial is not defined for negative numbers.\n");
	    } else
	    {
	        printf("Factorial of %d = %d\n", NUM, factorial(NUM));
	    }

    return 0;
}

int factorial (int x)
{
    if(x==0)
    {
         return (1);
    }
    else
    {
        return x * factorial(x-1);
    }
}
