#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


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

void MakeList(List *plist, int N) {
    for (int i=0; i<N; i++){
        LInsert(plist, '?');
    }
}

int main() {
    List list;
    int N, K, spin, flag, charCur;
    char charList[25];

    char data, input;
    ListInit(&list);

    flag=TRUE;
    scanf("%d %d", &N, &K);
    MakeList(&list,N);



    LFirst(&list, &data); // cur ÃÊ±âÈ­

    for (int i=0; i<K; i++) {
        scanf("%d %c", &spin, &input);
        for (int j=0; j<spin; j++) {
            LNext(&list, &data);
        }
        if (data=='?' || data==input)
            LUpdate(&list, input);
        else {
            flag=0;
        }


    }

    charCur = 0;
    if (flag==1) {
        for(int i = 0; i < LCount(&list); i++) {
            if (LPrev(&list, &data)) {
                if (data!='?') {
                    for (int j = 0; j < charCur; j++) {
                        if (charList[j] == data)
                            flag = 0;
                    }
                    charList[charCur] = data;
                    charCur++;
                }

            }
        }
    }




    if (flag==1) {
        LNext(&list, &data);
        for(int i = 0; i < LCount(&list); i++) {
            if(LPrev(&list, &data))
                printf("%c", data);
        }
    }
    else
        printf("!");

    return 0;
}