#include <stdio.h>
#include <stdlib.h>

#include "Balloon.h"

Balloon *MakeBalloon(int num, int weight) {
    Balloon *pBalloon = (Balloon *) malloc(sizeof(Balloon));
    pBalloon->num = num;
    pBalloon->weight = weight;
    return pBalloon;
}