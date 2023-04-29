#ifndef C_CPP_AVLTREECPP_H
#define C_CPP_AVLTREECPP_H

#include <iostream>

using namespace std;

class Node {
public:
    Node *lchild;
    int data;
    int height;
    Node *rchild;
};

class AVL {
public:
    Node *root;

    AVL() { root = nullptr; }

    // Helper methods for inserting
    int NodeHeight(Node *p);

    int BalanceFactor(Node *p);

    Node *LLRotation(Node *p);

    Node *RRRotation(Node *p);

    Node *LRRotation(Node *p);

    Node *RLRotation(Node *p);

    // Insert
    Node *rInsert(Node *p, int key);

    // Traversal
    void Inorder(Node *p);

    void Inorder() { Inorder(root); }

    Node *getRoot() { return root; }
};

int AVL::NodeHeight(Node *p) {
    int hl;
    int hr;

    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;

    return hl > hr ? hl + 1 : hr + 1;
}

int AVL::BalanceFactor(Node *p) {
    int hl;
    int hr;

    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;

    return hl - hr;
}

Node *AVL::LLRotation(Node *p) {
    Node *pl = p->lchild;

    // Assignment Logic using just 1 pointer
    p->lchild = pl->rchild;
    pl->rchild = p;

    // Update heights
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    // Update root
    if (root == p) root = pl;

    return pl;
}

Node *AVL::RRRotation(Node *p) {
    Node *pr = p->rchild;

    // Assignement logic
    p->rchild = pr->lchild;
    p->lchild = p;

    // Update height
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    // Update root
    if (root == p) root = pr;

    return pr;
}

Node *AVL::LRRotation(Node *p) {
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    // Update height
    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);

    // Update root
    if (p == root) {
        root = plr;
    }
    return plr;
}

Node *AVL::RLRotation(Node *p) {
    Node *pr = p->rchild;
    Node *prl = pr->lchild;

    // Assignment logic
    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;

    prl->rchild = pr;
    prl->lchild = p;

    // Update height
    pr->height = NodeHeight(pr);
    p->height = NodeHeight(p);
    prl->height = NodeHeight(prl);

    // Update root
    if (root == p) {
        root = prl;
    }
    return prl;
}

Node *AVL::rInsert(Node *p, int key) {
    Node *t;
    if (p == nullptr) {
        t = new Node;
        t->data = key;
        t->lchild = nullptr;
        t->rchild = nullptr;
        t->height = 1;  // Starting height from 1 onwards instead of 0
        return t;
    }

    if (key < p->data) {
        p->lchild = rInsert(p->lchild, key);
    } else if (key > p->data) {
        p->rchild = rInsert(p->rchild, key);
    }

    // Update height
    p->height = NodeHeight(p);

    // Balance Factor and Rotation
    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1) {
        return LLRotation(p);
    } else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1) {
        return LRRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1) {
        return RRRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1) {
        return RLRotation(p);
    }

    return p;
}

void AVL::Inorder(Node *p) {
    if (p) {
        Inorder(p->lchild);
        cout << p->data << ", " << flush;
        Inorder(p->rchild);
    }
}

void avlTreesCPP() {
    // 10, 20, 30, 25, 28, 27, 5
    AVL tlr;
    tlr.root = tlr.rInsert(tlr.root, 10);
    tlr.root = tlr.rInsert(tlr.root, 20);
    tlr.root = tlr.rInsert(tlr.root, 30);
    tlr.root = tlr.rInsert(tlr.root, 25);
    tlr.root = tlr.rInsert(tlr.root, 28);
    tlr.root = tlr.rInsert(tlr.root, 27);
    tlr.root = tlr.rInsert(tlr.root, 5);

    tlr.Inorder();
    cout << endl;
    cout << "Root is: " << tlr.root->data << endl;
}

#endif //C_CPP_AVLTREECPP_H
