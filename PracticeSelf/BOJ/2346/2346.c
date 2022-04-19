#include <stdio.h>
#include <string.h>
#include <stdlib.h>



#define TRUE 1
#define FALSE 0
#define MAX 1000

typedef struct __balloon {
    int count;
    int num;
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



Balloon *MakeBalloon(int count, int num) {
    Balloon *pBalloon = (Balloon *) malloc(sizeof(Balloon));
    pBalloon->count = count;
    pBalloon->num = num;
    return pBalloon;
}

int main() {
    List list;
    ListInit(&list);
    int N, inputNum, temp, resultIdx;
    int result[MAX];
    Balloon *data;
    scanf("%d", &N);


    for (int i=1; i<=N; i++) {
        scanf("%d", &inputNum);
        data = MakeBalloon(i,inputNum);
        LInsert(&list, data);
    }

    resultIdx = 0;

    if (LFirst(&list, &data)) {
        temp = data->num;
        result[resultIdx]=data->count;
        resultIdx++;
        data->num=0;
        if (temp>0) {
            for (int i=0; i<temp; i++) {
                LNext(&list, &data);
                if (data->num==0)
                    i--;
            }
        }
        else {
            temp = abs(temp);
            for (int i=0; i<temp; i++) {
                LPrev(&list, &data);
                if (data->num==0)
                    i--;
            }
        }
        temp = data->num;
        result[resultIdx]=data->count;
        resultIdx++;
        data->num=0;


        for (int i=0; i<N-2; i++) {
            if (temp>0) {
                for (int i=0; i<temp; i++) {
                    LNext(&list, &data);
                    if (data->num==0)
                        i--;
                }
            }
            else {
                temp = abs(temp);
                for (int i=0; i<temp; i++) {
                    LPrev(&list, &data);
                    if (data->num==0)
                        i--;
                }
            }
            temp = data->num;
            result[resultIdx]=data->count;
            resultIdx++;
            data->num=0;
        }
    }
    for (int i=0; i<N; i++) {
        printf("%d ", result[i]);
    }


    return 0;
}