// Created by Abdolrahman on 3/2/2021.

#ifndef DATA_STRUCTURES_SIMPLE_STACK_H
#define DATA_STRUCTURES_SIMPLE_STACK_H

typedef struct SimpleStack SimpleStack;
struct SimpleStack {
    int data;
    struct SimpleStack* next;
    struct SimpleStack* prev;
};

extern int _stack_count;
extern SimpleStack *_stack_first;
extern SimpleStack *_stack_last;

SimpleStack* simple_stack_init();
void simple_stack_push(int data);
int simple_stack_pop();
int simple_stack_size();
void simple_stack_print();

#endif //DATA_STRUCTURES_STACK_H