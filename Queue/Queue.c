// Created by Abdolrahman on 2/19/2021.
#include <stdlib.h>
#include <stdio.h>
#include "Queue.h"

int _queue_count = 0;
Queue *_queue_first = NULL;
Queue *_queue_last = NULL;

Queue* _queue_init() {
    Queue *q = (Queue *) malloc(sizeof(Queue));
    q->data = 0;
    q->next = NULL;
    return q;
}

void queue_push(int data) {
    if(_queue_first == NULL) {
        _queue_first = _queue_last = _queue_init();
        _queue_first->data = data;
        _queue_count++;
    }
    else if(_queue_first == _queue_last) {
        Queue *q = _queue_init();
        q->data = data;
        _queue_first->next = q;
        _queue_last = q;
        _queue_count++;
    } else {
        Queue *q = _queue_init();
        q->data = data;
        _queue_last->next = q;
        _queue_last = q;
        _queue_count++;
    }
}

int queue_pop() {
    if(_queue_first == NULL) {
        printf("The queue is empty!\n");
        return 0;
    }

    if(_queue_first == _queue_last) {
        int data = _queue_first->data;
        _queue_first = _queue_last = NULL;
        _queue_count--;
        return data;
    }

    Queue *q = _queue_first;
    int data = q->data;
    _queue_first = _queue_first->next;
    _queue_count--;
    free(q);    // After being done with everything, the no longer needed node can be deallocated from the memory.
    return data;
}

int queue_size() {
    return _queue_count;
}

void queue_print() {
    if(_queue_first == NULL) {
        printf("The queue is empty!\n");
        return;
    }

    Queue *q = _queue_first;
    printf("Queue values:\n[");
    while(q->next != NULL) {
        printf("%d,", q->data);
        q = q->next;
    }
    printf("%d]\n",q->data);
}