#include <stdio.h>

char buffer[1024][201];
struct String {
    int len;
    char *ref;
} expr[1024];

int strcmp(const struct String *, const struct String *);

int main(void) {
    int i, j, k, d;
    int top, count, len, cmp;
    int brackets[10][3], stack[10];
    char str[201];
    struct String temp;

    // parse input
    top = -1;
    count = 0;
    scanf("%s", str);
    for (i=0; str[i]!='\0'; i++) {
        if (str[i] == '(') {
            stack[++top] = count;
            brackets[count++][0] = i;
        } else if (str[i] == ')') brackets[stack[top--]][1] = i;
    }
    len = i;

    // make all expr
    top = 0;
    for (i=(1<<count)-2; i>=0; i--) {
        for (j=0; j<count; j++)
            if (!(i & (1<<j)))
                str[brackets[j][0]] = str[brackets[j][1]] = 0;

        k = j =0;
        for (; j<len; j++) {
            if (!str[j]) continue;
            buffer[top][k++] = str[j];
        }
        buffer[top][k] = '\0';
        expr[top].ref = buffer[top];
        expr[top++].len = k;

        for (j=0; j<count; j++) {
            if (!(i & (1<<j))) {
                str[brackets[j][0]] = '(';
                str[brackets[j][1]] = ')';
            }
        }
    }

    // sort expr
    for (i=0; i<top-1;) {
        d = 0;
        for (j=i+1; j<top; j++) {
            cmp = strcmp(&expr[i], &expr[j]);
            if (cmp == 1) {
                temp = expr[i];
                expr[i] = expr[j];
                expr[j] = temp;
            } else if (cmp == 0) {
                d++;
                temp = expr[i+d];
                expr[i+d] = expr[j];
                expr[j] = temp;
            }
        }
        printf("%s\n", expr[i].ref);
        i += 1 + d;
    }
    printf("%s", expr[top-1].ref);

    return 0;
}

int strcmp(const struct String * a, const struct String * b) {
    int i, len;
    len = (a->len > b->len) ? a->len : b->len;

    for (i=0; i<len; i++)
        if (a->ref[i] != b->ref[i]) break;

    if (i == len) return 0;
    return (a->ref[i] < b->ref[i]) ? -1 : 1;
}