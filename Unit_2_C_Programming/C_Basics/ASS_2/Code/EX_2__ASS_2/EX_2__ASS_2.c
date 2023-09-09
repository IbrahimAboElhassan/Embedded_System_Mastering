/*
 ============================================================================
 Name        : EX_2__ASS_2.c
 Author      : Ibrahim Abo_Elhassan
 Description : Solution of ASS_2 on C_Basics.
 ============================================================================
 */

// C Code to check vowel or consonant.

#include <stdio.h>
#include <stdlib.h>

int main()
{

	char ch;

	printf("Enter a character: ");
	fflush(stdin) , fflush(stdout);
	scanf("%c",&ch);

	switch(ch){
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
	case 'A':
	case 'E':
	case 'I':
	case 'O':
	case 'U':
		printf("%c is Vowel",ch);
		break;
	default:
		printf("%c is Consonant",ch);
	}

return 0;
}
