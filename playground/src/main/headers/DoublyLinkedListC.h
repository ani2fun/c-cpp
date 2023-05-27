#ifndef C_CPP_DOUBLYLINKEDLISTC_H
#define C_CPP_DOUBLYLINKEDLISTC_H

#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
} *first = NULL;

void Create(int A[], int size) {

    struct Node *t, *last = NULL;
    int i;

    first = (struct Node *) malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = first->prev = NULL;
    last = first;

    for (i = 1; i < size; i++) {
        t = (struct Node *) malloc(sizeof(struct Node));
        t->data = A[i];
        t->prev = last;
        last->next = t;
        last = t;
    }
}


void Display(struct Node *p) {
    //    while(p!=NULL)
    //    while(p!=0)
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int Length(struct Node *p) {
    int length = 0;
    while (p) {
        length++;
        p = p->next;
    }
    return length;
}

void Insert(struct Node *p, int index, int x) {
    struct Node *t;
    if (index < 0 || index > Length(p))
        return;

    if (index == 0) {
        t = (struct Node *) malloc(sizeof(struct Node));
        t->data = x;
        t->next = first;
        first->prev = NULL;
        first = t;
    } else {
        t = (struct Node *) malloc(sizeof(struct Node));
        t->data = x;

        for (int i = 0; i < index - 1; i++) p = p->next;

        t->next = p->next;
        t->prev = p;
        if (p->next) p->next->prev = t;
        p->next = t;
    }
}

int Delete(struct Node *p, int index) {
    struct Node *last;
    int x = -1;
    last = p;

    if (index < 0 || index > Length(last))
        return x;
    if (index == 0) {
        first = first->next;
        if (first) first->prev = NULL;
        x = first->data;
        free(last);
        return x;
    } else {
        for (int i = 0; i < index - 1; i++) last = last->next;
        last->prev->next = last->next;
        if (last->next) last->next->prev = last->prev;
        x = last->data;
        free(last);
        return x;
    }
}

void Reverse(struct Node *p) {
    struct Node *temp;

    while (p) {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if (p != NULL && p->next == NULL) first = p;
    }
}


int testDoublyLL() {
    // insert code here...
    int A[] = {10, 20, 30, 40, 50};
    Create(A, 5);
    Display(first);
    printf("Insert %d at index: %d \n", 25, 2);
    Insert(first, 2, 25);
    Display(first);
    printf("Length is: %d \n", Length(first));
    printf("Delete at index: %d \n", 2);
    int deleted = Delete(first, 2);
    printf("Deleted integer is: %d \n", deleted);
    Display(first);
    printf("Length becomes: %d \n", Length(first));

    printf("Reverse the DLL \n");
    Reverse(first);
    Display(first);

    return 0;
}

#endif //C_CPP_DOUBLYLINKEDLISTC_H
