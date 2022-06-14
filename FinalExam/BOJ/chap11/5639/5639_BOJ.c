#include <stdio.h>
#include <stdlib.h>

typedef int BTData;

typedef struct _bTreeNode {
    BTData data;
    struct _bTreeNode *left;
    struct _bTreeNode *right;
} BTreeNode;


BTreeNode *MakeBTreeNode(void) {
    BTreeNode *nd = (BTreeNode *)malloc(sizeof(BTreeNode));
    nd->left = NULL;
    nd->right = NULL;

    return nd;
}

BTData GetData(BTreeNode *bt) {
    return bt->data;
}

void SetData(BTreeNode *bt, BTData data) {
    bt->data = data;
}

BTreeNode *GetLeftSubTree(BTreeNode *bt) {
    return bt->left;
}

BTreeNode *GetRightSubTree(BTreeNode *bt) {
    return bt->right;
}

void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub) {
    if(main->left != NULL)
        free(main->left);

    main->left = sub;
}

void MakeRightSubTree(BTreeNode *main, BTreeNode *sub) {
    if(sub->right != NULL)
        free(main->right);

    main->right = sub;
}


typedef void VisitFuncPtr(BTData data);

void PostorderTraverses(BTreeNode *bt, VisitFuncPtr action) {
    if(bt == NULL)
        return;

    PostorderTraverses(bt->left, action);
    PostorderTraverses(bt->right, action);
    action(bt->data);
}

void DeleteTree(BTreeNode *bt) {
    if(bt == NULL)
        return;

    DeleteTree(bt->left);
    DeleteTree(bt->right);

    printf("del tree data: %d\n", bt->data);
    free(bt);
}

typedef BTData BSTData;


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

void ShowIntData(BTData data);

int main(void) {
    int temp;
    BTreeNode *bstRoot;
    BTreeNode *sNode;

    BSTMakeAndInit(&bstRoot);

    while (scanf("%d", &temp) !=EOF) {
        BSTInsert(&bstRoot, temp);
    }


    PostorderTraverses(bstRoot, ShowIntData);


    return 0;
}

void ShowIntData(BTData data) {
    printf("%d\n", data);
}