#include <stdio.h>

#include "CLinkedList.h"

void makeList(List *list, int N) {
    for (int i=1; i<=N; i++) {
        LInsert(list, i);
    }
}

Data searchFirst(List *list, int K) {
    Data data;
    Data rdata;
    LFirst(list, &data);
    for (int i=0; i<K-1; i++) {
        LNext(list, &data);
    }
    rdata = data;
    LRemove(list);
    return rdata;
}

Data searchLater(List *list, int K) {
    Data data;
    Data rdata;
    for (int i=0; i<K; i++) {
        LNext(list, &data);
    }
    rdata = data;
    LRemove(list);
    return rdata;
}


int main() {
    List list;
    int N, K;
    ListInit(&list);
    scanf("%d %d", &N, &K);
    makeList(&list, N);

    printf("<");
    printf("%d", searchFirst(&list, K));
    for (int i=0; i<N-1; i++) {
        printf(", %d", searchLater(&list, K));
    }
    printf(">");

    return 0;
}