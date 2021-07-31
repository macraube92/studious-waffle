#include <stdio.h>

#define push(x, y) { q[b][0] = x; q[b++][1] = y; }
#define pop(x, y) { x = q[f][0]; y = q[f++][1];}
#define empty() (b == f)

int visit[25][25];
int main(void) {
    int N, i, j, n, c, b, f, x, y, temp, size[700], q[2000][2];
    char s[25][26];
    scanf("%d", &N);
    for (i=0; i<N; i++) scanf("%s", s[i]);

    n = 1;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            if (s[j][i] == '0' || visit[j][i]) continue;
            c = b = f = 0;
            push(j, i);
            while (!empty()) {
                pop(x, y);
                if (visit[x][y]) continue;
                visit[x][y] = n;
                c++;
                if (x+1 < N && s[x+1][y] == '1' && !visit[x+1][y]) push(x+1, y);
                if (x-1 >= 0 && s[x-1][y] == '1' && !visit[x-1][y]) push(x-1, y);
                if (y+1 < N && s[x][y+1] == '1' && !visit[x][y+1]) push(x, y+1);
                if (y-1 >= 0 && s[x][y-1] == '1' && !visit[x][y-1]) push(x, y-1);
            }
            size[n-1] = c;
            n++;
        }
    }

    n--;
    printf("%d\n", n);
    for (i=0; i<n-1; i++) {
        for (j=i+1; j<n; j++) {
            if (size[i] > size[j]) {
                temp = size[i];
                size[i] = size[j];
                size[j] = temp;
            }
        }
        printf("%d\n", size[i]);
    }
    printf("%d\n", size[n-1]);

    return 0;
}