#include <stdio.h>

int main() {
    char a;
    char *ap = &a;
    int b;
    int *bp = &b;

    printf("%#p %#p", *ap, *bp);
    return 0;
}