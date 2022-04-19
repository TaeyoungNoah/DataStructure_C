#include <stdio.h>
#include <stdlib.h>

#include "DBCLinkedList.h"
#include "Balloon.h"

int main() {
    List list;
    Balloon *balloon;
    int N, weight, result[1000], resultCur, temp;

    ListInit(&list);

    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        scanf("%d", &weight);
        balloon = MakeBalloon(i, weight);
        LInsert(&list, balloon);
    }

    resultCur = 0;


    if (LFirst(&list, &balloon)) {
        temp = balloon->weight;
        result[resultCur] = balloon->num;
        resultCur++;
        balloon->weight=0;

        for (int i = 0; i < N-1; i++) {
            if (temp>0) {
                for (int j=0; j<temp; j++) {
                    LNext(&list, &balloon);
                    if (balloon->weight==0)
                        j--;
                }
                temp = balloon->weight;
                result[resultCur] = balloon->num;
                resultCur++;
                balloon->weight=0;
            }
            else {
                temp = abs(temp);
                for (int j=0; j<temp; j++) {
                    LPrev(&list, &balloon);
                    if (balloon->weight==0)
                        j--;
                }
                temp = balloon->weight;
                result[resultCur] = balloon->num;
                resultCur++;
                balloon->weight=0;
            }
        }
    }

    for (int i=0; i<N; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}