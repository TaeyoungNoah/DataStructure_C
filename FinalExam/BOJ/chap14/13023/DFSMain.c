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
        AddEdge(&graph,fromV,toV);
    }

    result = DFShowGraphVertex(&graph, 0);

    if (result==N) {
        printf("1");
    }
    else {
        printf("0");
    }



    GraphDestroy(&graph);
    return 0;
}