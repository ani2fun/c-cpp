#ifndef C_CPP_TWOARRAYMERGEUNIONDIFFINTERSECTIONCPP_H
#define C_CPP_TWOARRAYMERGEUNIONDIFFINTERSECTIONCPP_H

#include <iostream>
#include <cstdlib>

using namespace std;

class Array {
private:
    int *A;
    int size;
    int length;

public:
    Array(struct Array *arr) {
        A = arr->A;
        size = arr->size;
        length = arr->length;
    };

    int Get(int index) {
        if (index >= 0 && index < length) {
            return A[index];
        }
    }

    void Set(int index, int x) {
        if (index >= 0 && index < length) {
            A[index] = x;
        }
    }

    void display() {
        for (int i = 0; i < length; i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }


    Array Merge(Array &B) {
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < length && j < B.length) {
            if (A[i] < B.Get(j)) {
                Set(k++, A[i++]);
            } else {
                Set(k++, B.Get(j++));
            }
        }
        for (; i < length; i++) {
            Set(k++, A[i]);
        }
        for (; j < B.length; j++) {
            Set(k++, B.Get(j));
        }
        return this;
    }

    ~Array() {
        delete[] A;
    }
};

int testTwoArrayMergeUnionDiffIntersectionC() {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

#endif //C_CPP_TWOARRAYMERGEUNIONDIFFINTERSECTIONCPP_H
