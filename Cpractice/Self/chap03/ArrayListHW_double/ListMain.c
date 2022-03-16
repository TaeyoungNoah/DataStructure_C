#include <stdio.h>
#include "ArrayList.h"

int main(void) {
    // double형 데이터 생성
    double data;

    // 리스트의 생성 및 초기화
    List list;
    ListInit(&list);

    // 10개의 데이터 저장
    LInsert(&list, 0.0);
    LInsert(&list, 1.1);
    LInsert(&list, 2.2);
    LInsert(&list, 3.3);
    LInsert(&list, 4.4);
    LInsert(&list, 5.5);
    LInsert(&list, 6.6);
    LInsert(&list, 7.7);
    LInsert(&list, 8.8);
    LInsert(&list, 9.9);



    // 저장된 데이터 확인
    printf("-----------삭제전----------\n");
    printf("저장된 데이터수 : %d\n", LCount(&list));
    if(LFirst(&list, &data)) {
        printf("data : %lf\n", data);
        while(LNext(&list, &data)) {
            printf("data : %lf\n", data);
        }
    }
    printf("\n");

    // 데이터 2.2 삭제
    if(LFirst(&list, &data)) {
        if(data==2.2)
            LRemove(&list);
        while(LNext(&list, &data)) {
            if(data==2.2)
                LRemove(&list);
        }
    }

    // 저장된 데이터 확인
    printf("-----------2.2 삭제후----------\n");
    printf("저장된 데이터수 : %d\n", LCount(&list));
    if(LFirst(&list, &data)) {
        printf("data : %lf\n", data);
        while(LNext(&list, &data)) {
            printf("data : %lf\n", data);
        }
    }
    printf("\n");

    // 데이터 8.8 삭제
    if(LFirst(&list, &data)) {
        if(data==8.8)
            LRemove(&list);
        while(LNext(&list, &data)) {
            if(data==8.8)
                LRemove(&list);
        }
    }

    // 저장된 데이터 확인
    printf("-----------8.8 삭제후----------\n");
    printf("저장된 데이터수 : %d\n", LCount(&list));
    if(LFirst(&list, &data)) {
        printf("data : %lf\n", data);
        while(LNext(&list, &data)) {
            printf("data : %lf\n", data);
        }
    }
    printf("\n");

}