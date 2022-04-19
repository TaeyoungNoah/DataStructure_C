#ifndef __DB_LINKED_LIST_H__
#define __DB_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

#include "NameCard.h"

typedef NameCard * LData;

typedef struct _node {
    LData data;
    struct _node *next;
    struct _node *prev;
} Node;

typedef struct _DBLinkedList {
    Node *head;
    Node *cur;
    int numOfData;
    int (*comp)(LData d1, LData d2);
} DBLinkedList;
typedef DBLinkedList List;

void ListInit(List *plist);
void LInsert(List *plist, LData data);

int LFirst(List *plist, LData *pdata);
int LNext(List *plist, LData *pdata);
int LPrevious(List *plist, LData *pdata);

LData LRemove(List *plist);

int LCount(List *plist);


void SetSortRule(List *plist, int (*comp)(LData d1, LData d2));

#endif