#ifndef C_CPP_QUEUELINKEDLISTCPP_H
#define C_CPP_QUEUELINKEDLISTCPP_H

#include <iostream>

using namespace std;

template<typename T>
class Node {
public:
    T *nodeData;
    Node *next;
};

template<typename T>
class QueueLinkedList {
private:
    Node<T> *front;
    Node<T> *rear;
public:
    void enqueue(T *data);

    T *dequeue();

    int isQueueEmpty();

    void DisplayQueue();
};

template<typename T>
void QueueLinkedList<T>::DisplayQueue() {
    if (front == NULL) {
        cout << "Queue is empty.\n";
        return;
    }

    auto *p = front;

    while (p) {
        cout << "(" << *(p->nodeData) << ", " << p->nodeData << ")->";
        p = p->next;
    }

    cout << "|\n";
}

template<typename T>
int QueueLinkedList<T>::isQueueEmpty() {
    if (front == NULL)
        return 1; // return true - 1 if the Queue is EMPTY!
    return 0; // Otherwise return false - 0 if the Queue has some elements!
}

template<typename T>
T *QueueLinkedList<T>::dequeue() {
    auto *newNode = new Node<T>;
    T *data = NULL;

    if (front == NULL)
        cout << "Queue is EMPTY!" << endl;
    else {
        data = (front->nodeData);
        newNode = front;
        front = front->next;
        delete newNode;
    }
    return data;
}


template<typename T>
void QueueLinkedList<T>::enqueue(T *data) {
    auto *newNode = new Node<T>;

    // When you can not create anymore nodes means heap is full. This is the base condition.
    if (newNode == NULL)
        cout << "Queue is FULL!" << endl;
    else {

        newNode->nodeData = data;
        newNode->next = NULL;

        if (front == NULL)
            front = rear = newNode;
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }
}


void testQueueLinkedList() {
    QueueLinkedList<int> q = *new QueueLinkedList<int>;

    auto x = 2;
    q.enqueue(&x);
    int y = 3;
    q.enqueue(&y);
    int z = 4;
    q.enqueue(&z);

    q.DisplayQueue();

    cout << "Deque first element " << endl;
    auto dequeElement = q.dequeue();
    cout << "The address of dequeElement: " << dequeElement << endl;
    cout << "The value of dequeElement: " << *dequeElement << endl;
    cout << "Display queue after dequeue: " << endl;
    q.DisplayQueue();

}


#endif //C_CPP_QUEUELINKEDLISTCPP_H
