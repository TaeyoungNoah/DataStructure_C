#include<stdio.h>

int main()
{
    int T,N,a,b,x,cnt;
    int rank[100000][2];

    scanf("%d", &T);

    while(T--){
        scanf("%d", &N);
        cnt=1;
        for(int i = 0; i < N; i++){ //�����ɻ� ������ ������������ ����
            scanf("%d %d", &a, &b);
            rank[a-1][0] = a;
            rank[a-1][1] = b;
        }
        x=rank[0][1];
        for(int i = 1; i < N; i++){ //2��°���� ��
            if(x>rank[i][1]){
                x=rank[i][1];
                cnt+=1;
            }
        }
        printf("%d\n", cnt);
    }
}