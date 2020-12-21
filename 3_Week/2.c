#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int su_k(int* aa, int k, int n) {
    int su = 0;
    for (int i = (k - 1); i < n; i += k)
        su += *(aa + i);
    return su;
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


    for (int i = 0; i < n; i++)
        printf("%d\n", su_k(&aa[0], i + 1, n));

    free(aa);
    return 0;
}
