#include <stdio.h>
#include <string.h>

#define MAX 1000000

char stack[MAX];
int top = 0;

void push(char data) {
    stack[top] = data;
    top++;
}

char pop() {
    top--;
    return stack[top];
}

int isEmpty() {
    if (top==0)
        return 1;
    else
        return 0;
}


int main() {
    char sentence[MAX], result[MAX], tok;
    int count, flag;
    count = 0;
    flag = 0;
    fgets(sentence, MAX, stdin);
    for (int i=0; i<strlen(sentence)-1; i++) {
        tok = sentence[i];
        if (tok == '<') {
            while (!isEmpty()) {
                result[count] = pop();
                count++;
            }
            flag = 1;
            result[count] = tok;
            count++;
        }
        else if (tok == '>') {
            flag = 0;
            result[count] = tok;
            count++;
        }
        else if (flag == 1){
            result[count] = tok;
            count++;
        }
        else if (tok == ' ' && flag == 0) {
            while (!isEmpty()) {
                result[count] = pop();
                count++;
            }
            result[count] = tok;
            count++;
        }
        else {
            push(tok);
        }
    }

    while (!isEmpty()) {
        result[count] = pop();
        count++;
    }

    printf("%s", result);
    return 0;
}
