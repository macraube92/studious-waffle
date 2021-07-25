#include <stdio.h>

int main(void) {
    int N, i, j, temp, a[50], b[50], c[50];

    scanf("%d", &N);
    for (i=0; i<N; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
        c[i] = 0;
    }

    for (i=0; i<N-1; i++) {
        for (j=i+1; j<N; j++) {
            if (b[i] > b[j]) {
                temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }

    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            if (!c[j] && a[i] == b[j]) {
                c[j] = 1;
                break;
            }
        }
        printf("%d ", j);
    }
    return 0;
}