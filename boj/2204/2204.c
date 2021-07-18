#include <stdio.h>

int strcmp(char* a, char* b) {
    int i, al, bl;
    for (i=0; a[i]!='\0' && b[i]!='\0'; i++) {
        al = (a[i] < 'a') ? a[i] + 32 : a[i];
        bl = (b[i] < 'a') ? b[i] + 32 : b[i];
        if (al != bl) return (al < bl) ? -1 : 1;
    }
    return (a[i] == '\0') ? -1 : 1;
}

int main(void) {
    int N, i, j;
    char w[21], s[21];
    while (~scanf("%d", &N) && N > 0) {
        w[0] = 0;
        for (i=0; i<N; i++) {
            scanf("%s", s);
            if (!w[0] || strcmp(w, s) == 1) {
                for (j=0; s[j]!='\0'; j++) w[j] = s[j];
                w[j] = '\0';
            }
        }
        printf("%s\n", w);
    }
    return 0;
}