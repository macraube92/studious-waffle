#include <stdio.h>


int visit[100][100];
char maze[100][101];
int q[20000][3];
int f, b;

#define PUSH(X, Y, R) q[b][0]=(X); q[b][1]=(Y); q[b++][2]=(R);
#define POP(X, Y, R) X=q[f][0]; Y=q[f][1]; R=q[f++][2];
#define CHECK(x, y) (maze[y][x] == '1' && !visit[y][x])

int main(void) {
    int N, M, i, x, y, r;

    scanf("%d %d", &N, &M);
    for (i=0; i<N; i++) scanf("%s", maze[i]);

    PUSH(0, 0, 1);
    while (f != b) {
        POP(x, y, r);
        if (visit[y][x]) continue;
        else if (x == M-1 && y == N-1) break;

        visit[y][x] = 1;
        r++;
        if (x+1 < M && CHECK(x+1, y)) { PUSH(x+1, y, r); }
        if (x-1 >= 0 && CHECK(x-1, y)) { PUSH(x-1, y, r); }
        if (y+1 < N && CHECK(x, y+1)) { PUSH(x, y+1, r); }
        if (y-1 >= 0 && CHECK(x, y-1)) { PUSH(x, y-1, r); }
    }

    printf("%d", r);
    return 0;
}