#ifndef QueueLL_h
#define QueueLL_h

#include <stdio.h>
#include <stdlib.h>
#include "TreeNode.h"

// A node for creating Queue
struct QNode {
    struct TreeNode *treePtr; // data type of the Node. e.g TreeNode, or int, char etc
    struct QNode *next;
};

struct Queue {
    struct QNode *front;
    struct QNode *rear;
};

void enqueue(struct Queue *q, struct TreeNode *treeNode) {
    struct QNode *t = (struct QNode *) malloc(sizeof(struct QNode));

    // When you can not create anymore nodes means heap is full. This is the base condition.
    if (t == NULL)
        printf("Queue is FULL!\n");
    else {
        t->treePtr = treeNode;
        t->next = NULL;

        if (q->front == NULL)
            q->front = q->rear = t;
        else {
            q->rear->next = t;
            q->rear = t;
        }
    }
}

struct TreeNode *dequeue(struct Queue *q) {
    struct TreeNode *treeNode = NULL;
    struct QNode *t;

    if (q->front == NULL)
        printf("Queue is EMPTY!\n");
    else {
        treeNode = q->front->treePtr;
        t = q->front;
        q->front = q->front->next;
        free(t);
    }
    return treeNode;
}

int isQueueEmpty(struct Queue *q) {
    if (q->front == NULL)
        return 1; // return true - 1 if the Queue is EMPTY!
    return 0; // Otherwise return false - 0 if the Queue has some elements!
}

void DisplayQueue(struct Queue *q) {

    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct QNode *p = q->front;

    while (p != NULL) {
        printf("%d ", p->treePtr->data);
        p = p->next;
    }

    printf("\n");
}

#endif
