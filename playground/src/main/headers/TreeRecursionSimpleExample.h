#ifndef C_CPP_TREERECURSIONSIMPLEEXAMPLE_H
#define C_CPP_TREERECURSIONSIMPLEEXAMPLE_H

#include <stdio.h>

void fun(int n) {
    if (n > 0) {
        printf("%d ", n);
        fun(n - 1);
        fun(n - 1);
    }
}

int testTreeRecursionExample() {

    fun(5);
    printf("\n");
    return 0;
}


#endif //C_CPP_TREERECURSIONSIMPLEEXAMPLE_H
