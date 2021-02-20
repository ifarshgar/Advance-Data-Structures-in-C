// Created by Abdolrahman on 2/18/2021.
#include <stdio.h>
#include <stdlib.h>

#include "BinaryTree.h"

BinaryTree * _binary_tree_init() {
    BinaryTree *T = (BinaryTree *) malloc(sizeof(BinaryTree));
    T->data = 0;
    T->left = NULL;
    T->right = NULL;
    return T;
}

void binary_tree_insert(int data, BinaryTree **T) {
    if(*T == NULL) {
        *T = _binary_tree_init();
        (*T)->data = data;
        return;
    }

    if((*T)->left == NULL) {
        (*T)->left = _binary_tree_init();
        (*T)->left->data = data;
        return;
    } else {
        binary_tree_insert(data, &(*T)->left);
    }

    if((*T)->right == NULL) {
        (*T)->right = _binary_tree_init();
        (*T)->right->data = data;
        return;
    } else {
        binary_tree_insert(data, &(*T)->right);
    }
}

void traverse(BinaryTree *T, TraverseType type) {
    if(T == NULL) {
        printf("The tree is empty!\n");
        return;
    }

    switch(type) {
        case Breadth_First_Search:
            bfs(T);
            break;
        case Depth_First_Search_PreOrder:
            break;
        case Depth_First_Search_InOrder:
            break;
        case Depth_First_Search_PostOrder:
            break;
        default:
            break;
    }
}

void bfs(BinaryTree *T) {

}

//void delete(char data, BinaryTree *T);
//
//void binary_search_tree_insert(char data, BinaryTree *T);
//void binary_search_tree_delete(char data, BinaryTree *T);