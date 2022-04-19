#include <stdio.h>
#include <string.h>

#include "ListBaseStack.h"

#define MAX 1000000

int main() {
    Stack stack;
    char input[MAX], tok;
    int T, result;

    scanf("%d", &T);
    result = 0;

    for (int i=0; i<T; i++) {
        StackInit(&stack);
        scanf("%s", input);
        for (int j=0; j<strlen(input); j++) {
            tok = input[j];
            if (SIsEmpty(&stack)) {
                SPush(&stack, tok);
            }
            else {
                if (SPeek(&stack)==tok){
                    SPop(&stack);
                }
                else {
                    SPush(&stack, tok);
                }
            }
        }
        if (SIsEmpty(&stack)) {
            result+=1;
        }
    }

    printf("%d", result);


    return 0;
}