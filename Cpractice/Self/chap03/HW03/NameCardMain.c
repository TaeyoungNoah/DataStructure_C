#include <stdio.h>
#include <stdlib.h>
#include "NameCard.h"
#include "ArrayList.h"

int main() {
    // 필요한 변수 선언 및 List 초기화
    NameCard *nameCard;
    List list;
    ListInit(&list);
    int flag = 0;
    char name[30];
    char phone[30];

    // 1. 사용자로부터 저장할 명함의 내용을 받아 List에 저장
    printf("\n============1번=============\n");
    while (flag != 1) {
        printf("저장할 사용자의 이름과 전화번호를 입력하세요.\n");
        printf("이름 : ");
        scanf("%s", name);
        printf("전화번호 : ");
        scanf("%s", phone);

        nameCard = MakeNameCard(name, phone);
        LInsert(&list, nameCard);
        printf("--저장완료--\n");

        printf("계속 저장 : 0, 저장 종료 : 1 을 입력 해주세요 : ");
        scanf("%d", &flag);
    }


    // 2. 특정 이름을 대상으로 탐색을 진행하여, 그 사람의 정보를 탐색
    printf("\n============2번=============\n");
    printf("탐색할 대상의 이름을 입력해주세요 : ");
    scanf("%s", name);
    if (LFirst(&list, &nameCard)) {
        if (!NameCompare(nameCard, name))
            ShowNameCardInfo(nameCard);

        while (LNext(&list, &nameCard)) {
            if (!NameCompare(nameCard, name))
                ShowNameCardInfo(nameCard);
        }
    }

    // 3. 특정 이름을 대상으로 탐색을 진행하여, 그 사람의 전화번호 정보를 변경
    printf("\n============3번=============\n");
    printf("전화번호를 변경하고자 하는 대상의 이름과, \n변경할 전화번호를 입력해주세요.\n");
    printf("이름 : ");
    scanf("%s", name);
    printf("전화번호 : ");
    scanf("%s", phone);

    if (LFirst(&list, &nameCard)) {
        if (!NameCompare(nameCard, name)) {
            printf("--변경 완료--\n");
            printf("변경 전 : ");
            ShowNameCardInfo(nameCard);

            ChangePhoneNum(nameCard, phone);
            printf("변경 후 : ");
            ShowNameCardInfo(nameCard);
        }

        while (LNext(&list, &nameCard)) {
            if (!NameCompare(nameCard, name)) {
                printf("--변경 완료--\n");
                printf("변경 전 : ");
                ShowNameCardInfo(nameCard);

                ChangePhoneNum(nameCard, phone);
                printf("변경 후 : ");
                ShowNameCardInfo(nameCard);
            }
        }
    }

    // 4. 특정 이름을 대상으로 탐색을 진행하여, 그 사람의 정보를 삭제
    printf("\n============4번=============\n");
    printf("삭제하고자 하는 대상의 이름을 입력해주세요.\n");
    printf("이름 : ");
    scanf("%s", name);
    if (LFirst(&list, &nameCard)) {
        if (!NameCompare(nameCard, name)) {
            nameCard = LRemove(&list);
            printf("--삭제완료--");
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

    // 5. 남아있는 전체 정보 출력
    printf("============5번=============\n");
    if (LFirst(&list, &nameCard)) {
        ShowNameCardInfo(nameCard);
        while (LNext(&list, &nameCard)) {
            ShowNameCardInfo(nameCard);
        }
    }

    return 0;
}

