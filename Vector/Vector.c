//
// Created by Abdolrahman on 3/5/2021.
//
#include <stdio.h>
#include <stdlib.h>

#include "Vector.h"

Vector* _vector_init() {
    Vector *v = (Vector *) malloc(sizeof(Vector));
    v->next = NULL;
    v->prev = NULL;
    return v;
}

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

int vector_size(Vector *first) {
    if(first == NULL)
        return 0;
    return 1 + vector_size(first->next);
}