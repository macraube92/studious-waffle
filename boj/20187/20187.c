#include <stdio.h>

struct Rect {
    int x1;
    int x2;
    int y1;
    int y2;
};

enum {LEFT='L', RIGHT='R', UP='U', DOWN='D'};
int SIZE[9] = {1, 2, 4, 8, 16, 32, 64, 128, 256};

int main(void) {
    int K, N;
    int i, j, x, y;
    int top, punch_hole;
    int paper[256][256], stack[16];
    char dir;
    struct Rect a, b;

    scanf("%d", &K);
    top = 0;
    N = 2 * K;
    x = y = K;
    a.x1 = a.y1 = 0;
    a.x2 = a.y2 = SIZE[K]-1;
    for (i=0; i<N; i++) {
        scanf(" %c", &dir);
        stack[top++] = dir;
        switch (dir) {
        case LEFT:
            a.x2 -= SIZE[(x--)-1];
            break;
        case RIGHT:
            a.x1 += SIZE[(x--)-1];
            break;
        case UP:
            a.y2 -= SIZE[(y--)-1];
            break;
        case DOWN:
            a.y1 += SIZE[(y--)-1];
            break;
        }
    }
    scanf("%d", &punch_hole);
    paper[a.y1][a.x1] = punch_hole;

    while (top > 0) {
        dir = stack[--top];
        b = a;
        switch (dir) {
        case LEFT:
            b.x1 = a.x1+SIZE[x];
            b.x2 = a.x2+SIZE[x++];
            for (i=0; i<SIZE[x-1]; i++) {
                for (j=0; j<SIZE[y]; j++) {
                    if (paper[a.y1+j][a.x1+i] == 0) paper[a.y1+j][b.x2-i] = 1;
                    else if (paper[a.y1+j][a.x1+i] == 1) paper[a.y1+j][b.x2-i] = 0;
                    else if (paper[a.y1+j][a.x1+i] == 2) paper[a.y1+j][b.x2-i] = 3;
                    else if (paper[a.y1+j][a.x1+i] == 3) paper[a.y1+j][b.x2-i] = 2;
                }
            }
            break;
        case RIGHT:
            b.x1 = a.x1-SIZE[x];
            b.x2 = a.x2-SIZE[x++];
            for (i=0; i<SIZE[x-1]; i++) {
                for (j=0; j<SIZE[y]; j++) {
                    if (paper[a.y1+j][a.x2-i] == 0) paper[a.y1+j][b.x1+i] = 1;
                    else if (paper[a.y1+j][a.x2-i] == 1) paper[a.y1+j][b.x1+i] = 0;
                    else if (paper[a.y1+j][a.x2-i] == 2) paper[a.y1+j][b.x1+i] = 3;
                    else if (paper[a.y1+j][a.x2-i] == 3) paper[a.y1+j][b.x1+i] = 2;
                }
            }
            break;
        case UP:
            b.y1 = a.y1+SIZE[y];
            b.y2 = a.y2+SIZE[y++];
            for (i=0; i<SIZE[x]; i++) {
                for (j=0; j<SIZE[y-1]; j++) {
                    if (paper[a.y1+j][a.x1+i] == 0) paper[b.y2-j][a.x1+i] = 2;
                    else if (paper[a.y1+j][a.x1+i] == 1) paper[b.y2-j][a.x1+i] = 3;
                    else if (paper[a.y1+j][a.x1+i] == 2) paper[b.y2-j][a.x1+i] = 0;
                    else if (paper[a.y1+j][a.x1+i] == 3) paper[b.y2-j][a.x1+i] = 1;
                }
            }
            break;
        case DOWN:
            b.y1 = a.y1-SIZE[y];
            b.y2 = a.y2-SIZE[y++];
            for (i=0; i<SIZE[x]; i++) {
                for (j=0; j<SIZE[y-1]; j++) {
                    if (paper[a.y2-j][a.x1+i] == 0) paper[b.y1+j][a.x1+i] = 2;
                    else if (paper[a.y2-j][a.x1+i] == 1) paper[b.y1+j][a.x1+i] = 3;
                    else if (paper[a.y2-j][a.x1+i] == 2) paper[b.y1+j][a.x1+i] = 0;
                    else if (paper[a.y2-j][a.x1+i] == 3) paper[b.y1+j][a.x1+i] = 1;
                }
            }
            break;
        }
        
        a.x1 = (a.x1 < b.x1) ? a.x1 : b.x1;
        a.x2 = (a.x2 > b.x2) ? a.x2 : b.x2;
        a.y1 = (a.y1 < b.y1) ? a.y1 : b.y1;
        a.y2 = (a.y2 > b.y2) ? a.y2 : b.y2;
    }

    for (i=0; i<SIZE[K]; i++) {
        for (j=0; j<SIZE[K]; j++)
            printf("%d ", paper[i][j]);
        printf("\n");
    }

    return 0;
}