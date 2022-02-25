#include <stdio.h>

int calculator(int x, int y, char operator) {
    if (operator == '+')
        return x + y;
    else if (operator == '-')
        return x - y;
    else if (operator == '*')
        return x * y;
    else if (operator == '/')
        return x / y;
    else
        return 0;
}

int main() {
    int a, b;
    char operator;
    scanf("%d %c %d", &a, &operator, &b);
    printf("%d %c %d = %d", a, operator, b, calculator(a, b, operator));
    return 0;
}