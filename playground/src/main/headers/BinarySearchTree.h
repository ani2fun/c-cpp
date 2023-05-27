#ifndef C_CPP_BINARYSEARCHTREE_H
#define C_CPP_BINARYSEARCHTREE_H

#include <cstdio>
#include <cstdlib>
#include "TreeNode.h"
#include "BinaryTreeC.h"

struct TreeNode *RInsert(struct TreeNode *p, int key) {

    if (p == NULL) {
        struct TreeNode *t = (struct TreeNode *) malloc(sizeof(struct TreeNode));
        t->leftChild = t->rightChild = NULL;
        t->data = key;
        return t;
    } else if (key < p->data) {
        p->leftChild = RInsert(p->leftChild, key);
    } else if (key > p->data) {
        p->rightChild = RInsert(p->rightChild, key);
    }

    return p;
}

void IterativeInsert(struct TreeNode *t, int key) {
    struct TreeNode *r, *p;

    while (t != NULL) {
        r = t;
        if (key < t->data) {
            t = t->leftChild;
        } else if (key > t->data) {
            t = t->rightChild;
        } else
            return;
    }

    p = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    p->leftChild = p->rightChild = NULL;
    p->data = key;

    if (p->data < r->data) r->leftChild = p;
    else r->rightChild = p;

}

struct TreeNode *IterSearch(struct TreeNode *root, int key) {
    struct TreeNode *p = root;
    while (p != NULL) {
        if (key == p->data)
            return p;
        else if (key < p->data) {
            p = p->leftChild;
        } else
            p = p->rightChild;
    }
    return nullptr;
}

struct TreeNode *RSearch(struct TreeNode *root, int key) {
    if (root == NULL)
        return nullptr;

    return (key == root->data) ? root :
           (key < root->data) ? RSearch(root->leftChild, key) :
           RSearch(root->rightChild, key);
}


struct TreeNode *InOrderPredecessor(struct TreeNode *p) {
    while (p && p->rightChild != NULL)
        p = p->rightChild;
    return p;
}

struct TreeNode *InOrderSuccessor(struct TreeNode *p) {
    while (p && p->leftChild != NULL)
        p = p->leftChild;
    return p;
}

void InOrder(struct TreeNode *p) {
    if (p != NULL) {
        InOrder(p->leftChild);
        printf("%d ", p->data);
        InOrder(p->rightChild);
    }
}

void PreOrder(struct TreeNode *p) {
    if (p) {
        printf("%d ", p->data);
        PreOrder(p->leftChild);
        PreOrder(p->rightChild);
    }
}

int Height(struct TreeNode *p) {
    if (p == NULL)
        return 0;
    int leftHeight = Height(p->leftChild);
    int rightHeight = Height(p->rightChild);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

struct TreeNode *Delete(struct TreeNode *root, struct TreeNode *p, int key) {
    // Temporary pointer to hold In-Order Predecessor or Successor
    struct TreeNode *q = NULL;

    if (p == NULL)
        return NULL;

    if (p->leftChild == NULL && p->rightChild == NULL) {
        if (p == root)
            root = NULL;
        free(p);
        return NULL;
    }

    if (key < p->data) {
        p->leftChild = Delete(root, p->leftChild, key);
    } else if (key > p->data) {
        p->rightChild = Delete(root, p->rightChild, key);
    } else {
        if (Height(p->leftChild) > Height(p->rightChild)) {
            q = InOrderPredecessor(p->leftChild);
            p->data = q->data;
            p->leftChild = Delete(root, p->leftChild, q->data);
        } else {
            q = InOrderSuccessor(p->rightChild);
            p->data = q->data;
            p->rightChild = Delete(root, p->rightChild, q->data);
        }
    }
    return p;
}


struct TreeNode *createBSTFromPreOrderSequence(int preorder[], int n) {
    struct Stack *stack = (struct Stack *) malloc(sizeof(struct Stack));
    struct TreeNode *t, *p;
    int i = 0;

    struct TreeNode *root = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    root->data = preorder[i++]; // i[0] will be assigned as root node.
    root->leftChild = root->rightChild = NULL;
    p = root;

    while (i < n) {
        if (preorder[i] < p->data) {
            t = (struct TreeNode *) malloc(sizeof(struct TreeNode));
            t->data = preorder[i++]; // assign and increase i by 1.
            t->leftChild = t->rightChild = NULL;
            p->leftChild = t;
            pushToStack(stack, p);
            p = t;
        } else {
            if (preorder[i] > p->data && (stack->top != NULL || preorder[i] < stack->top->data->data)) {
                t = (struct TreeNode *) malloc(sizeof(struct TreeNode));
                t->data = preorder[i++]; // assign and increase i by 1.
                t->leftChild = t->rightChild = NULL;
                p->rightChild = t;
                p = t;
            } else {
                p = popFromStack(stack);
            }
        }
    }
    return root;
}

int binarySearchTree() {
    // -- Insert element into BST --
    struct TreeNode *root = NULL;
    root = RInsert(root, 10);
    RInsert(root, 5);
    RInsert(root, 20);
    RInsert(root, 8);
    RInsert(root, 30);

    printf("InOrder after inserting into tree with the order --> 10, 5, 20, 8, 30 \n");
    printf("InOrder output should be \n");
    InOrder(root);
    /*op--> InOrder: 5 8 10 20 30 */
    printf("\n");

    // -- Search element from BST --
    int element = 30;
    struct TreeNode *temp = RSearch(root, element);
    if (temp != NULL) {
        printf("\nelement found: %d\n", element);
    } else {
        printf("\nelement NOT found: %d\n", element);
    }

    // -- Delete element from BST --
    Delete(root, root, 5);
    printf("\nInOrder after deleting :\n ");
    InOrder(root);
    /*op--> InOrder: 8 10 20 30 */
    printf("\n");

    // -- Generate BST --
    printf("\n-- Generate BST --\n ");
    int preorder[] = {30, 20, 10, 15, 25, 40, 50, 45};
    int sizeOfPreOrder = sizeof(preorder) / sizeof(int);
    printf("sizeOfPreOrder: %d ", sizeOfPreOrder);
    struct TreeNode *bstFromPreOrder = createBSTFromPreOrderSequence(preorder, 8);
    printf("\nRecursivePreOrder:\n ");
    PreOrder(bstFromPreOrder);

    printf("\n");
    return 0;

}

/**
 *
InOrder after inserting into tree with the order --> 10, 5, 20, 8, 30
InOrder output should be
5 8 10 20 30

element found: 20

InOrder after deleting :
 8 10 20 30

-- Generate BST --
 sizeOfPreOrder: 8
RecursivePreOrder:
 30 20 10 15 25 40 50 45
 *
 * */

#endif //C_CPP_BINARYSEARCHTREE_H
