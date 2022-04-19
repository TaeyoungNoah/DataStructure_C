
#ifndef PRACTICESELF_BALLOON_H
#define PRACTICESELF_BALLOON_H

typedef struct _balloon {
    int num;
    int weight;
} Balloon;

Balloon *MakeBalloon(int num, int weight);

#endif //PRACTICESELF_BALLOON_H
