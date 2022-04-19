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

int main() {
    Stack leftStack;
    Stack rightStack;
    int T;
    char tok, temp;
    char input[MAX];



    scanf("%d", &T);

    for (int j=0; j<T; j++) {
        char result[MAX];
        scanf("%s", input);
        StackInit(&leftStack);
        StackInit(&rightStack);
        for (int i=0; i<strlen(input); i++) {
            tok = input[i];
            switch(tok) {
                case '<':
                    if (!SIsEmpty(&leftStack)) {
                        temp = SPop(&leftStack);
                        SPush(&rightStack,temp);
                    }
                    break;
                case '>':
                    if (!SIsEmpty(&rightStack)) {
                        temp = SPop(&rightStack);
                        SPush(&leftStack,temp);
                    }
                    break;
                case '-':
                    if (!SIsEmpty(&leftStack)) {
                        SPop(&leftStack);
                    }
                    break;
                default:
                    SPush(&leftStack, tok);
                    break;
            }
        }
        for (int i = SSize(&leftStack)-1; i>=0; i--) {
            result[i]= SPop(&leftStack);
        }

        for (int i = SSize(&leftStack); i<SSize(&leftStack)+SSize(&rightStack); i++) {
            result[i]= SPop(&rightStack);
        }

        printf("%s\n", result);
    }
    return 0;
}