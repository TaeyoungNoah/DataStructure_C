#include <stdio.h>
#include <string.h>
#include "ArrayList.h"

int main(void) {
    //ArrayList의 생성 및 초기화
    char data;
    List list;
    ListInit(&list);

    // 10개 데이터 저장
    LInsert(&list, 'a');
    LInsert(&list, 'B');
    LInsert(&list, 'B');
    LInsert(&list, 'c');
    LInsert(&list, 'd');
    LInsert(&list, 'E');
    LInsert(&list, 'e');
    LInsert(&list, 'F');
    LInsert(&list, 'G');
    LInsert(&list, 'h');

    //저장된 데이터의 전체 출력
    printf("=== 삭제 전 데이터 ===");
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
    printf("=== 'B' 삭제 후 남은 데이터 출력 ===");
    printf("현재 데이터의 수 : %d\n", LCount(&list));
    if(LFirst(&list, &data)) {
        printf("%c ", data);

        while(LNext(&list, &data)) {
            printf("%c ", data);
        }
    }
    printf("\n\n");

    //char 'e'를 탐색하여 모두 삭제
    if(LFirst(&list, &data)) {
        if(data == 'e')
            LRemove(&list);

        while(LNext(&list, &data)) {
            if(data == 'e')
                LRemove(&list);
        }
    }

    //삭제 후 남은 데이터 전체 출력
    printf("=== 'E' 삭제 후 남은 데이터 출력 ===");
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