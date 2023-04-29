#ifndef C_CPP_CIRCULARLINKEDLIST_H
#define C_CPP_CIRCULARLINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *Head;

void create(int A[], int n) {
    int i;
    struct Node *t, *last;
    Head = (struct Node *) malloc(sizeof(struct Node));
    Head->data = A[0];
    Head->next = Head;
    last = Head;
    for (i = 1; i < n; i++) {
        t = (struct Node *) malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *h) {
    do {
        printf("%d ", h->data);
        h = h->next;
    } while (h != Head);

    printf("\n");
}

// GLOBAL FLAG
static int flag = 0;

void RDisplay(struct Node *h) {
    if (h != Head || flag == 0) {
        flag = 1;
        printf("%d ", h->data);
        RDisplay(h->next);
    }
    flag = 0;
}


int testCircularLinkedList() {
    int A[] = {2, 3, 4, 5, 6};
    create(A, 5);
    RDisplay(Head);
    printf("\n");
    return 0;
}


#endif //C_CPP_CIRCULARLINKEDLIST_H
