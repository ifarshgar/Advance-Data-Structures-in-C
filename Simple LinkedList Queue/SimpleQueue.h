// Created by Abdolrahman on 2/18/2021.

#ifndef DATA_STRUCTURES_SIMPLE_QUEUE_H
#define DATA_STRUCTURES_SIMPLE_QUEUE_H

typedef struct SimpleQueue SimpleQueue;
struct SimpleQueue {
    int data;
    struct SimpleQueue* next;
};

extern int _queue_count;
extern SimpleQueue *_queue_first;
extern SimpleQueue *_queue_last;

SimpleQueue* simple_queue_init();
void simple_queue_push(int data);
int simple_queue_pop();
int simple_queue_size();
void simple_queue_print();

#endif //DATA_STRUCTURES_QUEUE_H