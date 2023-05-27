#ifndef C_CPP_BINARYTREECPP_H
#define C_CPP_BINARYTREECPP_H

#include <cstdio>
#include <cstdlib>
#include "iostream"
#include "QueueCPP.h"

using namespace std;

class BinaryTreeCPP {
    Node *root;
public:
    BinaryTreeCPP() { root = NULL; }

    void CreateTree();

    void Preorder() { Preorder(root); }

    void Preorder(Node *p);

    void Postorder() { Postorder(root); }

    void Postorder(Node *p);

    void Inorder() { Inorder(root); }

    void Inorder(Node *p);

    void Levelorder() { Levelorder(root); }

    void Levelorder(Node *p);

    int Height() { return Height(root); }

    int Height(Node *root);
};

void BinaryTreeCPP::CreateTree() {
    Node *p, *t = NULL;
    int x;
    Queue q(100);
    printf("Enter root value: ");
    scanf("%d", &x);
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;

    q.enqueue(root);

    while (!q.isEmpty()) {

        p = q.dequeue();
        printf("Current Node: %d \n", p->data);

        printf("Enter left child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1) {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }
        printf("Enter right child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1) {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

void BinaryTreeCPP::Preorder(struct Node *p) {
    if (p) {
        printf("%d ", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void BinaryTreeCPP::Inorder(struct Node *p) {
    if (p) {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}

void BinaryTreeCPP::Postorder(struct Node *p) {
    if (p) {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ", p->data);
    }
}

void BinaryTreeCPP::Levelorder(struct Node *p) {
    Queue q(100);
    printf("%d ", root->data);
    q.enqueue(root);
    while (!q.isEmpty()) {
        root = q.dequeue();
        if (root->lchild) {
            printf("%d ", root->lchild->data);
            q.enqueue(root->lchild);
        }
        if (root->rchild) {
        }
        printf("%d ", root->rchild->data);
        q.enqueue(root->rchild);
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}

int BinaryTreeCPP::Height(struct Node *root) {
    int x = 0, y = 0;
    if (root == 0)
        return 0;
    x = Height(root->lchild);
    y = Height(root->rchild);
    if (x > y)
        return x + 1;
    else
        return y + 1;
}


int testBinaryTreeCPP() {
    BinaryTreeCPP treeCpp;
    cout << "Create Tree\n";
    treeCpp.CreateTree();
    cout << "Preorder\n";
    treeCpp.Preorder();
    cout << "\nInorder\n";
    treeCpp.Inorder();

    cout << endl;
    return 0;
}

#endif //C_CPP_BINARYTREECPP_H
