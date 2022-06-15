#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "BinaryTree2.h"
#include "BinarySearchTree.h"

void BSTMakeAndInit(BTreeNode **pRoot) {
    *pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode *bst) {
    return GetData(bst);
}

void BSTInsert(BTreeNode **pRoot, BSTData data) {
    BTreeNode *pNode = NULL; // parent node
    BTreeNode *cNode = *pRoot; // current node
    BTreeNode *nNode = NULL; // new node

    // ���ο� ��尡 (�� �����Ͱ� ��� ��尡) �߰��� ��ġ�� ã�´�.
    while(cNode != NULL) {
        if(GetData(cNode) == data)
            return; // Ű �ߺ� ��� X

        pNode = cNode;

        if(GetData(cNode) > data)
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode);
    }

    // pNode �� �ڽ� ���� �߰��� �� ����� ����
    nNode = MakeBTreeNode();
    SetData(nNode, data);

    // pNode �� �ڽ� ���� �� ��带 �߰�
    if(pNode != NULL) { // �� ��尡 ��Ʈ ��尡 �ƴϸ�
        if(GetData(pNode) > data)
            MakeLeftSubTree(pNode, nNode);
        else
            MakeRightSubTree(pNode, nNode);
    }
    else { // �� ��尡 ��Ʈ ��� ���
        *pRoot = nNode;
    }
}

BTreeNode *BSTSearch(BTreeNode *bst, BSTData target) {
    BTreeNode *cNode = bst; // current node
    BSTData cd; // current data

    while(cNode != NULL) {
        cd = GetData(cNode);

        if(target == cd)
            return cNode;
        else if(target < cd)
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode);
    }

    return NULL;
}