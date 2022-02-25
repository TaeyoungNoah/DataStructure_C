#include <stdio.h>
#include <math.h>

int main() {
    double from, to, temp;
    scanf("%lf %lf", &from, &to);

    if (from>to) {
        temp = from;
        from = to;
        to = temp;
    }

    double fromSqrt, toSqrt;
    fromSqrt = ceil(sqrt(from));
    toSqrt = floor(sqrt(to));


    printf("%d", (int)(toSqrt - fromSqrt + 1));
    return 0;
}