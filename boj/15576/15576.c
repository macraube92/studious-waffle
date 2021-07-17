#include <stdio.h>

const int LIMIT_SIZE = 9;
const int LIMIT = 1000000000;

struct BigInt {
    int size;
    unsigned long long buf[100000];
} A, B, C;

void char_to_bigint(char const*, struct BigInt *);
void mul(struct BigInt const *, struct BigInt const *, struct BigInt *);
void print_bigint(struct BigInt const *);

int main(void) {
    char a[300001], b[300001];
    scanf("%s %s", a, b);
    char_to_bigint(a, &A);
    char_to_bigint(b, &B);
    mul(&A, &B, &C);
    print_bigint(&C);
    return 0;
}

void char_to_bigint(char const* s, struct BigInt * num) {
    int len, i, step;

    for (len=0; s[len]!='\0'; len++);
    if (len == 1 && s[0] == '0') {
        num->size = 0;
        return;
    }

    num->size = len/LIMIT_SIZE + (len%LIMIT_SIZE ? 1 : 0);

    for (i=0; i<len; i++) {
        if (i % LIMIT_SIZE == 0) step = 1;
        num->buf[i/LIMIT_SIZE] += (s[len-1-i] - '0') * step;
        step *= 10;
    }
}

void mul(struct BigInt const * num1, struct BigInt const * num2, struct BigInt * num) {
    int i, a, b, f1, f2;
    if (num1->size == 0 || num2->size == 0) {
        num->size = 0;
        return;
    }
    num->size = num1->size + num2->size;

    f1 = f2 = 0;
    for (i=0; i<num->size; i++) {
        a = f1;
        b = f2;
        while (a < num1->size && b >= 0) {
            num->buf[i] += num1->buf[a++] * num2->buf[b--];
        }
        if (f2 == num2->size - 1) f1++;
        else f2++;

        if (num->buf[i] / LIMIT) {
            num->buf[i+1] = num->buf[i] / LIMIT;
            num->buf[i] %= LIMIT;
        }
    }
}

void print_bigint(struct BigInt const * num) {
    int i;
    if (num->size == 0) {
        printf("0\n");
        return;
    }

    for (i=num->size; i>=0; i--) if (num->buf[i] > 0) break;
    printf("%llu", num->buf[i--]);
    for (; i>=0; i--)
        printf("%09llu", num->buf[i]);
    printf("\n");
}