#include <stdio.h>
#include <math.h>

double makeRound(double num) {
    return round(num * 10) * 0.1;
}

int main() {
    double h, b, c, s;
    double divide, result;
    divide = pow(2.0, 23.0);

    scanf("%lf %lf %lf %lf", &h, &b, &c, &s);

    result = makeRound((h * b * c * s) / divide);

    printf("%.1lf MB", result);
    return 0;
}