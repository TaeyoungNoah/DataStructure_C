#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

void QueueInit(Queue *pq) {
    pq->front = 0;
    pq->rear = 0;
}

int	QIsEmpty(Queue *pq) { // F 와 R 이 같은 곳을 가리키면 빈 것!
    if(pq->front == pq->rear)
        return TRUE;
    else
        return FALSE;
}

int NextPosIdx(int pos) { // F, R의 회전을 돕는 함수
    if(pos == QUE_LEN - 1)
        return 0; // 큐의 길이보다 하나 작은 값이 인자로 전달되면 0을 return -> 다시 맨 앞으로 보낸다!
    else
        return pos + 1; // 아니라면 그냥 옆으로 1칸 이동!
}

void Enqueue(Queue *pq, Data data) {
    if(NextPosIdx(pq->rear) == pq->front) { // R의 다음 자리가 F 인 상황은 큐가 꽉 찬 상황이므로
        printf("Queue Memory Error!\n");
        exit(-1);
    }

    pq->rear = NextPosIdx(pq->rear); // R 을 한칸 옮기고,
    pq->queArr[pq->rear] = data; // R 자리에 data 삽입
}

Data Dequeue(Queue *pq) {
    if(QIsEmpty(pq)) { // 비어있다면 뽑아낼게 없으니까
        printf("Queue Memory Error!\n");
        exit(-1);
    }

    pq->front = NextPosIdx(pq->front); // F 를 한칸 옆으로 옮기고,
    return pq->queArr[pq->front]; // 거기에 있는 데이터 반환
}

Data QPeek(Queue *pq) {
    if(QIsEmpty(pq)) { // 비어있으면 볼게 없어
        printf("Queue Memory Error!\n");
        exit(-1);
    }

    return pq->queArr[NextPosIdx(pq->front)]; // F 바로 뒤에 있는 데이터 반환, 이때 F를 옮기지 않아야 peek임

}