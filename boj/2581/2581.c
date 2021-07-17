#include <stdio.h>

int main(void) {
    int M, N, i, j, s, min, is_prime[10001];
    int n;

    scanf("%d %d", &M, &N);

    for (i=0; i<10001; i++) is_prime[i] = 1;
    is_prime[0] = is_prime[1] = 0;

    s = 0;
    min = 10000;
    for (i=2; i<=N; i++) {
        if (is_prime[i]) {
            if (M <= i && i <= N) {
                s += i;
                if (min > i) min = i;
            }
            for (j=i+i; j<=N; j+=i)
                if (is_prime[j]) is_prime[j] = 0;
        }
    }

    if (s == 0) printf("-1");
    else printf("%d\n%d", s, min);

    return 0;
}