#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "InfixToPostfix.h"
#include "ListBaseStack.h"

int GetOpPrec(char op) {
    switch(op) { // 연산의 우선 순위
        case '*':
        case '/':
            return 5;

        case '+':
        case '-':
            return 3;

        case '(':
            return 1;
    }

    return -1;
}


int WhoPrecOp(char op1, char op2) { // 연산자를 통한 우선 순위 판별
    int op1Prec = GetOpPrec(op1);
    int op2Prec = GetOpPrec(op2);

    if(op1Prec > op2Prec)
        return 1;
    else if(op1Prec < op2Prec)
        return -1;
    else
        return 0;
}


void ConvToRPNExp(char exp[]) { // exp : 입력받은 수식
    Stack stack;
    int expLen = strlen(exp);
    char *convExp = (char *)malloc(expLen + 1); // convExp : 후위 표기법으로 변환한 정보를 담을 곳

    char tok, popOp;
    int i, idx = 0;

    memset(convExp, 0, sizeof(char) * expLen + 1); // convExp 0으로 초기화
    StackInit(&stack); // 스택 (그릇) 생성

    for(i = 0; i < expLen; i++) {
        tok = exp[i];

        if(isdigit(tok)) { // 숫자이면 그냥 저장
            convExp[idx++] = tok;
        }
        else { // 연산자이면
            switch(tok) {
                case '(':
                    SPush(&stack, tok);
                    break;

                case ')':
                    while(1) {
                        popOp = SPop(&stack); // ) 들어오면 스택에 있는거 ( 나올 때 까지 pop
                        if(popOp == '(')
                            break;

                        convExp[idx++] = popOp;
                    }
                    break;

                case '*':
                case '/':
                case '+':
                case '-':
                    while(!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0) {
                        // 스택이 비어있지 않고 && 맨 위에 연산자보다 지금 판단중인 연산자의 우선순위가 낮은 경우
                        // 에 아래 내용 실행 (스택 아래에 먼저 들어와있던 연산자의 우선순위가 높으면 pop하고 push 해야함)
                        convExp[idx++] = SPop(&stack);
                    }

                    SPush(&stack, tok);
                    break;
            }
        }
    }

    while(!SIsEmpty(&stack)) {
        convExp[idx++] = SPop(&stack);
    }

    strcpy(exp, convExp); // 후위 표기법으로 바꾼것을 exp에 담고
    free(convExp); // 메모리 해제
}