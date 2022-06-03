#include <stdio.h>

#define MAX 1000

void Swap(int arr[], int idx1, int idx2) {
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}


int Partition(int arr[], int left, int right) {
    int pivot = arr[left];    // �ǹ��� ��ġ�� ���� ����!
    int low = left+1;
    int high = right;

    while(low <= high) {    // �������� ���� ������ �ݺ�
        while(pivot <= arr[low] && low <= right)
            low++;

        while(pivot >= arr[high] && high >= (left+1))
            high--;

        if(low <= high)    // �������� ���� ���¶�� Swap ����
            Swap(arr, low, high);    // low�� high�� ����Ű�� ��� ��ȯ
    }

    Swap(arr, left, high);    // �ǹ��� high�� ����Ű�� ��� ��ȯ
    return high;    // �Ű��� �ǹ��� ��ġ ���� ��ȯ
}

void QuickSort(int arr[], int left, int right) {
    if(left <= right) {
        int pivot = Partition(arr, left, right);    // �ѷ� ������
        QuickSort(arr, left, pivot-1);    // ���� ������ ����
        QuickSort(arr, pivot+1, right);    // ������ ������ ����
    }
}


int main(void) {
    int arr[MAX];
    int N, num;

    scanf("%d", &num);

    N = 0;
    while(num>0) {
        arr[N] = num%10;
        num/=10;
        N++;
    }

    QuickSort(arr, 0, N - 1);

    for(int i = 0; i < N; i++)
        printf("%d", arr[i]);


    return 0;
}