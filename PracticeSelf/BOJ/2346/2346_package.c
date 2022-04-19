#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "DBCLinkedList.h"
#include "Balloon.h"

#define MAX 1000
int main() {
    List list;
    ListInit(&list);
    int N, inputNum, temp, resultIdx;
    int result[MAX];
    Balloon *data;
    scanf("%d", &N);


    for (int i=1; i<=N; i++) {
        scanf("%d", &inputNum);
        data = MakeBalloon(i,inputNum);
        LInsert(&list, data);
    }

    resultIdx = 0;

    if (LFirst(&list, &data)) {
        temp = data->num;
        result[resultIdx]=data->count;
        resultIdx++;
        data->num=0;
        if (temp>0) {
            for (int i=0; i<temp; i++) {
                LNext(&list, &data);
                if (data->num==0)
                    i--;
                }
        }
        else {
            temp = abs(temp);
            for (int i=0; i<temp; i++) {
                LPrev(&list, &data);
                if (data->num==0)
                    i--;
            }
        }
        temp = data->num;
        result[resultIdx]=data->count;
        resultIdx++;
        data->num=0;


        for (int i=0; i<N-2; i++) {
            if (temp>0) {
                for (int i=0; i<temp; i++) {
                    LNext(&list, &data);
                    if (data->num==0)
                        i--;
                }
            }
            else {
                temp = abs(temp);
                for (int i=0; i<temp; i++) {
                    LPrev(&list, &data);
                    if (data->num==0)
                        i--;
                }
            }
            temp = data->num;
            result[resultIdx]=data->count;
            resultIdx++;
            data->num=0;
        }
    }
    for (int i=0; i<N; i++) {
        printf("%d ", result[i]);
    }


    return 0;
}