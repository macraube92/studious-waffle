#include <stdio.h>

struct SerialInfo {
    int len;
    int num;
    char * ref;
} serial[1000];
char buf[1000][51];

int compare(struct SerialInfo a, struct SerialInfo b) {
    int i;

    if (a.len != b.len) return (a.len < b.len) ? -1 : 1;
    else if (a.num != b.num) return (a.num < b.num) ? -1 : 1;

    for (i=0; a.ref[i]!='\0' && b.ref[i]!='\0'; i++)
        if (a.ref[i] != b.ref[i]) return (a.ref[i] <= b.ref[i]) ? -1 : 1;
    return (a.ref[i] == '\0') ? -1 : 1;
}

int main(void) {
    int N, i, j, num;
    struct SerialInfo temp;

    scanf("%d", &N);
    for (i=0; i<N; i++) {
        scanf("%s", buf[i]);
        num = 0;
        for (j=0; buf[i][j]!='\0'; j++) {
            if (buf[i][j] >= '0' && buf[i][j] <= '9')
                num += buf[i][j]-'0';
        }
        serial[i].ref = buf[i];
        serial[i].num = num;
        serial[i].len = j;
    }

    for (i=0; i<N-1; i++) {
        for (j=i+1; j<N; j++) {
            if (compare(serial[i], serial[j]) == 1) {
                temp = serial[i];
                serial[i] = serial[j];
                serial[j] = temp;
            }
        }
        printf("%s\n", serial[i].ref);
    }
    printf("%s\n", serial[i].ref);

    return 0;
}