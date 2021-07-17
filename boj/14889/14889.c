#include <stdio.h>

int min_diff(int (*matrix)[20], int N, int team[], int no) {
    int i, j, a, b, A, B, min, diff, team2[10];

    if (no == N/2) {
        a = b = 0;
        for (i=0; i<N; i++) {
            if (team[a] == i) a++;
            else team2[b++] = i;
        }

        A = B = 0;
        for (i=0; i<N/2-1; i++) {
            for (j=i+1; j<N/2; j++) {
                A += matrix[team[j]][team[i]];
                B += matrix[team2[j]][team2[i]];
            }
        }

        diff = A - B;
        if (diff < 0) diff *= -1;
        return diff;
    }

    if (no == 0) i = 0;
    else i = team[no-1]+1;
    min = 100;
    for (; i<=(N - (N/2-no)); i++) {
        team[no] = i;
        diff = min_diff(matrix, N, team, no+1);
        if (diff == 0) return 0;
        else if (min > diff) min = diff;
    }

    return min;
}

int main(void) {
    int N, i, j, matrix[20][20], team[10];
    scanf("%d", &N);
    for (i=0; i<N; i++)
        for (j=0; j<N; j++)
            scanf("%d", &matrix[i][j]);

    for (i=0; i<N; i++)
        for (j=0; j<i; j++)
            matrix[i][j] += matrix[j][i];

    printf("%d", min_diff(matrix, N, team, 0));
    return 0;
}