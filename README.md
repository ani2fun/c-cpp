# Review Notes on DSA Topics using C-CPP

The examples are aimed at reviewing fundamental data structures and algorithms in C and CPP.

### Running the project Using Gradle:

1. Add function in main.
For example:
    ```
    #include "cpp/BinaryTreeCPP.h"
    int main() {
        testBinaryTreeCPP();
        return 0;
    }
    ```

2. To execute main, use the following gradle command:
    ```console
    ./gradlew :training:clean :training:build && /bin/sh ./training/build/install/main/debug/training
    ```
   
3. (Alternative) Can be executed using `CLion IDE` as well. Clone this repository and run `main.cpp`.