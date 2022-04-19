#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX 100000

typedef char Data;

typedef struct _node {
    Data data;
    struct _node *next;
} Node;

typedef struct _listStack {
    Node *head;
    int numOfData;
} ListStack;

typedef ListStack Stack;

void StackInit(Stack *pstack) {
    pstack->head = NULL;
    pstack->numOfData = 0;
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

    (pstack->numOfData)++;
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
    (pstack->numOfData)--;
    return rdata;
}

Data SPeek(Stack *pstack) {
    if(SIsEmpty(pstack)) {
        printf("Stack Memory Error!\n");
        exit(-1);
    }

    return pstack->head->data;
}

int LCount(Stack *pstack) {
    return pstack->numOfData;
}

int main() {
    Stack stack;
    StackInit(&stack);
    int flag, result;
    char input[MAX];
    scanf("%s", input);
    flag = 0; // 앞에 (면 0, )면 1
    result = 0;

    for (int i=0; i<strlen(input); i++) {
        if (input[i]=='(') {
            SPush(&stack, '(');
            flag = 0;
        }
        else {
            if (flag==0) {
                SPop(&stack);
                result+= LCount(&stack);
                flag=1;
            }
            else {
                SPop(&stack);
                result+=1;
                flag=1;
            }
        }
    }
    printf("%d", result);
    return 0;
}