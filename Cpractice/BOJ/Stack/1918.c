#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = 0;

void push(char data) {
    stack[top] = data;
    top++;
}

char pop() {
    if (top>0) {
        top--;
        return stack[top];
    }
}

char peek() {
    if (top>0) {
        return stack[top - 1];
    }
}

int checkImportance(char op) {
    switch (op) {
        case '*':
        case '/':
            return 5;
        case '+':
        case '-':
            return 3;
        case '(':
        case ')':
            return 1;
    }
    return -1;
}

int checkPriority(char op1, char op2) {
    if (checkImportance(op1) > checkImportance(op2))
        return 1;
    else if (checkImportance(op1) == checkImportance(op2))
        return 0;
    else
        return -1;
}

int isEmpty() {
    if (top==0)
        return 1;
    else
        return 0;
}


int main() {
    char expression[MAX] , result[MAX]={0}, tok, temp;
    int index;
    index = 0;
    scanf("%s", expression);

    for (int i=0; i<strlen(expression); i++) {
        tok = expression[i];
        if (checkImportance(tok)==-1) {
            result[index] = tok;
            index++;
        }
        else {
            switch (tok) {
                case '(':
                    push(tok);
                    break;
                case ')':
                    while (1) {
                        temp = pop();
                        if (temp == '(')
                            break;
                        result[index] = temp;
                        index++;
                    }
                    break;
                case '*':
                case '/':
                case '+':
                case '-':
                    while (!isEmpty() && checkPriority(peek(), tok)>-1) {
                        result[index] = pop();
                        index++;
                    }
                    push(tok);
                    break;
            }
        }
    }
    while(!isEmpty()) {
        result[index] = pop();
        index++;
    }

    printf("%s", result);
    return 0;
}