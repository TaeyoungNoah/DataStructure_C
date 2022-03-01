#ifndef __C_LINKED_LIST_H__
#define __C_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

#include "Employee.h"

typedef Employee  * EData;

typedef struct _node {
    EData data;
    struct _node *next;
} Node;

typedef struct _CLL {
    Node *tail;
    Node *cur;
    Node *before;
    int numOfData;
} CList;

typedef CList List;

void ListInit(List *plist);
void LInsert(List *plist, EData data);
void LInsertFront(List *plist, EData data);

int LFirst(List *plist, EData *pdata);
int LNext(List *plist, EData *pdata);

EData LRemove(List *plist);
int LCount(List *plist);

#endif