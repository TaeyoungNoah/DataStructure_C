#include <stdio.h>

int main() {
    int x, y, i, j;
    scanf("%d %d", &x, &y);

    for (i = 1; i <= x; i++) {
        for (j = 1; j <= y; j++) {
            printf("%d %d\n", i, j);
        }
    }
    return 0;
}