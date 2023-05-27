#ifndef C_CPP_QUEUECPP_H
#define C_CPP_QUEUECPP_H

#include "stdio.h"
#include "stdlib.h"

class Node {
public:
    Node *lchild;
    int data;
    Node *rchild;
};

class Queue {
private:
    int front;
    int rear;
    int size;
    Node **Q;
public:
    Queue() {
        front = rear = -1;
        size = 10;
        Q = new Node *[size];
    }

    Queue(int size) {
        front = rear = -1;
        this->size = size;;
        Q = new Node *[size];
    }

    void enqueue(Node *x);

    Node *dequeue();

    int isEmpty() { return front == rear; }
};

void Queue::enqueue(Node *x) {
    if (rear == size - 1)
        printf("Queue Full\n");
    else {
        rear++;
        Q[rear] = x;
    }
}

Node *Queue::dequeue() {
    Node *x = NULL;
    if (front == rear)
        printf("Queue is Empty\n");
    else {
        x = Q[front + 1];
        front++;
    }
    return x;
}

#endif //C_CPP_QUEUECPP_H
