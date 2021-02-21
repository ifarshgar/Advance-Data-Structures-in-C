// Created by Abdolrahman on 2/18/2021.
#include <stdio.h>
#include <stdlib.h>

#include "BinaryTree.h"
#include "../Generic Queue/Queue.h"

BinaryTree * _binary_tree_init() {
    BinaryTree *T = (BinaryTree *) malloc(sizeof(BinaryTree));
    T->data = 0;
    T->left = NULL;
    T->right = NULL;
    return T;
}

void binary_tree_insert(int data, BinaryTree **T) {
    // if the tree has no element, simply the data can be inserted as root.
    if(*T == NULL) {
        *T = _binary_tree_init();
        (*T)->data = data;
        return;
    }
    // Else level order traversal should take place to find an empty place.
    Queue *first = NULL;
    Queue *last = NULL;
    QueueDataType type = _BinaryTree;
    void *v  = (void *) *T;
    queue_push(v, &first, &last, type);

    while(queue_size(first) != 0) {
        BinaryTree *bt = queue_pop(&first, &last);
        if(bt->left != NULL) {
            queue_push(bt->left, &first, &last, type);
        } else {
            bt->left = _binary_tree_init();
            bt->left->data = data;
            break;
        }
        if(bt->right != NULL) {
            queue_push(bt->right, &first, &last, type);
        } else {
            bt->right = _binary_tree_init();
            bt->right->data = data;
            break;
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
            printf("Tree values: ");
            preOrder_dfs(T);
            printf("\n");
            break;
        case Depth_First_Search_InOrder:
            printf("Tree values: ");
            inOrder_dfs(T);
            printf("\n");
            break;
        case Depth_First_Search_PostOrder:
            printf("Tree values: ");
            postOrder_dfs(T);
            printf("\n");
            break;
        default:
            break;
    }
}

void bfs(BinaryTree *T) {
    Queue *first = NULL;
    Queue *last = NULL;
    QueueDataType type = _BinaryTree;
    void *data  = (void *) T;
    queue_push(data, &first, &last, type);

    printf("Tree values: ");
    while(queue_size(first) != 0) {
        BinaryTree *bt = queue_pop(&first, &last);
        printf("%d ", bt->data);
        if(bt->left != NULL) {
            queue_push(bt->left, &first, &last, type);
        }
        if(bt->right != NULL) {
            queue_push(bt->right, &first, &last, type);
        }
    }

    printf("\n");
}

void preOrder_dfs(BinaryTree *T) {
    printf("%d ", T->data);
    if(T->left != NULL)
        preOrder_dfs(T->left);
    if(T->right != NULL)
        preOrder_dfs(T->right);
}

void inOrder_dfs(BinaryTree *T) {
    if(T == NULL)
        return;
    inOrder_dfs(T->left);
    printf("%d ", T->data);
    inOrder_dfs(T->right);
}

void postOrder_dfs(BinaryTree *T) {
    if(T->left != NULL)
        postOrder_dfs(T->left);
    if(T->right != NULL)
        postOrder_dfs(T->right);
    printf("%d ", T->data);
}

void delete(int data, BinaryTree **T) {
    // if the tree is empty
    if(*T == NULL) {
        printf("The tree is empty!\n");
        return;
    }

    Queue *first = NULL;
    Queue *last = NULL;
    QueueDataType type = _BinaryTree;
    void *v  = (void *) T;
    queue_push(v, &first, &last, type);

    while(queue_size(first) != 0) {
        BinaryTree *bt = queue_pop(&first, &last);
        if(bt->data == data) {
            // connect the children of the current node to the parent of the current node and delete the node!
            // TODO tree has to me modified to hold a link to the parent of the nodes as well.
            printf("Node<%d> is deleted!\n", data);
            break;
        }
        if(bt->left != NULL) {
            queue_push(bt->left, &first, &last, type);
        }
        if(bt->right != NULL) {
            queue_push(bt->right, &first, &last, type);
        }
    }
}

//void binary_search_tree_insert(char data, BinaryTree *T);
//void binary_search_tree_delete(char data, BinaryTree *T);