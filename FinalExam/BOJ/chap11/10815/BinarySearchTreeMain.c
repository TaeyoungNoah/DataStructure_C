#include <stdio.h>
#include "BinarySearchTree.h"

int main(void) {
    int N, M, temp;
    BTreeNode *bstRoot;
    BTreeNode *sNode;


    BSTMakeAndInit(&bstRoot);

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &temp);
        BSTInsert(&bstRoot, temp);
    }

    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d", &temp);
        sNode = BSTSearch(bstRoot, temp);
        if(sNode == NULL)
            printf("0 ");
        else
            printf("1 ");
    }

    return 0;
}