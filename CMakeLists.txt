cmake_minimum_required(VERSION 3.15)
project(DataStructures C)

set(CMAKE_C_STANDARD 11)

add_executable(
        DataStructures
        main.c
        Arrays/arrays.h Arrays/arrays.c
        "Searching Algorithms/Binary Search/Binary_Search.h" "Searching Algorithms/Binary Search/Binary_Search.c"
        "Searching Algorithms/Sequential Search/Sequential_Search.h" "Searching Algorithms/Sequential Search/Sequential_Search.c"
        "Binary Tree/BinaryTree.h" "Binary Tree/BinaryTree.c"
        "Generic Queue/Queue.h" "Generic Queue/Queue.c"
        "Simple Queue/SimpleQueue.h" "Simple Queue/SimpleQueue.c"
        "Simple Stack/SimpleStack.h" "Simple Stack/SimpleStack.c"
        Vector/Vector.h Vector/Vector.c
    )