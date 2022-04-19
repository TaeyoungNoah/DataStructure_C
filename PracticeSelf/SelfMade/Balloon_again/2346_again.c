#include <stdio.h>
#include <stdlib.h>


#define TRUE 1
#define FALSE 0

typedef struct _balloon {
    int num;
    int weight;
} Balloon;


typedef Balloon * Data;

typedef struct _node {
    struct _node *prev;
    Data data;
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

Balloon *MakeBalloon(int num, int weight) {
    Balloon *pBalloon = (Balloon *) malloc(sizeof(Balloon));
    pBalloon->num = num;
    pBalloon->weight = weight;
    return pBalloon;
}

int main() {
    List list;
    Balloon *balloon;
    int N, weight, result[1000], resultCur, temp;

    ListInit(&list);

    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        scanf("%d", &weight);
        balloon = MakeBalloon(i, weight);
        LInsert(&list, balloon);
    }

    resultCur = 0;


    if (LFirst(&list, &balloon)) {
        temp = balloon->weight;
        result[resultCur] = balloon->num;
        resultCur++;
        balloon->weight=0;

        for (int i = 0; i < N-1; i++) {
            if (temp>0) {
                for (int j=0; j<temp; j++) {
                    LNext(&list, &balloon);
                    if (balloon->weight==0)
                        j--;
                }
                temp = balloon->weight;
                result[resultCur] = balloon->num;
                resultCur++;
                balloon->weight=0;
            }
            else {
                temp = abs(temp);
                for (int j=0; j<temp; j++) {
                    LPrev(&list, &balloon);
                    if (balloon->weight==0)
                        j--;
                }
                temp = balloon->weight;
                result[resultCur] = balloon->num;
                resultCur++;
                balloon->weight=0;
            }
        }
    }

    for (int i=0; i<N; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}