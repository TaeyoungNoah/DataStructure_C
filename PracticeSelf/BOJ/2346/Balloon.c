#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Balloon.h"


Balloon *MakeBalloon(int count, int num) {
    Balloon *pBalloon = (Balloon *) malloc(sizeof(Balloon));
    pBalloon->count = count;
    pBalloon->num = num;
    return pBalloon;
}