#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 1001

void Swap(int arr[], int idx1, int idx2) {
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}


int Partition(int arr[], int left, int right) {
    int pivot = arr[left];    // ���� ������ �ǹ�
    int low = left+1;
    int high = right;

    while(low <= high) {    // �������� ���� ������ �ݺ�
        while(pivot >= arr[low] && low <= right) // �ǹ����� ū ���� ã�� �� ���� & ��� �˻�
            low++;

        while(pivot <= arr[high] && high >= (left+1)) // �ǹ����� ���� ���� ã�� �� ���� & ��� �˻�
            high--;

        if(low <= high)    // �������� ���� ���¶��
            Swap(arr, low, high);    // low�� high�� ����Ű�� ��� ��ȯ
    }

    Swap(arr, left, high);    // �ǹ��� high�� ����Ű�� ��� ��ȯ
    return high;    // �Ű��� �ǹ��� �ε��� ��ȯ
}

void QuickSort(int arr[], int left, int right) {
    if(left <= right) {
        int pivot = Partition(arr, left, right);    // �� �� ������ ���� �ǹ�
        QuickSort(arr, left, pivot-1);    // �ǹ� ����
        QuickSort(arr, pivot+1, right);    // �ǹ� ����
    }
}


int main() {
    int N;
    int numArr[MAX];

    scanf("%d", &N); // �� �������� ����
    for (int i=0; i<N; i++) {
        scanf("%d", &numArr[i]);
    }

    QuickSort(numArr, 0, N-1);

    for(int i = 0; i < N; i++)
        printf("%d\n", numArr[i]);

    return 0;
}