#ifndef C_CPP_TWOARRAYMERGEUNIONDIFFINTERSECTIONC_H
#define C_CPP_TWOARRAYMERGEUNIONDIFFINTERSECTIONC_H

#include <stdio.h>
#include <stdlib.h>

struct Array {
    int A[10];
    int size;
    int length;
};

void Display(struct Array *arr) {
    printf("\nElements are\n");
    for (int i = 0; i < arr->length; i++) {
        printf("%d ", arr->A[i]);
    }
    printf("\n");
}

struct Array *Merge(struct Array *arr1, struct Array *arr2) {
    // (arr1->length + arr2->length)
    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));
    int i, j, k;
    i = j = k = 0;

    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }

    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];

    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = arr1->length + arr2->length;
    arr3->size = arr1->size + arr2->size;

    return arr3;

}

struct Array *Union(struct Array *arr1, struct Array *arr2) {
    // (arr1->length + arr2->length)
    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));
    int i, j, k;
    i = j = k = 0;

    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr1->A[i] > arr2->A[j])
            arr3->A[k++] = arr2->A[j++];
        else {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];

    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = k;
    arr3->size = 10;

    return arr3;

}


struct Array *Intersection(struct Array *arr1, struct Array *arr2) {
    // (arr1->length + arr2->length)
    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));
    int i, j, k;
    i = j = k = 0;

    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j])
            i++;
        else if (arr1->A[i] > arr2->A[j])
            j++;
        else if (arr1->A[i] == arr2->A[j]) {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    arr3->length = k;
    arr3->size = 10;

    return arr3;

}

struct Array *Difference(struct Array *arr1, struct Array *arr2) {
    // (arr1->length + arr2->length)
    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));
    int i, j, k;
    i = j = k = 0;

    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr1->A[i] > arr2->A[j])
            j++;
        else if (arr1->A[i] == arr2->A[j]) {
            i++;
            j++;
        }
    }

    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];

    arr3->length = k;
    arr3->size = 10;

    return arr3;

}

int testTwoArrayMergeUnionDiffIntersectionC() {
    struct Array arr1 = {{2, 6, 10, 15, 25}, 10, 5};
    struct Array arr2 = {{3, 6, 7, 15, 20}, 10, 5};

    struct Array *arr3;

    arr3 = Difference(&arr1, &arr2);
    Display(arr3);

    printf("------------------------------\n");
    return 0;
}

#endif //C_CPP_TWOARRAYMERGEUNIONDIFFINTERSECTIONC_H
