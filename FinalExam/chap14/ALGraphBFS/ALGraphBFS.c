#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DLinkedList.h"
#include "CircularQueue.h"
#include "ALGraphBFS.h"

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
        printf("%c ", visitV + 65);
        return TRUE;
    }
    return FALSE;
}

void BFShowGraphVertex(ALGraph *pg, int startV) {
    Queue queue;
    int visitV = startV;
    int nextV;

    QueueInit(&queue);
    VisitVertex(pg, visitV); // 시작 정점을 탐색

    // 아래의 while 문에서는 visitV 와 연결된 모든 정점에 방문한다
    while(LFirst(&(pg->adjList[visitV]), &nextV) == TRUE) {
        if(VisitVertex(pg, nextV) == TRUE)
            Enqueue(&queue, nextV); // nextV에 방문했으니 큐에 저장

        while(LNext(&(pg->adjList[visitV]), &nextV) == TRUE) {
            if(VisitVertex(pg, nextV) == TRUE)
                Enqueue(&queue, nextV); // // nextV에 방문했으니 큐에 저장
        }

        if(QIsEmpty(&queue) == TRUE) // 큐가 비면 BFS 종료
            break;
        else
            visitV = Dequeue(&queue); // 큐에서 하나 꺼내어 while 문 다시 시작
    }
    memset(pg->visitInfo, 0, sizeof(int) * pg->numV); // 탐색 정보 초기화
}