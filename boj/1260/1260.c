#include <stdio.h>

int buf[1000000];

int main(void) {
    int N, M, V;
    int i, j, a, b, v, temp, min, top, front;
    int index[1002], visit[1001]={0};
    unsigned int edge[10000];

    scanf("%d %d %d", &N, &M, &V);
    for (i=0; i<M; i++) {
        scanf("%d %d", &a, &b);
        if (a > b) {
            temp = a;
            a = b;
            b = temp;
        }
        edge[i] = (a & 0xffff) << 16 | (b & 0xffff);
    }

    if (M > 1) {
        for (i=0; i<M-1; i++) {
            a = i;
            min = edge[i];
            for (j=i+1; j<M; j++) {
                if (edge[j] < min) {
                    a = j;
                    min = edge[j];
                }
            }

            if (a != i) {
                temp = edge[i];
                edge[i] = edge[a];
                edge[a] = temp;
            }
        }

        j = 1;
        for (i=0; i<M-j;) {
            if (edge[i] == edge[i+j]) {
                j++;
            } else if (a > 1) {
                edge[i+1] = edge[i+j];
                i++;
            }

        }
        M = M - j + 2;
    }

    for (i=1; i<=N; i++) index[i] = 1000;
    for (i=0; i<M; i++) {
        a = edge[i] >> 16 & 0xffff;
        if (i < index[a]) index[a] = i;
    }
    index[0] = index[1] = 0;
    index[N+1] = M;
    for (i=N; i>1; i--) if (index[i] == 1000) index[i] = index[i+1];

    // dfs
    buf[0] = V;
    top = 0;
    while (top >= 0) {
        v = buf[top--];
        if (visit[v]) continue;
        visit[v] = 1;
        printf("%d ", v);
        for (i=index[v+1]-1; i>=0; i--) {
            a = edge[i] >> 16 & 0xffff;
            b = edge[i] & 0xffff;
            if (b == v && !visit[a]) {
                buf[++top] = a;
            } else if (a == v && !visit[b]) {
                buf[++top] = b;
            } else if (a > v) break;
        }
    }
    printf("\n");

    for (i=1; i<=N; i++) visit[i] = 0;

    // bfs
    buf[0] = V;
    top = 0;
    front = -1;
    while (front < top) {
        v = buf[++front];
        if (visit[v]) continue;
        visit[v] = 1;
        printf("%d ", v);
        for (i=0; i<M; i++) {
            a = edge[i] >> 16 & 0xffff;
            b = edge[i] & 0xffff;
            if (b == v && !visit[a]) {
                buf[++top] = a;
            } else if (a == v && !visit[b]) {
                buf[++top] = b;
            } else if (a > v) break;
        }
    }

    return 0;
}