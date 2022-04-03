#include <stdio.h>
#include <string.h>
#define MAX 100000

int stack[MAX];
int top = 0;

void push(int data) {
    stack[top] = data;
    top++;
}

int pop() {
    if (top>0) {
        top--;
        return stack[top];
    }
    else
        return 0;
}

int peek() {
    if (top>0)
        return stack[top-1];
    else
        return 0;
}

int main() {
    int N, stackCount, inputCount, resultCount, flag;
    char result[MAX*3];
    int input[MAX];

    scanf("%d", &N);
    for(int i = 0; i<N; i++) {
        scanf("%d", &input[i]);
    }

    flag = 0;
    stackCount=1;
    inputCount=0;
    resultCount=0;
    while(1) {
        if (input[inputCount] < stackCount && input[inputCount]!=peek())
            break;

        else if (peek() != input[inputCount]) {
            push(stackCount);
            stackCount++;
            result[resultCount]='+';
            resultCount++;
        }

        if (peek() == input[inputCount]) {
            pop();
            inputCount++;
            result[resultCount]='-';
            resultCount++;
        }

        if (inputCount == N){
            flag = 1;
            break;
        }

    }

    if (flag==0)
        printf("NO");
    else {
        for (int i=0; i<strlen(result); i++) {
            printf("%c\n", result[i]);
        }

    }
    return 0;
}