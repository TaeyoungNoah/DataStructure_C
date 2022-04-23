#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "DLinkedList.h"
#include "Exp.h"

int WhoIsPrecede(int data1, int  data2) {
    if (data1 > data2) // strcmp : data1.name < data2.name 이면 음수를 반환함
        return 0;
    else
        return 1;
}

int main() {
    List list;
    int T;
    int nom, coef;
    Exp *exp;

    ListInit((&list));
    SetSortRule(&list, WhoIsPrecede);

    scanf("%d", &T);

    for (int i=0; i<T; i++) {
        scanf("%d %d", &nom, &coef);
        exp = MakeExp(nom, coef);
        LInsert(&list, exp);
    }


    if (LFirst(&list, &exp)) {
        if (exp->nom>0) {
            printf("+");
            printf("%dx^%d", exp->nom, exp->coef);
        }
        else {
            printf("-");
            printf("%dx^%d", -(exp->nom), exp->coef);
        }
        while (LNext(&list, &exp)) {
            if (exp->coef!=1 && exp->coef!=0) {
                if (exp->nom>0) {
                    printf("+");
                    printf("%dx^%d", exp->nom, exp->coef);
                }
                else {
                    printf("-");
                    printf("%dx^%d", -(exp->nom), exp->coef);
                }
            }
            else {
                if (exp->coef==1) {
                    if (exp->nom>0) {
                        printf("+");
                        printf("%dx", exp->nom);
                    }
                    else {
                        printf("-");
                        printf("%dx", -(exp->nom));
                    }
                }

                else {
                    if (exp->nom>0) {
                        printf("+");
                        printf("%d", exp->nom);
                    }
                    else {
                        printf("-");
                        printf("%d", -(exp->nom));
                    }
                }


            }
        }
    }



    return 0;

}