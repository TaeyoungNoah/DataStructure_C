#include <stdio.h>
#include <stdlib.h>
#include "NameCard.h"
#include "ArrayList.h"

int main(void) {
    NameCard *nameCard;
    List list;
    ListInit(&list);

    nameCard = MakeNameCard("ȫ�浿", "010-1234-5678");
    LInsert(&list, nameCard);
    nameCard = MakeNameCard("�Ѽ���", "010-9012-3456");
    LInsert(&list, nameCard);
    nameCard = MakeNameCard("�̼���", "010-0987-6543");
    LInsert(&list, nameCard);

    printf("�̼��� ���� ���\n");
    if(LFirst(&list, &nameCard)) {
        if(!NameCompare(nameCard, "�̼���"))
            ShowNameCardInfo(nameCard);

        while(LNext(&list, &nameCard)) {
            if(!NameCompare(nameCard, "�̼���"))
                ShowNameCardInfo(nameCard);
        }
    }
    printf("\n");


    printf("�Ѽ��� ��ȭ��ȣ ����\n");
    printf("�Ѽ����� ���� ��ȭ��ȣ: 010-9012-3456\n");
    if(LFirst(&list, &nameCard)) {
        if(!NameCompare(nameCard, "�Ѽ���"))
            ChangePhoneNum(nameCard, "010-1029-3847");

        while(LNext(&list, &nameCard)) {
            if(!NameCompare(nameCard, "�Ѽ���"))
                ChangePhoneNum(nameCard, "010-1029-3847");
        }
    }
    printf("\n");

    printf("ȫ�浿 ���� ����\n");
    if(LFirst(&list, &nameCard)) {
        if(!NameCompare(nameCard, "ȫ�浿")) {
            nameCard = LRemove(&list);
            free(nameCard);
        }

        while(LNext(&list, &nameCard)) {
            if(!NameCompare(nameCard, "ȫ�浿")) {
                nameCard = LRemove(&list);
                free(nameCard);
            }
        }
    }
    printf("\n");

    printf("��ü ��� ���\n");
    if(LFirst(&list, &nameCard)) {
        ShowNameCardInfo(nameCard);

        while(LNext(&list, &nameCard)) {
            ShowNameCardInfo(nameCard);
        }
    }

    return 0;
}