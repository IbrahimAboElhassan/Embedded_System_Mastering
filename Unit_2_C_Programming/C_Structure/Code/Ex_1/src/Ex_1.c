/*
 ============================================================================
 Name        : Ex_5.c
 Author      : Ibrahim Abo Elhassan
 Unit        : 2, lesson_6
 Description : C program to store information of students by structure.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct SStudent
{
    char name[30];
    int roll_number;
    float mark;
};

int main()
{
	setbuf(stdout,NULL);
    struct SStudent s;
    printf("Enter student info: \n");
    printf("Enter Name: ");
    scanf("%s",&s.name);
    printf("Enter roll number: ");
    scanf("%d",&s.roll_number);
    printf("Enter Mark: ");
    scanf("%f",&s.mark);

    printf("Displaying inforamtions\n");
    printf("Name:%s\n",s.name);
    printf("Name:%d\n",s.roll_number);
    printf("Name:%0.2f\n",s.mark);

    return 0;
}
