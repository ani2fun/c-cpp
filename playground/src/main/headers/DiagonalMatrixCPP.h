#ifndef C_CPP_DIAGONALMATRIXCPP_H
#define C_CPP_DIAGONALMATRIXCPP_H

#include <iostream>

using namespace std;

class Diagonal {
private:
    int n;
    int *A;
public:
    Diagonal() {
        this->n = 10;
        A = new int[this->n];
    }

    Diagonal(int n) {
        this->n = n;
        A = new int[this->n];
    }

    ~Diagonal() {
        delete[]A;
    }

    void set(int i, int j, int x);

    int get(int i, int j);

    void Display();
};

void Diagonal::set(int i, int j, int x) {
    if (i == j) A[i - 1] = x;
}

int Diagonal::get(int i, int j) {
    if (i == j) return A[i - 1];
    else return 0;
}

void Diagonal::Display() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) cout << A[i - 1] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
}

int testDiagonalMatrix() {
    // insert code here...
    std::cout << "Hello, World!\n";
    Diagonal d = Diagonal(3);
    d.set(0, 0, 2);
    d.set(1, 1, 4);
    d.set(2, 2, 6);

    d.Display();
    return 0;
}


#endif //C_CPP_DIAGONALMATRIXCPP_H
