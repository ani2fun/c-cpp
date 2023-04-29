#ifndef C_CPP_ARRAYDECLARATIONC_H
#define C_CPP_ARRAYDECLARATIONC_H

#include <stdio.h>
#include <stdlib.h>

int testArrayDeclaration() {

    int *p, *q;

    p = (int *) malloc(5 * sizeof(int));
    q = (int *) malloc(10 * sizeof(int));

    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    p[3] = 4;
    p[4] = 5;

    for (int i = 0; i < 5; i++) {
        //printf("%d ", p[i]);
        q[i] = p[i];
    }
    printf("\n");

    free(p);
    p = q;
    q = NULL;

    for (int i = 0; i < 5; i++) {
        printf("%d \n", p[i]);
    }


    printf("\n");
    printf("P--> %u \n", &p);
    printf("Q--> %u \n", &q);

    //    int A[5]={2,4,6,8,10};
    //    int *p;
    //    int i;
    //    int *q;
    //
    //    p = (int *) malloc(5 * sizeof(int));
    //    p[0] = 3;
    //    p[1] = 5;
    //    p[2] = 9;
    //    p[3] = 7;
    //    p[4] = 11;
    //
    //    for(i = 0;i < 5; i++ ) {
    //        printf("%d ", A[i]);
    //    }
    //
    //    printf("\n");
    //    for(i = 0;i < 5; i++ ) {
    //        printf("%d ", p[i]);
    //    }

    // arrays are vector element
    //    int A[5];
    //    int B[5] = {1,2,3,4,5};
    //    int C[10] = {2, 4, 6};
    //    int D[5] = {0};
    //    int E[5] = {0};
    //
    //    for(int i = 0; i<5 ; i++) {
    //        printf("%u \n", &A[i]);
    //    }

    printf("\n,");

    return 0;
}

#endif //C_CPP_ARRAYDECLARATIONC_H
