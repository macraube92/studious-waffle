#include <stdio.h>

void swap(int **a, int **b) {
    int *temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int *temp[200000];
void sort(int *arr[], int s, int e) {
    int a, b, h, i;
    if (e - s < 2) return;
    else if (e - s == 2) {
        if (*arr[s] > *arr[s+1]) swap(&arr[s], &arr[s+1]);
        return;
    }

    h = s + (e - s) / 2;
    sort(arr, s, h);
    sort(arr, h, e);

    a = s;
    b = h;
    for (i=s; i<e; i++) {
        if (a < h && b < e) {
            if (*arr[a] < *arr[b]) {
                temp[i] = arr[a];
                a++;
            } else {
                temp[i] = arr[b];
                b++;
            }
        } else if (a == h) {
            temp[i] = arr[b];
            b++;
        } else {
            temp[i] = arr[a];
            a++;
        }
    }
    for (i=s; i<e; i++) arr[i] = temp[i];
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

    sort(arr1, 0, N);
    sort(arr2, 0, M);

    j = 0;
    for (i=0; i<M; i++) {
        while (j < N && *arr1[j] < *arr2[i]) j++;
        if (j < N && *arr1[j] == *arr2[i]) *arr2[i] = j;
        else *arr2[i] = -1;
    }

    for (i=0; i<M; i++) printf("%d\n", query[i]);

    return 0;
}