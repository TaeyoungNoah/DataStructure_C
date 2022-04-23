#define _CRT_SECURE_NO_WARNINGS
#ifndef PRACTICESELF_EXP_H
#define PRACTICESELF_EXP_H


typedef struct __exp {
    int nom;
    int coef;
} Exp;

Exp *MakeExp(int nom, int coef);

#endif //PRACTICESELF_EXP_H
