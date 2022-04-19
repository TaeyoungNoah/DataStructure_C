#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX 1000001

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
    int N, input[MAX], result[MAX];
    Stack stack;
    StackInit(&stack);

    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        scanf("%d", &input[i]);
    }

    SPush(&stack, input[N-1]);
    result[N-1]=-1;
    if (N>1) {
        for (int i = N - 2; i >= 0; i--) {
            while (!SIsEmpty(&stack) && input[i] >= SPeek(&stack)) {
                SPop(&stack);
            }
            if (SIsEmpty(&stack))
                result[i]=-1;
            else
                result[i] = SPeek(&stack);
            SPush(&stack, input[i]);
        }
    }


    for (int i=0; i<N; i++)
        printf("%d ", result[i]);



    return 0;
}