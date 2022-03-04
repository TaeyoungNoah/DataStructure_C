#include <stdio.h>

int main() {
    int n, x, y;
    int board[19][19] = {};

    for (int i=0; i<19; i++) {
        for (int j=0; j<19; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        for (int j=0; j<19; j++) { // 세로
            if (board[x-1][j]==0)
                board[x-1][j]=1;
            else
                board[x-1][j]=0;
        }
        for (int j=0; j<19; j++) { // 가로
            if (board[j][y-1]==0)
                board[j][y-1]=1;
            else
                board[j][y-1]=0;
        }
//        if (board[x-1][y-1]==0)
//            board[x-1][y-1]=1;
//        else
//            board[x-1][y-1]=0;
    }



    for (int i=0; i<19; i++) {
        for (int j=0; j<19; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    return 0;
}