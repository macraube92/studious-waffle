#include <stdio.h>

int main(void) {
    int N, i, j, r=0;
    int m[26];
    char s[101];
    scanf("%d", &N);
    for (i=0; i<N; i++) {
        scanf("%s", s);
        for (j=0; j<26; j++) m[j] = -1;
        for (j=0; s[j]!='\0'; j++) {
            if (m[s[j]-'a'] != -1 && j - m[s[j]-'a'] > 1) break;
            else m[s[j]-'a'] = j;
        }
        if (s[j] == '\0') r++;
    }

    printf("%d", r);
    return 0;
}