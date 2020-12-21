#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void sort(int* aa, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (*(aa + j) > * (aa + j + 1)) {
                int hp = *(aa + j);
                *(aa + j) = *(aa + j + 1);
                *(aa + j + 1) = hp;
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    scanf("%d\n", &n);
    int* aa = (int*)malloc(n * sizeof(int));

    if (aa == 0)
        return 0;

    for (int i = 0; i < n; i++)
        scanf("%d", &aa[i]);
    sort(aa, n);

    for (int i = 0; i < n; i++)
        printf("%d ", aa[i]);

    free(aa);
}
