#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printTime(int h, int m, int s) {
    printf("%02d:%02d:%02d\n", h, m, s);
}

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    int h;
    int m;
    int s;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &h, &m, &s);
        printTime(h, m, s);
    }
    return 0;
}
