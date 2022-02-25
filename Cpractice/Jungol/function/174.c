#include <stdio.h>

int sum(int x, int y, int z) {
    return x+y+z;
}

int main() {
    int scoreBoard[4][4];
    int i, j;
    for (i=0; i<3; i++) {
        scanf("%d %d %d", &scoreBoard[i][0], &scoreBoard[i][1], &scoreBoard[i][2]);
        scoreBoard[i][3] = sum(scoreBoard[i][0], scoreBoard[i][1], scoreBoard[i][2]);
    }

    for (i=0; i<4; i++) {
        scoreBoard[3][i] = sum(scoreBoard[0][i], scoreBoard[1][i], scoreBoard[2][i]);
    }

    for (i=0; i<4; i++) {
        for (j=0; j<4; j++) {
            printf("%d ", scoreBoard[i][j]);
        }
        printf("\n");
    }

    return 0;
}