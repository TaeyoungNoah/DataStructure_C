#include <stdio.h>
#include "ArrayList.h"

int main(void) {
    /*
    == 책의 예시 ==

    //ArrayList의 생성 및 초기화
    int data;
    List list;
    ListInit(&list);

    //5개 데이터 저장
    LInsert(&list, 11);
    LInsert(&list, 11);
    LInsert(&list, 22);
    LInsert(&list, 22);
    LInsert(&list, 33);

    //저장된 데이터의 전체 출력
    printf("현재 데이터의 수 : %d\n", LCount(&list));
    if(LFirst(&list, &data)) {
        printf("%d ", data);

        while(LNext(&list, &data)) {
            printf("%d ", data);
        }
    }
    printf("\n\n");

    //숫자 22를 탐색하여 모두 삭제
    if(LFirst(&list, &data)) {
        if(data == 22)
            LRemove(&list);

        while(LNext(&list, &data)) {
            if(data == 22)
                LRemove(&list);
        }
    }

    //삭제 후 남은 데이터 전체 출력
    printf("현재 데이터의 수 : %d\n", LCount(&list));
    if(LFirst(&list, &data)) {
        printf("%d ", data);

        while(LNext(&list, &data)) {
            printf("%d ", data);
        }
    }
    printf("\n\n");

    return 0;
     */

    // 문제 03-1 (1)
    int data;
    List list;
    ListInit(&list);

    LInsert(&list, 1);
    LInsert(&list, 2);
    LInsert(&list, 3);
    LInsert(&list, 4);
    LInsert(&list, 5);
    LInsert(&list, 6);
    LInsert(&list, 7);
    LInsert(&list, 8);
    LInsert(&list, 9);



    // 문제 03-1 (2)
    int sum = 0;

    if(LFirst(&list, &data)) {
        sum+=data;
        while(LNext(&list, &data)) {
            sum+=data;
        }
    }
    printf("sum = %d \n", sum);

    // 문제 03-1 (3)
    if(LFirst(&list, &data)) {
        if(data % 2 == 0 || data % 3 == 0)
            LRemove(&list);
        while(LNext(&list, &data)) {
            if(data % 2 == 0 || data % 3 == 0)
                LRemove(&list);
        }
    }

    // 문제 03-1 (3)
    printf("현재 데이터의 수 : %d\n", LCount(&list));
    if(LFirst(&list, &data)) {
        printf("%d ", data);

        while(LNext(&list, &data)) {
            printf("%d ", data);
        }
    }

}