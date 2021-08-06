#include <stdio.h>

int edge[101][101];
int visit[101];
int main(void) {
    int N, M, i, x, y, n, v, top, stack[10000];
    scanf("%d %d", &N, &M);
    for (i=0; i<M; i++) {
        scanf("%d %d", &x, &y);
        edge[x][y] = edge[y][x] = 1;
    }

    n = top = 0;
    stack[0] = 1;
    while (top >= 0) {
        v = stack[top--];
        if (visit[v]) continue;
        visit[v] = 1;
        n++;
        for (i=1; i<=N; i++) if (edge[v][i] && !visit[i]) stack[++top] = i;
    }
    printf("%d", n-1);
    return 0;
}