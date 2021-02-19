// Created by Abdolrahman on 2/18/2021.
#ifndef DATA_STRUCTURES_BINARY_TREE_H
#define DATA_STRUCTURES_BINARY_TREE_H

typedef struct BinaryTree BinaryTree;
struct BinaryTree {
    int data;
    BinaryTree *left;
    BinaryTree *right;
};

typedef enum TraverseType TraverseType;
enum TraverseType {
    Breadth_First_Search = 1,
    Depth_First_Search_InOrder = 2,
    Depth_First_Search_PreOrder = 3,
    Depth_First_Search_PostOrder = 4
};

BinaryTree * init();

void insert_to_left(int data, BinaryTree *T);
void insert_to_right(int data, BinaryTree *T);

void traverse(BinaryTree *T, TraverseType type);
void bfs(BinaryTree *T);
void delete(int data, BinaryTree *T);

void binary_search_tree_insert(int data, BinaryTree *T);
void binary_search_tree_delete(int data, BinaryTree *T);

#endif //DATA_STRUCTURES_BINARY_TREE_H