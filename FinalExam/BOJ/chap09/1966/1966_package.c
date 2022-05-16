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
        scanf("%d %d", &N, &M);
        for (int j=0; j<N; j++) {
            scanf("%d", &temp);
            PEnqueue(&pq, temp);
        }

        result = 0;

        for (int j=0; j<M; j++) {
            PDequeue(&pq);
            result++
        }



        while(TRUE) {
            temp = PDequeue(&pq);
            if (temp==M) {
                result++;
                break;
            }
            result++;
        }

        printf("%d\n", result);
    }



    return 0;
}