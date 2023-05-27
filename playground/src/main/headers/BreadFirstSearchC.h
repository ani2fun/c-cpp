#ifndef C_CPP_BREADFIRSTSEARCHC_H
#define C_CPP_BREADFIRSTSEARCHC_H

#include "cstdio"
#include <cstdlib>

void BFS (int i) {

    // i is Starting vertex, whatever it will be

    int u; // some variable to hold the vertex taken out from the queue.

    printf("%d", i);
    visited[i] = 1;
    enqueue(q, i);

    while(!isEmpty(q)) {

        u = dequeue(q);

        for (int v = 1; v <= n; v) {
            if(A[u][v] == 1 && visited[v] == 0) {

                printf("%d", v);
                visited[v] = 1;
                enqueue(q, v);

            }
        }
    }
}

#endif //C_CPP_BREADFIRSTSEARCHC_H
