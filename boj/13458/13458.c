#include <stdio.h>

int main(void) {
    long long N, A, B, room[1000000], i, r, S;
    scanf("%lld", &N);
    for (i=0; i<N; i++) scanf("%lld", &room[i]);
    scanf("%lld %lld", &A, &B);
    S = 0;
    for (i=0; i<N; i++) {
        S += 1;
        r = room[i] - A;
        if (r > 0) S += r / B + (r%B ? 1 : 0);
    }
    printf("%lld", S);
    return 0;
}