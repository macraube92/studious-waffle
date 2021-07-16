#include <stdio.h>

int main(void) {
    int i;
    unsigned long long A, B, C, r, cached[31];
    scanf("%llu %llu %llu", &A, &B, &C);

    cached[0] = A;
    for (i=1; (1<<i)<B; i++)
        cached[i] = (cached[i-1] % C) * (cached[i-1] % C) % C;

    r = 1;
    while (B > 0) {
        if ((1<<i) <= B) {
            r = r * cached[i] % C;
            B -= (1<<i);
        } else i--;
    }

    printf("%llu", r);

    return 0;
}