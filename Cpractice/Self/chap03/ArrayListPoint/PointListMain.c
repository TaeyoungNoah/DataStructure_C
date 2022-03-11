#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Point.h"

int main(void) {
    // 리스트 생성 및 초기화
    List list;
    ListInit(&list);

    // Point를 담을 수 있는 변수 선언
    Point compPos;
    Point *ppos;

    // 데이터 담기
    ppos = (Point *)malloc(sizeof(Point));
    SetPointPos(ppos, 2, 1);
    LInsert(&list, ppos);

    ppos = (Point *)malloc(sizeof(Point));
    SetPointPos(ppos, 2, 2);
    LInsert(&list, ppos);

    ppos = (Point *)malloc(sizeof(Point));
    SetPointPos(ppos, 3, 1);
    LInsert(&list, ppos);

    ppos = (Point *)malloc(sizeof(Point));
    SetPointPos(ppos, 3, 2);
    LInsert(&list, ppos);

    // 저장 후 출력
    printf("현재 데이터의 수 : %d\n", LCount(&list));
    if(LFirst(&list, &ppos)) {
        ShowPointPos(ppos);

        while(LNext(&list, &ppos)) {
            ShowPointPos(ppos);
        }
    }


    compPos.xpos = 2;
    compPos.ypos = 0;

    // [2, 0]과 x 성분이 동일한 데이터 제거
    if(LFirst(&list, &ppos)) {
        if(PointComp(ppos, &compPos) == 1) {
            ppos = LRemove(&list);
            free(ppos);
        }

        while(LNext(&list, &ppos)) {
            if(PointComp(ppos, &compPos) == 1) {
                ppos = LRemove(&list);
                free(ppos);
            }
        }
    }

    printf("\n");

    printf("현재 데이터의 수 : %d\n", LCount(&list));
    if(LFirst(&list, &ppos)) {
        ShowPointPos(ppos);

        while(LNext(&list, &ppos)) {
            ShowPointPos(ppos);
        }
    }

    return 0;



}