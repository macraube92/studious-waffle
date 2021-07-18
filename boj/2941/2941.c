#include <stdio.h>

char s[105];
int main(void) {
    int i, r=0;
    scanf("%s", s);
    for (i=0; s[i]!='\0'; i++) {
        if (s[i] == 'd') {
            if (s[i+1] == 'z' && s[i+2] == '=') {
                r++;
                i += 2;
            } else if (s[i+1] == '-') {
                r++;
                i++;
            } else {
                r++;
            }
        } else if ((s[i] == 'c' && (s[i+1] == '-' || s[i+1] == '=')) ||
                (s[i] == 'l' && s[i+1] == 'j') ||
                (s[i] == 'n' && s[i+1] == 'j') ||
                (s[i] == 's' && s[i+1] == '=') ||
                (s[i] == 'z' && s[i+1] == '=')) {
            r++;
            i++;
        } else {
            r++;
        }
    }
    printf("%d", r);
    return 0;
}