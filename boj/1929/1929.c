#include <stdio.h>

int is_prime[1000001];
int main(void) {
    int M, N, i, j;
    scanf("%d %d", &M, &N);
    for (i=2; i<=N; i++) {
        if (is_prime[i] == 0) {
            is_prime[i] = 1;
            for (j=i+i; j<=N; j+=i) if (!is_prime[j]) is_prime[j] = -1;
            if (i >= M) printf("%d\n", i);
        }
    }
    return 0;
}