#include <stdio.h>
#include "BinaryTree.h"

void InorderTraverses(BTreeNode *bt) { // 중위 순회
    if(bt == NULL)
        return;

    InorderTraverses(bt->left);
    printf("%d ", bt->data);
    InorderTraverses(bt->right);
}

void PreorderTraverses(BTreeNode *bt) { // 전위 순회
    if(bt == NULL)
        return;

    printf("%d ", bt->data);
    PreorderTraverses(bt->left);
    PreorderTraverses(bt->right);

}

void PostorderTraverses(BTreeNode *bt) { // 후위 순회
    if(bt == NULL)
        return;

    PostorderTraverses(bt->left);
    PostorderTraverses(bt->right);
    printf("%d ", bt->data);
}

int main(void) {
    BTreeNode *bt1 = MakeBTreeNode();
    BTreeNode *bt2 = MakeBTreeNode();
    BTreeNode *bt3 = MakeBTreeNode();
    BTreeNode *bt4 = MakeBTreeNode();
    BTreeNode *bt5 = MakeBTreeNode();
    BTreeNode *bt6 = MakeBTreeNode();
    BTreeNode *bt7 = MakeBTreeNode();
    BTreeNode *bt8 = MakeBTreeNode();
    BTreeNode *bt9 = MakeBTreeNode();
    BTreeNode *bt10 = MakeBTreeNode();
    BTreeNode *bt11 = MakeBTreeNode();

    SetData(bt1, 1);
    SetData(bt2, 2);
    SetData(bt3, 3);
    SetData(bt4, 4);
    SetData(bt5, 5);
    SetData(bt6, 6);
    SetData(bt7, 7);
    SetData(bt8, 8);
    SetData(bt9, 9);
    SetData(bt10, 10);
    SetData(bt11, 11);


    MakeLeftSubTree(bt1, bt2);
    MakeRightSubTree(bt1, bt3);

    MakeLeftSubTree(bt2, bt4);
    MakeRightSubTree(bt2, bt5);

    MakeLeftSubTree(bt3, bt6);
    MakeRightSubTree(bt3, bt7);

    MakeLeftSubTree(bt4, bt8);
    MakeRightSubTree(bt4, bt9);

    MakeLeftSubTree(bt6, bt10);
    MakeRightSubTree(bt6, bt11);

    printf("=== 전위 순회 ===\n");
    PreorderTraverses(bt1);
    printf("\n");
    printf("=== 중위 순회 ===\n");
    InorderTraverses(bt1);
    printf("\n");
    printf("=== 후위 순회 ===\n");
    PostorderTraverses(bt1);
    printf("\n");

    return 0;
}