#include <stdio.h>

#include "ListBaseStack.h"

int main() {
    Stack resultStack;
    Stack tempStack;

    StackInit(&resultStack);
    StackInit(&tempStack);
    int N, K;

    scanf("%d", &N);

    for(int i=1; i<=N; i++) {
        scanf("%d", &K);
        for (int j=0; j<K; j++) {
            SPush(&tempStack, SPop(&resultStack));
        }
        SPush(&resultStack, i);
        while(!SIsEmpty(&tempStack))
            SPush(&resultStack, SPop(&tempStack));
    }

    while(!SIsEmpty(&resultStack))
        SPush(&tempStack, SPop(&resultStack));

    while(!SIsEmpty(&tempStack))
        printf("%d ", SPop(&tempStack));
    return 0;
}