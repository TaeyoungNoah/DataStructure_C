#include <stdio.h>

#include "ListBaseStack.h"

int main() {
    Stack stack;
    StackInit(&stack);

     int K, T, sum;
    scanf("%d", &K);
    sum = 0;

    for (int i=0; i<K; i++) {
        scanf("%d", &T);
        if (T!=0)
            SPush(&stack, T);
        else
            SPop(&stack);
    }

    while(!SIsEmpty(&stack)) {
        sum+= SPop(&stack);
    }

    printf("%d", sum);


    return 0;
}