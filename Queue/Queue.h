// Created by Abdolrahman on 2/18/2021.

#ifndef DATA_STRUCTURES_QUEUE_H
#define DATA_STRUCTURES_QUEUE_H

typedef struct Queue Queue;
struct Queue {
    int data;
    struct Queue* next;
};

Queue* _queue_init();
void queue_push(int data, Queue **first, Queue **last);
int queue_pop(Queue **first, Queue **last);
int queue_size(Queue *first);
void queue_print(Queue *first);

#endif //DATA_STRUCTURES_QUEUE_H
