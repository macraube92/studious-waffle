#include <stdio.h>

int arr1[1000], arr2[1000], count[1001];
int main(void) {
    int N, i, s;
    scanf("%d", &N);
    for (i=0; i<N; i++) {
        scanf("%d", &arr1[i]);
        count[arr1[i]]++;
    }
    for (i=2; i<=1000; i++) count[i] += count[i-1];
    for (i=0; i<N; i++) arr2[--count[arr1[i]]] = arr1[i];

    s = arr2[0];
    for (i=1; i<N; i++) {
        arr2[i] += arr2[i-1];
        s += arr2[i];
    }

    printf("%d", s);
    return 0;
}