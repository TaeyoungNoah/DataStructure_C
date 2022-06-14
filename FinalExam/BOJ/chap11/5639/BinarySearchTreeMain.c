#include <stdio.h>
#include "BinarySearchTree.h"
#include "BinaryTree2.h"


void ShowIntData(BTData data);

int main(void) {
    int N, temp;
    BTreeNode *bstRoot;
    BTreeNode *sNode;

    BSTMakeAndInit(&bstRoot);

    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        scanf("%d", &temp);
        BSTInsert(&bstRoot, temp);
    }

    PostorderTraverses(bstRoot, ShowIntData);


    return 0;
}

void ShowIntData(BTData data) {
    printf("%d\n", data);
}