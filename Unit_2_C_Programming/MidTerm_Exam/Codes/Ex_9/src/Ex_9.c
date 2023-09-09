/*
 ============================================================================
 Author      : Ibrahim Abo Elhassan

 Description : C function to reverse words in string.

 ============================================================================
 */


#include <stdio.h>
#include <string.h>

void reverse(char *start, char *end) {
    char temp;
    while (start < end) {
        temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
}

void reverse_words(char *str) {
    char *word_begin = str;
    char *temp = str;

    while (*temp) {
        temp++;
        if (*temp == '\0') {
            reverse(word_begin, temp - 1);
        } else if (*temp == ' ') {
            reverse(word_begin, temp - 1);
            word_begin = temp + 1;
        }
    }

    reverse(str, temp - 1);
}

int main()
{
	setbuf(stdout,NULL);
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    reverse_words(str);
    printf("Reversed words: %s\n", str);
    return 0;
}



