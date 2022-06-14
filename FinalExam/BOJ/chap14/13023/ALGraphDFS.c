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
        printf("%c�� ����� ����: ", i + 65);

        if(LFirst(&(pg->adjList[i]), &vx)) {
            printf("%c ", vx + 65);

            while(LNext(&(pg->adjList[i]), &vx)) {
                printf("%c ", vx + 65);
            }
            printf("\n");
        }
    }
}

// visitV �� ������ �湮
int VisitVertex(ALGraph *pg, int visitV) {
    if(pg->visitInfo[visitV] == 0) { // ù �湮�϶� ��
        pg->visitInfo[visitV] = 1; // �湮 �� ������ ���
//        printf("%c ", visitV + 65); // �湮�� ���� ���
        return TRUE; // �湮 ����
    }
    return FALSE; // �̹� �湮 �� ��
}

int DFShowGraphVertex(ALGraph *pg, int startV) {
    Stack stack;
    int visitV = startV;
    int nextV;

    int result;
    result=1;
    StackInit(&stack); // DFS ���� ������ �ʱ�ȭ
    VisitVertex(pg, visitV); // ���� ���� �湮
    SPush(&stack, visitV); // ���� ���� ���� Ǫ��

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