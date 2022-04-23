#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "InfixToPostfix.h"
#include "ListBaseStack.h"


int main(void) {
    char exp[60];
    char tok;
    int flag = 1;
    Stack stack;
    scanf("%s", exp);
    StackInit(&stack);

    for (int i=0; i<strlen(exp); i++) {
        tok = exp[i];
        if (tok=='(')
            SPush(&stack, tok);
        else if (tok==')') {
            if (SIsEmpty(&stack)) {
                flag = 0;
                break;
            }
            else if (SPeek(&stack)=='(')
                SPop(&stack);
            else {
                flag = 0;
                break;
            }
        }
    }
    if (!SIsEmpty(&stack))
        flag=0;

    if (flag==1) {
        ConvToRPNExp(exp);
        printf("%s", exp);
    }
    else {
        printf("INVALID");
    }








    return 0;
}