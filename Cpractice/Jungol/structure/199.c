#include <stdio.h>

typedef struct student {
    char name[20];
    int kor;
    int eng;
    int math;
    int total;
} student;

int main() {
    int sizeOfClass, i ,j;

    scanf("%d", &sizeOfClass);

    student class[sizeOfClass], temp;

    for (i=0; i<sizeOfClass; i++) {
        scanf("%s %d %d %d", class[i].name, &class[i].kor, &class[i].eng, &class[i].math);
        class[i].total = class[i].kor + class[i].eng + class[i].math;
    }

    for (i=0; i<sizeOfClass; i++) {
        for (j=i; j<sizeOfClass; j++) {
            if (class[i].total<class[j].total) {
                temp = class[i];
                class[i] = class[j];
                class[j] = temp;
            }
        }
    }

    for (i=0; i<sizeOfClass; i++) {
        printf("%s %d %d %d %d\n", class[i].name, class[i].kor, class[i].eng, class[i].math, class[i].total);
    }


    return 0;
}