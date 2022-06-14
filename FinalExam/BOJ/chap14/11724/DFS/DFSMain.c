#include <stdio.h>
#include "ALGraphDFS.h"

int main(void) {
    int N, M, result;
    int fromV, toV;
    ALGraph graph;

    scanf("%d %d", &N, &M);
    GraphInit(&graph, N);

    for (int i=0; i<M; i++) {
        scanf("%d %d", &fromV, &toV);
        AddEdge(&graph, fromV-1, toV-1);
    }

    result = 0;
    for (int i=0; i<N; i++) {
        if (graph.visitInfo[i]==0) {
            result++;
            DFShowGraphVertex(&graph,i);
        }
    }
    printf("%d", result);



    GraphDestroy(&graph);
    return 0;
}