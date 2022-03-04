#include <stdio.h>

int main() {
    int board[10][10];

    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    int x, y;
    x = 1;
    y = 1;

    if (board[1][1]!=2) {
        while(1) {
            board[x][y]=9;
            if (board[x][y+1]==2) {
                board[x][y+1]=9;
                break;
            }
            else if (board[x][y+1]==0) {
                y++;
                continue;
            }
            else {
                if (board[x+1][y]==2) {
                    board[x+1][y]=9;
                    break;
                }

                else if (board[x+1][y]==0) {
                    x++;
                    continue;
                }
                else
                    break;
            }
        }
    }
    else
        board[x][y]=9;


    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    return 0;
}