#include <stdio.h>
#include "CircularQueue.h"

int main(void) {
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