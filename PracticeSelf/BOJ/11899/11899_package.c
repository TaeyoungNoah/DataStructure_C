#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ListBaseStack.h"

int main() {
    Stack stack;
    char input[50], tok;

    StackInit(&stack);
    scanf("%s", input);


    for (int i=0; i<strlen(input); i++) {
        tok = input[i];
        if (tok=='(') {
            SPush(&stack, tok);
        }
        else {
            if (!SIsEmpty(&stack) && SPeek(&stack)=='(') {
                SPop(&stack);
            }
            else {
                SPush(&stack, tok);
            }
        }
    }

    printf("%d", SSize(&stack));
    return 0;
}