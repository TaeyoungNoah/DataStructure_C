#ifndef __AL_GRAPH_DFS_H__
#define __AL_GRAPH_DFS_H__

#include "DLinkedList.h"


typedef struct _ual {
    int numV; // ������ ��
    int numE; // ������ ��
    List *adjList; // ������ ����
    int *visitInfo;
} ALGraph;

// �׷��� �ʱ�ȭ
void GraphInit(ALGraph *pg, int nv);

// �׷����� ���ҽ� ����
void GraphDestroy(ALGraph *pg);

// ������ �߰�
void AddEdge(ALGraph *pg, int fromV, int toV);

// �׷����� ���� ���� ���
void ShowGraphEdgeInfo(ALGraph *pg);

// BFS ��� �׷����� ���� ���� ���
void BFShowGraphVertex(ALGraph *pg, int startV);

#endif