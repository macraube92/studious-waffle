#include <stdio.h>

int buf[100000];
int graph[1001][1001];

int main(void) {
    int N, M, V;
    int i, from, to, top, bot, cur;

    scanf("%d %d %d", &N, &M, &V);
    for (i=0; i<M; i++) {
        scanf("%d %d", &from, &to);
        graph[from][to] = graph[to][from] = 1;
    }

    // Stack;
    top = 0;
    buf[top] = V;
    while (top >= 0) {
        cur = buf[top--];
        if (graph[cur][0] == 1) continue;
        graph[cur][0] = 1;
        printf("%d ", cur);
        for (i=N; i>0; i--)
            if (graph[cur][i] && graph[i][0] < 1)
                buf[++top] = i;
    }
    printf("\n");

    // Queue
    buf[++top] = V;
    bot = -1;
    while (top > bot) {
        cur = buf[++bot];
        if (graph[cur][0] == 2) continue;
        graph[cur][0] = 2;
        printf("%d ", cur);
        for (i=1; i<=N; i++)
            if (graph[cur][i] && graph[i][0] < 2)
                buf[++top] = i;
    }
    printf("\n");

    return 0;
}