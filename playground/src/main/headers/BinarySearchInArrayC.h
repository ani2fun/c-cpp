#ifndef C_CPP_BINARYSEARCHINARRAYC_H
#define C_CPP_BINARYSEARCHINARRAYC_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Array {
    int A[14];
    int size;
    int length;
};

void Display(struct Array arr) {
    int i;
    printf("\nElements are\n");
    for (i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
}

// Recursive (note: tail recursive function will be converted to iterative version by the compiler internally)
int RBinSearch(int a[], int low, int high, int key) {
    int mid = 0;
    if (low <= high) {
        mid = (int) floor((low + high) / 2);
        if (key == a[mid]) {
            return mid;
        } else if (key < a[mid]) {
            return RBinSearch(a, low, mid - 1, key);
        } else {
            return RBinSearch(a, mid + 1, high, key);
        }
    }
    return -1;
}

// Iterative
int IBinSearch(struct Array arr, int key) {
    int l, mid, h;
    l = 0;
    h = arr.length - 1;
    while (l <= h) {
        mid = (l + h) / 2;
        if (key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int testBinarySearchArray() {
    printf("-- START -- \n");

    struct Array arr = {{2, 4, 6, 7, 8, 9, 10, 16, 20, 34, 56, 61, 89, 95}, 14, 14}; // array of 14 elements.

    int key = 61;
    printf("The integer %d is found at index: %d \n", key, IBinSearch(arr, key));
    printf("The integer %d is found at index: %d \n", key, RBinSearch(arr.A, 0, arr.length - 1, key));

    int key2 = 100; // not present in the current array should return -1
    printf("The integer %d is found at index: %d \n", key2, IBinSearch(arr, key2));
    printf("The integer %d is found at index: %d \n", key2, RBinSearch(arr.A, 0, arr.length - 1, key2));
    printf("-- END -- \n");
    return 0;
}

/*
 -- START --
 The integer 61 is found at index: 11
 The integer 61 is found at index: 11
 The integer 100 is found at index: -1
 The integer 100 is found at index: -1
 -- END --
*/


#endif //C_CPP_BINARYSEARCHINARRAYC_H
