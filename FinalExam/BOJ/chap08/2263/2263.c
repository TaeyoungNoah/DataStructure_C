#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int InOrder[100001];
int PostOrder[100001];

void findPreOrder(int inOrderStartIdx, int inOrderEndIdx, int postOrderStartIdx, int postOrderEndIdx) {
    if (inOrderStartIdx>inOrderEndIdx || postOrderStartIdx>postOrderEndIdx) {
        return;
    } // �Ұ����� ��Ȳ

    int root = PostOrder[postOrderEndIdx];
    int LCount; // ��Ʈ ��� ���� ���� ��� ����
    int rootIdx; // ������ȸ���� ��Ʈ ��� �ε���
    rootIdx = -1;

    for (int i=1; i<=inOrderEndIdx; i++) { // ������ȸ���� ��Ʈ ��� �ε��� ã��
        if (InOrder[i]==root) {
            rootIdx = i;
            break;
        }
    }

    LCount = rootIdx - inOrderStartIdx;

    // root
    printf("%d ", root);
    // left
    findPreOrder(inOrderStartIdx, rootIdx - 1, postOrderStartIdx, postOrderStartIdx + LCount - 1);
    // right
    findPreOrder(rootIdx + 1, inOrderEndIdx, postOrderStartIdx + LCount, postOrderEndIdx - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        scanf("%d", &InOrder[i]);
    }
    for (int i=1; i<=n; i++) {
        scanf("%d", &PostOrder[i]);
    }

    findPreOrder(1,n,1,n);



    return 0;
}