#include <stdio.h>

#include "DLinkedList.h"

int main() {
    List list;
    int temp, resultMax, resultIdx, tempIdx;
    int data;

    ListInit(&list);

    for (int i=0; i<9; i++) {
        scanf("%d", &temp);
        LInsert(&list, temp);
    }



    if (LFirst(&list, &data)) {
        resultMax = data;
        tempIdx = 9;
        resultIdx = tempIdx;
        for (int i=0; i<8; i++) {
            if (LNext(&list, &data)) {
                tempIdx--;
                if (data>resultMax) {
                    resultMax = data;
                    resultIdx = tempIdx;
                }

            }
        }
    }

    printf("%d\n%d", resultMax, resultIdx);

}