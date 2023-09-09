/*
 ============================================================================
 Name        : Ex_1.c
 Author      : Ibrahim Abo Elhassan
 Unit        : 2 lesson "8".
 Description : C program that define how pointer handle with normal variable.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	setbuf(stdout,NULL);
    int* ptr = NULL;
    int N_Var =29;

    printf("Address of N_Var is 0x%x\n",&N_Var);
    printf("Value of N_Var is %d\n",N_Var);

    ptr = &N_Var;
    printf("=================================\n");
    printf("Now ptr is assigned with the address of N_Var.\n");
    printf("Address of pointer is  0x%x\n",ptr);
    printf("Content of pointer is %d\n",*ptr);

    N_Var = 34;
    printf("=================================\n");
    printf("The value of N_Var assigned to 34 now.\n");
    printf("Address of pointer is 0x%x\n",ptr);
    printf("Content of pointer is %d\n",*ptr);

    *ptr = 7;
    printf("=================================\n");
    printf("The pointer variable ptr is assigned with the value 7 now.\n");
    printf("Address of N_Var is 0x%x\n",&N_Var);
    printf("Value of N_Var is %d\n",N_Var);

    return 0;
}

