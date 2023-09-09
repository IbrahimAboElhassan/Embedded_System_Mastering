/*
 ============================================================================
 Name        : Ex_5.c
 Author      : Ibrahim Abo Elhassan
 Unit        : 2, lesson_6
 Description : C program to Add distance system by structure.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct distance
{
    int feet;
    float inch;
};

struct distance Add(struct distance x , struct distance y);

int main()
{
	setbuf(stdout,NULL);
    struct distance One;
    printf("Enter information for 1st distance\n");
    printf("Enter feet: ");
    scanf("%d",&One.feet);
    printf("Enter inch: ");
    scanf("%f",&One.inch);

    struct distance Two;
    printf("Enter information for 2nd distance\n");
    printf("Enter feet: ");
    scanf("%d",&Two.feet);
    printf("Enter inch: ");
    scanf("%f",&Two.inch);

    struct distance result = Add(One , Two);
    if(result.inch > 12.0)
    {
        result.inch = result.inch - 12.0;
        ++result.feet;
    }
    printf("Sum of distance = %d\' -%0.1f\" ",result.feet , result.inch);

    return 0;
}

struct distance Add(struct distance x , struct distance y)
{
    struct distance z;

    z.feet = x.feet + y.feet;
    z.inch = x.inch + y.inch;

    return z;
}


