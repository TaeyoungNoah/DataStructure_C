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

#define QUE_LEN 100
typedef int Data;

typedef struct _cQueue {
    int front;
    int rear;
    Data queArr[QUE_LEN];
} CQueue;

typedef CQueue Queue;

void QueueInit(Queue *pq) {
    pq->front = 0;
    pq->rear = 0;
}

int	QIsEmpty(Queue *pq) {
    if(pq->front == pq->rear)
        return TRUE;
    else
        return FALSE;
}

int NextPosIdx(int pos) {
    if(pos == QUE_LEN - 1)
        return 0;
    else
        return pos + 1;
}

void Enqueue(Queue *pq, Data data) {
    if(NextPosIdx(pq->rear) == pq->front) {
        printf("Queue Memory Error!\n");
        exit(-1);
    }

    pq->rear = NextPosIdx(pq->rear);
    pq->queArr[pq->rear] = data;
}

Data Dequeue(Queue *pq) {
    if(QIsEmpty(pq)) {
        printf("Queue Memory Error!\n");
        exit(-1);
    }

    pq->front = NextPosIdx(pq->front);

    return pq->queArr[pq->front];
}

typedef struct _ual {
    int numV; // 정점의 수
    int numE; // 간선의 수
    List *adjList; // 간선의 정보
    int *visitInfo;
} ALGraph;

int WhoIsPrecede(int data1, int data2) {
    if(data1 > data2)
        return 1;
    else
        return 0;
}

void GraphInit(ALGraph *pg, int nv) {
    int i;

    pg->adjList = (List *)malloc(sizeof(List) * nv);
    pg->numV = nv;
    pg->numE = 0;

    for(i = 0; i < nv; i++) {
        ListInit(&(pg->adjList[i]));
        SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
    }

    pg->visitInfo = (int *)malloc(sizeof(int) * pg->numV);
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
        printf("%d와 연결된 정점: ", i+1);

        if(LFirst(&(pg->adjList[i]), &vx)) {
            printf("%d ", vx+1);

            while(LNext(&(pg->adjList[i]), &vx)) {
                printf("%d ", vx+1);
            }
            printf("\n");
        }
    }
}

int VisitVertex(ALGraph *pg, int visitV) {
    if(pg->visitInfo[visitV] == 0) {
        pg->visitInfo[visitV] = 1;
        return TRUE;
    }
    return FALSE;
}

int BFShowGraphVertex(ALGraph *pg, int startV) {
    Queue queue;
    int visitV = startV;
    int nextV;
    int result;

    QueueInit(&queue);
    VisitVertex(pg, visitV); // 시작 정점을 탐색
    result = 0;

    // 아래의 while 문에서는 visitV 와 연결된 모든 정점에 방문한다
    while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE) {
        if (VisitVertex(pg, nextV) == TRUE) {
            Enqueue(&queue, nextV); // nextV에 방문했으니 큐에 저장
            result += 1;
        }

        while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE) {
            if (VisitVertex(pg, nextV) == TRUE) {
                Enqueue(&queue, nextV); // // nextV에 방문했으니 큐에 저장
                result += 1;
            }

        }

        if (QIsEmpty(&queue) == TRUE) // 큐가 비면 BFS 종료
            break;
        else
            visitV = Dequeue(&queue); // 큐에서 하나 꺼내어 while 문 다시 시작
    }
    memset(pg->visitInfo, 0, sizeof(int) * pg->numV); // 탐색 정보 초기화
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

    printf("%d", BFShowGraphVertex(&graph, 0));


    GraphDestroy(&graph);
    return 0;
}