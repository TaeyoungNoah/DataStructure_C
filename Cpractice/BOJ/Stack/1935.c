#include <stdio.h>
#include <string.h>

#define MAX 100

double stack[MAX];
int top = 0;

void push(double data) {
    stack[top] = data;
    top++;
}

double pop() {
    top--;
    double temp = stack[top];
    stack[top] =0;
    return temp;

}

double calculator(char *pInput, double *pNum) {
    char tok;
    double op1, op2;

    for (int i = 0; i < strlen(pInput); i++) {
        tok = pInput[i];

        if (tok >= 'A' && tok <= 'Z') {
            push(pNum[tok-65]);
        }
        else {
            op2 = pop();
            op1 = pop();

            switch (tok) {
                case '*' :
                    push(op1 * op2);
                    break;
                case '+' :
                    push(op1 + op2);
                    break;
                case '-' :
                    push(op1 - op2);
                    break;
                case '/' :
                    push(op1 / op2);
                    break;
            }
        }
    }
    return pop();
}

int main() {
    int N;
    char expression[MAX];
    double num[26];

    scanf("%d", &N);
    scanf("%s", expression);
    for (int i=0; i<N; i++)
        scanf("%lf", &num[i]);


    printf("%.2lf", calculator(expression, num));

    return 0;
}