#include <stdio.h>
#include <stdlib.h>

typedef char BTData;

typedef struct _bTreeNode {
    BTData data;
    struct _bTreeNode *left;
    struct _bTreeNode *right;
} BTreeNode;

typedef void VisitFuncPtr(BTData data);

void PreorderTraverses(BTreeNode *bt, VisitFuncPtr action);
void InorderTraverses(BTreeNode *bt, VisitFuncPtr action);
void PostorderTraverses(BTreeNode *bt, VisitFuncPtr action);

void DeleteTree(BTreeNode *bt);

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
        DeleteTree(main->left);

    main->left = sub;
}

void MakeRightSubTree(BTreeNode *main, BTreeNode *sub) {
    if(sub->right != NULL)
        DeleteTree(main->right);

    main->right = sub;
}

void PreorderTraverses(BTreeNode *bt, VisitFuncPtr action) {
    if(bt == NULL)
        return;

    action(bt->data);
    PreorderTraverses(bt->left, action);
    PreorderTraverses(bt->right, action);
}

void InorderTraverses(BTreeNode *bt, VisitFuncPtr action) {
    if(bt == NULL)
        return;

    InorderTraverses(bt->left, action);
    action(bt->data);
    InorderTraverses(bt->right, action);
}

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

    return 0;
}

void ShowIntData(BTData data) {
    printf("%c", data);
}