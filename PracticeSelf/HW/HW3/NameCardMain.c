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
        printf("1. 사용자 입력하기  2. 검색하기  3. 수정하기  4. 삭제  5. 전체조회  6. exit : ");
        scanf("%d", &order);
        if (order==6)
            break;

        switch (order) {
            case 1:
                printf("\n============1=============\n");
                printf("사용자의 이름과 전화번호를 입력하세요.\n");
                printf("name : ");
                scanf("%s", name);
                printf("phone : ");
                scanf("%s", phone);

                nameCard = MakeNameCard(name, phone);
                LInsert(&list, nameCard);
                printf("--저장완료--\n");
                printf("\n");
                break;
            case 2:
                printf("\n============2=============\n");
                printf("조회하고자하는 이름을 입력하세요.\n");
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
                printf("변경하고자 하는 사람의 이름과, \n변경하고자 하는 번호를 입력하세요.\n");
                printf("name : ");
                scanf("%s", name);
                printf("phone : ");
                scanf("%s", phone);

                if (LFirst(&list, &nameCard)) {
                    if (!NameCompare(nameCard, name)) {
                        printf("--변경완료--\n");
                        printf("수정 전 : ");
                        ShowNameCardInfo(nameCard);

                        ChangePhoneNum(nameCard, phone);
                        printf("수정 후 : ");
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
                printf("삭제할 사람의 이름을 입력해주세요.\n");
                printf("name : ");
                scanf("%s", name);
                if (LFirst(&list, &nameCard)) {
                    if (!NameCompare(nameCard, name)) {
                        nameCard = LRemove(&list);
                        printf("--삭제완료--\n");
                        free(nameCard);
                    }
                    while (LNext(&list, &nameCard)) {
                        if (!NameCompare(nameCard, name)) {
                            nameCard = LRemove(&list);
                            printf("--삭제완료--\n");
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
