#include "DLinkedList.h"
#include <stdlib.h>
#include <stdio.h>

void ListInit(List *plist) {
    plist->head = (Node *)malloc(sizeof(Node));
    plist->head->next = NULL;
    plist->comp = NULL;
    plist->numOfCount = 0;
}

void FInsert(List *plist, LData data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = plist->head->next;
    plist->head->next = newNode;

    (plist->numOfCount)++;
}

void SInsert(List *plist, LData data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    Node *pred = plist->head;

    newNode->data = data;

    while(pred->next != NULL && plist->comp(data, pred->next->data) != 0) {
        pred = pred->next;
    }

    newNode->next = pred->next;
    pred->next = newNode;

    (plist->numOfCount)++;
}

void LInsert(List *plist, LData data) {
    if(plist->comp == NULL)
        FInsert(plist, data);
    else
        SInsert(plist, data);
}

int LFirst(List *plist, LData *pdata) {
    if(plist->head->next == NULL)
        return FALSE;
    plist->before = plist->head;
    plist->cur = plist->head->next;

    *pdata = plist->cur->data;
    return TRUE;
}

int LNext(List *plist, LData *pdata) {
    if(plist->cur->next == NULL)
        return FALSE;
    plist->before = plist->cur;
    plist->cur = plist->cur->next;

    *pdata = plist->cur->data;
    return TRUE;
}

LData LRemove(List *plist) {
    Node *rpos = plist->cur;
    LData rdata = rpos->data;

    plist->before->next = plist->cur->next;
    plist->cur = plist->before;

    free(rpos);
    (plist->numOfCount)--;
    return rdata;
}

int LCount(List *plist) {
    return plist->numOfCount;
}

void ListDestroy(List *plist) {
    LData data;
    if (LFirst(plist, &data)) {
        LRemove(plist);

        while (LNext(plist, &data)) {
            LRemove(plist);
        }
    }
    free(plist->head);
}

void SetSortRule(List *plist, int (*comp)(LData data1, LData data2)) {
    plist->comp = comp;
}

#define STACK_LEN 1001

typedef int Data;

typedef struct _arrayStack {
    Data stackArr[STACK_LEN];
    int topIndex;
} ArrayStack;

typedef ArrayStack Stack;

void StackInit(Stack *pstack) {
    pstack->topIndex = -1;
}

int SIsEmpty(Stack *pstack) {
    if(pstack->topIndex == -1)
        return TRUE;
    else
        return FALSE;
}

void SPush(Stack *pstack, Data data) {
    pstack->topIndex += 1;
    pstack->stackArr[pstack->topIndex] = data;
}

Data SPop(Stack *pstack) {
    int rIdx;

    if(SIsEmpty(pstack)) {
        printf("Stack Memory Error!\n");
        exit(-1);
    }
    rIdx = pstack->topIndex;
    pstack->topIndex -= 1;
    return pstack->stackArr[rIdx];
}

Data SPeek(Stack *pstack) {
    if(SIsEmpty(pstack)) {
        printf("Stack Memory Error!\n");
        exit(-1);
    }

    return pstack->stackArr[pstack->topIndex];
}


typedef struct _ual {
    int numV; // 정점의 수
    int numE; // 간선의 수
    List *adjList; // 간선의 정보
    int *visitInfo; //
} ALGraph;