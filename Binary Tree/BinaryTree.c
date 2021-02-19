// Created by Abdolrahman on 2/18/2021.
#include <stdio.h>
#include <stdlib.h>

#include "BinaryTree.h"

BinaryTree * init() {
    BinaryTree *T = (BinaryTree *) malloc(sizeof(BinaryTree));
    T->data = 0;
    T->left = NULL;
    T->right = NULL;
    return T;
}

void insert_to_left(int data, BinaryTree *T) {
    if (T == NULL) {
        T = init();
        T->data = data;
    } else {
        if(T->left == NULL) {
            T->left = init();
            T->left->data = data;
        } else {
            insert_to_left(data, T->left);
        }
    }
}

void insert_to_right(int data, BinaryTree *T) {
    if (T == NULL) {
        T = init();
        T->data = data;
    } else {
        if(T->right == NULL) {
            T->right = init();
            T->right->data = data;
        } else {
            insert_to_right(data, T->right);
        }
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