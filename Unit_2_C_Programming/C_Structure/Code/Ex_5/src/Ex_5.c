/*
 ============================================================================
 Name        : Ex_5.c
 Author      : Ibrahim Abo Elhassan
 Unit        : 2, lesson_6
 Description : C program to find area of circle, passing argument to Macros.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define PI 3.14
#define AREA(r) (PI*r*r)

int main()
{
	setbuf(stdout,NULL);
    int radius;
    float area;

    printf("Enter the radius: ");
    scanf("%d",&radius);

    area = AREA(radius);

    printf("Area = %0.2f",area);
    return 0;
}


