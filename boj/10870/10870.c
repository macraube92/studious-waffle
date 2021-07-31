#include <stdio.h>

int arr[20] = {0, 1, 1, 2};
int size=3;
int fib(int n) {
    if (n <= size) return arr[n];
    return fib(n-2) + fib(n-1);
}

int main(void) {
    int N;
    scanf("%d", &N);
    printf("%d", fib(N));
    return 0;
}