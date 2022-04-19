#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX 1000000

typedef char Data;

typedef struct _node {
    Data data;
    struct _node *next;
} Node;

typedef struct _listStack {
    Node *head;
    int size;
} ListStack;

typedef ListStack Stack;

void StackInit(Stack *pstack) {
    pstack->head = NULL;
    pstack->size = 0;
}

int SIsEmpty(Stack *pstack) {
    if(pstack->head == NULL)
        return TRUE;
    else
        return FALSE;
}

int SSize(Stack *pstack) {
    return pstack->size;
}

void SPush(Stack *pstack, Data data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = pstack->head;
    pstack->head = newNode;

    (pstack->size)++;
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
    (pstack->size)--;
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
    char input[MAX], tok;
    int T, result;

    scanf("%d", &T);
    result = 0;

    for (int i=0; i<T; i++) {
        StackInit(&stack);
        scanf("%s", input);
        for (int j=0; j<strlen(input); j++) {
            tok = input[j];
            if (SIsEmpty(&stack)) {
                SPush(&stack, tok);
            }
            else {
                if (SPeek(&stack)==tok){
                    SPop(&stack);
                }
                else {
                    SPush(&stack, tok);
                }
            }
        }
        if (SIsEmpty(&stack)) {
            result+=1;
        }
    }

    printf("%d", result);


    return 0;
}