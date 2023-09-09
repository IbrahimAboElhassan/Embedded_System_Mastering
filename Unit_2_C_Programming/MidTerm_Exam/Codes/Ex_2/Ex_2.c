/*
 ============================================================================

 Author      : Ibrahim Abo Elhassan

 Description : C Program takes an integer number and calculate it's square root.

 ============================================================================
 */

#include<stdio.h>
#include<math.h>

double Sqar_Num(double x);

int main()
{
	setbuf(stdout,NULL);
    int number;

    printf("Enter a number: ");
    scanf("%d",&number);

    if(number <0)
    {
    	printf("Sorry, No square root for negative number !!");
    }
    else
    {
    	printf("square root of %d is %0.3lf" ,number, Sqar_Num(number));
    }


}

double Sqar_Num(double x)
{
    return sqrt(x);
}
