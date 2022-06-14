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

    // 새로운 노드가 (새 데이터가 담긴 노드가) 추가될 위치를 찾는다.
    while(cNode != NULL) {
        if(GetData(cNode) == data)
            return; // 키 중복 허용 X

        pNode = cNode;

        if(GetData(cNode) > data)
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode);
    }

    // pNode 의 자식 노드로 추가할 새 노드의 생성
    nNode = MakeBTreeNode();
    SetData(nNode, data);

    // pNode 의 자식 노드로 새 노드를 추가
    if(pNode != NULL) { // 새 노드가 루트 노드가 아니면
        if(GetData(pNode) > data)
            MakeLeftSubTree(pNode, nNode);
        else
            MakeRightSubTree(pNode, nNode);
    }
    else { // 새 노드가 루트 노드 라면
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