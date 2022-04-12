#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node {
    int data;
    struct _node *next;
} Node;

typedef struct _CLL {
    Node *tail;
    Node *cur;
    Node *before;
    int numOfData;
} CList;

typedef CList List;

void ListInit(List *plist) {
    plist->tail = NULL;
    plist->cur = NULL;
    plist->before = NULL;
    plist->numOfData = 0;
}

void LInsert(List *plist, Data data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    if(plist->tail == NULL) {
        plist->tail = newNode;
        newNode->next = newNode;
    }
    else {
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
        plist->tail = newNode;
    }

    (plist->numOfData)++;
}

int LFirst(List *plist, Data *pdata) {
    if(plist->tail == NULL)
        return FALSE;

    plist->before = plist->tail;
    plist->cur = plist->tail->next;

    *pdata = plist->cur->data;
    return TRUE;
}

int LNext(List *plist, Data *pdata) {
    if(plist->tail == NULL)
        return FALSE;

    plist->before = plist->cur;
    plist->cur = plist->cur->next;

    *pdata = plist->cur->data;
    return TRUE;
}

Data LRemove(List *plist) {
    Node *rpos = plist->cur;
    int rdata = rpos->data;

    if(rpos == plist->tail) {
        if(plist->tail == plist->tail->next)
            plist->tail = NULL;
        else
            plist->tail = plist->before;
    }

    plist->before->next = plist->cur->next;
    plist->cur = plist->before;

    (plist->numOfData)--;

    free(rpos);
    return rdata;
}


void makeList(List *plist, int num) {
    for (int i=1; i<=num; i++) {
        LInsert(plist, i);
    }
}

Data popFirst(List *plist, int num) {
    Data data;
    LFirst(plist, &data);
    for (int count=1; count<num; count++) {
        LNext(plist, &data);
    }
    data = LRemove(plist);
    return data;
}

Data popLater(List *plist, int num) {
    Data data;
    for (int count=0; count<num; count++) {
        LNext(plist, &data);
    }
    data = LRemove(plist);
    return data;
}

int main() {
    int N, K, count;
    List list;
    ListInit(&list);
    scanf("%d", &N);
    scanf("%d", &K);

    makeList(&list, N);

    printf("<");
    printf("%d", popFirst(&list,K));
    for (count = 1; count<N; count++) {
        printf(", %d", popLater(&list,K));
    }
    printf(">");
    return 0;
}


