#include <stdio.h>
#include "DBLinkedList.h"

int WhoIsPrecede(int d1, int d2) {
    if(d1 < d2)
        return 0;
    else
        return 1;
}


int main(void) {
    List list;
    int data;

    ListInit(&list);
    SetSortRule(&list, WhoIsPrecede);

    LInsert(&list, 1);LInsert(&list, 3);
    LInsert(&list, 2);LInsert(&list, 4);
    LInsert(&list, 6);LInsert(&list, 5);
    LInsert(&list, 7);LInsert(&list, 8);

    if(LFirst(&list, &data)) {
        printf("%d ", data);

        while(LNext(&list, &data)) {
            printf("%d ", data);
        }

        while(LPrevious(&list, &data)) {
            printf("%d ", data);
        }

        printf("\n\n");
    }

    return 0;
}