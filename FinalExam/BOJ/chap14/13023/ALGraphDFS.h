#ifndef __AL_GRAPH_DFS_H__
#define __AL_GRAPH_DFS_H__

#include "DLinkedList.h"

enum {A, B, C, D, E, F, G, H, I, J};

typedef struct _ual {
    int numV; // 정점의 수
    int numE; // 간선의 수
    List *adjList; // 간선의 정보
    int *visitInfo; //
} ALGraph;

// 그래프 초기화
void GraphInit(ALGraph *pg, int nv);

// 그래프 리소스 해제
void GraphDestroy(ALGraph *pg);

// 간선 추가
void AddEdge(ALGraph *pg, int fromV, int toV);

// 간선 정보 출력
void ShowGraphEdgeInfo(ALGraph *pg);

// 정점의 정보 출력 : DFS 기반
int DFShowGraphVertex(ALGraph *pg, int startV);

#endif