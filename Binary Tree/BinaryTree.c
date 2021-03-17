// Created by Abdolrahman on 2/18/2021.
#include <stdio.h>
#include <stdlib.h>

#include "BinaryTree.h"
#include "../Generic Queue/Queue.h"

BinaryTree * binary_tree_init() {
    BinaryTree *T = (BinaryTree *) malloc(sizeof(BinaryTree));
    T->data = 0;
    T->root = NULL;
    T->left = NULL;
    T->right = NULL;
    return T;
}

void binary_tree_insert(int data, BinaryTree **T) {
    // if the tree has no element, simply the data can be inserted as root.
    if(*T == NULL) {
        *T = binary_tree_init();
        (*T)->data = data;
        return;
    }
    // Else level order traversal should take place to find an empty place.
    Queue *first = NULL;
    Queue *last = NULL;
    void *v  = (void *) *T;
    queue_push(v, &first, &last);

    while(queue_size(first) != 0) {
        BinaryTree *bt = queue_pop(&first, &last);
        if(bt->left != NULL) {
            queue_push(bt->left, &first, &last);
        } else {
            bt->left = binary_tree_init();
            bt->left->root = bt;
            bt->left->data = data;
            break;
        }
        if(bt->right != NULL) {
            queue_push(bt->right, &first, &last);
        } else {
            bt->right = binary_tree_init();
            bt->right->root = bt;
            bt->right->data = data;
            break;
        }
    }
}

void binary_tree_traverse(BinaryTree *T, TraverseType type) {
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
    void *data  = (void *) T;
    queue_push(data, &first, &last);

    printf("Tree values: ");
    while(queue_size(first) != 0) {
        BinaryTree *bt = queue_pop(&first, &last);
        printf("%d ", bt->data);
        if(bt->left != NULL) {
            queue_push(bt->left, &first, &last);
        }
        if(bt->right != NULL) {
            queue_push(bt->right, &first, &last);
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

void binary_tree_delete(int data, BinaryTree **T) {
    // if the tree is empty
    if(*T == NULL) {
        printf("The tree is empty!\n");
        return;
    }

    Queue *first = NULL;
    Queue *last = NULL;
    void *v  = (void *) *T;
    queue_push(v, &first, &last);
    BinaryTree *deepest = NULL;
    BinaryTree *target = NULL;
    int found = 0;

    while(queue_size(first) != 0) {
        BinaryTree *bt = queue_pop(&first, &last);
        deepest = bt;
        if(bt->data == data) {
            found = 1;
            target = bt;
        }
        if(bt->left != NULL) {
            queue_push(bt->left, &first, &last);
        }
        if(bt->right != NULL) {
            queue_push(bt->right, &first, &last);
        }
    }

    if(found) {
        // if tree has only one node!
        if(binary_tree_size(*T) == 1) {
            *T = NULL;
            free(deepest);
            printf("Node<%d> is deleted!\n", data);
            return;
        }
        target->data = deepest->data;
        if(deepest->root->left == deepest)
            deepest->root->left = NULL;
        else if(deepest->root->right == deepest)
            deepest->root->right = NULL;
        free(deepest);
        printf("Node<%d> is deleted!\n", data);
    }
    else
        printf("Node<%d> was not found!\n", data);

}

int binary_tree_size(BinaryTree *T) {
    if(T == NULL)
        return 0;

    return 1 + binary_tree_size(T->left) + binary_tree_size(T->right);
}

void binary_search_tree_insert(int data, BinaryTree **T) {
    // if the tree has no element, simply the data can be inserted as root.
    if(*T == NULL) {
        *T = binary_tree_init();
        (*T)->data = data;
        return;
    }
    // Else an empty place should be found according to the passed argument data.
    Queue *first = NULL;
    Queue *last = NULL;
    void *v  = (void *) *T;
    queue_push(v, &first, &last);

    while(queue_size(first) != 0) {
        BinaryTree *bt = queue_pop(&first, &last);
        // if the node is less than the current node value it has to go to the left side of the tree.
        if(bt->data > data) {
            if(bt->left == NULL) {
                bt->left = binary_tree_init();
                bt->left->root = bt;
                bt->left->data = data;
                break;
            }
            queue_push(bt->left, &first, &last);
        }
        // greater values has to go to the right side of the tree.
        else {
            if(bt->right == NULL) {
                bt->right = binary_tree_init();
                bt->right->root = bt;
                bt->right->data = data;
                break;
            }
            queue_push(bt->right, &first, &last);
        }
    }
}

BinaryTree * getBinaryTreeNode(int data, BinaryTree *T) {
    BinaryTree *bt = T;
    while(bt != NULL) {
        if(bt->data == data)
            return bt;
        else if(data > bt->data)
            bt = bt->right;
        else
            bt = bt->left;
    }

    return NULL;
}

BinaryTree * getBinaryTreeMinimumNode(BinaryTree *T) {
    while (T->left != NULL) {
        T = T->left;
    }
    return T;
}

void binary_search_tree_delete_helper(int data, BinaryTree **T, BinaryTree *bt) {
    // deleting a node with no children
    if(bt->left == NULL && bt->right == NULL) {
        if(binary_tree_size(*T) == 1) {
            *T = NULL;
            free(*T);
            return;
        }

        // setting the child of the current node parent to null
        if(bt->root->left == bt) {
            bt->root->left = NULL;
            free(bt);
            return;
        } else {
            bt->root->right = NULL;
            free(bt);
            return;
        }
    }

    // deleting a node with two children
    // (Approach: replacing the current node with the minimum of the right subtree.
    if (bt->left != NULL && bt->right != NULL)
    {
        // find the inorder successor node of bt
        BinaryTree* successor = getBinaryTreeMinimumNode(bt->right);
        // store successor value
        int val = successor->data;
        // recursively deleting the successor node that will only have at most one child (right child)
        binary_search_tree_delete(successor->data, T);
        // copy value of the successor to the current node
        bt->data = val;
        return;
    }

    // deleting a node with one child - (Approach: replacing the node with its child)
    if(bt->left != NULL) {
        bt->data = bt->left->data;
        bt->left = NULL;
        free(bt->left);
    }
    else {
        bt->data = bt->right->data;
        bt->right = NULL;
        free(bt->right);
    }
}

void binary_search_tree_delete(int data, BinaryTree **T) {
    if (*T == NULL) {
        printf("The tree is empty!\n");
        return;
    }

    BinaryTree *bt = getBinaryTreeNode(data, *T);
    if (bt == NULL) {
        printf("Data node not found!\n");
        return;
    }

    binary_search_tree_delete_helper(data, T, bt);
}