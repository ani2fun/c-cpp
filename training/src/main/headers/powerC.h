#ifndef C_CPP_POWERC_H
#define C_CPP_POWERC_H

#include <stdio.h>

int powerRec(int m, int n) {
    if (n == 0)
        return 1;
    else
        return powerRec(m, n - 1) * m;
}

int power2(int m, int n) {
    if (n == 0) {
        return 1;
    }
    if (n % 2 == 0) {
        // e.g.
        // 2^8 = (2^2)^4
        // 2^8 = (2 * 2)^4
        return power2(m * m, n / 2);
    }
    // 2^9 = 2 * (2 * 2)^4
    return m * power2(m * m, (n - 1) / 2);
}

int testPowerExample() {
    // insert code here...
    printf("%d \n", powerRec(2, 9));
    printf("%d \n", power2(2, 9));
    printf("\n");
    return 0;
}


#endif //C_CPP_POWERC_H
