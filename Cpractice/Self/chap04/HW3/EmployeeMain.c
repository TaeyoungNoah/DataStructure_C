#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "CLinkedList.h"
#include "Employee.h"

char *whoIsNext(List *plist, char *name, int day) {
    int i, j;
    Employee *p = (Employee *)malloc(sizeof(Employee));

    LFirst(plist, &p);
    if(strcmp(p->name, name)!=0) {
        for(i = 0; i < LCount(plist) - 1; i++) {
            LNext(plist, &p);
            if(strcmp(p->name, name)==0) {
                break;
            }
        }

    }

    for(i = 0; i < day; i++) {
        LNext(plist, &p);
    }

    return p->name;
}

void printInfo(Employee *pemp) {
    printf("이름: %s\n사번: %d\n\n", pemp->name, pemp->num);
}

int main() {
    // - 직원 정보를 등록할 수 있다. 직원정보는 사번과 이름으로 구성된다.
    // - 직원은 순서대로 돌아가면서 당직을 선다.
    int i;
    Employee *pemp;

    // 리스트의 생성 및 초기화
    List list;
    ListInit(&list);

    // 4명의 데이터 저장
    pemp = (Employee *) malloc(sizeof(Employee));
    pemp->num = 1;
    stpcpy(pemp->name, "1번직원");
    LInsert(&list, pemp);

    pemp = (Employee *) malloc(sizeof(Employee));
    pemp->num = 2;
    stpcpy(pemp->name, "2번직원");
    LInsert(&list, pemp);

    pemp = (Employee *) malloc(sizeof(Employee));
    pemp->num = 3;
    stpcpy(pemp->name, "3번직원");
    LInsert(&list, pemp);

    pemp = (Employee *) malloc(sizeof(Employee));
    pemp->num = 4;
    stpcpy(pemp->name, "4번직원");
    LInsert(&list, pemp);

    // 순서대로 한바퀴 출력하기
    if (LFirst(&list, &pemp)) {
        printInfo(pemp);

        for(i = 0; i < LCount(&list) - 1; i++) {
            if (LNext(&list, &pemp)) {
                printInfo(pemp);
            }
        }

    }

    char tempName[30];
    stpcpy(tempName, "4번직원");

    printf("%s이(가) 당직을 선 후로 %d일 뒤에 당직을 서는 사람: %s\n", tempName, 7, whoIsNext(&list, tempName, 7));
    return 0;
}