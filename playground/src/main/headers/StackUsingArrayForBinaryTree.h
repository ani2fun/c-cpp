#ifndef C_CPP_STACKUSINGARRAYFORBINARYTREE_H
#define C_CPP_STACKUSINGARRAYFORBINARYTREE_H

#include <stdio.h>
#include <stdlib.h>

struct StackArray {
    int size;
    int top; // pointer for the TOP position
    int *S; // A Pointer for the array of TreeNodes
};

struct Node {
    int data;
    struct Node *next;
};

void createStackArr(struct StackArray *st) {
    printf("Enter size of the stack: ");
    scanf("%d", &st->size);
    st->top = -1; // initialise the TOP pointer to -1 which points at nowhere.
    st->S = (int *) malloc(st->size * sizeof(int));
}

// call by value , only reading is happening
void DisplayStackArr(struct StackArray st) {
    int i = st.top;
    while (i >= 0) {
        printf("%d ", st.S[i]);
        i--;
    }
    printf("\n");
}

void pushArr(struct StackArray *st, int x) {
    if (st->top == st->size - 1) {
        printf("stakc overflow!\n");
    } else {
        st->top++;
        st->S[st->top] = x;
    }
}

int popArr(struct StackArray *st) {
    int x = -1;
    if (st->top <= -1) {
        printf("stakc underflow!\n");
    } else {
        x = st->S[st->top];
        // st->S[st->top] = 0; this is not really needed
        st->top--;
    }

    return x;
}

int peekArr(struct StackArray st, int pos) {
    int x = -1;
    // formula is [ top - pos + 1 ]
    if (st.top - pos + 1 < 0) {
        printf("Invalid Index!\n");
    } else
        x = st.S[st.top - pos + 1];
    return x;
}

int isEmptyArr(struct StackArray st) {
    return st.top <= -1;
}

int isFullArr(struct StackArray st) {
    return st.top == st.size - 1;
}

int stackTopArr(struct StackArray st) {
    if (!isEmptyArr(st))
        return st.S[st.top];
    return -1;
}


int testStackArray(void) {
    printf("--- START: Testing stack using array ---\n");
    struct StackArray st; // declare stack variable in stack of main function
    createStackArr(&st); // first create a stack of some size

    pushArr(&st, 10);
    pushArr(&st, 20);
    pushArr(&st, 30);
    pushArr(&st, 40);
    DisplayStackArr(st);

    printf("peek at index 2 is: %d \n", peekArr(st, 2));

    printf("poped: %d\n", popArr(&st));
    printf("peek at index 2 is: %d \n", peekArr(st, 2));

    DisplayStackArr(st);


    printf("\n--- END: Testing stack using array ---\n");
    return 0;
}

#endif //C_CPP_STACKUSINGARRAYFORBINARYTREE_H
