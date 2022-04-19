#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NameCard.h"
#include "DLinkedList.h"

int WhoIsPrecede(NameCard data1, NameCard data2) {
    if (strcmp(data1.name, data2.name)<0) // strcmp : data1.name < data2.name 이면 음수를 반환함
        return 0;
    else
        return 1;
}

int main() {
    // 필요한 변수 선언 및 List 초기화
    NameCard *nameCard;
    List list;
    ListInit(&list);
    SetSortRule(&list, WhoIsPrecede); // 정렬 기준 설정
    int flag = 0; // 입력을 계속 받을지 말지를 판단하기 위한 변수 선언
    char name[30];
    char phone[30];

    // 1. 사용자로부터 저장할 명함의 내용을 받아 List에 저장
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


    // 2. 특정 이름을 대상으로 탐색을 진행하여, 그 사람의 정보를 탐색
    printf("\n============no.2=============\n");
    printf("Please enter the name of the object you want to search for : ");
    scanf("%s", name);
    if (LFirst(&list, &nameCard)) {
        if (!NameCompare(nameCard, name)) // NameCompare : 두 인자의 값이 같으면 0을 리턴함을 이용
            ShowNameCardInfo(nameCard);

        while (LNext(&list, &nameCard)) {
            if (!NameCompare(nameCard, name)) // NameCompare : 두 인자의 값이 같으면 0을 리턴함을 이용
                ShowNameCardInfo(nameCard);
        }
    }

    // 3. 특정 이름을 대상으로 탐색을 진행하여, 그 사람의 전화번호 정보를 변경
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
            ShowNameCardInfo(nameCard); // 변경 전 정보 출력

            ChangePhoneNum(nameCard, phone); // 변경
            printf("after : ");
            ShowNameCardInfo(nameCard); // 변경 후 정보 출력
        }

        while (LNext(&list, &nameCard)) {
            if (!NameCompare(nameCard, name)) {
                printf("--change complete--\n");
                printf("before : ");
                ShowNameCardInfo(nameCard); // 변경 전 정보 출력

                ChangePhoneNum(nameCard, phone); // 변경
                printf("after : ");
                ShowNameCardInfo(nameCard); // 변경 후 정보 출력
            }
        }
    }

    // 4. 특정 이름을 대상으로 탐색을 진행하여, 그 사람의 정보를 삭제
    printf("\n============no.4=============\n");
    printf("Please enter the name of the object you want to delete.\n");
    printf("name : ");
    scanf("%s", name);
    if (LFirst(&list, &nameCard)) {
        if (!NameCompare(nameCard, name)) {
            nameCard = LRemove(&list); // 삭제
            printf("--delete complete--\n");
            free(nameCard); // 메모리 해제
        }
        while (LNext(&list, &nameCard)) {
            if (!NameCompare(nameCard, name)) {
                nameCard = LRemove(&list); // 삭제
                printf("--delete complete--\n");
                free(nameCard); // 메모리 해제
            }
        }
    }

    // 5. 남아있는 전체 정보 출력
    printf("\n============no.5=============\n");
    if (LFirst(&list, &nameCard)) {
        ShowNameCardInfo(nameCard);
        while (LNext(&list, &nameCard)) {
            ShowNameCardInfo(nameCard);
        }
    }

    return 0;
}
