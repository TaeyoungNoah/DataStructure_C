#include <stdio.h>
#include <stdlib.h>
#include "ALGraph.h"

int WhoIsPrecede(int data1, int data2);

void GraphInit(ALGraph *pg, int nv) { // 그래프 초기화
    int i;

    pg->adjList = (List *)malloc(sizeof(List) * nv); // 간선정보를 저장할 리스트 생성
    pg->numV = nv; // 정점 수는 nv 에 저장된 값
    pg->numE = 0; // 초기 간선 수는 0

    for(i = 0; i < nv; i++) {
        ListInit(&(pg->adjList[i]));
        SetSortRule(&(pg->adjList[i]), WhoIsPrecede); // 출력 했을 때 이쁘게 보이게 하기 위해서
    }
}

void GraphDestroy(ALGraph *pg) { // 그래프 리소스 해제
    if(pg->adjList != NULL) {
        for(int i=0; i<pg->numV; i++) {
            ListDestroy(&pg->adjList[i]);
        }
        free(pg->adjList);
    }

}

void AddEdge(ALGraph *pg, int fromV, int toV) { // fromV, toV 연결
    // 정점 fromV 의 연결 리스트에 정점 toV 의 정보 추가
    LInsert(&(pg->adjList[fromV]), toV);

    // 정점 toV의 연결 리스트에 정점 fromV 의 정보 추가
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
        }
        printf("\n");
    }
}

int WhoIsPrecede(int data1, int data2) {
    if(data1 < data2)
        return 0;
    else
        return 1;
}