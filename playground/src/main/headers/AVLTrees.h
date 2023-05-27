#ifndef C_CPP_AVLTREES_H
#define C_CPP_AVLTREES_H

#include <cstdio>
#include <cstdlib>

// Height Balanced Binary Search Trees.
// balance factor = height of left-subtree - height of right-subtree
// bf = hl - hr = {-1,0,1}
// if, bf = |hl - hr| <= 1 -->  Balanced
// if, bf = |hl - hr| > 1 -->  Imbalanced


struct Node {
    Node *lchild;
    int data;
    int height;
    Node *rchild;
} *root = NULL;


int NodeHeight(struct Node *p) {
    int hl, hr;
    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;
    return hl > hr ? hl + 1 : hr + 1;
}

int BalanceFactor(struct Node *p) {
    int hl, hr;
    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;
    return hl - hr;
}

struct Node *LLRotation(struct Node *p) {
    struct Node *pl = p->lchild;

    // Assignment Logic
    p->lchild = pl->rchild;
    pl->rchild = p;

    // Update heights
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    // Update root
    if (root == p) root = pl;

    return pl; // return new ROOT => pl
}

struct Node *RRRotation(struct Node *p) {
    struct Node *pr = p->rchild;

    p->rchild = pr->lchild;
    pr->lchild = p;

    pr->height = NodeHeight(pr);
    p->height = NodeHeight(p);

    if (root == p) root = pr;

    return pr; // return new ROOT => pr
}

struct Node *LRRotation(struct Node *p) {
    // Initialise pointers
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

    // Assignment logic
    p->lchild = plr->rchild;
    pl->rchild = plr->lchild;

    plr->lchild = pl;
    plr->rchild = p;

    // Change heights
    plr->height = NodeHeight(plr);
    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);

    if (root == p)
        root = plr;

    return plr; // return new ROOT, plr
}

struct Node *RLRotation(struct Node *p) {
    // Initialise pointers
    struct Node *pr = p->rchild;
    struct Node *prl = pr->lchild;

    // Assignment logic
    p->rchild = prl->lchild;
    pr->lchild = prl->rchild;

    prl->lchild = p;
    prl->rchild = pr;

    // Change heights
    prl->height = NodeHeight(prl);
    pr->height = NodeHeight(pr);
    p->height = NodeHeight(p);

    if (root == p) root = prl;
    return prl; // return new ROOT, prl
}

struct Node *RInsert(struct Node *p, int key) {
    struct Node *t = NULL;
    if (p == NULL) {
        t = (struct Node *) malloc(sizeof(struct Node));
        t->lchild = t->rchild = NULL;
        t->height = 1;
        t->data = key;
        return t;
    } else if (key < p->data) {
        p->lchild = RInsert(p->lchild, key);
    } else if (key > p->data) {
        p->rchild = RInsert(p->rchild, key);
    }
    p->height = NodeHeight(p);

    // Now Performing rotation logic comes here
    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
        return LLRotation(p);
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
        return LRRotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
        return RRRotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
        return RLRotation(p);

    return p;
}

struct Node *InOrderPredecessor(struct Node *p) {
    while (p && p->rchild != NULL)
        p = p->rchild;
    return p;
}

struct Node *InOrderSuccessor(struct Node *p) {
    while (p && p->lchild != NULL)
        p = p->lchild;
    return p;
}

struct Node *RDelete(struct Node *p, int key) {
    struct Node *q = NULL;

    if (p == NULL) {
        return NULL;
    }

    if (p->lchild == NULL && p->rchild == NULL) {
        if (p == root)
            root = NULL;
        free(p);
        return NULL;
    }

    if (key < p->data) {
        p->lchild = RDelete(p->lchild, key);
    } else if (key > p->data) {
        p->rchild = RDelete(p->rchild, key);
    } else {

        if (NodeHeight(p->lchild) > NodeHeight(p->rchild)) {
            q = InOrderPredecessor(p->lchild);
            p->data = q->data;
            p->lchild = RDelete(p->lchild, q->data);
        } else {
            q = InOrderSuccessor(p->rchild);
            p->data = q->data;
            p->rchild = RDelete(p->rchild, q->data);
        }

        // Now Performing rotation logic comes here
        if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
            return LLRotation(p);
        else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
            return LRRotation(p);
        else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
            return RRRotation(p);
        else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
            return RLRotation(p);

    }
    return p;
}

void Inorder(struct Node *p) {
    if (p) {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}

void testLLRotation() {
    /* Expected Input tree:
     *          10
     *      5
     *  2
     * */
    root = RInsert(root, 10);
    RInsert(root, 5);
    RInsert(root, 2);
    /* Output tree after insert, because of LL Rotation effect it becomes:
     *
     *      5
     * 2        10
     *
     * */
}

void testLRRotation() {

    /* Input tree:
     *
     *      50
     * 10
     *      20
     * */

    root = RInsert(root, 50);
    RInsert(root, 10);
    RInsert(root, 20);

    /* Expected Output tree after insert, because of LR Rotation effect it becomes:
     *
     *      20
     * 10        50
     *
     * */

}

void testRRRotation() {

    /* Expected Input tree:
     * 10
     *     20
     *         30
     * */

    root = RInsert(root, 10);
    RInsert(root, 20);
    RInsert(root, 30);

    /* Output tree after insert, because of LR Rotation effect it becomes:
     *
     *      20
     * 10        30
     *
     * */

}

void testRLRotation() {

    /* Expected Input tree:
    *       50
    *           75
    *        60
    * */

    root = RInsert(root, 50);
    RInsert(root, 75);
    RInsert(root, 60);

    /* Output tree after insert, because of RL Rotation effect it becomes:
     *        60
     *   50         75
     *
     * */
    printf("\nAfter RL Rotation:\n");
    printf("root: %d\n", root->data);
    printf("left: %d\n", root->lchild->data);
    printf("right: %d\n", root->rchild->data);
    printf("InOrder: \n");
    Inorder(root);
}

void avlTreesC() {
    // 10, 20, 30, 25, 28, 27, 5
    root = RInsert(root, 10);
    RInsert(root, 20);
    RInsert(root, 30);
    RInsert(root, 25);
    RInsert(root, 28);
    RInsert(root, 27);
    RInsert(root, 5);
    printf("InOrder tree: \n");
    Inorder(root);


    int key = 5;
    printf("\nDelete: %d", key);
    // Delete key
    RDelete(root, key);
    printf("\nAfter deletion - InOrder tree: \n");
    Inorder(root);

    // Again insert key
    printf("\nAgain Insert: %d", key);
    RInsert(root, key);
    printf("\n");
    printf("InOrder tree: \n");
    Inorder(root);
}

/*
InOrder:
5 10 20 25 27 28 30
*/

#endif //C_CPP_AVLTREES_H