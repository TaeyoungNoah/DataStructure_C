#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "ALGraphBFS.h"

int main(void) {
    int N, M, startV;
    int fromV, toV;
    ALGraph graph;

    scanf("%d %d %d", &N, &M, &startV);

    GraphInit(&graph, N);

    for (int i=0; i<M; i++) {
        scanf("%d %d", &fromV, &toV);
        AddEdge(&graph, fromV-1, toV-1);
    }

    BFShowGraphVertex(&graph, startV-1);


    GraphDestroy(&graph);
    return 0;
}