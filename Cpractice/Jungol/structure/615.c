#include <stdio.h>

struct student {
    char name[20];
    int kor;
    int eng;
};

int average(int score1, int score2) {
    return (score1 + score2)/2;
}

int main() {
    struct student student1;
    struct student student2;

    scanf("%s %d %d", student1.name, &student1.kor, &student1.eng);
    scanf("%s %d %d", student2.name, &student2.kor, &student2.eng);

    printf("%s %d %d\n", student1.name, student1.kor, student1.eng);
    printf("%s %d %d\n", student2.name, student2.kor, student2.eng);

    printf("avg %d %d\n", average(student1.kor, student2.kor), average(student1.eng, student2.eng));
    return 0;
}
