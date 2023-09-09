/*
 ============================================================================
 Name        : Ex_5.c
 Author      : Ibrahim Abo Elhassan
 Unit        : 2, lesson_6
 Description : C program to store information of students using structure.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct SStudent
{
    char name[30];
    int roll_number;
    float mark;
}data[10];

int main()
{
	setbuf(stdout,NULL);
	printf("Enter info of students\n");
    for(int i=0 ; i<10 ; i++)
    {
        printf("For roll number %d:\n",i+1);
        printf("Enter Name: ");
        scanf("%s",&data[i].name);
        printf("Enter Mark: ");
        scanf("%f",&data[i].mark);
        printf("\n");
    }

    printf("Displaying inforamtions\n");
    for(int i=0 ; i<10 ; i++)
    {
        printf("Information for roll number %d:\n",i+1);
        printf("Name:%s\n",data[i].name);
        printf("Name:%0.2f\n",data[i].mark);
        printf("\n");
    }

    return 0;
}

