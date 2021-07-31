#include <stdio.h>

int col[1000][3];
int mem[1000][3];

int price(int sel, int n, int N) {
    int i, p, min;
    if (n == N) return 0;
    else if (mem[n][sel] != 0) return mem[n][sel];

    min = 1000000;
    for (i=0; i<3; i++) {
        if (i == sel) continue;
        p = col[n][i] + price(i, n+1, N);
        if (p < min) min = p;
    }
    mem[n][sel] = min;
    return min;
}

int main(void) {
    int N, i, p, min;
    scanf("%d", &N);
    for (i=0; i<N; i++) scanf("%d %d %d", &col[i][0], &col[i][1], &col[i][2]);
    min = 1000000;
    for (i=0; i<3; i++) {
        p = col[0][i] + price(i, 1, N);
        if (p < min) min = p;
    }
    printf("%d", min);
    return 0;
}