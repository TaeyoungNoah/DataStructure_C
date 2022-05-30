#include <stdio.h>

int ISearch(int ar[], int first, int last, int target) {
    int mid;

//    if(first > last) // arr 1 4 2 ��Ȳ �ݷ� ��� �̷��� ���ۺ��� ��
//        return -1;

    if(ar[first] > target || ar[last] < target)
        return -1;

    // A : Q = (high-low) : (s-low)
    mid = ((double) (target - ar[first]) / (ar[last] - ar[first]) * (last - first)) + first;

    if(target == ar[mid])
        return mid;
    else if(target < ar[mid])
        return ISearch(ar, first, mid - 1, target);
    else
        return ISearch(ar, mid + 1, last, target);
}

int main(void) {
    int arr[] = {1, 3, 5, 7, 9};
    int idx;

    idx = ISearch(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1, 2);
    if(idx == -1)
        printf("Ž�� ����\n");
    else
        printf("Ž�� ���� �ε��� : %d\n", idx);

    idx = ISearch(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1, 10);
    if(idx == -1)
        printf("Ž�� ����\n");
    else
        printf("Ž�� ���� �ε��� : %d\n", idx);

    return 0;
}