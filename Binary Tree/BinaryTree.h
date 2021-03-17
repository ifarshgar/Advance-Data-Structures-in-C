// Created by Abdolrahman on 2/18/2021.
#ifndef DATA_STRUCTURES_BINARY_TREE_H
#define DATA_STRUCTURES_BINARY_TREE_H

typedef struct BinaryTree BinaryTree;
struct BinaryTree {
    int data;
    BinaryTree *root;
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

BinaryTree* binary_tree_init();

// insertion with respect to the completeness of the tree.
void binary_tree_insert(int data, BinaryTree **T);
void binary_tree_delete(int data, BinaryTree **T);

void binary_tree_traverse(BinaryTree *T, TraverseType type);
void bfs(BinaryTree *T);
void preOrder_dfs(BinaryTree *T);
void inOrder_dfs(BinaryTree *T);
void postOrder_dfs(BinaryTree *T);

int binary_tree_size(BinaryTree *T);

// Returns the node that contains the provided data within the binary search tree.
BinaryTree * getBinaryTreeNode(int data, BinaryTree *T);
void binary_search_tree_insert(int data, BinaryTree **T);   // binary search tree insertion
void binary_search_tree_delete(int data, BinaryTree **T);   // binary search tree deletion


#endif //DATA_STRUCTURES_BINARY_TREE_H