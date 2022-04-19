#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ListBaseStack.h"

int main() {
    Stack stack;
    int T, temp, top, result;
    StackInit(&stack);
    scanf("%d", &T);

    for (int i=0; i<T; i++) {
        scanf("%d", &temp);
        SPush(&stack, temp);
    }

    result = 1;
    top = SPop(&stack);
    while(!SIsEmpty(&stack)) {
        temp = SPop(&stack);
        if (temp>top) {
            top = temp;
            result+=1;
        }
    }

    printf("%d", result);

    return 0;
}