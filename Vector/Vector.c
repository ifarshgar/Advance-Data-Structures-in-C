//
// Created by Abdolrahman on 3/5/2021.
//
#include <stdio.h>
#include <stdlib.h>

#include "Vector.h"

//      _vector_init creates and initializes a new instance of the Vector struct.
Vector* _vector_init() {
    Vector *v = (Vector *) malloc(sizeof(Vector));
    v->next = NULL;
    v->prev = NULL;
    return v;
}

//  vector_push inserts a new node to the end of the vector
int vector_push(Vector **first, Vector **last, void *data) {
    if(*first == NULL) {
        *first = *last = _vector_init();
        (*first)->data = data;
        return 1;
    }
    else if((*first)->next == NULL) {
        Vector *v = _vector_init();
        v->data = data;
        v->prev = *first;
        *last = v;
        (*first)->next = *last;
        return 1;
    }
    else {
        Vector *v = _vector_init();
        v->data = data;
        v->prev = *last;
        (*last)->next = v;
        *last = v;
        return 1;
    }
}

//     vector_pop return the last node of the vector and deletes the node.
void * vector_pop(Vector **first, Vector **last) {
    if(*first == NULL) {
        printf("The vector is empty!\n");
        return NULL;
    }

    if((*first)->next == NULL) {
        void *data = (*first)->data;
        *first = *last = NULL;
        return data;
    }

    Vector *v = *last;
    void *data = v->data;
    *last = (*last)->prev;
    (*last)->next = NULL;
    free(v);    // After being done with everything, the no longer needed node can be deallocated from the memory.
    return data;
}

//     vector_get returns a certain node in the vector
void * vector_get(Vector *first, Vector *last, int index) {
    if(index < 0 || index >= vector_size(first)) {
        printf("Index is out of bound!\n");
        return NULL;
    }

    int i = 0;
    while(first != NULL) {
        if(i == index) {
            void *v = first->data;
            return v;
        }
        i++;
        first = first->next;
    }

    return NULL;
}

//   vector_set modifies the value that a node is holding if the index is with in a correct range.
void vector_set(Vector **first, Vector **last, void *data, int index) {
    if(index < 0 || index >=vector_size(*first)) {
        printf("Index is out of bound!\n");
        return;
    }

    Vector *v = *first;
    int i = 0;
    while(v != NULL) {
        if(i == index) {
             v->data = data;
            break;
        }
        i++;
        v = v->next;
    }
}

//  vector_insert adds a new node to the vector at a certain index.
int vector_insert(Vector **first, Vector **last, void *data, int index) {
    int size = vector_size(*first);
    if(index < 0 || index > size) {
        printf("Index is out of bound!\n");
        return 0;
    }

    // if the insertion is supposed to happen at the end of the vector
    if(index == size)
        return vector_push(first, last, data);

    // if the insertion is supposed to happen at the beginning of the vector
    if(index == 0) {
        Vector *newNode = _vector_init();
        newNode->data = data;
        newNode->next = *first;
        (*first)->prev = newNode;
        *first = newNode;
        return 1;
    }

    // otherwise if a node has to inserted in the middle of the vector
    Vector *v = *first;
    int i = 0;
    while(v != NULL) {
        if(i == index) {
            Vector *newNode = _vector_init();
            newNode->data = data;
            newNode->next = v;
            newNode->prev = v->prev;
            v->prev = newNode;
            return 1;
        }
        i++;
        v = v->next;
    }

    return 0;
}

//  vector_delete deletes a node from the vector at a certain index.
int vector_delete(Vector **first, Vector **last, void *data, int index) {
    int size = vector_size(*first);
    if(index < 0 || index >= size) {
        printf("Index is out of bound!\n");
        return 0;
    }

    // if the insertion is supposed to happen at the end of the vector
    if(index == size-1) {
        vector_pop(first, last);
        return 1;
    }

    // if the deletion is supposed to happen at the beginning of the vector
    if(index == 0) {
        Vector *v = *first;
        (*first)->next->prev = NULL;
        *first = (*first)->next;
        free(v);
        return 1;
    }

    // otherwise if a node has to inserted in the middle of the vector
    Vector *v = *first;
    int i = 0;
    while(v != NULL) {
        if(i == index) {
            v->next->prev = v->prev;
            v->prev->next = v->next;
            free(v);
            return 1;
        }
        i++;
        v = v->next;
    }

    return 0;
}

//  vector_size gets the number of nodes in the vector
//  This function can also be written with recursion but iterative approach is obviously faster.
int vector_size(Vector *first) {
    if(first == NULL) {
        return 0;
    }

    int count = 0;
    while(first != NULL) {
        count++;
        first = first->next;
    }

    return count;
}