//
// Created by Abdolrahman on 3/5/2021.
//

#ifndef DATA_STRUCTURES_VECTOR_H
#define DATA_STRUCTURES_VECTOR_H

typedef enum VectorType VectorType;
enum VectorType {
    INTEGER,
    FLOAT,
    DOUBLE,
    CHAR,
    STRING
};

typedef struct Vector Vector;
struct Vector {
    void *data;
    Vector *next;
    Vector *prev;
};

Vector* vector_init();

int vector_push(Vector **first, Vector **last, void *v);
void * vector_pop(Vector **first, Vector **last);

void * vector_get(Vector *first, int index);
void vector_set(Vector **first, Vector **last, void *data, int index);

int vector_insert(Vector **first, Vector **last, void *data, int index);
int vector_delete(Vector **first, Vector **last, int index);

int vector_size(Vector *first);

#endif //DATA_STRUCTURES_VECTOR_H
