/*
 ============================================================================
 Name        : EX_2.c
 Author      : Ibrahim Abo Elhassan
 Unit        : 2 lesson"5" --> Functions.
 Description : Solution part code in C_function quiz.
 ============================================================================
 */

//C progarm to swap two array with different length.

#include <stdio.h>

void swapArrays(int *arr1, int *arr2, int len1, int len2) {
    int i;
    for (i = 0; i < len1 && i < len2; i++) {
        int temp = arr1[i];
        arr1[i] = arr2[i];
        arr2[i] = temp;
    }
}

int main() {
    int arr1[] = {1, 2, 3, 4};
    int arr2[] = {5, 6, 7};
    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    int len2 = sizeof(arr2) / sizeof(arr2[0]);
    int i;

    printf("Before swapping:\n");
    printf("arr1: ");
    for (i = 0; i < len1; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\narr2: ");
    for (i = 0; i < len2; i++) {
        printf("%d ", arr2[i]);
    }

    swapArrays(arr1, arr2, len1, len2);

    printf("\n\nAfter swapping:\n");
    printf("arr1: ");
    for (i = 0; i < len1; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\narr2: ");
    for (i = 0; i < len2; i++) {
        printf("%d ", arr2[i]);
    }

    return 0;
}
