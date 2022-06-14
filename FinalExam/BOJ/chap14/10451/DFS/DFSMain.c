#include <stdio.h>
#include "ALGraphDFS.h"

int main(void) {
    int T, N, toV, result;
    ALGraph graph;

    scanf("%d", &T);
    for (int i=0; i<T; i++) {
        scanf("%d", &N);
        GraphInit(&graph, N+1);
        for (int j=1; j<=N; j++) {
            scanf("%d", &toV);
            AddEdge(&graph, j, toV);
        }
        result = 0;
        for (int j=1; j<=N; j++) {
            if (graph.visitInfo[j]==0) {
                DFShowGraphVertex(&graph, j);
                result++;
            }
        }
        printf("%d\n", result);
        GraphDestroy(&graph);

    }


    return 0;
}