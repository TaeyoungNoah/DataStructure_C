#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NameCard.h"
#include "DLinkedList.h"

int WhoIsPrecede(NameCard data1, NameCard data2) {
    if (strcmp(data1.name, data2.name)<0) // strcmp : data1.name < data2.name �̸� ������ ��ȯ��
        return 0;
    else
        return 1;
}

int main() {
    // �ʿ��� ���� ���� �� List �ʱ�ȭ
    NameCard *nameCard;
    List list;
    ListInit(&list);
    SetSortRule(&list, WhoIsPrecede); // ���� ���� ����
    int flag = 0; // �Է��� ��� ������ ������ �Ǵ��ϱ� ���� ���� ����
    char name[30];
    char phone[30];

    // 1. ����ڷκ��� ������ ������ ������ �޾� List�� ����
    printf("\n============no.1=============\n");
    while (flag != 1) {
        printf("Enter the name and phone number of the user to be saved.\n");
        printf("name : ");
        scanf("%s", name);
        printf("phone : ");
        scanf("%s", phone);

        nameCard = MakeNameCard(name, phone);
        LInsert(&list, nameCard);
        printf("--save complete--\n");

        printf("keep save : 0, stop save : 1 = ");
        scanf("%d", &flag);
    }


    // 2. Ư�� �̸��� ������� Ž���� �����Ͽ�, �� ����� ������ Ž��
    printf("\n============no.2=============\n");
    printf("Please enter the name of the object you want to search for : ");
    scanf("%s", name);
    if (LFirst(&list, &nameCard)) {
        if (!NameCompare(nameCard, name)) // NameCompare : �� ������ ���� ������ 0�� �������� �̿�
            ShowNameCardInfo(nameCard);

        while (LNext(&list, &nameCard)) {
            if (!NameCompare(nameCard, name)) // NameCompare : �� ������ ���� ������ 0�� �������� �̿�
                ShowNameCardInfo(nameCard);
        }
    }

    // 3. Ư�� �̸��� ������� Ž���� �����Ͽ�, �� ����� ��ȭ��ȣ ������ ����
    printf("\n============no.3=============\n");
    printf("The name of the person whose phone number you want to change, \nPlease enter the phone number to change.\n");
    printf("name : ");
    scanf("%s", name);
    printf("phone : ");
    scanf("%s", phone);

    if (LFirst(&list, &nameCard)) {
        if (!NameCompare(nameCard, name)) {
            printf("--change complete--\n");
            printf("before : ");
            ShowNameCardInfo(nameCard); // ���� �� ���� ���

            ChangePhoneNum(nameCard, phone); // ����
            printf("after : ");
            ShowNameCardInfo(nameCard); // ���� �� ���� ���
        }

        while (LNext(&list, &nameCard)) {
            if (!NameCompare(nameCard, name)) {
                printf("--change complete--\n");
                printf("before : ");
                ShowNameCardInfo(nameCard); // ���� �� ���� ���

                ChangePhoneNum(nameCard, phone); // ����
                printf("after : ");
                ShowNameCardInfo(nameCard); // ���� �� ���� ���
            }
        }
    }

    // 4. Ư�� �̸��� ������� Ž���� �����Ͽ�, �� ����� ������ ����
    printf("\n============no.4=============\n");
    printf("Please enter the name of the object you want to delete.\n");
    printf("name : ");
    scanf("%s", name);
    if (LFirst(&list, &nameCard)) {
        if (!NameCompare(nameCard, name)) {
            nameCard = LRemove(&list); // ����
            printf("--delete complete--\n");
            free(nameCard); // �޸� ����
        }
        while (LNext(&list, &nameCard)) {
            if (!NameCompare(nameCard, name)) {
                nameCard = LRemove(&list); // ����
                printf("--delete complete--\n");
                free(nameCard); // �޸� ����
            }
        }
    }

    // 5. �����ִ� ��ü ���� ���
    printf("\n============no.5=============\n");
    if (LFirst(&list, &nameCard)) {
        ShowNameCardInfo(nameCard);
        while (LNext(&list, &nameCard)) {
            ShowNameCardInfo(nameCard);
        }
    }

    return 0;
}
