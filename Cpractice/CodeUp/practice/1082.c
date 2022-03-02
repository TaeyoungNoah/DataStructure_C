#include <stdio.h>

int main() {
    int num, i;
    scanf("%X", &num);

    for (i = 1; i < 16; i++) {
        printf("%X*%X=%X\n", num, i, num * i);
    }
    return 0;
}