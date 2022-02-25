#include <stdio.h>

void multiplicationTable(int x) {

    printf("== %ddan ==\n", x);

    int i;
    for (i=1; i<10; i++)
        printf("%d * %d = %2d\n", x, i, x*i);
    printf("\n");
}

int main() {
    int from, to, temp, i;
    scanf("%d %d", &from, &to);
    if (from>to) {
        temp = from;
        from = to;
        to = temp;
    }

    for (i=from; i<=to; i++) {
        multiplicationTable(i);
    }

    return 0;
}