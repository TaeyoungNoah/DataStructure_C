#include <stdio.h>

#define MAX 100000

int stack[MAX];
int top = 0;
int sum = 0;

void push(int data) {
    stack[top] = data;
    sum += data;
    top++;
}

void pop() {
    top--;
    sum -= stack[top];
    stack[top] = 0;
}

int main() {
    int k, num;
    scanf("%d", &k);
    for (int i=0; i<k; i++) {
        scanf("%d", &num);
        if (num!=0)
            push(num);
        else
            pop();
    }

    printf("%d", sum);



    return 0;
}