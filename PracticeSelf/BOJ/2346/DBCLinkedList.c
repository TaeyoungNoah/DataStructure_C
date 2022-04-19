#include <stdio.h>
#include <stdlib.h>
#include "DBCLinkedList.h"

void ListInit(List *plist) {
    plist->tail = NULL;
    plist->numOfData = 0;
}


void LInsertFront(List *plist, Data data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    if(plist->tail == NULL) {
        plist->tail = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    }
    else {
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
    }

    (plist->numOfData)++;
}

void LInsert(List *plist, Data data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    if(plist->tail == NULL) {
        plist->tail = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    }
    else {
        newNode->next = plist->tail->next;
        newNode->prev = plist->tail;

        plist->tail->next->prev = newNode;
        plist->tail->next = newNode;

        plist->tail = newNode;
    }

    (plist->numOfData)++;
}

int LFirst(List *plist, Data *pdata) {
    if(plist->tail == NULL)
        return FALSE;

    plist->cur = plist->tail->next;

    *pdata = plist->cur->data;
    return TRUE;
}

int LNext(List *plist, Data *pdata) {
    if(plist->tail == NULL)
        return FALSE;
    plist->cur = plist->cur->next;
    *pdata = plist->cur->data;
    return TRUE;
}

int LPrev(List *plist, Data *pdata) {
    if(plist->tail == NULL)
        return FALSE;
    plist->cur = plist->cur->prev;
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
            plist->tail = plist->cur->prev;
    }

    plist->cur->prev->next = plist->cur->next;
    plist->cur = plist->cur->prev;

    (plist->numOfData)--;

    free(rpos);
    return rdata;
}

void LUpdate(List *plist, Data data) {
    plist->cur->data = data;
}

int LCount(List *plist) {
    return plist->numOfData;
}