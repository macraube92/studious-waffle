#include <stdio.h>

int top, front, queue[1000];

int size() {
    return top - front;
}

void push(int x) {
    queue[top++ % 1000] = x;
}

int pop() {
    return queue[front++ % 1000];
}

int main(void) {
    int N, K, i;
    scanf("%d %d", &N, &K);
    K--;
    for (i=1; i<=N; i++) push(i);
    printf("<");
    while (size() > 1) {
        for (i=0; i<K; i++) push(pop());
        printf("%d, ", pop());
    }
    printf("%d>", pop());
}