#include <stdio.h>

int arr[12] = {1, 2, 4};
int already = 3;
int calc(int n) {
    int m;
    if (n < 1) return 0;
    else if (n <= already) return arr[n-1];
    m = calc(n - 1) + calc(n - 2) + calc(n - 3);
    arr[n-1] = m;
    already = n;
    return m;
}

int main(void) {
    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        printf("%d\n", calc(n));
    }
    return 0;
}