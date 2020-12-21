#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    scanf("%d\n", &n);
    int* aa = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) 
        scanf("%d", &aa[i]);

    int k;

    for (int i = 0; i < n-1; i++) {
        k = 0;
        for (int j = (i + 1); j < n; j++)
            if (aa[i] > aa[j])
                k++;
        printf("%d ", k);
    
    }
    printf("%d ", 0);
    return 0;
}
