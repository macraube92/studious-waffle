#include <stdio.h>

typedef struct {
    int buf[100][2];
    int top;
} Stack;

void init(Stack * stack) { stack->top = -1; }
void push(Stack * stack, int l, int h) {
    stack->buf[++stack->top][0] = l;
    stack->buf[stack->top][1] = h;
}
void pop(Stack * stack, int *l, int *h) {
    *l = stack->buf[stack->top][0];
    *h = stack->buf[stack->top--][1];
}
int empty(const Stack * stack) { return stack->top < 0; }

void swap(int **a, int **b) {
    int *temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int *arr[], int N) {
    Stack stack;
    int L, H, t, l, h;

    if (N == 1) return;

    init(&stack);
    push(&stack, 0, N-1);
    while (!empty(&stack)) {
        pop(&stack, &L, &H);
        t = L;
        l = t + 1;
        h = H;

        while (l < h) {
            if (*arr[l] < *arr[t] || *arr[h] >= *arr[t]) {
                if (*arr[l] < *arr[t]) l++;
                if (*arr[h] >= *arr[t]) h--;
            } else if (*arr[l] > *arr[h]) swap(&arr[l], &arr[h]);
        }

        if (*arr[l] < *arr[t]) swap(&arr[l], &arr[t]);
        else swap(&arr[--l], &arr[t]);

        if (l-1 > L) push(&stack, L, l-1);
        if (l+1 < H) push(&stack, l+1, H);
    }
}

int main(void) {
    int N, M;
    int i, j, n, idx;
    int nums[200000], query[200000];
    int *arr1[200000], *arr2[200000];

    scanf("%d %d", &N, &M);
    for (i=0; i<N; i++) {
        idx = (i * 727) % N;
        scanf("%d", &nums[idx]);
        arr1[idx] = &nums[idx];
    }
    for (i=0; i<M; i++) {
        idx = (i * 727) % M;
        scanf("%d", &query[i]);
        arr2[idx] = &query[i];
    }

    sort(arr1, N);
    sort(arr2, M);

    j = 0;
    for (i=0; i<M; i++) {
        while (j < N && *arr1[j] < *arr2[i]) j++;
        if (j < N && *arr1[j] == *arr2[i]) *arr2[i] = j;
        else *arr2[i] = -1;
    }

    for (i=0; i<M; i++) printf("%d\n", query[i]);

    return 0;
}