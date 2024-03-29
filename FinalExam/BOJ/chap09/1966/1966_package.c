#include <stdio.h>
#include "PriorityQueue.h"

int DataPriorityComp(int ch1, int ch2) {
    return ch1 - ch2;
}
int main(void) {
    int T, N, M, temp, result;

    scanf("%d", &T);
    for (int i=0; i<T; i++) {
        PQueue pq;
        PQueueInit(&pq, DataPriorityComp);
        scanf("%d %d", &N, &M); // data 개수, 몇번째로 나오는지 궁금한 수
        for (int i=0; i<N; i++) {
            scanf("%d", &temp);
            PEnqueue(&pq, temp);
        }
        result=0;
        while(!PQIsEmpty(&pq)) {
            result++;
            temp = PDequeue(&pq);
            if (temp==M) {
                break;
            }
        }
        printf("%d\n", result);
    }



    return 0;
}