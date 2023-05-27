#ifndef C_CPP_FINDINGMISSINGEXAMPLESCPP_H
#define C_CPP_FINDINGMISSINGEXAMPLESCPP_H

#include <iostream>

using namespace std;


void missingElementsInSortedList(int A[]) {
    int diff = A[0] - 0;
    for (int i = 0; i < 6; i++) {
        if (A[i] - i != diff) {
            while (diff < A[i] - i) {
                cout << i + diff << " ";
                diff++;
            }

        }
    }
    cout << endl;
}

void missingElementsInUnsortedList(int B[]) {
    int low;
    int high;
    int n;
    low = 1;
    high = 12;
    n = 10;
    int *H = new int[high];

    for (int i = 0; i < n; i++) {
        H[B[i]]++;
    }

    for (int i = low; i < high; i++) {
        if (H[i] == 0)
            cout << i << " ";
    }
    cout << endl;
}

void findDuplicates(int A[], int n) {
    int lastDuplicate = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] == A[i + 1] && A[i] != lastDuplicate) {
            cout << A[i] << endl;
            lastDuplicate = A[i];
        }
    }
}

void countDuplicates(int *A, int n) {
    int j;
    for (int i = 0; i < n - 1; i++) {
        if (A[i] == A[i + 1]) {
            j = i + 1;
            while (A[j] == A[i]) j++;
            cout << A[i] << " is appearing " << j - i << " times" << endl;
            i = j - 1;
        }
    }
}

void findDuplicatesUsingBitSet(int arr[], int size) {
    int *H = new int[size * 2];
    for (int i = 0; i < size; i++) {
        H[arr[i]]++;
    }
    int sizeOfH = size * 2;
    for (int i = 0; i < sizeOfH; i++) {
        if (H[i] > 0) cout << i << " is duplicated " << H[i] << " times" << endl;
    }
}


void findDuplicatesInUnsortedArraySolution1(int arr[], int size) {
    // O(n^2)
    int count;
    int i, j;
    for (int i = 0; i < size - 1; i++) {
        count = 1;
        if (arr[i] != -1) {
            for (j = i + 1; j < size; j++) {
                if (arr[i] == arr[j]) {
                    count++;
                    cout << arr[i] << " is duplicated " << count << " times" << endl;
                    arr[j] = -1;
                }
            }
        }
    }
}

void findDuplicatesInUnsortedArrayUsingBitSet(int arr[], int size, int highest) {
    int *H = new int[highest];
    for (int i = 0; i < size; i++) {
        H[arr[i]]++;
    }

    for (int i = 0; i < highest; i++) {
        if (H[i] > 0) cout << i << " is duplicated " << H[i] << " times" << endl;
    }
}

void findPairWithSumKUnsorted(int A[], int n, int highest, int k) {
    int *H = new int[highest];
    for (int i = 0; i < n; i++) {
        if (H[k - A[i]] != 0) {
            printf("%d+%d=%d \n", A[i], k - A[i], k);
        }
        H[A[i]]++;
    }
}

void findPairWithSumKSorted(int A[], int k, int n) {
    int i, j;
    i = 0;
    j = n - 1;
    while (i < j) {
        if (A[i] + A[j] == k) {
            printf("%d+%d=%d\n", A[i], A[j], k);
            i++;
            j--;
        } else if (A[i] + A[j] < k) {
            i--;
        } else if (A[i] + A[j] > k) {
            j--;
        }
    }
}

void findMaxMinInSingleScan(int A[], int n) {
    int min = A[0];
    int max = A[0];

    for (int i = 0; i < n; i++) {
        if (A[i] < min)
            min = A[i];  // (n-1)
        else if (A[i] > max) // 2(n-1)
            max = A[i];
    }
    cout << "Max: " << max << endl;
    cout << "Min: " << min << endl;

}

int testMissingInArray() {
    cout << "--- Missing Element ---" << endl;
    int A[] = {1, 2, 3, 5, 6, 9, 10};
    cout << "In Sorted List" << endl;
    missingElementsInSortedList(A);

    cout << "In Unsorted List" << endl;
    int B[] = {3, 7, 4, 9, 12, 6, 1, 11, 2, 10};
    missingElementsInUnsortedList(B);

    cout << "--- Duplicates element ---" << endl;
    int C[] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20}; // sorted
    //int C[] = {15,3,6,10,15,12,15,8,20,8}; // unsorted
    int size = sizeof(C) / sizeof(C[0]);
    cout << "Size of C " << size << endl;
    findDuplicates(C, size);

    cout << "--- Count duplicate element ---" << endl;
    countDuplicates(C, size);
    findDuplicatesInUnsortedArraySolution1(C, size);
    int highestElement = 15;
    findDuplicatesInUnsortedArrayUsingBitSet(C, size, highestElement);
    cout << "--- findPairWithSumK ---" << endl;
    int D[] = {6, 3, 8, 10, 16, 7, 5, 2, 9, 14};
    //a+b=10
    findPairWithSumKUnsorted(D, 10, 16, 10);
    cout << "--- findPairWithSumKSorted ---" << endl;
    int E[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    //a+b=10
    findPairWithSumKSorted(E, 10, 13); // sum=k, n=13

    findMaxMinInSingleScan(E, 13); // sum=k, n=13

    return 0;
}

#endif //C_CPP_FINDINGMISSINGEXAMPLESCPP_H
