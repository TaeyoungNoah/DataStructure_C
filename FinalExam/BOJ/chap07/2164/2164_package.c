#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define QUE_LEN 500001

typedef int Data;

typedef struct _cQueue {
    int front;
    int rear;
    Data queArr[QUE_LEN];
} CQueue;

typedef CQueue Queue;


void QueueInit(Queue *pq) {
    pq->front = 0;
    pq->rear = 0;
}

int	QIsEmpty(Queue *pq) {
    if(pq->front == pq->rear)
        return TRUE;
    else
        return FALSE;
}

int NextPosIdx(int pos) {
    if(pos == QUE_LEN - 1)
        return 0;
    else
        return pos + 1;
}

void Enqueue(Queue *pq, Data data) {
    if(NextPosIdx(pq->rear) == pq->front) {
        printf("Queue Memory Error!\n");
        exit(-1);
    }

    pq->rear = NextPosIdx(pq->rear);
    pq->queArr[pq->rear] = data;
}

Data Dequeue(Queue *pq) {
    if(QIsEmpty(pq)) {
        printf("Queue Memory Error!\n");
        exit(-1);
    }

    pq->front = NextPosIdx(pq->front);

    return pq->queArr[pq->front];
}

Data QPeek(Queue *pq) {
    if(QIsEmpty(pq)) {
        printf("Queue Memory Error!\n");
        exit(-1);
    }

    return pq->queArr[NextPosIdx(pq->front)];
}


int main() {
    int N;
    int deqData;
    Queue q;

    scanf("%d", &N);
    QueueInit(&q);

    for (int i=1; i<=N; i++) {
        Enqueue(&q, i);
    }

    deqData = Dequeue(&q);
    while(!QIsEmpty(&q)) {
        Enqueue(&q, Dequeue(&q));
        deqData = Dequeue(&q);
    }

    printf("%d", deqData);

    return 0;
}