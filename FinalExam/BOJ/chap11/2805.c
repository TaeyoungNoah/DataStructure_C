#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N, M;
    int * treeArr;
    long long left, mid, right, sum, max, result;
    scanf("%d %d",&N, &M);
    treeArr = (int*) malloc(N * sizeof(int));

    max=0;
    for (int i=0; i<N; i++) {
        scanf(" %d", &treeArr[i]);
        if (max < treeArr[i])
            max = treeArr[i];
    }

    result = 0;
    left = 0;
    right = max;
    while(left<=right) {
        mid = (left+right)/2;
        sum = 0;
        for (int i=0; i<N; i++) {
            if (treeArr[i]>mid)
                sum += (treeArr[i]-mid);
        }

        if (sum<M)
            right = mid-1;
        else {
            if (mid > result)
                result = mid;
            left = mid+1;
        }

    }

    printf("%lld", result);

    return 0;
}