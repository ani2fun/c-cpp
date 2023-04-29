#ifndef C_CPP_INDIRECTRECURSIONC_H
#define C_CPP_INDIRECTRECURSIONC_H

#include <stdio.h>
// declare first the funB

void funB(int n);

// definition
void funA(int n) {
    if (n > 0) {
        printf("%d ", n);
        funB(n - 1);
    }

};

void funB(int n) {
    if (n > 1) {
        printf("%d ", n);
        funA(n / 2);
    }
}

int indrectRecTest() {

    funA(20); // OUTPUT: 20 19 9 8 4 3 1
    printf("\n");
    return 0;
}


#endif //C_CPP_INDIRECTRECURSIONC_H
