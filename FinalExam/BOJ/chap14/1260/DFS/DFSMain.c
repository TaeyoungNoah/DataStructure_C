#include <stdio.h>
#include "ALGraphDFS.h"

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

    ShowGraphEdgeInfo(&graph);

    DFShowGraphVertex(&graph, startV-1);

    GraphDestroy(&graph);
    return 0;
}