#include <stdio.h>

int stairs[301];
int mem[301][2];
int up_stairs(int c, int s, int N) {
    int one, two;
    if (c > N || s > 1) return -1;
    else if (mem[c][s] != 0) return mem[c][s];

    one = up_stairs(c+1, s+1, N);
    two = up_stairs(c+2, 0, N);
    if (one == two && one == -1)
        mem[c][s] = -1;
    else
        mem[c][s] = stairs[c] + (one < two ? two : one);

    return mem[c][s];
}

int main(void) {
    int i, N;
    scanf("%d", &N);
    for (i=1; i<=N; i++) scanf("%d", &stairs[i]);
    mem[N][0] = mem[N][1] = stairs[N];
    printf("%d", up_stairs(0, -1, N));
    return 0;
}