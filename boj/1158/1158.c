#include <stdio.h>

int main(void) {
    int N, K, i, top, front;
    int queue[5000];
    scanf("%d %d", &N, &K);
    for (i=0; i<N; i++) queue[i] = i + 1;
    top = i;
    front = 0;
    printf("<");
    while (top != front) {
        for (i=0; i<K-1; i++)
            queue[top++ % 5000] = queue[front++ % 5000];
        if (top - front > 1) printf("%d, ", queue[front++ % 5000]);
        else printf("%d>", queue[front++ % 5000]);
    }
    return 0;
}