#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#include "ListBaseStack.h"

int main() {
    int K, temp, result;
    Stack stack;

    StackInit(&stack);

    scanf("%d", &K);

    for (int i=0; i<K; i++) {
        scanf("%d", &temp);
        if (temp==0)
            SPop(&stack);
        else
            SPush(&stack, temp);
    }

    result = 0;
    while(!SIsEmpty(&stack)) {
        result += SPop(&stack);
    }

    printf("%d", result);

    return 0;
}