cmake_minimum_required(VERSION 3.25)
project(c-cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/main/headers)
include_directories(src/main/headers/c)

add_executable(c-cpp
        src/main/cpp/main.cpp
        src/main/headers/QueueUsingLinkedListForBinaryTree.h src/main/headers/StackUsingLinkedListForBinaryTree.h src/main/headers/StackUsingArrayForBinaryTree.h src/main/headers/LinkedListInC.h src/main/headers/IndirectRecursionC.h src/main/headers/ArrayADT.h src/main/headers/DoublyLinkedListC.h src/main/headers/cpp/findingMissingExamplesCPP.h src/main/headers/cpp/ArrayADTCPP.h src/main/headers/ArrayCPPGenericExample.h src/main/headers/ArrayDeclarationC.h src/main/headers/BinarySearchInArrayC.h src/main/headers/CircularLinkedList.h src/main/headers/cpp/CircularQueueUsingArrayCPP.h src/main/headers/DiagonalMatrixCPP.h src/main/headers/cpp/LowerTriangularMatrixCPP.h src/main/headers/TwoArrayMergeUnionDiffIntersectionC.h src/main/headers/cpp/TwoArrayMergeUnionDiffIntersectionCPP.h src/main/headers/cpp/CallByReferenceAddressValueCPP.h src/main/headers/StringOps.h src/main/headers/sumofnaturalnums.h src/main/headers/RecursionSimpleExample.h src/main/headers/TowerOfHanoiC.h src/main/headers/TreeRecursionSimpleExample.h src/main/headers/cpp/StackLinkedListCPP.h src/main/headers/NestedRecursionSimpleExampleC.h src/main/headers/powerC.h src/main/headers/BinaryTreeC.h src/main/headers/cpp/QueueLinkedListCPP.h src/main/headers/cpp/BinaryTreeCPP.h src/main/headers/TreeNode.h src/main/headers/cpp/QueueCPP.h src/main/headers/cpp/IterativeTreeTraversalUsingStackCPP.h src/main/headers/BinarySearchTree.h "src/main/headers/AVLTrees.h" src/main/headers/AVLCreate.h src/main/headers/cpp/AVLTreeCPP.h)
