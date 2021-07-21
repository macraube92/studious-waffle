#include <stdio.h>

int q[2000000];
int f, t;

int size() {
    return t - f;
}

int empty() {
    return f == t;
}

int front() {
    if (empty()) return -1;
    return q[f];
}

int back() {
    if (empty()) return -1;
    return q[t-1];
}

void push(int x) {
    q[t++] = x;
}

int pop() {
    if (empty()) return -1;
    return q[f++];
}

int main(void) {
    int N, i, x;
    char cmd[6];
    scanf("%d", &N);
    for (i=0; i<N; i++) {
        scanf("%s", cmd);
        if (cmd[0] == 'p') {
            if (cmd[1] == 'u') {
                scanf("%d", &x);
                push(x);
            } else printf("%d\n", pop());
        } else if (cmd[0] == 's') printf("%d\n", size());
        else if (cmd[0] == 'e') printf("%d\n", empty());
        else if (cmd[0] == 'f') printf("%d\n", front());
        else if (cmd[0] == 'b') printf("%d\n", back());
    }
    return 0;
}