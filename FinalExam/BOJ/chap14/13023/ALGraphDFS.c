#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DLinkedList.h"
#include "ArrayBaseStack.h"
#include "ALGraphDFS.h"

int WhoIsPrecede(int data1, int data2) {
    if(data1 > data2)
        return 1;
    else
        return 0;
}

void GraphInit(ALGraph *pg, int nv) { // 그래프 초기화
    int i;

    pg->adjList = (List *)malloc(sizeof(List) * nv);
    pg->numV = nv;
    pg->numE = 0;

    for(i = 0; i < nv; i++) {
        ListInit(&(pg->adjList[i]));
        SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
    }

    // 정점의 수를 길이로 하여 배열을 할당
    pg->visitInfo = (int *)malloc(sizeof(int) * pg->numV);

    // 배열의 모든 요소를 0으로 초기화
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

// visitV 의 정점에 방문
int VisitVertex(ALGraph *pg, int visitV) {
    if(pg->visitInfo[visitV] == 0) { // 첫 방문일때 참
        pg->visitInfo[visitV] = 1; // 방문 한 것으로 기록
//        printf("%c ", visitV + 65); // 방문한 정점 출력
        return TRUE; // 방문 성공
    }
    return FALSE; // 이미 방문 한 곳
}

int DFShowGraphVertex(ALGraph *pg, int startV) {
    Stack stack;
    int visitV = startV;
    int nextV;

    int result;
    result=1;
    StackInit(&stack); // DFS 위한 스택의 초기화
    VisitVertex(pg, visitV); // 시작 정점 방문
    SPush(&stack, visitV); // 시작 정점 정보 푸시

    while(LFirst(&(pg->adjList[visitV]), &nextV) == TRUE) {
        int visitFlag = FALSE;

        if(VisitVertex(pg, nextV) == TRUE) { // 방문 성공
            SPush(&stack, visitV); // 정점 정보 푸시
            visitV = nextV;
            visitFlag = TRUE;
            result++;
        }
        else { // 방문 실패 -> 연결된 다른 정점
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

        if(visitFlag == FALSE) { // 추가로 방문한 정점이 없음
            if(SIsEmpty(&stack) == TRUE) // 시작점으로 되돌아왔음
                break;
            else
                visitV = SPop(&stack); // 길을 되돌아 감 (앞 순서로)
        }
    }
    memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
    return result;
}