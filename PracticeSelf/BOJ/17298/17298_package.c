#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "ListBaseStack.h"

#define MAX 1000001

int main() {
    int N, input[MAX], result[MAX];
    Stack stack;
    StackInit(&stack);

    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        scanf("%d", &input[i]);
    }

    SPush(&stack, input[N-1]);
    result[N-1]=-1;
    if (N>1) {
        for (int i = N - 2; i >= 0; i--) {
            while (!SIsEmpty(&stack) && input[i] >= SPeek(&stack)) {
                SPop(&stack);
            }
            if (SIsEmpty(&stack))
                result[i]=-1;
            else
                result[i] = SPeek(&stack);
            SPush(&stack, input[i]);
        }
    }


    for (int i=0; i<N; i++)
        printf("%d ", result[i]);



    return 0;
}