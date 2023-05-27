#ifndef C_CPP_ARRAYADT_H
#define C_CPP_ARRAYADT_H

#include <stdio.h>
#include <stdlib.h>

struct Array {
    int A[10];
    int size;
    int length;
};

int Get(struct Array arr, int index) {
    if (index >= 0 && index < arr.length) {
        return arr.A[index];
    }
    return -1;
}

void Set(struct Array *arr, int index, int x) {
    if (index >= 0 && index < arr->length) {
        arr->A[index] = x;
    }
}

int Max(struct Array arr) {
    int max = arr.A[0];
    for (int i = 0; i < arr.length; i++) {
        if (arr.A[i] > max) {
            max = arr.A[i];
        }
    }
    return max;
}

int Min(struct Array arr) {
    int min = arr.A[0];
    for (int i = 0; i < arr.length; i++) {
        if (arr.A[i] < min)
            min = arr.A[i];
    }
    return min;
}

int Sum(struct Array arr) {
    int s = 0;
    int i;
    for (i = 0; i < arr.length; i++)
        s += arr.A[i];
    return s;
}

float Avg(struct Array arr) {
    return (float) Sum(arr) / arr.length;
}

void Display(struct Array arr) {
    for (int i = 0; i < arr.length; i++) {
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

void Reverse(struct Array *arr) {
    int *B;
    int i, j;

    B = (int *) malloc(arr->length * sizeof(int));

    for (i = arr->length - 1, j = 0; i >= 0; i--, j++) {
        B[j] = arr->A[i];
    }

    for (i = 0; i < arr->length; i++) {
        arr->A[i] = B[i];
    }
}

void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void Reverse2(struct Array *arr) {
    int i, j;
    for (i = 0, j = arr->length - 1; i < j; i++, j--) {
        swap(&arr->A[j], &arr->A[i]);
    }
}


void InsertSort(struct Array *arr, int x) {
    if (arr->length == arr->size)
        return;

    int i = arr->length - 1;

    while (i >= 0 && arr->A[i] > x) {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = x;
    arr->length++;
}

int isSorted(struct Array arr) {
    int i;
    for (i = 0; i < arr.length - 1; i++) {
        if (arr.A[i] > arr.A[i + 1])
            return 0;
    }
    return 1;
}

void Rearrange(struct Array *arr) {
    int i = 0;
    int j = arr->length - 1;
    while (i < j) {
        while (arr->A[i] < 0) i++;
        while (arr->A[j] >= 0) j--;
        if (i < j) swap(&arr->A[i], &arr->A[j]);
    }
}

int testArrayADT() {
    printf("------------------------------\n");
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};
    printf("Sum: %d\n", Sum(arr));
    printf("Get at index: %d , the value is: %d \n", 2, Get(arr, 2));
    Set(&arr, 2, 7);
    Display(arr);
    printf("Max : %d\n", Max(arr));
    printf("Min : %d\n", Min(arr));
    printf("Sum : %d\n", Sum(arr));
    printf("Avg : %f\n", Avg(arr));

    printf("------------------------------\n");

    struct Array arr2 = {{8, 3, 9, 15, 6, 10, 7, 2, 12, 4}, 10, 10};
    printf("Before reverse \n");
    Display(arr2);
    printf("After reverse \n");
    Reverse2(&arr2);
    Display(arr2);


    printf("------------------------------\n");
    struct Array arr3 = {{2, 3, 5, 10, 15}, 10, 5};
    printf("Before Insert \n");
    Display(arr3);
    printf("After Insert \n");
    InsertSort(&arr3, 7);
    Display(arr3);
    printf("------------------------------\n");

    struct Array arr4 = {{2, 3, 5, 10, 15}, 10, 5};
    printf("true=1 false=0, arr4 isSorted? result is: %d", isSorted(arr4));

    printf("------------------------------\n");
    struct Array arr5 = {{2, -3, 25, 10, -15, -7}, 10, 6};
    printf("Before Rearrange\n");
    Display(arr5);
    printf("After Rearrange\n");
    Rearrange(&arr5);
    Display(arr5);


    printf("\n------------------------------\n");
    return 0;
}

#endif //C_CPP_ARRAYADT_H
