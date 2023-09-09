/*
 ============================================================================
 Name        : Ex_5.c
 Author      : Ibrahim Abo Elhassan
 Unit        : 2 lesson "8".
 Description : C program to show a pointer to an array which contents are pointer to structure.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct emplyees {
	char name[50];
	int ID;
}emp1 , emp2 , emp3;

int main()
{
	setbuf(stdout,NULL);
	struct emplyees *data[3];
	data[0] = &emp1;
	data[1] = &emp2;
	data[2] = &emp3;

	strcpy(data[0]->name , "Alex");
	data[0]->ID = 1002;

	strcpy(data[1]->name , "Hima");
	data[1]->ID = 2001;

	strcpy(data[2]->name , "mohamed");
	data[2]->ID = 2023;

	for(int i=0 ; i<3 ; i++)
	{
		printf("Emplyee %d\n", i+1);
		printf("Employee Name : %s\n",data[i]->name);
		printf("Employee ID   : %d\n",data[i]->ID);
		printf("=======================\n");
	}

	return 0;
}

