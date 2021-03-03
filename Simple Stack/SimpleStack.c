// Created by Abdolrahman on 3/2/2021.
#include <stdlib.h>
#include <stdio.h>
#include "SimpleStack.h"

int _stack_count = 0;
SimpleStack *_stack_first = NULL;
SimpleStack *_stack_last = NULL;

SimpleStack* simple_stack_init() {
    SimpleStack *q = (SimpleStack *) malloc(sizeof(SimpleStack));
    q->data = 0;
    q->next = NULL;
    q->prev = NULL;
    return q;
}

void simple_stack_push(int data) {
    if(_stack_first == NULL) {
        _stack_first = _stack_last = simple_stack_init();
        _stack_first->data = data;
        _stack_count++;
    }
    else if(_stack_first == _stack_last) {
        SimpleStack *q = simple_stack_init();
        q->data = data;
        q->prev = _stack_first;
        _stack_first->next = q;
        _stack_last = q;
        _stack_count++;
    } else {
        SimpleStack *q = simple_stack_init();
        q->data = data;
        q->prev = _stack_last;
        _stack_last->next = q;
        _stack_last = q;
        _stack_count++;
    }
}

int simple_stack_pop() {
    if(_stack_first == NULL) {
        printf("The stack is empty!\n");
        return 0;
    }

    if(_stack_first == _stack_last) {
        int data = _stack_first->data;
        _stack_first = _stack_last = NULL;
        _stack_count--;
        return data;
    }

    SimpleStack *q = _stack_last;
    int data = q->data;
    _stack_last = _stack_last->prev;
    _stack_last->next = NULL;
    _stack_count--;
    free(q);    // After being done with everything, the no longer needed node can be deallocated from the memory.
    return data;
}

int simple_stack_size() {
    return _stack_count;
}

void simple_stack_print() {
    if(_stack_first == NULL) {
        printf("The stack is empty!\n");
        return;
    }

    SimpleStack *q = _stack_first;
    printf("SimpleStack values:\n[");
    while(q->next != NULL) {
        printf("%d,", q->data);
        q = q->next;
    }
    printf("%d]\n",q->data);
}