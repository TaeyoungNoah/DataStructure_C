#include <stdio.h>

int main() {
    int num, i;
    int *ptr = &num;

    scanf("%d", ptr);

    for (i=0; i<*ptr; i++)
        printf("*");
    return 0;
}
