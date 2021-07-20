#include <stdio.h>

int main(void) {
    int T, N, price, t, i, front, top, queue[100];
    scanf("%d", &T);
    for (t=1; t<=T; t++) {
        scanf("%d", &N);
        front = top = 0;
        for (i=0; i<N*2;i++) {
            scanf("%d", &price);
            if (front == top) queue[top++] = price;
            else if (!(price%4) && (queue[front] / 3 * 4) == price) front++;
            else queue[top++] = price;
        }
        printf("Case #%d:", t);
        for (i=0; i<N; i++) printf(" %d", queue[i]);
        printf("\n");
    }
    return 0;
}