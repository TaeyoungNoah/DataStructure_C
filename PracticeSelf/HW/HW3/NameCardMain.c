#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NameCard.h"
#include "ArrayList.h"


int main() {
    NameCard *nameCard;
    List list;
    ListInit(&list);
    int order;
    char name[30];
    char phone[30];

    while (1) {
        printf("1. ����� �Է��ϱ�  2. �˻��ϱ�  3. �����ϱ�  4. ����  5. ��ü��ȸ  6. exit : ");
        scanf("%d", &order);
        if (order==6)
            break;

        switch (order) {
            case 1:
                printf("\n============1=============\n");
                printf("������� �̸��� ��ȭ��ȣ�� �Է��ϼ���.\n");
                printf("name : ");
                scanf("%s", name);
                printf("phone : ");
                scanf("%s", phone);

                nameCard = MakeNameCard(name, phone);
                LInsert(&list, nameCard);
                printf("--����Ϸ�--\n");
                printf("\n");
                break;
            case 2:
                printf("\n============2=============\n");
                printf("��ȸ�ϰ����ϴ� �̸��� �Է��ϼ���.\n");
                scanf("%s", name);
                if (LFirst(&list, &nameCard)) {
                    if (!NameCompare(nameCard, name))
                        ShowNameCardInfo(nameCard);

                    while (LNext(&list, &nameCard)) {
                        if (!NameCompare(nameCard, name))
                            ShowNameCardInfo(nameCard);
                    }
                }
                printf("\n");
                break;
            case 3:
                printf("\n============3=============\n");
                printf("�����ϰ��� �ϴ� ����� �̸���, \n�����ϰ��� �ϴ� ��ȣ�� �Է��ϼ���.\n");
                printf("name : ");
                scanf("%s", name);
                printf("phone : ");
                scanf("%s", phone);

                if (LFirst(&list, &nameCard)) {
                    if (!NameCompare(nameCard, name)) {
                        printf("--����Ϸ�--\n");
                        printf("���� �� : ");
                        ShowNameCardInfo(nameCard);

                        ChangePhoneNum(nameCard, phone);
                        printf("���� �� : ");
                        ShowNameCardInfo(nameCard);
                    }

                    while (LNext(&list, &nameCard)) {
                        if (!NameCompare(nameCard, name)) {
                            printf("--change complete--\n");
                            printf("before : ");
                            ShowNameCardInfo(nameCard);

                            ChangePhoneNum(nameCard, phone);
                            printf("after : ");
                            ShowNameCardInfo(nameCard);
                        }
                    }
                }
                printf("\n");
                break;
            case 4:
                printf("\n============4=============\n");
                printf("������ ����� �̸��� �Է����ּ���.\n");
                printf("name : ");
                scanf("%s", name);
                if (LFirst(&list, &nameCard)) {
                    if (!NameCompare(nameCard, name)) {
                        nameCard = LRemove(&list);
                        printf("--�����Ϸ�--\n");
                        free(nameCard);
                    }
                    while (LNext(&list, &nameCard)) {
                        if (!NameCompare(nameCard, name)) {
                            nameCard = LRemove(&list);
                            printf("--�����Ϸ�--\n");
                            free(nameCard);
                        }
                    }
                }
                printf("\n");
                break;
            case 5:
                printf("\n============5=============\n");
                if (LFirst(&list, &nameCard)) {
                    ShowNameCardInfo(nameCard);
                    while (LNext(&list, &nameCard)) {
                        ShowNameCardInfo(nameCard);
                    }
                }
                printf("\n");
                break;
        }
    }
    return 0;
}
