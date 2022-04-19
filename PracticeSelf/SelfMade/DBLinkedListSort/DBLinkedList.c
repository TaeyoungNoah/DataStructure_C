#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedList.h"

void ListInit(List *plist) {
    plist->head = NULL;
    plist->comp = NULL;
    plist->numOfData = 0;
}


void FInsert(List *plist, LData data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = plist->head;
    if(plist->head != NULL)
        plist->head->prev = newNode;

    newNode->prev = NULL;
    plist->head = newNode;

    (plist->numOfData)++;
}

void SInsert(List *plist, LData data) {
    Node *pred = plist->head;
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    while(pred != NULL && plist->comp(data, pred->data) != 0) {
        pred = pred->next;
    }
    if (plist->head==NULL) {
        newNode->next = plist->head;
        newNode->prev = NULL;
        plist->head = newNode;
    }
    else {
        newNode->next = pred->next;
        newNode->prev = pred;

        if (newNode->next != NULL) {
            newNode->next->prev = newNode;
            newNode->prev->next = newNode;
        }
        else {
            newNode->prev->next = newNode;
        }

        (plist->numOfData)++;
    }

}

void LInsert(List *plist, LData data) {
    if(plist->comp == NULL)
        FInsert(plist, data);
    else
        SInsert(plist, data);
}

int LFirst(List *plist, LData *pdata) {
    if(plist->head == NULL)
        return FALSE;

    plist->cur = plist->head;
    *pdata = plist->cur->data;

    return TRUE;
}

int LNext(List *plist, LData *pdata) {
    if(plist->cur->next == NULL)
        return FALSE;

    plist->cur = plist->cur->next;
    *pdata = plist->cur->data;

    return TRUE;
}

int LPrevious(List *plist, LData *pdata) {
    if(plist->cur->prev == NULL)
        return FALSE;

    plist->cur = plist->cur->prev;
    *pdata = plist->cur->data;

    return TRUE;
}

int LCount(List *plist) {
    return plist->numOfData;
}

void SetSortRule(List *plist, int (*comp)(LData d1, LData d2)) {
    plist->comp = comp;
}