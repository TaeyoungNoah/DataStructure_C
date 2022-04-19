#ifndef __DBC_LINKED_LIST_H__
#define __DBC_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

typedef char Data;

typedef struct _node {
    struct _node *prev;
    int data;
    struct _node *next;
} Node;

typedef struct _CLL {
    Node *tail;
    Node *cur;
    int numOfData;
} CList;

typedef CList List;

void ListInit(List *plist);
void LInsert(List *plist, Data data);
void LInsertFront(List *plist, Data data);

int LFirst(List *plist, Data *pdata);
int LNext(List *plist, Data *pdata);
int LPrev(List *plist, Data *pdata);

Data LRemove(List *plist);
void LUpdate(List *plist, Data data);
int LCount(List *plist);

#endif