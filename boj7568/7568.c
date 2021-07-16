#include <stdio.h>

int main(void) {
    int N, i, j, r, w[50], h[50];
    scanf("%d", &N);
    for (i=0; i<N; i++) {
        scanf("%d %d", &w[i], &h[i]);
    }

    for (i=0; i<N; i++) {
        r = 1;
        for (j=0; j<N; j++) {
            if (i == j) continue;
            else if (w[i] < w[j] && h[i] < h[j]) r++;
        }
        printf("%d ", r);
    }

    return 0;
}