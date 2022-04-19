#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "CLinkedList.h"
#include "Employee.h"

char *WhoIsTurn(List *plist, char *name, int day) {
    int i, j;

    Employee *p = (Employee *)malloc(sizeof(Employee));
    LFirst(plist, &p);
    if(!strcmp(p->name, name)) {
        for(j = 0; j < day; j++) {
            LNext(plist, &p);
        }
        return p->name;
    }
    for(i = 0; i < LCount(plist) - 1; i++) {
        LNext(plist, &p);
        if(!strcmp(p->name, name)) {
            for(j = 0; j < day; j++) {
                LNext(plist, &p);
            }
        }
    }

    return p->name;
}


int main(void) {
    Employee employee[] = {{1, "A"}, {2, "B"},{3, "C"}, {4, "D"}}, *p = employee;
    int i;
    List list;
    ListInit(&list);

    for(i = 0; i < sizeof(employee) / sizeof(Employee); i++, p++) {
        LInsert(&list, p);
    }

    if(LFirst(&list, &p)) {
        printf("[���]: %d\n", p->num);
        printf("[�̸�]: %s\n\n", p->name);

        for(i = 0; i < LCount(&list) * 3 - 1; i++) {
            if(LNext(&list, &p)) {
                printf("[���]: %d\n", p->num);
                printf("[�̸�]: %s\n\n", p->name);
            }
        }
    }
    printf("\n");

    printf("%s��(��) ������ �� �ķ� %d�� �ڿ� ������ ���� ���: %s\n", employee[0].name, 10, WhoIsTurn(&list, employee[0].name, 10));

    return 0;
}