#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "CLinkedList.h"

void makeList(List *plist, int num) {
    for (int i=1; i<=num; i++) {
        LInsert(plist, i);
    }
}

Data popFirst(List *plist, int num) {
    Data data;
    LFirst(plist, &data);
    for (int i=1; i<num; i++) {
        LNext(plist, &data);
    }
    return LRemove(plist);
}

Data popLater(List *plist, int num) {
    Data data;
    for (int i=0; i<num; i++) {
        LNext(plist, &data);
    }
    return LRemove(plist);
}

int main() {
    int N, K;
    List list;
    ListInit(&list);
    scanf("%d", &N);
    scanf("%d", &K);

    makeList(&list, N);

    printf("<");
    printf("%d", popFirst(&list, K));
    for (int i=1; i<N; i++) {
        printf(", %d", popLater(&list, K));
    }
    printf(">");

    return 0;
}