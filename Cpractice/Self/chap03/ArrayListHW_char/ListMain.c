#include <stdio.h>
#include <string.h>
#include "ArrayList.h"

int main(void) {
    //ArrayList의 생성 및 초기화
    char data;
    List list;
    ListInit(&list);

    //5개 데이터 저장
    LInsert(&list, 'a');
    LInsert(&list, 'B');
    LInsert(&list, 'c');
    LInsert(&list, 'D');
    LInsert(&list, 'e');

    //저장된 데이터의 전체 출력
    printf("현재 데이터의 수 : %d\n", LCount(&list));
    if(LFirst(&list, &data)) {
        printf("%c ", data);

        while(LNext(&list, &data)) {
            printf("%c ", data);
        }
    }
    printf("\n\n");

    //char 'B'를 탐색하여 모두 삭제
    if(LFirst(&list, &data)) {
        if(data == 'B')
            LRemove(&list);

        while(LNext(&list, &data)) {
            if(data == 'B')
                LRemove(&list);
        }
    }

    //삭제 후 남은 데이터 전체 출력
    printf("현재 데이터의 수 : %d\n", LCount(&list));
    if(LFirst(&list, &data)) {
        printf("%c ", data);

        while(LNext(&list, &data)) {
            printf("%c ", data);
        }
    }
    printf("\n\n");

    return 0;


}