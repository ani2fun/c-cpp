# Review Notes on Programming Topics

## Instructions for the `app`:
// To be added

## Instructions for the `java-training`:
// To be added

## Instructions for the `c-cpp`:

The examples in this directory are aimed at reviewing fundamental data structures and algorithms in C and CPP.

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
    ./gradlew :c-cpp:clean :c-cpp:build && /bin/sh ./c-cpp/build/install/main/debug/c-cpp
    ```

3. (Alternative) Can be executed using `CLion IDE` as well. Clone this repository and run `main.cpp`.

4. To speed up the process and avoid unnecessary log messages from other projects, it is recommended to comment out the include statements in the settings.gradle.kts file at the root directory for other projects. 
    For example:
    ```
    // include("app") // spring boot app
    // include("java-training")
    include("c-cpp")
    rootProject.name = "csnotes"
    ```