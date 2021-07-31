#include <stdio.h>

int arr[1000] = {1, 2};
int size = 2;

int f(int n) {
    int m;
    if (n <= size) return arr[n-1];
    m = (f(n-1) + f(n-2)) % 10007;
    arr[n-1] = m;
    size = n;
    return m;
}

int main(void) {
    int N;
    scanf("%d", &N);
    printf("%d", f(N));
    return 0;
}