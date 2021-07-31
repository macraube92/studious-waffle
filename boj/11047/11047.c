#include <stdio.h>

int main(void) {
    int N, K, A[10], i, r;
    scanf("%d %d", &N, &K);
    for (i=0; i<N; i++) scanf("%d", &A[i]);

    i--;
    r = 0;
    while (K > 0) {
        r += (K / A[i]);
        K %= A[i--];
    }

    printf("%d", r);
    return 0;
}