#ifndef C_CPP_STACKLINKEDLISTCPP_H
#define C_CPP_STACKLINKEDLISTCPP_H

#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *next;
};

class Stack {
private:
    Node *top;
public:
    Stack() { top = NULL; }

    void push(int data);

    int pop(void);

    void Display(void);
};

void Stack::push(int data) {
    Node *t = new Node;

    if (t == NULL)
        cout << "Stack Overflow!" << endl;
    else {
        t->data = data;
        t->next = top;
        top = t;
    }
}

int Stack::pop() {
    int x = -1;
    Node *t = NULL;
    if (top == NULL)
        cout << "Stack Empty!" << endl;
    else {
        x = top->data; // take value of of the top to x to return.
        t = top; // store top in temp variable t.
        top = top->next; // move top to next node.
        delete t; // free up delete nodes memory.
    }
    return x;
}

void Stack::Display() {
    cout << "Current Stacks data:";;
    cout << "\n-------------------\n";
    Node *temp = top;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n-------------------\n";
}

int testStackLLCPP() {
    // insert code here...
    std::cout << "---START---\n";

    Stack stk;
    stk.push(10);
    stk.push(20);

    stk.Display();

    cout << "pop: " << stk.pop() << endl;;
    stk.Display();
    std::cout << "\n---END---\n";
    return 0;
}

#endif //C_CPP_STACKLINKEDLISTCPP_H
