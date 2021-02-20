// Created by Abdolrahman on 2/19/2021.
#include <stdlib.h>
#include <stdio.h>
#include "Queue.h"

Queue* _queue_init() {
    Queue *q = (Queue *) malloc(sizeof(Queue));
    q->data = 0;
    q->next = NULL;
    return q;
}

void queue_push(int data, Queue **first, Queue **last) {
    if(*first == NULL) {
        *first = *last = _queue_init();
        (*first)->data = data;
    }
    else if((*first)->next == NULL) {
        Queue *q = _queue_init();
        q->data = data;
        (*first)->next = q;
        *last = q;
    }
    else {
        Queue *q = _queue_init();
        q->data = data;
        (*last)->next = q;
        *last = q;
    }
}

int queue_pop(Queue **first, Queue **last) {
    if(*first == NULL) {
        printf("The queue is empty!\n");
        return 0;
    }

    if((*first)->next == NULL) {
        int data = (*first)->data;
        *first = *last = NULL;
        return data;
    }

    Queue *q = *first;
    int data = q->data;
    *first = (*first)->next;
    free(q);    // After being done with everything, the no longer needed node can be deallocated from the memory.
    return data;
}

int queue_size(Queue *first) {
    if(first == NULL) {
        printf("The queue is empty!\n");
        return 0;
    }

    Queue *q = first;
    int count = 0;
    while(q != NULL) {
        count++;
        q = q->next;
    }

    return count;
}

void queue_print(Queue *first) {
    if(first == NULL) {
        printf("The queue is empty!\n");
        return;
    }

    Queue *q = first;
    printf("Queue values:\n[");
    while(q->next != NULL) {
        printf("%d,", q->data);
        q = q->next;
    }
    printf("%d]\n",q->data);
}