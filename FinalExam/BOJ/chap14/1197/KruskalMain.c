#include <stdio.h>
#include "ALGraphKruskal.h"

int main(void) {
    int V, E;
    int fromV, toV, weight;
    ALGraph graph;

    scanf("%d %d", &V, &E);

    GraphInit(&graph, V);

    for (int i=0; i<E; i++) {
        scanf("%d %d %d", &fromV, &toV, &weight);
        AddEdge(&graph, fromV-1, toV-1, weight);
    }

    ConKruskalMST(&graph);

    printf("%d", GetWeightSum(&graph));

    GraphDestroy(&graph);
    return 0;
}