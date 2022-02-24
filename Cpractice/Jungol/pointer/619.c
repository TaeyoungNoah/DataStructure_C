#include <stdio.h>

int main() {
    int x;
    int * ptr;

    scanf("%d", &x);

    ptr = &x;

    printf("%#p %d", *ptr, x);

    return 0;
}