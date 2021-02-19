// Created by Abdolrahman on 2/18/2021.

#ifndef DATA_STRUCTURES_QUEUE_H
#define DATA_STRUCTURES_QUEUE_H

typedef struct Queue Queue;
struct Queue {
    int data;
    struct Queue* next;
};

extern int _queue_count;
extern Queue *_queue_first;
extern Queue * _queue_last;

Queue* _queue_init();
void queue_push(int data);
int queue_pop();
int queue_size();
void queue_print();

#endif //DATA_STRUCTURES_QUEUE_H
