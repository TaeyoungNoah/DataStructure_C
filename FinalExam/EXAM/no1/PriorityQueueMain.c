#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PriorityQueue.h"

int DataPriorityComp(Work *work1, Work *work2) {
    return work1->score - work2->score;
}
int main(void) {
    int N, date, score, result, temp;
    int *day;
    PQueue pq;
    PQueueInit(&pq, DataPriorityComp);
    Work *pWork;

    day = (int *) malloc(1001* sizeof(int));
    scanf("%d", &N);
    for (int i=0; i<N; i++) { // 점수로 내림차순 정렬
        scanf("%d %d", &date ,&score);
        pWork = makeWork(date, score);
        PEnqueue(&pq, pWork);
    }

    memset(day, 0, sizeof(int) * 1001);
    result = 0;
    for (int i=0; i<N; i++) { // 가능하면 일 하기
        pWork = PDequeue(&pq);
        temp = pWork->date;
        while (temp>0) {
            if (day[temp] == 0) {
                day[temp] = 1;
                result += (pWork->score);
                break;
            }
            temp--;
        }
    }


    printf("%d", result);



    return 0;
}