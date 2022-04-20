#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0


typedef int LData;

typedef struct _node {
    LData data;
    struct _node *next;
} Node;

typedef struct _linkedList {
    Node *head;
    Node *cur;
    Node *before;
    int numOfData;
    int (*comp)(LData d1, LData d2);
} LinkedList;

typedef LinkedList List;


void ListInit(List *plist) {
    plist->head = (Node *)malloc(sizeof(Node));
    plist->head->next = NULL;
    plist->numOfData = 0;
    plist->comp = NULL;
}

void FInsert(List *plist, LData data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = plist->head->next;
    plist->head->next = newNode;
    (plist->numOfData)++;
}

void SInsert(List *plist, LData data) {
    Node *pred = plist->head;
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    while(pred->next != NULL && plist->comp(data, pred->next->data) != 0) {
        pred = pred->next;
    }
    newNode->next = pred->next;
    pred->next = newNode;
    (plist->numOfData)++;
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




int main() {
    List list;
    int temp, resultMax, resultIdx, tempIdx;
    int data;

    ListInit(&list);

    for (int i=0; i<9; i++) {
        scanf("%d", &temp);
        LInsert(&list, temp);
    }



    if (LFirst(&list, &data)) {
        resultMax = data;
        tempIdx = 9;
        resultIdx = tempIdx;
        for (int i=0; i<8; i++) {
            if (LNext(&list, &data)) {
                tempIdx--;
                if (data>resultMax) {
                    resultMax = data;
                    resultIdx = tempIdx;
                }

            }
        }
    }

    printf("%d\n%d", resultMax, resultIdx);

}