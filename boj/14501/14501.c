#include <stdio.h>

int max_price(int* T, int* P, int N, int i, int p) {
    int a, b;
    if (i == N) return p;

    a = b = 0;
    if (i + T[i] <= N)
        a = max_price(T, P, N, i+T[i], p+P[i]);
    b = max_price(T, P, N, i+1, p);

    if (a > b) return a;
    else return b;
}

int main(void) {
    int N, T[15], P[15], i;
    scanf("%d", &N);
    for (i=0; i<N; i++) scanf("%d %d", &T[i], &P[i]);
    printf("%d", max_price(T, P, N, 0, 0));
    return 0;
}