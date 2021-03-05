//
// Created by Abdolrahman on 3/5/2021.
//

#ifndef DATA_STRUCTURES_VECTOR_H
#define DATA_STRUCTURES_VECTOR_H

typedef enum VectorType VectorType;
enum VectorType {
    _INTEGER,
    _FLOAT,
    _DOUBLE,
    _CHAR,
    _STRING
};

typedef struct Vector Vector;
struct Vector {
    void *data;
    Vector *next;
    Vector *prev;
};

Vector* _vector_init();
int vector_push(Vector **first, Vector **last, void *v);
void * vector_pop(Vector **first, Vector **last);
void * vector_get(Vector *first, Vector *last, int index);
int vector_size(Vector *first);

#endif //DATA_STRUCTURES_VECTOR_H
