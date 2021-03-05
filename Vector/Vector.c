//
// Created by Abdolrahman on 3/5/2021.
//
#include <stdio.h>
#include <stdlib.h>

#include "Vector.h"

int vector_push(Vector **first, Vector **last, void *v) {
    if(*first == NULL) {
        *first = (Vector *) malloc(sizeof(Vector));
        *first = *last;
        (*first)->data = v;
        return 1;
    }


    return 1;
}