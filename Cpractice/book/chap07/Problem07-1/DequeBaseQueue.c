#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"
#include "DequeBaseQueue.h"

void QueueInit(Queue *pq) {
    pq->pdeque = (Deque *) malloc(sizeof(Deque));
    DequeInit(pq->pdeque);
}

int QIsEmpty(Queue *pq) {
    return DQIsEmpty(pq->pdeque);
}

void Enqueue(Queue *pq, Data data) {
    DQAddFirst(pq->pdeque, data);
}

Data Dequeue(Queue *pq) {
    return DQRemoveFirst(pq->pdeque);
}

Data QPeek(Queue *pq) {
    return DQPeekFirst(pq->pdeque);
}
