#include <stdio.h>
#include "ArrayList.h"

int main(void) {

    //ArrayList�� ���� �� �ʱ�ȭ
    char data;
    List list;
    ListInit(&list);

    //5�� ������ ����
    LInsert(&list, 'a');
    LInsert(&list, 'b');
    LInsert(&list, 'c');
    LInsert(&list, 'c');
    LInsert(&list, 'd');

    //����� �������� ��ü ���
    printf("���� �������� �� : %d\n", LCount(&list));
    if(LFirst(&list, &data)) {
        printf("%c ", data);

        while(LNext(&list, &data)) {
            printf("%c ", data);
        }
    }
    printf("\n\n");

    //���� 22�� Ž���Ͽ� ��� ����
    if(LFirst(&list, &data)) {
        if(data == 'c')
            LRemove(&list);

        while(LNext(&list, &data)) {
            if(data == 'c')
                LRemove(&list);
        }
    }

    //���� �� ���� ������ ��ü ���
    printf("���� �������� �� : %d\n", LCount(&list));
    if(LFirst(&list, &data)) {
        printf("%c ", data);

        while(LNext(&list, &data)) {
            printf("%c ", data);
        }
    }
    printf("\n\n");

    return 0;
}