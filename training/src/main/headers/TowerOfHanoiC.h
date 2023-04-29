#ifndef C_CPP_TOWEROFHANOIC_H
#define C_CPP_TOWEROFHANOIC_H

#include <stdio.h>

void TOH(int n, int A, int B, int C) {

    if (n > 0) {
        TOH(n - 1, A, C, B);
        printf("(%d,%d)\n", A, C);
        TOH(n - 1, B, A, C);

    }
}

void foo(int n, int sum) {

    int k = 0, j = 0;

    if (n == 0) return;

    k = n % 10;

    j = n / 10;

    sum = sum + k;

    foo(j, sum);

    printf("%d", k);

}


int fun(int n) {

    int x = 1, k;

    if (n == 1) return x;

    for (k = 1; k < n; ++k)
        x = x + fun(k) * fun(n - k);

    return x;

}


int testTowerOfHanoi() {

    //    TOH(3,1,2,3);
    int a = 2048, sum = 0;

    foo(a, sum);

    printf("%d\n", sum);
    printf("%d\n", fun(5));
    printf("\n");
    return 0;
}


#endif //C_CPP_TOWEROFHANOIC_H
