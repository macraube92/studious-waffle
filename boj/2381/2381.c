#include <stdio.h>

int main(void) {
    int N, i, x, y;
    int p, m, pmax, pmin, mmax, mmin;
    mmax = pmax = -2000000;
    mmin = pmin = 2000000;
    scanf("%d", &N);
    for (i=0; i<N; i++) {
        scanf("%d %d", &x, &y);
        p = x + y;
        m = x - y;
        if (pmax < p) pmax = p;
        if (pmin > p) pmin = p;
        if (mmax < m) mmax = m;
        if (mmin > m) mmin = m;
    }

    p = pmax - pmin;
    m = mmax - mmin;
    printf("%d", (p > m) ? p : m);

    return 0;
}