#include <stdio.h>
#include <string.h>

#include "ListBaseStack.h"

int main() {
    Stack stack;
    char input[100];
    StackInit(&stack);

    scanf("%s", input);

    for (int i=0; i<strlen(input); i++) {
        SPush(&stack, input[i]);
    }

    while(!SIsEmpty(&stack))
        printf("%c", SPop(&stack));


    return 0;
}