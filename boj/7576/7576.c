#include <stdio.h>

int box[1000][1000];
int visit[1000][1000];
int q[1000000][3];
int f, b, n, t;

#define PUSH(x, y, d) { q[b][0] = x; q[b][1] = y; q[b++][2] = d; }
int main(void) {
    int M, N, x, y, d;
    scanf("%d %d", &M, &N);
    t = N * M;
    for (y=0; y<N; y++) {
        for (x=0; x<M; x++) {
            scanf("%d", &box[y][x]);
            if (box[y][x] == 1) PUSH(x, y, 0)
            else if (box[y][x] == -1) t--;
        }
    }
    while (f != b) {
        x = q[f][0];
        y = q[f][1];
        d = q[f++][2];
        n++;
        if (x-1 >= 0 && box[y][x-1] == 0) {
            PUSH(x-1, y, d+1);
            box[y][x-1] = 1;
        }
        if (x+1 < M && box[y][x+1] == 0) {
            PUSH(x+1, y, d+1);
            box[y][x+1] = 1;
        }
        if (y-1 >= 0 && box[y-1][x] == 0) {
            PUSH(x, y-1, d+1);
            box[y-1][x] = 1;
        }
        if (y+1 < N && box[y+1][x] == 0) {
            PUSH(x, y+1, d+1);
            box[y+1][x] = 1;
        }
    }
    printf("%d", (n == t ? d : -1));
    return 0;
}