// Created by Abdolrahman on 2/18/2021.

#ifndef DATA_STRUCTURES_QUEUE_H
#define DATA_STRUCTURES_QUEUE_H

typedef struct Queue Queue;
struct Queue {
    void *data;
    struct Queue* next;
};

typedef enum QueueDataType QueueDataType;
enum QueueDataType {
    _Integer,
    _Float,
    _Double,
    _Char,
    _String,
    _BinaryTree,
};

Queue* _queue_init();
void queue_push(void *data, Queue **first, Queue **last);
void * queue_pop(Queue **first, Queue **last);
int queue_size(Queue *first);
void queue_print(Queue *first, QueueDataType type);

#endif //DATA_STRUCTURES_QUEUE_H
