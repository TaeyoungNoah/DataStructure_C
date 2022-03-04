#include <stdio.h>

int main() {
    int n, i, input;
    int attendance[24] = {};

    scanf("%d", &n);

    for (i=0; i<n; i++) {
        scanf("%d", &input);
        attendance[input]++;
    }

    for (i=1; i<24; i++) {
        printf("%d ", attendance[i]);
    }

    return 0;
}