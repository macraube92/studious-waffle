#include <stdio.h>

int back, front, queue[2000];
int empty() { return back == front; }
void push(int x) { queue[back++] = x; }
int pop() { return queue[front++]; }

int main(void) {
    int N, M, price[100], weight[2000];
    int parked[100], pos[2000];
    int i, j, car;
    unsigned int count, income;

    scanf("%d %d", &N, &M);
    for (i=0; i<N; i++) {
        scanf("%d", &price[i]);
        parked[i] = 0;
    }
    for (i=0; i<M; i++) scanf("%d", &weight[i]);

    M *= 2;
    count = N;
    income = 0;
    for (i=0; i<M; i++) {
        scanf("%d", &car);
        if (car < 0) {
            car = (car * -1) - 1;
            parked[pos[car]] = 0;
            count++;
        } else push(car-1);

        while (count > 0 && !empty()) {
            car = pop();
            for (j=0; j<N; j++) if (!parked[j]) break;
            parked[j] = 1;
            pos[car] = j;

            income += weight[car] * price[j];
            count--;
        }
    }

    printf("%d", income);

    return 0;
}