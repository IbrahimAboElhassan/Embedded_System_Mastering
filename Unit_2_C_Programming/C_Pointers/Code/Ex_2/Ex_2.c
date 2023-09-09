/*
 ============================================================================
 Name        : Ex_2.c
 Author      : Ibrahim Abo Elhassan
 Unit        : 2 lesson "8".
 Description : C program to print all the alphabets using a pointer.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	setbuf(stdout,NULL);
	char alph[27];
	char* ptr = NULL;
	char ch;

	ptr = alph;

    for (ch = 'A'; ch <= 'Z'; ch++) {
        *ptr = ch;
        ptr++;
    }
	ptr = alph;

	printf("ALL alphabets \n");

	for(ch=0 ; ch<26 ;ch++)
	{
		printf("%c ",*ptr);
		ptr++;
	}
	printf("\n");

	return 0;
}
