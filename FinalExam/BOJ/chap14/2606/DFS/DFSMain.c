#include <stdio.h>
#include "ALGraphDFS.h"

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

    printf("%d", DFShowGraphVertex(&graph, 0));


    GraphDestroy(&graph);
    return 0;
}