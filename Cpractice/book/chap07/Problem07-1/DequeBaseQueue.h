#ifndef __DEQUE_BASE_QUEUE_H
#define __DEQUE_BASE_QUEUE_H

#include "Deque.h"

typedef struct _dbQueue {
    Deque *pdeque;
} DBQueue;

typedef DBQueue Queue;

void QueueInit(Queue *pq);
int QIsEmpty(Queue *pq);

void Enqueue(Queue *pq, Data data);
Data Dequeue(Queue *pq);
Data QPeek(Queue *pq);

#endif
