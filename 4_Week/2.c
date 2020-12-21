#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void reverse(char* aa, int l) {
    char pom;
    for (int i = 0; i <= l / 2; i++) {
        pom = *(aa + i);
        *(aa + i) = *(aa + (l - i));
        *(aa + (l - i)) = pom;
    }
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    char aa[100];
    int l;
    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        l = 0;
        while ((scanf("%c", &aa[l]) == 1) && (aa[l] != '\n'))
            l++;

        reverse(aa, l - 1);

        if (aa[l] == '\n')
            for (int j = 0; j <= l; j++)
                printf("%c", aa[j]);
        else
            for (int j = 0; j < l; j++)
                printf("%c", aa[j]);
    }
    return 0;
}
