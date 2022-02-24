# include <stdio.h>
# include <stdlib.h>

int main() {
    int *a = (int *)malloc(sizeof(int));
    int *b = (int *)malloc(sizeof(int));
    int *c = (int *)malloc(sizeof(int));

    scanf("%d %d", a, b);
    if (*a>*b) {
        *c = *a - *b;
    }
    else {
        *c = *b - *a;
    }

    printf("%d", *c);
    return 0;
}