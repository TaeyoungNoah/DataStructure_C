#include <stdio.h>
#include <string.h>

#include "ListBaseStack.h"

double EvalRPNExp(char exp[], double numTable[]) {
    Stack stack;
    int i;
    int expLen = strlen(exp);
    char tok;
    double op1, op2;

    StackInit(&stack);
    for (i = 0; i < expLen; i++) {
        tok = exp[i];

        if (tok>='A' && tok<='Z') {
            SPush(&stack, numTable[tok-65]);
        } else {
            op2 = SPop(&stack);
            op1 = SPop(&stack);

            switch (tok) {
                case '+':
                    SPush(&stack, op1 + op2);
                    break;
                case '-':
                    SPush(&stack, op1 - op2);
                    break;
                case '*':
                    SPush(&stack, op1 * op2);
                    break;
                case '/':
                    SPush(&stack, op1 / op2);
                    break;
            }
        }
    }

    return SPop(&stack);
}

int main() {
    int N;
    double numTable[26], temp, result;
    char inputExp[100];

    scanf("%d", &N);
    scanf("%s", inputExp);
    for (int i = 0; i < N; i++) {
        scanf("%lf", &temp);
        numTable[i] = temp;
    }

    result = EvalRPNExp(inputExp, numTable);

    printf("%.2lf", result);



    return 0;
}