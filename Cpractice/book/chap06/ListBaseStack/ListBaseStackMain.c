

#include <stdio.h>
#include "ListBaseStack.h"

int main(void) {
    Stack stack;

    StackInit(&stack);

    SPush(&stack, 1);SPush(&stack, 2);
    SPush(&stack, 3);SPush(&stack, 4);
    SPush(&stack, 5);

    while(!SIsEmpty(&stack)) {
        printf("peek: %d\n", SPeek(&stack));
        printf("pop: %d\n\n", SPop(&stack));
    }
    printf("\n");
    return 0;
}