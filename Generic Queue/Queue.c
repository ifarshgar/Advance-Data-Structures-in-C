// Created by Abdolrahman on 2/19/2021.
#include <stdlib.h>
#include <stdio.h>
#include "Queue.h"
#include "../Binary Tree/BinaryTree.h"

Queue* queue_init() {
    Queue *q = (Queue *) malloc(sizeof(Queue));
    q->next = NULL;
    return q;
}

void queue_push(void *data, Queue **first, Queue **last) {
    if(*first == NULL) {
        *first = *last = queue_init();
        (*first)->data = data;
    }
    else if((*first)->next == NULL) {
        Queue *q = queue_init();
        q->data = data;
        (*first)->next = q;
        *last = q;
    }
    else {
        Queue *q = queue_init();
        q->data = data;
        (*last)->next = q;
        *last = q;
    }
}

void * queue_pop(Queue **first, Queue **last) {
    if(*first == NULL) {
        printf("The queue is empty!\n");
        return 0;
    }

    if((*first)->next == NULL) {
        void *data = (*first)->data;
        *first = *last = NULL;
        return data;
    }

    Queue *q = *first;
    void *data = q->data;
    *first = (*first)->next;
    free(q);    // After being done with everything, the no longer needed node can be deallocated from the memory.
    return data;
}

int queue_size(Queue *first) {
    if(first == NULL) {
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

void queue_print(Queue *first, QueueDataType type) {
    if(first == NULL) {
        printf("The queue is empty!\n");
        return;
    }

    Queue *q = first;
    printf("Generic Queue values:\n[");

    BinaryTree *bt;
    int *i;
    float *f;
    double *d;
    char *c;

    while(q != NULL) {
        switch(type) {
            case _Integer:
                i = (int *)q->data;
                printf("%d", *i);
                break;
            case _Float:
                f = (float *)q->data;
                printf("%f,", *f);
                break;
            case _Double:
                d = (double *)q->data;
                printf("%lf", *d);
                break;
            case _Char:
                c = (char *)q->data;
                printf("%c", *c);
                break;
            case _String:
                c = (char *)q->data;
                printf("%s", c);
                break;
            case _BinaryTree:
                bt = (BinaryTree *)q->data;
                printf("%d", bt->data);
                break;
            default:
                printf("Wrong queue data type!\n");
                exit(1);
        }

        if(q->next == NULL)
            printf("]\n");
        else
            printf(",");
        q = q->next;
    }

}