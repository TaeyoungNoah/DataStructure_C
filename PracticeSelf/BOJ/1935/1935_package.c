#include <stdio.h>
#include <string.h>

#include "ListBaseStack.h"

double calculator(Stack *stack, double *numChart, char *userInput) {
    char tok;
    double op1, op2;
    for (int i=0; i<strlen(userInput); i++) {
        tok = userInput[i];
        if (tok >= 'A' && tok <= 'Z') {
            SPush(stack, numChart[tok-65]);
        }
        else {
            op2 = SPop(stack);
            op1 = SPop(stack);

            switch (tok) {
                case '*' :
                    SPush(stack,op1 * op2);
                    break;
                case '+' :
                    SPush(stack,op1 + op2);
                    break;
                case '-' :
                    SPush(stack,op1 - op2);
                    break;
                case '/' :
                    SPush(stack,op1 / op2);
                    break;
            }
        }
    }
    return SPop(stack);;
}


int main() {
    Stack stack;
    int N;
    double numChart[26];
    char userInput[101];
    StackInit(&stack);
    scanf("%d", &N);
    scanf("%s", userInput);
    for (int i=0; i<N; i++)
        scanf("%lf", &numChart[i]);

    printf("%.2lf", calculator(&stack, numChart, userInput));

    return 0;
}