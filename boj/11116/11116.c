#include <stdio.h>

struct Queue {
    int buf[101];
    int front;
    int top;
} lq, rq;

void init(struct Queue* q) {
    q->front = q->top = 0;
}

int empty(const struct Queue* q) {
    return q->front == q->top;
}

int front(const struct Queue* q) {
    return q->buf[q->front];
}

void push(struct Queue* q, int t) {
    q->buf[q->top++] = t;
}

void pop(struct Queue* q) {
    q->front++;
}

int main(void) {
    int T, N, i, j, t, left;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        init(&lq);
        for (i=0; i<N; i++) {
            scanf("%d", &t);
            if (empty(&lq) || front(&lq) + 500 > t) push(&lq, t);
            else pop(&lq);
        }
        init(&rq);
        for (i=0; i<N; i++) {
            scanf("%d", &t);
            if (empty(&rq) || front(&rq) + 500 > t) push(&rq, t);
            else pop(&rq);
        }

        left = j = 0;
        for (i=0; i<lq.top; i++) {
            for (; j<rq.top; j++) {
                if (lq.buf[i] + 1000 == rq.buf[j]) {
                    left++;
                    break;
                } else if (lq.buf[i] + 1000 < rq.buf[j]) break;
            }
        }
        printf("%d\n", left);
    }
    return 0;
}