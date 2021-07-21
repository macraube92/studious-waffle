#include <stdio.h>

int main(void) {
    int T, N, M;
    int i, n, front, top;
    int priorities[100], *queue[100];
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &N, &M);
        for (i=0; i<N; i++) {
            scanf("%d", &priorities[i]);
            queue[i] = &priorities[i];
        }
        front = n = 0;
        top = i;
        while (top != front) {
            for (i=front+1; i<top; i++)
                if (*queue[front % 100] < *queue[i % 100]) break;
            if (i == top) {
                n++;
                if (queue[front % 100] == &priorities[M]) break;
                front++;
            } else queue[top++ % 100] = queue[front++ % 100];
        }
        printf("%d\n", n);
    }
    return 0;
}