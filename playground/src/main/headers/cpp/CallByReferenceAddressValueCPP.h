#ifndef C_CPP_CALLBYREFERENCEADDRESSVALUECPP_H
#define C_CPP_CALLBYREFERENCEADDRESSVALUECPP_H

////
////  main.cpp
////  MyFirstCPP
////
////  Created by Aniket.Kakde on 23/03/2023.
////
//
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int f(int &x, int c) {
    c = c - 1;
    if (c == 0) return 1;
    x = x + 1;
    return f(x, c) * x;
}

int testCallByReferenceAddressValue() {

    int a = 5;
    int &r = a; // r is called as reference variable

    r = 14;

    int p = 5;
    cout << f(p, p) << endl;
    cout << r << endl;
    cout << a << endl;
    cout << &r << endl;
    cout << &a << endl;
    return 0;
}
//
//
//
//// --- SOME ---
//
//void somePointerExample(){
//    int a = 5;
//    int &r=a; // r is called as reference variable
//    r=14;
//
//    cout<<a<<endl<<&a<<endl<<&r<<endl<<r<<endl;
//
//    cout<<endl;
//    cout<<"different address"<<endl;
//    int b = 10;
//    int r2 = b;
//    cout<<b<<endl<<&b<<endl<<&r2<<endl;
//}
//
//void pointerWithMalloc() {
//    // This is in C
//    int *p;
//    cout<<"Size of p: ";
//    cout<<sizeof(p)<<endl;
//    p = (int *)malloc(5 * sizeof(int));
//
//    p[0]=10;p[1]=15;p[2]=20;p[3]=30;p[4]=40;
//
//    for(int i =0 ; i<5; i++){
//        cout<<p[i]<<endl;
//    }
//
//    // Using CPP method
//    int *p1;
//    p1 = new int[5]; // dynamic allocations
//
//    p1[0]=10;p1[1]=15;p1[2]=20;p1[3]=30;p1[4]=40;
//
//    for(int i =0 ; i<5; i++){
//        cout<<p1[i]<<endl;
//    }
//
//    free(p); // this is in C
//    delete [] p1; // this is in CPP
//    cout<<"after deleting p"<<endl;
//    for(int i =0 ; i<5; i++){
//        cout<<p[i]<<endl;
//    }
//    cout<<"after deleting p1"<<endl;
//    for(int i =0 ; i<5; i++){
//        cout<<p1[i]<<endl;
//    }
//}
//
//void pointerExample1() {
//    int A[5]={4,4,6,8,10};
//
//    int *p1;
//    p1=&A[0];
//
//    for(int i =0 ; i<5; i++){
//        cout<<A[i]<<endl;
//    }
//    printf("Value to p1:");
//    cout<<p1<<endl;
//    cout<<&A[0]<<endl;
//    cout<<&A[1]<<endl;
//    cout<<p1<<endl;
//
//
//    int a = 4;
//    int *p;
//    printf("before assigning value to p:");
//    cout<<p<<endl;
//    p = &a;
//
//    printf("a: %d ", a);
//    cout<<endl;
//    printf("pointer p:");
//    cout<<p<<endl;
//    printf("deref pointer p:");
//    cout<<*p<<endl;
//    printf("address of &a: ");
//    cout<<&a<<endl;
//}


#endif //C_CPP_CALLBYREFERENCEADDRESSVALUECPP_H
