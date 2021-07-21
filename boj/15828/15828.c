#include <stdio.h>

int N;
int queue[100000], front, top;

int size() {
    return top - front;
}

void push(int x) {
    if (size() == N) return;
    queue[top++ % 100000] = x;
}

int pop() {
    return queue[front++ % 100000];
}

int main(void) {
    int x;
    scanf("%d", &N);
    while (~scanf("%d", &x) && x != -1) {
        if (!x) pop();
        else push(x);
    }

    if (size() == 0) printf("empty");
    else while (size() > 0) printf("%d ", pop());

    return 0;
}