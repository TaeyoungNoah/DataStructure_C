#include <string.h>
#include <ctype.h>
#include "PostCalculator.h"
#include "ListBaseStack.h"

int EvalRPNExp(char exp[]) {
    Stack stack;
    int i;
    int expLen = strlen(exp);
    char tok;
    char op1, op2;

    StackInit(&stack);
    for(i = 0; i < expLen; i++) {
        tok = exp[i];

        if(isdigit(tok)) { // 정수인지 확인
            SPush(&stack, tok - '0'); // 정수라면 숫자로 바꿔서 push
        }
        else {
            op2 = SPop(&stack);
            op1 = SPop(&stack); // 주의할점 : 먼저 pop된게 연산의 오른쪽임

            switch(tok) {
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