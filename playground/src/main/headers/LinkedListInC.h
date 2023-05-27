#ifndef C_CPP_LINKEDLISTINC_H
#define C_CPP_LINKEDLISTINC_H


#include <stdio.h>
#include <stdlib.h>
#include <climits>

struct Node {
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL; // define first, second and third as global pointers

void create(int A[], int n) {
    int i;
    struct Node *t;
    struct Node *last;

    first = (struct Node *) malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++) {
        t = (struct Node *) malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void create2(int A[], int n) {
    struct Node *t = NULL;
    struct Node *last = NULL;

    second = (struct Node *) malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;

    for (int i = 1; i < n; i++) {
        t = (struct Node *) malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }

}

void Display(struct Node *p) {
    //    while(p!=NULL)
    //    while(p!=0)
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
}

void RDisplay(struct Node *p) {
    if (p != NULL) {
        printf("%d ", p->data);
        RDisplay(p->next);
    }
}

int count_recursive(struct Node *p, int acc) {
    if (!p)
        return acc;
    return count_recursive(p->next, acc + 1);
}

int RCount(struct Node *p) {
    return count_recursive(p, 0);
}

int count1(struct Node *p) {
    if (p != NULL)
        return count1(p->next) + 1;
    return 0;
}

int sum_recursive(struct Node *p, int acc) {
    if (!p)
        return acc;
    return sum_recursive(p->next, (p->data) + acc);
}

int sum(struct Node *p) {
    return sum_recursive(p, 0);
}

void destroy(struct Node *p) {
    if (p == NULL)
        return;
    destroy(p->next);
    free(p);
}

int Max(struct Node *p) {
    int max = INT_MIN;
    while (p) {

        if ((p->data) > max) {
            max = p->data;
        }

        p = p->next;
    }
    return max;
}

int RMax(struct Node *p) {
    int x = INT_MIN;

    if (p == 0)
        return x;

    x = RMax(p->next);

    if (x > p->data)
        return x;
    else
        return p->data;
}

int max_recursive(struct Node *p, int max_so_far) {
    // Base case
    if (!p)
        return max_so_far;

    // Compare the current node's data with the maximum so far
    if (p->data > max_so_far)
        max_so_far = p->data;

    // Tail recursive call to check the remaining nodes
    return max_recursive(p->next, max_so_far);
}

int max_in_list(struct Node *head) {
    return max_recursive(head, head->data);
}

struct Node *LSearch(struct Node *p, int key) {
    while (p) {
        if (p->data == key)
            return p;
        p = p->next;
    }
    return NULL;
}

struct Node *LRSearch(struct Node *p, int key) {
    if (p == NULL)
        return NULL;
    if (key == p->data)
        return p;
    return LRSearch(p->next, key);
}

struct Node *LSearchWithMoveToFrontApproach(struct Node *p, int key) {
    struct Node *q = NULL;

    while (p != NULL) {
        if (key == p->data) {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

void SortedInsert(struct Node *p, int x) {
    struct Node *t, *q = NULL;
    t = (struct Node *) malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if (first == NULL)
        first = t;
    else {
        while (p && p->data < x) {
            q = p;
            p = p->next;
        }
        if (p == first) {
            t->next = first;
            first = t;
        } else {
            t->next = q->next;
        }
        q->next = t;
    }
}

void InsertAtIndex(struct Node *p, int index, int x) {
    if (index < 0 || index > RCount(p))
        return;

    struct Node *t;
    t = (struct Node *) malloc(sizeof(struct Node));
    t->data = x;

    if (index == 0) {
        t->next = first;
        first = t;
    } else {
        for (int i = 0; i < index - 1; i++)
            p = p->next;

        t->next = p->next;
        p->next = t;
    }
}


int isSorted(struct Node *p) {
    int x = INT_MIN;

    while (p) // or while(p!=NULL)
    {
        if (p->data < x) {
            printf("List is NOT sorted!\n");
            return 0;
        }
        x = p->data;
        p = p->next;
    }
    printf("List is Sorted\n");
    return 1;
}

int DeleteAtIndex(struct Node *p, int index) {
    struct Node *q = NULL;
    int x; // to hold the deleted data

    if (index < 1 || index > RCount(p))
        return -1;

    if (index == 1) {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    } else {

        for (int i = 0; i < index - 1 && p; i++) {
            q = p;
            p = p->next;
        }
        x = p->data;
        q->next = p->next;
        free(p);
        return x;
    }
}

void RemoveDuplicated(struct Node *p) {

    struct Node *q = p->next;

    while (q != NULL) {

        if (p->data != q->data) {
            p = q;
            q = q->next;
        } else {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }

}

// Iterative version to reverse
void IReverse(struct Node *p) {
    struct Node *q = NULL;
    struct Node *r = NULL;

    while (p != NULL) {
        // Sliding steps
        r = q;
        q = p;
        p = p->next;
        // Reversing step
        q->next = r;
    }
    // then at last first node becomes q
    first = q;
}


// Recursive reverse
void RReverse(struct Node *p, struct Node *q) {

    if (p != NULL) {
        RReverse(p->next, p);
        p->next = q;
    } else {
        first = q;
    }

}

void Merge(struct Node *p, struct Node *q) {
    struct Node *last;
    if (p->data < q->data) {
        third = last = p;
        p = p->next;
        last->next = NULL;
    } else {
        third = last = q;
        q = q->next;
        last->next = NULL;
    }

    while (p && q) {

        if (p->data < q->data) {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        } else {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }

    if (p) last->next = p;
    if (q) last->next = q;
}

void Concat(struct Node *p, struct Node *q) {
    third = p;
    while (p->next != NULL)
        p = p->next;
    p->next = q;
}


// --- TEST ---
void RReverseMain(void) {
    int A[] = {3, 6, 9, 12};
    create(A, 4);
    printf("Original List: \n");
    RDisplay(first);

    RReverse(first, NULL);
}

void removeDuplicatedMain(void) {
    int A[] = {3, 5, 5, 7, 8, 8, 8};
    create(A, 7);
    printf("Original List: \n");
    RDisplay(first);

    RemoveDuplicated(first);
    printf("\nAfter removing duplicates the List: \n");
    RDisplay(first);
}

void deleteAtIndexMain(void) {
    int A[] = {2, 3, 4, 5, 6};

    create(A, 5);
    isSorted(first);
    printf("Original List: \n");
    RDisplay(first);
    // ------------------------------ //
    if (isSorted(first))
        printf("\nDeleted: %d at index: 2 \n", DeleteAtIndex(first, 2));

    printf("\nAfter delelting: \n");
    RDisplay(first);
    printf("\n");
}

int testLinkedListInCMain() {
    // NOTE: "first" node is NULL by default.
    int A[] = {3, 10, 30, 40, 50};
    int B[] = {2, 4, 6, 8, 9};
    create(A, 5);
    create2(B, 5);
    RDisplay(first);
    printf("\n");
    RDisplay(second);

    printf("\n");
    // first and second should be sorted Individually before provided to Merge
    Merge(first, second);
    printf("\nAfter merging the List: \n");
    RDisplay(third);
    printf("\n");
    destroy(first);
    return 0;
}

int testLinkedListInC() {
    int A[] = {3, 5, 7, 10, 25, 8, 32, 2};
    create(A, 8);
    // ------------------------------ //

    printf("Original List: \n");
    RDisplay(first);
    printf("\n");
    // ------------------------------ //
    printf("\n");
    printf("Count: %d \n", RCount(first));
    printf("Count1: %d \n", count1(first));
    printf("Sum of all elements: %d \n", sum(first));

    // ------------------------------ //
    int min_value = INT_MIN;
    int max_value = INT_MAX;
    printf("Minimum value of an integer is: %d \n", min_value);
    printf("Size of MIN or MAX integer is: %lu \n", sizeof(max_value));
    // ------------------------------ //

    printf("Max value in LL is: %d \n", Max(first));
    printf("RMax value in LL is: %d \n", RMax(first));
    printf("max_in_list : %d \n", max_in_list(first));
    // ------------------------------ //
    const int key = 12;
    printf("Iterative. searching key: %d . Found at address: %p\n", key, LSearch(first, key));
    printf("Recursive. searching key: %d . Found at address: %p\n", key, LRSearch(first, key));
    struct Node *temp;
    temp = LSearchWithMoveToFrontApproach(first, 25);
    printf("\n");
    Display(first);
    temp = LSearchWithMoveToFrontApproach(first, 8);

    printf("\n");
    Display(first);

    printf("Original List: \n");
    RDisplay(first);

    InsertAtIndex(first, 0, 10);
    InsertAtIndex(first, 1, 20);
    InsertAtIndex(first, 2, 30);
    RDisplay(first);
    InsertAtIndex(first, 0, 5);

    // -------



    return 0;
}


#endif //C_CPP_LINKEDLISTINC_H
