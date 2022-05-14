#include <stdio.h>
#include "BinaryTree2.h"

void ShowIntData(BTData data);

BTreeNode *SearchNode(BTreeNode *bt, char var) {
    if (bt == NULL)
        return NULL;

    if (bt->data == var) {
        return bt;
    }
    else {
        BTreeNode *temp;
        temp = SearchNode(bt->left, var);
        if (temp != NULL) {
            return temp;
        }
        temp = SearchNode(bt->right, var);
        if (temp != NULL) {
            return temp;
        }
        return NULL;
    }
}

void MakeSubTree(BTreeNode *bt, char left, char right) {
    if (left != '.') {
        BTreeNode *leftBt = MakeBTreeNode();
        SetData(leftBt, left);
        MakeLeftSubTree(bt, leftBt);
    }
    if (right != '.') {
        BTreeNode *rightBt = MakeBTreeNode();
        SetData(rightBt, right);
        MakeRightSubTree(bt, rightBt);
    }

}

int main(void) {
    int N;
    char node, left, right;

    BTreeNode *rootBt = MakeBTreeNode();
    BTreeNode *temp;

    scanf("%d", &N);
    scanf(" %c %c %c", &node, &left, &right);
    SetData(rootBt, node);
    MakeSubTree(rootBt, left, right);
    for (int i=1; i<N; i++) {
        scanf(" %c", &node);
        scanf(" %c %c", &left, &right);
        temp = SearchNode(rootBt, node);
        MakeSubTree(temp, left, right);
    }

    PreorderTraverses(rootBt, ShowIntData);
    printf("\n");
    InorderTraverses(rootBt, ShowIntData);
    printf("\n");
    PostorderTraverses(rootBt, ShowIntData);
    printf("\n");

    DeleteTree(rootBt);

    return 0;
}

void ShowIntData(BTData data) {
    printf("%c", data);
}