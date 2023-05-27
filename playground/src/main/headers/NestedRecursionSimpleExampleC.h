#ifndef C_CPP_NESTEDRECURSIONSIMPLEEXAMPLEC_H
#define C_CPP_NESTEDRECURSIONSIMPLEEXAMPLEC_H

#include <stdio.h>

int fun(int n) {

    if (n > 100) {
        return n - 10;
    } else {
        return fun(fun(n + 11));
    }
}

int testNestedRecursionC() {

    printf("%d ", fun(96));
    printf("\n");
    return 0;
}

#endif //C_CPP_NESTEDRECURSIONSIMPLEEXAMPLEC_H
