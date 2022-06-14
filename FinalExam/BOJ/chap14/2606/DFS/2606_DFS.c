#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define TRUE 1
#define FALSE 0
typedef int LData;

typedef struct _node {
    LData data;
    struct _node *next;
} Node;

typedef struct _linkedList {
    Node *head;
    Node *before;
    Node *cur;
    int numOfCount;
    int (*comp)(LData data1, LData data2);
} LinkedList;

typedef LinkedList List;

void ListInit(List *plist) {
    plist->head = (Node *)malloc(sizeof(Node));
    plist->head->next = NULL;
    plist->comp = NULL;
    plist->numOfCount = 0;
}

void FInsert(List *plist, LData data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = plist->head->next;
    plist->head->next = newNode;

    (plist->numOfCount)++;
}

void SInsert(List *plist, LData data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    Node *pred = plist->head;

    newNode->data = data;

    while(pred->next != NULL && plist->comp(data, pred->next->data) != 0) {
        pred = pred->next;
    }

    newNode->next = pred->next;
    pred->next = newNode;

    (plist->numOfCount)++;
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

LData LRemove(List *plist) {
    Node *rpos = plist->cur;
    LData rdata = rpos->data;

    plist->before->next = plist->cur->next;
    plist->cur = plist->before;

    free(rpos);
    (plist->numOfCount)--;
    return rdata;
}

int LCount(List *plist) {
    return plist->numOfCount;
}

void ListDestroy(List *plist) {
    LData data;
    if (LFirst(plist, &data)) {
        LRemove(plist);

        while (LNext(plist, &data)) {
            LRemove(plist);
        }
    }
    free(plist->head);
}

void SetSortRule(List *plist, int (*comp)(LData data1, LData data2)) {
    plist->comp = comp;
}

#define STACK_LEN 100

typedef int Data;

typedef struct _arrayStack {
    Data stackArr[STACK_LEN];
    int topIndex;
} ArrayStack;

typedef ArrayStack Stack;


void StackInit(Stack *pstack) {
    pstack->topIndex = -1;
}

int SIsEmpty(Stack *pstack) {
    if(pstack->topIndex == -1)
        return TRUE;
    else
        return FALSE;
}

void SPush(Stack *pstack, Data data) {
    pstack->topIndex += 1;
    pstack->stackArr[pstack->topIndex] = data;
}

Data SPop(Stack *pstack) {
    int rIdx;

    if(SIsEmpty(pstack)) {
        printf("Stack Memory Error!\n");
        exit(-1);
    }
    rIdx = pstack->topIndex;
    pstack->topIndex -= 1;
    return pstack->stackArr[rIdx];
}

typedef struct _ual {
    int numV; // ������ ��
    int numE; // ������ ��
    List *adjList; // ������ ����
    int *visitInfo; //
} ALGraph;


int WhoIsPrecede(int data1, int data2) {
    if(data1 > data2)
        return 1;
    else
        return 0;
}

void GraphInit(ALGraph *pg, int nv) { // �׷��� �ʱ�ȭ
    int i;

    pg->adjList = (List *)malloc(sizeof(List) * nv);
    pg->numV = nv;
    pg->numE = 0;

    for(i = 0; i < nv; i++) {
        ListInit(&(pg->adjList[i]));
        SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
    }

    // ������ ���� ���̷� �Ͽ� �迭�� �Ҵ�
    pg->visitInfo = (int *)malloc(sizeof(int) * pg->numV);

    // �迭�� ��� ��Ҹ� 0���� �ʱ�ȭ
    memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

void GraphDestroy(ALGraph *pg) {
    if(pg->adjList != NULL) {
        for(int i=0; i<pg->numV; i++) {
            ListDestroy(&pg->adjList[i]);
        }
        free(pg->adjList);
    }

    if(pg->visitInfo != NULL)
        free(pg->visitInfo);
}

void AddEdge(ALGraph *pg, int fromV, int toV) {
    LInsert(&(pg->adjList[fromV]), toV);
    LInsert(&(pg->adjList[toV]), fromV);
    pg->numE += 1;
}


void ShowGraphEdgeInfo(ALGraph *pg) {
    int i;
    int vx;

    for(i = 0; i < pg->numV; i++) {
        printf("%d�� ����� ����: ", i+1);

        if(LFirst(&(pg->adjList[i]), &vx)) {
            printf("%d ", vx+1);

            while(LNext(&(pg->adjList[i]), &vx)) {
                printf("%d ", vx+1);
            }
            printf("\n");
        }
    }
}

// visitV �� ������ �湮
int VisitVertex(ALGraph *pg, int visitV) {
    if(pg->visitInfo[visitV] == 0) { // ù �湮�϶� ��
        pg->visitInfo[visitV] = 1; // �湮 �� ������ ���
        return TRUE; // �湮 ����
    }
    return FALSE; // �̹� �湮 �� ��
}

int DFShowGraphVertex(ALGraph *pg, int startV) {
    Stack stack;
    int visitV = startV;
    int nextV;
    int result;

    StackInit(&stack); // DFS ���� ������ �ʱ�ȭ
    VisitVertex(pg, visitV); // ���� ���� �湮
    SPush(&stack, visitV); // ���� ���� ���� Ǫ��
    result = 0;

    while(LFirst(&(pg->adjList[visitV]), &nextV) == TRUE) {
        int visitFlag = FALSE;

        if(VisitVertex(pg, nextV) == TRUE) { // �湮 ����
            SPush(&stack, visitV); // ���� ���� Ǫ��
            visitV = nextV;
            visitFlag = TRUE;
            result++;
        }
        else { // �湮 ���� -> ����� �ٸ� ����
            while(LNext(&(pg->adjList[visitV]), &nextV) == TRUE) {
                if(VisitVertex(pg, nextV) == TRUE) {
                    SPush(&stack, visitV);
                    visitV = nextV;
                    visitFlag = TRUE;
                    result++;
                    break;
                }
            }
        }

        if(visitFlag == FALSE) { // �߰��� �湮�� ������ ����
            if(SIsEmpty(&stack) == TRUE) // ���������� �ǵ��ƿ���
                break;
            else
                visitV = SPop(&stack); // ���� �ǵ��� �� (�� ������)
        }
    }
    memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
    return result;
}

int main(void) {
    int N, M;
    int fromV, toV;
    ALGraph graph;

    scanf("%d", &N);
    scanf("%d", &M);

    GraphInit(&graph, N);

    for (int i=0; i<M; i++) {
        scanf("%d %d", &fromV, &toV);
        AddEdge(&graph, fromV-1, toV-1);
    }

    printf("%d", DFShowGraphVertex(&graph, 0));


    GraphDestroy(&graph);
    return 0;
}
