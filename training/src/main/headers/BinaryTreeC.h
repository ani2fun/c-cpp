#ifndef C_CPP_BINARYTREEC_H
#define C_CPP_BINARYTREEC_H

#include <cstdio>
#include <cstdlib>
#include "TreeNode.h"
#include "QueueUsingLinkedListForBinaryTree.h"
#include "StackUsingLinkedListForBinaryTree.h"


// Create Binary Tree and return it's Root node.
struct TreeNode *CreateBinaryTree(struct TreeNode *ROOT) {

    struct TreeNode *p, *t; // Temporary pointers, where p is kind of tail pointer for the addresses taken out of Queue.
    int value; // a placeholder for the user entered data
    struct Queue *queue = (struct Queue *) malloc(sizeof(struct Queue)); // Create Queue which holds addresses

    // Initial steps to create root node and add it to Queue
    printf("Enter the value for the ROOT : ");
    scanf("%d", &value);
    ROOT = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    ROOT->data = value;
    ROOT->leftChild = ROOT->rightChild = NULL;

    p = ROOT; // Bring the Pointer P onto the Root node.
    enqueue(queue, ROOT);

    // Start repeating steps here using while loop.
    while (!isQueueEmpty(queue)) {

        // Take out the value from the Queue and make *p point on that TreeNode.
        p = dequeue(queue);
        printf("Current node: %d\n", p->data);

        // FOR LEFT
        printf("Enter the value for the Left child of %d: ", p->data);
        scanf("%d", &value);

        // here we assume "-1" entered value as NO VALUE. Hence if there is any other number then we create a node.
        if (value != -1) {
            // create new TreeNode and assign the entered value
            t = (struct TreeNode *) malloc(sizeof(struct TreeNode));
            t->data = value;
            t->leftChild = t->rightChild = NULL;

            // Make leftChild of P points to newly created Node.
            p->leftChild = t;
            enqueue(queue, t); // Add the new address back into the Queue again.
        }

        // FOR RIGHT
        printf("Enter the value for the Right child of %d: ", p->data);
        scanf("%d", &value);

        // here we assume "-1" entered value as NO VALUE. Hence if there is any other number then we create a node.
        if (value != -1) {
            // create new TreeNode and assign the entered value
            t = (struct TreeNode *) malloc(sizeof(struct TreeNode));
            t->data = value;
            t->leftChild = t->rightChild = NULL;

            // Make leftChild of P points to newly created Node.
            p->rightChild = t;
            enqueue(queue, t); // Add the new address back into the Queue again.
        }
    }

    // RETURN "ROOT" so that it can be used to pass it to Traversal functions
    return ROOT;
}

void RecursivePreOrder(struct TreeNode *p) {
    if (p) {
        printf("%d ", p->data);
        RecursivePreOrder(p->leftChild);
        RecursivePreOrder(p->rightChild);
    }
}

void RecursiveInOrder(struct TreeNode *p) {
    if (p) {
        RecursiveInOrder(p->leftChild);
        printf("%d ", p->data);
        RecursiveInOrder(p->rightChild);
    }
}

void RecursivePostOrder(struct TreeNode *p) {
    if (p) {
        RecursivePostOrder(p->leftChild);
        RecursivePostOrder(p->rightChild);
        printf("%d ", p->data);
    }
}

void RecursiveLevelOrderHelper(struct TreeNode *p, int level) {
    if (p == NULL)
        return;

    if (level == 1)
        printf("%d ", p->data);
    else if (level > 1) {
        RecursiveLevelOrderHelper(p->leftChild, level - 1);
        RecursiveLevelOrderHelper(p->rightChild, level - 1);
    }
}

int getHeight(struct TreeNode *p) {
    if (p == NULL)
        return 0;
    int leftHeight = getHeight(p->leftChild);
    int rightHeight = getHeight(p->rightChild);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int getHeightOfTree(struct TreeNode *p) {
    int leftHeight = 0, rightHeight = 0;
    if (p != NULL) {
        leftHeight = getHeightOfTree(p->leftChild);
        rightHeight = getHeightOfTree(p->rightChild);

        if (leftHeight > rightHeight)
            return leftHeight + 1;
        else
            return rightHeight + 1;
    }
    return 0;
}

void RecursiveLevelOrderTraversal(struct TreeNode *p) {
    int height = getHeight(p);
    for (int level = 1; level <= height; level++) {
        RecursiveLevelOrderHelper(p, level);
    }
}

// ITERATIVE procedures
void IterativePreOrder(struct TreeNode *t) {
    struct Stack *stack = (struct Stack *) malloc(sizeof(struct Stack));

    while (t != NULL || !isStackEmpty(stack)) {

        if (t != NULL) {
            printf("%d ", t->data);
            pushToStack(stack, t);
            t = t->leftChild;
        } else {
            t = popFromStack(stack);
            t = t->rightChild;
        }
    }

}

void IterativeInOrder(struct TreeNode *t) {
    struct Stack *stack = (struct Stack *) malloc(sizeof(struct Stack));

    while (t != NULL || !isStackEmpty(stack)) {

        if (t) {
            pushToStack(stack, t);
            t = t->leftChild;
        } else {
            t = popFromStack(stack);
            printf("%d ", t->data);
            t = t->rightChild;
        }
    }

}

void IterativePostOrder(struct TreeNode *t) {
    struct Stack *stack = (struct Stack *) malloc(sizeof(struct Stack));
    struct TreeNode *last_node_visited = NULL;

    while (t != NULL || !isStackEmpty(stack)) {
        if (t != NULL) {
            pushToStack(stack, t);
            t = t->leftChild;
        } else {
            struct TreeNode *peek_node = stack->top->data;
            if (peek_node->rightChild != NULL && peek_node->rightChild != last_node_visited) {
                t = peek_node->rightChild;
            } else {
                printf("%d ", peek_node->data);
                last_node_visited = popFromStack(stack);
            }
        }
    }
}

// LOGIC IS SIMILAR TO CREATING TREE procedure "CreateBinaryTree()"
void IterativeLevelOrder(struct TreeNode *p) {
    // Take the Queue to push the pointer addresses of type TreeNode
    struct Queue *queue = (struct Queue *) malloc(sizeof(struct Queue)); // Create Queue which holds addresses

    printf("%d ", p->data);

    enqueue(queue, p);

    while (!isQueueEmpty(queue)) {
        p = dequeue(queue);
        if (p->leftChild) {
            printf("%d ", p->leftChild->data);
            enqueue(queue, p->leftChild);
        }
        if (p->rightChild) {
            printf("%d ", p->rightChild->data);
            enqueue(queue, p->rightChild);
        }
    }
}

int countAllNodes(struct TreeNode *p) {
    int x, y;
    if (p != NULL) {
        x = countAllNodes(p->leftChild);
        y = countAllNodes(p->rightChild);
        return x + y + 1; // this is post-order form. (e.g. first left then right and then printf)
    }
    return 0;
}

int countNodesWithDegreeZero(struct TreeNode *p) { // countNodesWithDegreeZero
    int x = 0, y = 0;
    if (p) {
        x = countNodesWithDegreeZero(p->leftChild);
        y = countNodesWithDegreeZero(p->rightChild);
        if (p->leftChild == NULL && p->rightChild == NULL) {
//        if (!p->leftChild && !p->rightChild ) {
            return x + y + 1;
        } else {
            return x + y;
        }
    }
    return 0;
}

int countNodesWithDegreeTwo(struct TreeNode *p) {
    int x = 0, y = 0;
    if (p) {
        x = countNodesWithDegreeTwo(p->leftChild);
        y = countNodesWithDegreeTwo(p->rightChild);
        if (p->leftChild != NULL && p->rightChild != NULL) {
//            if (p->leftChild && p->rightChild ) {
            return x + y + 1;
        } else {
            return x + y;
        }
    }
    return 0;
}

int countNodesWithDegreeOneOrTwo(struct TreeNode *p) {
    int x = 0, y = 0;
    if (p) {
        x = countNodesWithDegreeOneOrTwo(p->leftChild);
        y = countNodesWithDegreeOneOrTwo(p->rightChild);
        if (p->leftChild != NULL || p->rightChild != NULL) {
//            if (p->leftChild || p->rightChild ) {
            return x + y + 1;
        } else {
            return x + y;
        }
    }
    return 0;
}

int countNodesWithExactDegreeOne(struct TreeNode *p) {
    int x = 0, y = 0;
    if (p) {
        x = countNodesWithExactDegreeOne(p->leftChild);
        y = countNodesWithExactDegreeOne(p->rightChild);
        // if ((p->leftChild != NULL && p->rightChild == NULL) || (p->leftChild == NULL && p->rightChild != NULL)) {
        // XOR = LR' + L'R
        if (p->leftChild != NULL ^ p->rightChild != NULL) {
            return x + y + 1;
        } else {
            return x + y;
        }
    }
    return 0;
}

int testBinaryTreeC() {
    printf("---> [In C] Creating Binary Tree / Tree Traversal <---\n");

    struct TreeNode *root = NULL;
    root = CreateBinaryTree(root);

    printf("\n------------------\n");
    printf("Recursive Traversals\n");
    printf("PRE-ORDER: \n");
    RecursivePreOrder(root);
    printf("\nIN-ORDER: \n");
    RecursiveInOrder(root);
    printf("\nPOST ORDER: \n");
    RecursivePostOrder(root);
    printf("\nLEVEL ORDER: \n");
    RecursiveLevelOrderTraversal(root);
    printf("\n------------------\n");

    printf("\n------------------\n");
    printf("Iterative Traversals\n");
    printf("PRE-ORDER: \n");
    IterativePreOrder(root);
    printf("\nIN-ORDER: \n");
    IterativeInOrder(root);
    printf("\nIterativePostOrder POST-ORDER: \n");
    IterativePostOrder(root);
    printf("\nLEVEL-ORDER: \n");
    IterativeLevelOrder(root);
    printf("\n------------------\n");

    printf("\nHeight Of Tree : %d \n", getHeightOfTree(root));
    printf("\ncountAllNodes: %d \n", countAllNodes(root));
    printf("\ncountNodesWithDegreeZero: %d \n", countNodesWithDegreeZero(root));
    printf("\ncountNodesWithDegreeTwo: %d \n", countNodesWithDegreeTwo(root));
    printf("\ncountNodesWithDegreeOneOrTwo: %d \n", countNodesWithDegreeOneOrTwo(root));
    printf("\ncountNodesWithDegreeOneOrTwo: %d \n", countNodesWithExactDegreeOne(root));

    printf("\n");
    return 0;
}


/*
OUTPUT:
----------------------------------------------------------------
---> [In C] Creating Binary Tree / Tree Traversal <---
Enter the value for the ROOT : 8
Current node: 8
Enter the value for the Left child of 8: 3
Enter the value for the Right child of 8: 5
Current node: 3
Enter the value for the Left child of 3: 4
Enter the value for the Right child of 3: 9
Current node: 5
Enter the value for the Left child of 5: 7
Enter the value for the Right child of 5: 2
Current node: 4
Enter the value for the Left child of 4: -1
Enter the value for the Right child of 4: -1
Current node: 9
Enter the value for the Left child of 9: -1
Enter the value for the Right child of 9: -1
Current node: 7
Enter the value for the Left child of 7: -1
Enter the value for the Right child of 7: -1
Current node: 2
Enter the value for the Left child of 2: -1
Enter the value for the Right child of 2: -1
PRE-ORDER:
8 3 4 9 5 7 2
POST ORDER:
4 9 3 7 2 5 8
IN-ORDER:
4 3 9 8 7 5 2
Height of a tree is: 3
*/

#endif //C_CPP_BINARYTREEC_H
