#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "CLinkedList.h"
#include "Employee.h"

void printInfo(Employee *pemp) {
    printf("[num: %d, name: %s]\n", pemp->num, pemp->name);
}

char *WhoIsTurn(List *plist, char *name, int day) {
    int i, j;

    Employee *p = (Employee *)malloc(sizeof(Employee));

    LFirst(plist, &p);
    if(strcmp(p->name, name)==0) {
        for(j = 0; j < day; j++) {
            LNext(plist, &p);
        }
        return p->name;
    }


    for(i = 0; i < LCount(plist) - 1; i++) {
        LNext(plist, &p);
        if(strcmp(p->name, name)==0) {
            for(j = 0; j < day; j++) {
                LNext(plist, &p);
            }
            return p->name;
        }
    } // 이상이상

}

int main() {
    Employee * pemp;
    List list;
    ListInit(&list);
    int flag=1;
    int num, day;
    char name[50];
    while (flag==1) {
        pemp = (Employee *) malloc(sizeof (Employee));
        printf("num: ");
        scanf("%d", &num);
        printf("name: ");
        scanf("%s", name);

        pemp->num = num;
        strcpy(pemp->name, name);

        LInsert(&list, pemp);

        printf("flag : ");
        scanf("%d", &flag);
    }

    if (LFirst(&list, &pemp)) {
        printInfo(pemp);
        for (int i=0; i<list.numOfData-1; i++) {
            LNext(&list, &pemp);
            printInfo(pemp);
        }
    }

    printf("name: ");
    scanf("%s", name);
    printf("day: ");
    scanf("%d", &day);
    printf("%s이(가) 당직을 선 후로 %d일 뒤에 당직을 서는 사람: %s\n", name, day, WhoIsTurn(&list, name, day));




    return 0;
}