#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include "Exp.h"


Exp *MakeExp(int nom, int coef) {
    Exp *pExp = (Exp *) malloc(sizeof(Exp));
    pExp->nom = nom;
    pExp->coef = coef;
    return pExp;
}
