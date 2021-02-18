cmake_minimum_required(VERSION 3.15)
project(DataStructures C)

set(CMAKE_C_STANDARD 11)

add_executable(
        DataStructures
        main.c
        Arrays/arrays.h Arrays/arrays.c
        "Binary Search/Binary_Search.h" "Binary Search/Binary_Search.c"
        "Sequential Search/Sequential_Search.h" "Sequential Search/Sequential_Search.c"
        "Binary Tree/BinaryTree.h" "Binary Tree/BinaryTree.c"
)