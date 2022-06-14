#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DLinkedList.h"
#include "ArrayBaseStack.h"
#include "ALGraphKruskal.h"
#include "ALEdge.h"

int WhoIsPrecede(int data1, int data2) {
    if(data1 > data2)
        return 1;
    else
        return 0;
}

int PQWeightComp(Edge d1, Edge d2) {
    return d1.weight - d2.weight; // 우선순위 큐에 오름차순으로 넣기 위함
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

    PQueueInit(&(pg->pqueue), PQWeightComp); // 우선순위 큐의 초기화
}

void GraphDestroy(ALGraph *pg) {
    if(pg->adjList != NULL)
        free(pg->adjList);

    if(pg->visitInfo != NULL)
        free(pg->visitInfo);
}

void AddEdge(ALGraph *pg, int fromV, int toV, int weight) {
    Edge edge = {fromV, toV, weight};

    LInsert(&(pg->adjList[fromV]), toV);
    LInsert(&(pg->adjList[toV]), fromV);
    pg->numE += 1;

    PEnqueue(&(pg->pqueue), edge);
}


void ShowGraphEdgeInfo(ALGraph *pg) {
    int i;
    int vx;

    for(i = 0; i < pg->numV; i++) {
        printf("%c와 연결된 정점: ", i + 65);

        if(LFirst(&(pg->adjList[i]), &vx)) {
            printf("%c ", vx + 65);

            while(LNext(&(pg->adjList[i]), &vx)) {
                printf("%c ", vx + 65);
            }
            printf("\n");
        }
    }
}

int VisitVertex(ALGraph *pg, int visitV) {
    if(pg->visitInfo[visitV] == 0) {
        pg->visitInfo[visitV] = 1;
//        	printf("%c ", visitV + 65);
        return TRUE;
    }
    return FALSE;
}

void DFShowGraphVertex(ALGraph *pg, int startV) {
    Stack stack;
    int visitV = startV;
    int nextV;
    StackInit(&stack);
    VisitVertex(pg, visitV);
    SPush(&stack, visitV);

    while(LFirst(&(pg->adjList[visitV]), &nextV) == TRUE) {
        int visitFlag = FALSE;

        if(VisitVertex(pg, nextV) == TRUE) {
            SPush(&stack, visitV);
            visitV = nextV;
            visitFlag = TRUE;
        }
        else {
            while(LNext(&(pg->adjList[visitV]), &nextV) == TRUE) {
                if(VisitVertex(pg, nextV) == TRUE) {
                    SPush(&stack, visitV);
                    visitV = nextV;
                    visitFlag = TRUE;
                    break;
                }
            }
        }

        if(visitFlag == FALSE) {
            if(SIsEmpty(&stack) == TRUE)
                break;
            else
                visitV = SPop(&stack);
        }
    }
    memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

// 한쪽 방향의 간선 소멸
void RemoveWayEdge(ALGraph *pg, int fromV, int toV) {
    int edge;

    if(LFirst(&(pg->adjList[fromV]), &edge) == TRUE) {
        if(edge == toV) {
            LRemove(&(pg->adjList[fromV]));
            return;
        }

        while(LNext(&(pg->adjList[fromV]), &edge) == TRUE) {
            if(edge == toV) {
                LRemove(&(pg->adjList[fromV]));
                return;
            }
        }
    }
}


// 그래프에서 간선을 삭제한다
void RemoveEdge(ALGraph *pg, int fromV, int toV) {
    RemoveWayEdge(pg, fromV, toV);
    RemoveWayEdge(pg, toV, fromV);
    (pg->numE)--;
}

// 삭제된 간선을 다시 삽입한다
void RecoverEdge(ALGraph *pg, int fromV, int toV, int weight) {
    LInsert(&(pg->adjList[fromV]), toV);
    LInsert(&(pg->adjList[toV]), fromV);
    (pg->numE)++;
}

// 두 정점이 연결되어 있는지 확인한다
// 인자로 전달된 두 정점이 연결 되어 있다면 TURE, 그렇지 않다면 FALSE 반환
int IsConnVertex(ALGraph *pg, int v1, int v2) {
    Stack stack;
    int visitV = v1;
    int nextV;

    StackInit(&stack);
    VisitVertex(pg, visitV);
    SPush(&stack, visitV);

    while(LFirst(&(pg->adjList[visitV]), &nextV) == TRUE) {
        int visitFlag = FALSE;

        if(nextV == v2) {
            memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
            return TRUE;
        }

        if(VisitVertex(pg, nextV) == TRUE) {
            SPush(&stack, visitV);
            visitV = nextV;
            visitFlag = TRUE;
        }
        else {
            while(LNext(&(pg->adjList[visitV]), &nextV) == TRUE) {
                if(nextV == v2) {
                    memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
                    return TRUE;
                }

                if(VisitVertex(pg, nextV) == TRUE) {
                    SPush(&stack, visitV);
                    visitV = nextV;
                    visitFlag = TRUE;
                    break;
                }
            }
        }

        if(visitFlag == FALSE) {
            if(SIsEmpty(&stack) == TRUE)
                break;
            else
                visitV = SPop(&stack);
        }
    }

    memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
    return FALSE;
}

void ConKruskalMST(ALGraph *pg) { // 크루스칼 알고리즘 기반 MST 구성
    Edge recvEdge[20]; // 복원할 간선의 정보 저장
    Edge edge;
    int eidx = 0;
    int i;

    // MST 를 형성할 때까지 아래의 while 문을 반복
    while(pg->numE + 1 > pg->numV) { // MST : 간선의 수 + 1 == 정점의 수
        edge = PDequeue(&(pg->pqueue)); // 우선순위 큐에서 가중치가 제일 높은 간선의 정보를 꺼낸다
        RemoveEdge(pg, edge.v1, edge.v2); // 우선순위 큐에서 꺼낸 간선을 실제로 그래프에서 삭제한다.

        if(!IsConnVertex(pg, edge.v1, edge.v2)) { // 간선을 삭제한 이후 두 정점을 연결하는 경로가 있는지 확인한다.
            RecoverEdge(pg, edge.v1, edge.v2, edge.weight); // 경로가 없다면 삭제한 간선을 복원
            // 복원한 간선의 정보를 별도로 저장
            // 크루스칼 알고리즘에서는 한번 검토가 이루어진 간선은 재검토 하지 않음
            // 따라서 다시 큐에 넣지 않고 따로 빼 두었다가 아래 for 문에서 마지막에 다시 다 넣어줌
            recvEdge[eidx++] = edge;
        }
    }

    // 우선순위 큐에서 삭제된 간선의 정보를 회복
    for(i = 0; i < eidx; i++) {
        PEnqueue(&(pg->pqueue), recvEdge[i]);
    }
}

void ShowGraphEdgeWeightInfo(ALGraph *pg) {
    PQueue copyPQ = pg->pqueue;
    Edge edge;

    while(!PQIsEmpty(&copyPQ)) {
        edge = PDequeue(&copyPQ);
        printf("(%c-%c), w:%d\n", edge.v1 + 65, edge.v2 + 65, edge.weight);
    }
}

int GetWeightSum(ALGraph *pg) {
    PQueue copyPQ = pg->pqueue;
    Edge edge;
    int weightSum;

    weightSum = 0;
    while(!PQIsEmpty(&copyPQ)) {
        edge = PDequeue(&copyPQ);
        weightSum += edge.weight;
    }
    return weightSum;
}
