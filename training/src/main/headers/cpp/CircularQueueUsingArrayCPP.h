#ifndef C_CPP_CIRCULARQUEUEUSINGARRAYCPP_H
#define C_CPP_CIRCULARQUEUEUSINGARRAYCPP_H

#include <iostream>

using namespace std;


class CircularQueue {
private:
    int size;
    int front;
    int rear;
    int *Q;
public:
    CircularQueue(int size);

    ~CircularQueue();

    bool isFull();

    bool isEmpty();

    void enqueue(int x);

    int dequeue();

    void display();
};

CircularQueue::CircularQueue(int size) {
    this->size = size;
    front = 0;
    rear = 0;
    Q = new int[size];
}

CircularQueue::~CircularQueue() {
    delete[] Q;
}

bool CircularQueue::isEmpty() {
    if (front == rear) {
        return true;
    }
    return false;
}

bool CircularQueue::isFull() {
    if ((rear + 1) % size == front) {
        return true;
    }
    return false;
}

void CircularQueue::enqueue(int x) {
    if (isFull()) {
        cout << "Queue Overflow" << endl;
    } else {
        rear = (rear + 1) % size;
        Q[rear] = x;
    }
}

int CircularQueue::dequeue() {
    int x = -1;
    if (isEmpty()) {
        cout << "Queue Underflow" << endl;
    } else {
        front = (front + 1) % size;
        x = Q[front];
    }
    return x;
}

void CircularQueue::display() {
    int i = front + 1;
    do {
        cout << Q[i] << flush;
        if (i < rear) {
            cout << " <- " << flush;
        }
        i = (i + 1) % size;
    } while (i != (rear + 1) % size);
}

/*
int main(void) {

    CircularQueue cq(4);
    cq.enqueue(2);
    cq.enqueue(5);

    return 0;
}
*/


int testCircularQueueCpp(void) {

    int A[] = {15, 3, 5, 7, 9};

    CircularQueue cq(sizeof(A) / sizeof(A[0]) + 1);

    // Enqueue
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++) {
        cq.enqueue(A[i]);
    }

    // Display
    cq.display();
    cout << endl;

    // Overflow
    cq.enqueue(10);

    // Display

    cout << endl;
    // Dequeue
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++) {
        cq.dequeue();
        cq.display();
        cout << endl;
    }

    // Underflow
    cq.dequeue();

    return 0;
}

#endif //C_CPP_CIRCULARQUEUEUSINGARRAYCPP_H
