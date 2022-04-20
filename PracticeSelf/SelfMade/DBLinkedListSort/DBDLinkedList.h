#ifndef __DBD_LINKED_LIST_H__
#define __DBD_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

typedef int LData;

typedef struct _node {
    LData data;
    struct _node *next;
    struct _node *prev;
} Node;

typedef struct _dbDLinkedList {
    Node *head;
    Node *cur;
    Node *tail;
    int numOfData;
    int (*comp)(LData d1, LData d2);
} DBDLinkedList;

typedef DBDLinkedList List;

void ListInit(List *plist);
void LInsert(List *plist, LData data);

int LFirst(List *plist, LData *pdata);
int LNext(List *plist, LData *pdata);
int LPrev(List *plist, LData *pdata);
void SetSortRule(List *plist, int (*comp)(LData d1, LData d2));

LData LRemove(List *plist);
int LCount(List *plist);

#endif