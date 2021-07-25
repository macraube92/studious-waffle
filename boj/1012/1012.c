#include <stdio.h>

struct Node {
    int item;
    int visit;
} field[50][50];

int stack[10000][2], top;

void init() { top=-1; }
void push(int x, int y) {
    stack[++top][0] = x;
    stack[top][1] = y;
}
void pop(int *x, int *y) {
    *x = stack[top][0];
    *y = stack[top--][1];
}
int empty() { return top == -1; }

void change_to_visit(int y, int x, int Y, int X) {
    init();
    push(x, y);
    while (!empty()) {
        pop(&x, &y);
        field[y][x].visit = 1;
        if (y-1 >= 0 && field[y-1][x].item && !field[y-1][x].visit) push(x, y-1);
        if (y+1 < Y && field[y+1][x].item && !field[y+1][x].visit) push(x, y+1);
        if (x-1 >= 0 && field[y][x-1].item && !field[y][x-1].visit) push(x-1, y);
        if (x+1 < X && field[y][x+1].item && !field[y][x+1].visit) push(x+1, y);
    }
}

int main(void) {
    int T, N, M, K;
    int x, y, i, j, n;

    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &M, &N, &K);
        for (i=0; i<N; i++)
            for (j=0; j<M; j++)
                field[i][j].item = field[i][j].visit = 0;
        for (i=0; i<K; i++) {
            scanf("%d %d", &x, &y);
            field[y][x].item = 1;
        }

        n = 0;
        for (i=0; i<N; i++) {
            for (j=0; j<M; j++) {
                if (field[i][j].item && !field[i][j].visit) {
                    change_to_visit(i, j, N, M);
                    n++;
                }
            }
        }

        printf("%d\n", n);
    }

    return 0;
}