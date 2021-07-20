#include <stdio.h>

struct Person {
    int hungry;
    int clear;
} person[1000];

int main(void) {
    int N, i, top, front, time;
    struct Person * queue[1000];

    top = front = 0;
    scanf("%d", &N);
    for (i=0; i<N; i++) {
        scanf("%d", &person[i].hungry);
        queue[top++] = &person[i];
    }

    for (time=1; top != front; time++) {
        if (queue[front % 1000]->hungry == 1) queue[front++ % 1000]->clear = time;
        else {
            queue[front % 1000]->hungry--;
            queue[top++ % 1000] = queue[front++ % 1000];
        }
    }

    for (i=0; i<N; i++)
        printf("%d ", person[i].clear);

    return 0;
}