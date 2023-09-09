/*
 ============================================================================
 Author      : Ibrahim Abo Elhassan

 Description : C Program to count the max number of ones between two zeros.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int MAX_N(char arr[]) ;

int main()
{
	setbuf(stdout,NULL);

    char bin[100];
    printf("Enter binary num: ");
    scanf("%s", bin);

    int res = MAX_N(bin);
    printf("the max number of ones between two zeros = %d", res);

    return 0;
}

int MAX_N(char arr[])
{
    int max_count = 0;
    int current_count = 0;
    int found_zero = 0;

    for (int i = 0; arr[i] != '\0'; i++)
        {
        if (arr[i] == '1')
        {
        	current_count++;
        } else
        {
            if (found_zero)
            {
                if (current_count > max_count)
                {
                	max_count = current_count;
                }
                current_count = 0;
            }
            found_zero = 1;
        }
    }

    return max_count;
}
