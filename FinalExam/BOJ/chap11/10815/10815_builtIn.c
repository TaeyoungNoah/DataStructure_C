#include <stdio.h>
#include <stdlib.h>

#define MAX 500001

int cmpQsort (const void * a, const void * b) {
    return *(int*)a > * (int*)b ? 1 : (*(int*)a < *(int*)b ? -1 : 0);
}

int cmpBsearch (void *first, void *second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}

int main() {
    int N, M, temp, find;
    int arr[MAX];

    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, N, sizeof(int), cmpQsort);

    scanf("%d", &M);
    for (int i=0; i<M; i++) {
        scanf("%d", &temp);
        find = (bsearch(&temp, arr, N, sizeof(int), cmpBsearch));
        if (find != NULL)
            printf("1 ");
        else
            printf("0 ");
    }
    return 0;
}
