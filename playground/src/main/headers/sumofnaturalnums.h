#ifndef C_CPP_SUMOFNATURALNUMS_H
#define C_CPP_SUMOFNATURALNUMS_H

#include <stdio.h>

int usingLoops(int n) {
    int i, s = 0;
    for (int i = 1; i <= n; i++) {
        s = s + i;
    }
    return s;
}

int usingRecursion(int n) {
    if (n == 0)
        return 0;
    else
        return usingRecursion(n - 1) + n;
}

int sumUsingFormula(int n) {
    return (n * (n + 1)) / 2;
}

int testSumOfNaturalNums() {

    // using formula -> (n(n+1))/2


    printf("%d \n", usingRecursion(10)); // O(1)
    printf("%d \n", sumUsingFormula(10)); // O(n)
    printf("%d \n", usingLoops(10)); // O(n)
    printf("\n");
    return 0;
}

#endif //C_CPP_SUMOFNATURALNUMS_H
