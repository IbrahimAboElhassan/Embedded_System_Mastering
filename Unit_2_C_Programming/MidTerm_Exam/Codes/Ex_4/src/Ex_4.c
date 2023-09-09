/*
 ============================================================================

 Author      : Ibrahim Abo Elhassan

 Description : C Program to reverse the digits of a number.

 ============================================================================
 */

#include<stdio.h>
#include<math.h>

void reverse_Num(int x);

int main()
{
	setbuf(stdout,NULL);
    int number;

    printf("Enter a number to reverse it: ");
    scanf("%d",&number);

    reverse_Num(number);

    return 0;
}

void reverse_Num(int x)
{
    int rem ,arr[100];
    for(int i = 0 ; x!=0 ; i++)
    {
        rem = x%10;
        arr[i] = rem;
        printf("%d",arr[i]);
        x/=10;
    }
}



