#include <stdio.h>

int main() {
    int a, m, d, n, i;
    long long int result;

    scanf("%d %d %d %d", &a, &m, &d, &n);

    result = a;
    for (i=1; i<n; i++) {
        result = result*m + d;
    }

    printf("%lld", result);
    return 0;
}