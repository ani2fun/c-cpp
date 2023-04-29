#ifndef C_CPP_STACKUSINGLINKEDLISTFORBINARYTREE_H
#define C_CPP_STACKUSINGLINKEDLISTFORBINARYTREE_H

#include <stdio.h>
#include <stdlib.h>
#include "TreeNode.h"

struct Stack {
    struct Node *top;
};

struct Node {
    struct TreeNode *data;
    struct Node *next;
};

void pushToStack(struct Stack *stack, struct TreeNode *data) {
    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
    if (new_node == nullptr)
        printf("Stack Overflow!");
    else {
        new_node->data = data;
        new_node->next = stack->top;
        stack->top = new_node;
    }
}

int isStackEmpty(struct Stack *stack) {
    if(stack -> top == NULL) return 1;
    return 0;
}

void DisplayStack(struct Stack *stack) {
    struct Node *temp = stack->top;
    while (temp) {
        printf("%d ", temp->data->data);
        temp = temp->next;
    }
    printf("\n");
}

struct TreeNode *popFromStack(struct Stack *stack) {
    struct Node *temp;
    struct TreeNode *x = NULL;
    if (stack == NULL) {
        printf("Stack is Empty!\n");
        return x;
    } else {
        temp = stack->top;
        x = temp->data;
        stack->top = stack->top->next;
        free(temp);
    }
    return x;
}

void testCreateStack() {
    printf("--- START: Testing of creating Stack Using Linked List  ---\n");

    struct Stack *stack = (struct Stack *) malloc(sizeof(struct Stack));

    struct TreeNode *node1 = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    node1->data = 10;
    struct TreeNode *node2 = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    node2->data = 20;
    struct TreeNode *node3 = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    node3->data = 30;

    pushToStack(stack, node1);
    pushToStack(stack, node2);
    pushToStack(stack, node3);

    // Display all values in StackArray
    DisplayStack(stack);

    // Pop 1 value from StackArray and print it
    printf("%d\n", popFromStack(stack)->data);

    // Display all values in StackArray again after pop
    DisplayStack(stack);

    printf("\n--- END: Test Creating StackArray ---\n");
}

/*
 * OUTPUT of testCreateStack():

--- START: Test Creating StackArray ---
30 20 10
30
20 10

--- END: Test Creating StackArray ---
* */

#endif //C_CPP_STACKUSINGLINKEDLISTFORBINARYTREE_H
