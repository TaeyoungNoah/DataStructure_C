#include <stdio.h>
#include <stdlib.h>
#include "NameCard.h"
#include "ArrayList.h"

int main() {
    // 1. 총 3명의 전화번호 정보를, 앞서 우리가 구현한 리스트에 저장한다.
    NameCard *nameCard;
    List list;
    ListInit(&list);

    nameCard = MakeNameCard("고죠 사토루", "1234-1234");
    LInsert(&list, nameCard);
    nameCard = MakeNameCard("이타도리 유지", "1212-1212");
    LInsert(&list, nameCard);
    nameCard = MakeNameCard("이누마키 토게", "4321-4321");
    LInsert(&list, nameCard);

    // 2. 특정 이름을 대상으로 탐색을 진행하여, 그 사람의 정보를 탐색한다. (이누마키 토게)
    printf("============2번=============\n");
    if(LFirst(&list, &nameCard)) {
        if(!NameCompare(nameCard, "이누마키 토게"))
            ShowNameCardInfo(nameCard);

        while(LNext(&list, &nameCard)) {
            if(!NameCompare(nameCard, "이누마키 토게"))
                ShowNameCardInfo(nameCard);
        }
    }

    // 3. 특정 이름을 대상으로 탐색을 진행하여, 그 사람의 전화번호 정보를 변경한다. (이타도리 유지)
    printf("============3번=============\n");
    if(LFirst(&list, &nameCard)) {
        if(!NameCompare(nameCard, "이타도리 유지"))
            ChangePhoneNum(nameCard, "9876-9876");

        while(LNext(&list, &nameCard)) {
            if(!NameCompare(nameCard, "이타도리 유지"))
                ChangePhoneNum(nameCard, "9876-9876");
        }
    }
    // 확인
    if(LFirst(&list, &nameCard)) {
        if(!NameCompare(nameCard, "이타도리 유지"))
            ShowNameCardInfo(nameCard);

        while(LNext(&list, &nameCard)) {
            if(!NameCompare(nameCard, "이타도리 유지"))
                ShowNameCardInfo(nameCard);
        }
    }


    // 4. 특정 이름을 대상으로 탐색을 진행하여, 그 사람의 정보를 삭제한다. (고죠 사토루)
    printf("============4번=============\n");
    if(LFirst(&list, &nameCard)) {
        if(!NameCompare(nameCard, "고죠 사토루")) {
            nameCard = LRemove(&list);
            free(nameCard);
        }


        while(LNext(&list, &nameCard)) {
            if(!NameCompare(nameCard, "고죠 사토루")) {
                nameCard = LRemove(&list);
                free(nameCard);
            }
        }
    }

    // 5. 끝으로 남아있는 모든 사람의 전화번호 정보를 출력한다.
    printf("============5번=============\n");
    if(LFirst(&list, &nameCard)) {
        ShowNameCardInfo(nameCard);
        while(LNext(&list, &nameCard)) {
            ShowNameCardInfo(nameCard);
        }
    }

    return 0;
}