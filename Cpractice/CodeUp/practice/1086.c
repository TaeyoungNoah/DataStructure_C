#include <stdio.h>
#include <math.h>

double makeRound(double num) {
    return round(num * 100) * 0.01;
}


int main() {
    double w, h, b, result, divide;
    scanf("%lf %lf %lf", &w, &h, &b);

    divide = pow(2.0, 23.0);

    result = makeRound((w * h * b) / divide);

    printf("%.2lf MB", result);

    return 0;
}