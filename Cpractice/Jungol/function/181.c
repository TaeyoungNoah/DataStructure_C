#include <stdio.h>
#include <math.h>
#define PI 3.141592

double area(double radius) {
    return PI * radius * radius;
}

double roundFourth(double num) {
    double a;
    a = round(num * 1000);
    return a*0.001;

}

int main() {
    double userInput, userArea;
    printf("radius : ");
    scanf("%lf", &userInput);
    userArea = area(userInput);
    printf("area = %.3lf", roundFourth(userArea));
    return 0;
}