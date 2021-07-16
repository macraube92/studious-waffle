#include <stdio.h>

int main(void) {
    int N, i, j, x, max, num[100];
    int is_prime[1000]={0, 1};

    max = 0;
    scanf("%d", &N);
    for (i=0; i<N; i++) {
        scanf("%d", &num[i]);
        if (num[i] > max) max = num[i];
    }

    int n = 0;
    for (i=2; i<max; i++) {
        x = i + 1;
        for (j=0; j<i; j++) {
            n++;
            if (is_prime[j] && !(x % (j+1))) break;
        }
        if (j == i) {
            is_prime[i] = 1;
        }
    }

    x = 0;
    for (i=0; i<N; i++)
        if (is_prime[num[i]-1]) x++;
    printf("%d", x);

    return 0;
}