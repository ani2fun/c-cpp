#ifndef C_CPP_RECURSIONSIMPLEEXAMPLE_H
#define C_CPP_RECURSIONSIMPLEEXAMPLE_H

#include <stdio.h>

int fun(int n) {
    static int x;
    if (n > 0) {
        x++;
        return fun(n - 1) + x;
    }
    return 0;
}

int testRecursionSimple() {
    int a = 5;
    printf("%d \n", fun(a));
    return 0;
}

#endif //C_CPP_RECURSIONSIMPLEEXAMPLE_H
