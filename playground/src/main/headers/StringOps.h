#ifndef C_CPP_STRINGOPS_H
#define C_CPP_STRINGOPS_H

#include <iostream>
#include <string.h>

using namespace std;

void permSwap(char s[], int l, int h);

void swap(char *x, char *y);

int validate(char *name) {
    for (int i = 0; name[i] != '\0'; i++) {
        if (
                !(name[i] >= 65 && name[i] <= 90) &&
                !(name[i] >= 97 && name[i] <= 122) &&
                !(name[i] >= 48 && name[i] <= 57) &&
                !(name[i] != ' ')
                ) {
            return 0;
        }
    }
    return 1;
}

void reverse1(char *A, char *B) {
    int i;

    for (i = 0; A[i] != '\0'; i++) {}

    i = i - 1;

    int j;
    for (j = 0; i >= 0; i--, j++) {
        B[j] = A[i];
    }
    B[j] = '\0';

    printf("Reversed: %s \n", B);
}

void reverse2(char *A, int sz) {
    int i, j;

    char t;
    j = sz - 1; // last character is '\0' hence -1;
    for (i = 0; i < j; i++, j--) {
        t = A[i];
        A[i] = A[j];
        A[j] = t;
    }

    printf("Reversed2: %s \n", A);
}

int palindrome(char *A, int sz) {
    int i, j;
    j = sz - 1; // last character is '\0' hence -1;
    for (i = 0; A[i] != '\0'; i++, j--) {
        if (A[i] != A[j])
            return 0;
    }
    return 1;
}

bool palhelper(char str[], int start, int end) {
    // If there is only one character
    if (start == end)
        return true;

    // If first and last characters do not match
    if (str[start] != str[end])
        return false;

    // If there are more than two characters, check if middle substring is also palindrome or not.
    if (start < end + 1)
        return palhelper(str, start + 1, end - 1);

    return true;
}

bool isPalindrome(char str[]) {
    int n = (int) strlen(str);
    // An empty string is considered as palindrome
    if (n == 0)
        return true;
    return palhelper(str, 0, n - 1);
}

void prevCode() {
    const char X[] = {'A', 'B', 'C', 'D', 'E'};
    const char Y[] = {65, 66, 67, 68, 69};
    const char Z[5] = {65, 66};

    for (int i = 0; i < 5; i++) {
        printf("---\n");
        printf("X: %d , %c\n", X[i], X[i]);
        printf("Y: %d , %c\n", Y[i], Y[i]);
        printf("Z: %d , %c\n", Z[i], Z[i]);
    }

    char name[] = "Home";
    char name2[] = {'H', 'O', 'M', 'E', '\0'};
    printf("%s\n", name);
    printf("%s\n", name2);

    char n = '\0';
    char n1 = NULL;
    printf("%c, %d \n", n, n);      // op: , 0
    printf("%c, %d \n", n1, n1);    // op: , 0

    cout << "-------------" << endl;
    char upper[] = {'W', 'E', 'L', 'C', 'O', 'M', 'E', '\0'};
    int i = 0;
    int j = 0;
    for (i = 0; upper[i] != '\0'; i++) {
        upper[i] += 32;
    }
    printf("%s\n", upper);

    cout << "-------------" << endl;
    char lower[] = "hello";
    for (int j = 0; lower[j] != '\0'; j++) {
        lower[j] -= 32;
    }
    printf("%s\n", lower);

    cout << "-------------" << endl;
    char toggle[] = "W5lCoMe";
    printf("Original: %s\n", toggle);
    for (int k = 0; toggle[k] != '\0'; k++) {
        if (toggle[k] >= 65 && toggle[k] <= 90) {
            toggle[k] += 32;
        } else if (toggle[k] >= 'a' && toggle[k] <= 'z') {
            toggle[k] -= 32;
        }
    }
    printf("After toggle: %s\n", toggle);
    cout << "-------------" << endl;
    char how[] = "how are   u";
    int word = 1;
    for (int i = 0; how[i] != '\0'; i++) {
        if (how[i] == ' ' && how[i - 1] != ' ')
            word++;
    }
    printf("Number of words: %d \n", word);
    cout << "-------------" << endl;
    char *valid = (char *) "Ani?123 z";
    if (validate(valid)) {
        printf("Valid string: %s\n", valid);
    } else {
        printf("In-Valid string: %s\n", valid);
    }

    cout << "-------------" << endl;

    char toReverse[] = "Python";
    int sizeOfReverse = sizeof(toReverse) - 1;
    char B[sizeOfReverse];
    reverse1(toReverse, B);
    cout << "-------------" << endl;

    char toReverse2[] = "Python";
    int size = sizeof(toReverse2) - 1;
    cout << "size: " << size << endl;
    reverse2(toReverse2, size);
    cout << "-------------" << endl;

    char pl[] = "madam";
    cout << "fn sizeof(pl) gives length of pl: " << sizeof(pl) << endl;
    if (palindrome(pl, sizeof(pl) - 1))
        cout << "Palindrome" << endl;
    else
        cout << "Not Palindrome" << endl;

    cout << "-------------" << endl;


    cout << "------Palindrome Rec------" << endl;

    char paliStr[] = "ROTOR";
    if (isPalindrome(pl))
        cout << "Palindrome" << endl;
    else
        cout << "Not Palindrome" << endl;

    cout << "-------------" << endl;
}

void printDuplicatesInString() {
    char A[] = "finding";
    int H[26] = {0};
    int i;
    for (i = 0; A[i] != '\0'; i++) {
        H[A[i] - 97] += 1;
    }
    for (i = 0; i < 26; i++) {
        if (H[i] > 1) {
            printf("Char: '%c' appeared %d times \n", i + 97, H[i]);
        }
    }
}

void printDuplicatesInStringBitWise() {
    char A[] = "finding";
    int H = 0;
    int x = 0;

    for (int i = 0; A[i] != '\0'; i++) {
        x = 1;

        x = x << (A[i] - 97);

        if ((x & H) > 0)
            printf("%c is duplicated\n", A[i]);
        else
            H = (x | H);

    }
}

int checkAnagram() {
    //    char A[] = "decimal";
    //    char B[] = "medical";
    char A[] = "verbose";
    char B[] = "observe";

    int sizeA = strlen(A);
    int sizeB = strlen(B);

    if (sizeA != sizeB) {
        printf("Not Anagram!!!");
        return 0;
    }

    int H[26] = {0};
    int i;
    for (i = 0; A[i] != '\0'; i++) {
        H[A[i] - 97] += 1; // incr by 1 for the found value
    }

    for (i = 0; B[i] != '\0'; i++) {
        H[B[i] - 97] -= 1; // decr by 1
        if (H[B[i] - 97] < 0) {
            printf("Not Anagram!!!");
            break;
        }
    }
    if (B[i] == '\0') {
        printf("It's Anagram!!!");
    }

    return 1;
}

void perm(char s[], int k) {
    static int A[4];
    static char result[4];
    int i;

    if (s[k] == '\0') {
        result[k] = '\0';
        printf("%s\n", result);
    } else {
        for (i = 0; s[i] != '\0'; i++) {
            if (A[i] == 0) {
                result[k] = s[i];
                A[i] = 1;
                perm(s, k + 1);
                A[i] = 0;
            }
        }
    }
}

int testStringOps() {
    //prevCode();

    //printDuplicatesInString();
    //printDuplicatesInStringBitWise();
    // checkAnagram();
    char s[] = "ABCD";
    //    perm(s, 0);
    permSwap(s, 0, 3);

    return 0;
}


void permSwap(char s[], int l, int h) {
    if (l == h) {
        printf("%s\n", s);
    } else {
        for (int i = l; i <= h; i++) {
            swap(&s[l], &s[i]);
            permSwap(s, l + 1, h);
            swap(&s[l], &s[i]);
        }
    }
}

void swap(char *x, char *y) {
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

#endif //C_CPP_STRINGOPS_H
