#include <stdio.h>
#include "DBCLinkedList.h"

int main(void) {
    // ���� ���� ����Ʈ�� ���� �� �ʱ�ȭ
    List list;
    int data, i, numNode;
    ListInit(&list);

    // ����Ʈ�� 5���� �����͸� ����
    LInsert(&list, 3);
    LInsert(&list, 4);
    LInsert(&list, 5);
    LInsertFront(&list, 2);
    LInsertFront(&list, 1);


    // ����Ʈ�� ����� �����͸� ���� 3ȸ ���
    if(LFirst(&list, &data)) {
        printf("%d ", data);

        for(i = 0; i < LCount(&list) * 3 - 1; i++) {
            if(LNext(&list, &data))
                printf("%d ", data);
        }
    }
    printf("\n");

    if(LFirst(&list, &data)) {
        printf("%d ", data);

        for(i = 0; i < LCount(&list) * 3 - 1; i++) {
            if(LPrev(&list, &data))
                printf("%d ", data);
        }
    }
    printf("\n");

    // 2�� ����� ã�Ƽ� ��� ����
    numNode = LCount(&list);

    if(numNode != 0) {
        LFirst(&list, &data);
        if(data%2 == 0)
            LRemove(&list);

        for(i = 0; i < numNode - 1; i++) {
            LNext(&list, &data);
            if(data%2 == 0)
                LRemove(&list);
        }
    }

    if(LFirst(&list, &data)) {
        printf("%d ", data);

        for(i = 0; i < LCount(&list) - 1; i++) {
            if(LNext(&list, &data))
                printf("%d ", data);
        }
    }

    printf("\n");

    return 0;
}