#ifndef C_CPP_RECURSION_H
#define C_CPP_RECURSION_H


#include <cstdio>

int power(int m, int n) {
    if (n == 0)
        return 1;

    if (n % 2 == 0) {
        return power(m * m, n / 2);
    } else {
        return m * power(m * m, (n - 1) / 2);
    }
}

void testPower() {
    printf("%d ", power(2,7));
}

#endif //C_CPP_RECURSION_H
