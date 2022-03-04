#include <stdio.h>

int main() {
    int h, w;
    scanf("%d %d", &h, &w);

    int board[100][100];
    int n, l, d, x, y;

    scanf("%d", &n);


    for (int i=0; i<n; i++) {
        scanf("%d %d %d %d", &l, &d, &x, &y);
        for (int j=0; j<l; j++) {
            if (d==0) {
                board[x-1][y+j-1]=1;
            }
            else {
                board[x+j-1][y-1]=1;
            }
        }
    }

    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}