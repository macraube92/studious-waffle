#include <stdio.h>

int main(void) {
    int N;
    long long stack[100002][2], top;
    long long i, v, s, S, n;

    while (~scanf("%d", &N) && N > 0) {
        top = -1;
        S = 0L;
        stack[++top][0] = 0;
        stack[top][1] = 0;
        for (i=0; i<=N; i++) {
            if (i < N) scanf("%lld", &v);
            else v = 0;
            n = i;
            while (top >= 0 && stack[top][0] > v) {
                s = stack[top][0] * (i - stack[top][1]);
                if (s > S) S = s;
                n = stack[top][1];
                top--;
            }
            if (top < 0 || stack[top][0] < v) {
                stack[++top][0] = v;
                stack[top][1] = n;
            }
        }
        printf("%lld\n", S);
    }

    return 0;
}