#include <stdlib.h>
#include <string.h>
#include "InfixToPostfix.h"
#include "PostCalculator.h"

int EvalInfixExp(char exp[]) {
    int ret;
    int len = strlen(exp);
    char *expcpy = (char *)malloc(len + 1);
    strcpy(expcpy, exp);
    ConvToRPNExp(expcpy); // 후위표현식으로 고치고
    ret = EvalRPNExp(expcpy); // 그걸 계산

    free(expcpy);
    return ret;

}