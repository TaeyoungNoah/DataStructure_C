#include <stdio.h>
#include <stdlib.h>

void MergeTwoArea(int arr[], int left, int mid, int right) {
    int fIdx = left; // �迭�� ���� ������ ����Ŵ
    int rIdx = mid + 1; // �迭�� ���� ������ ����Ŵ
    int i;

    int *sortArr = (int *)malloc(sizeof(int) * (right + 1));
    int sIdx = left; // �� �迭�� ���� �ε���

    while(fIdx <= mid && rIdx <= right) {
        if(arr[fIdx] <= arr[rIdx]) // ���� �� �� ������ �����͵��� ���Ͽ�,
            sortArr[sIdx] = arr[fIdx++]; // ���� ������� sortArr�� �ϳ��� �Ű� ��´�.
        else
            sortArr[sIdx] = arr[rIdx++];

        sIdx++;
    }

    if(fIdx > mid) { // �迭�� �պκ��� ��� sortArr�� �Ű����ٸ�
        for(i = rIdx; i <= right; i++, sIdx++)
            sortArr[sIdx] = arr[i]; // �迭 �޺κп� ���� �����͵��� sortArr�� �״�� �ű��
    }
    else { // �迭�� �޺κ��� ��� sortArr�� �Ű����ٸ�,
        for(i = fIdx; i <= mid; i++, sIdx++)
            sortArr[sIdx] = arr[i]; // �迭 �պκп� ���� �����͵��� sortArr�� �״�� �ű��
    }

    for(i = left; i <= right; i++) {
        arr[i] = sortArr[i];
    }

    free(sortArr);
}

void MergeSort(int arr[], int left, int right) {
    int mid;

    if(left < right) {
        mid = (left + right) / 2;

        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);

        MergeTwoArea(arr, left, mid, right);
    }
}

int main(void) {
    int arr[] = {3, 2, 7, 1, 4, 6, 5};
    int len = sizeof(arr) / sizeof(arr[0]);
    int i;
    MergeSort(arr, 0, len - 1);

    for(i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}