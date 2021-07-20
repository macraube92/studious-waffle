#include <stdio.h>

int main(void) {
    int N, i, top, front, queue[1000];
    top = front = 0;
    scanf("%d", &N);
    for (i=1; i<=N; i++) queue[top++] = i;
    printf("%d", queue[front++]);
    while (top != front) {
        if (top >= 1000) top = 0;
        if (front >= 1000) front %= 1000;
        queue[top++] = queue[front++ % 1000];
        printf(" %d", queue[front++ % 1000]);
    }
    return 0;
}