#include <stdio.h>

int printer(int a) {
    if (a==1)
        return 1;
    printf("%d ", a);
    printer(a-1);
}

int main() {
    int userInput;
    scanf("%d", &userInput);
    printf("%d", printer(userInput));
    return 0;

}