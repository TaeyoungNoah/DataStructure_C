#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "CLinkedList.h"
#include "Employee.h"

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

    
    return 0;
}