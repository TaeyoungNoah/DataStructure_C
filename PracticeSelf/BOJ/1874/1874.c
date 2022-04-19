#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX 100005

typedef int Data;

typedef struct _node {
    Data data;
    struct _node *next;
} Node;

typedef struct _listStack {
    Node *head;
} ListStack;

typedef ListStack Stack;

void StackInit(Stack *pstack) {
    pstack->head = NULL;
}

int SIsEmpty(Stack *pstack) {
    if(pstack->head == NULL)
        return TRUE;
    else
        return FALSE;
}

void SPush(Stack *pstack, Data data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = pstack->head;
    pstack->head = newNode;
}

Data SPop(Stack *pstack) {
    Data rdata;
    Node *rnode;

    if(SIsEmpty(pstack)) {
        printf("Stack Memory Error!\n");
        exit(-1);
    }

    rnode = pstack->head;
    rdata = pstack->head->data;

    pstack->head = pstack->head->next;

    free(rnode);
    return rdata;
}

Data SPeek(Stack *pstack) {
    if(SIsEmpty(pstack)) {
        printf("Stack Memory Error!\n");
        exit(-1);
    }

    return pstack->head->data;
}


int main() {
    Stack stack;
    StackInit(&stack);

    int n, result_idx, num_count, input_idx, flag;
    int input[MAX];
    char result[MAX * 2];
    result_idx = 0;
    num_count = 1;
    input_idx = 0;
    flag = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &input[i]);
    }

    while (flag==1) {
        if (num_count <= input[input_idx]) {
            SPush(&stack, num_count);
            result[result_idx] = '+';
            result_idx++;
            num_count++;
        }
        else {
            if (SPeek(&stack) == input[input_idx]) {
                SPop(&stack);
                result[result_idx] = '-';
                result_idx++;
                input_idx++;
            }
            else if (SPeek(&stack) > input[input_idx]) {
                flag = 0;
                break;
            }
            else
                break;
        }
        if (input_idx == n)
            break;
    }

    if (flag == 1) {
        for (int i = 0; i < strlen(result); i++) {
            printf("%c\n", result[i]);
        }
    } else
        printf("NO");


    return 0;
}