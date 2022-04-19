#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define TRUE 1
#define FALSE 0

typedef double Data;

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




double EvalRPNExp(char exp[], double numTable[]) {
    Stack stack;
    int i;
    int expLen = strlen(exp);
    char tok;
    double op1, op2;

    StackInit(&stack);
    for (i = 0; i < expLen; i++) {
        tok = exp[i];

        if (tok>='A' && tok<='Z') {
            SPush(&stack, numTable[tok-65]);
        } else {
            op2 = SPop(&stack);
            op1 = SPop(&stack);

            switch (tok) {
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

int main() {
    int N;
    double numTable[26], temp, result;
    char inputExp[100];

    scanf("%d", &N);
    scanf("%s", inputExp);
    for (int i = 0; i < N; i++) {
        scanf("%lf", &temp);
        numTable[i] = temp;
    }

    result = EvalRPNExp(inputExp, numTable);

    printf("%.2lf", result);



    return 0;
}