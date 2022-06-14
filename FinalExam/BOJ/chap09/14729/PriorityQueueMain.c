#include <stdio.h>
#include "PriorityQueue.h"

int DataPriorityComp(double ch1, double ch2) {
    return ch2 - ch1;
}
int main() {
    int N;
    double score;
    PQueue pq;
    PQueueInit(&pq, DataPriorityComp);

    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        scanf("%lf", &score);
        PEnqueue(&pq, score);
    }

    for (int i=0; i<7; i++) {
        printf("%lf\n", PDequeue(&pq));
    }



    return 0;
}