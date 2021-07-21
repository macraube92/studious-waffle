#include <stdio.h>

int top, front, queue[500000];

void push(int x) {
    queue[top++ % 500000] = x;
}

int pop() {
    return queue[front++ % 500000];
}

int size() {
    return top - front;
}

int main(void) {
    int N, i;
    scanf("%d", &N);

    if (N == 1) {
        printf("1");
        return 0;
    }

    if (N%2) push(N);
    for (i=2; i<=N; i+=2) push(i);

    while (size() > 1) {
        pop();
        push(pop());
    }

    printf("%d", pop());
    return 0;
}