#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    int k;
    int a;
    int kol = 0;
    int ind = 0;

    int aa[100001] = { 0 };
    int bb[100001] = { 0 };

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        aa[a] += 1;
    }

    scanf("%d", &k);
    
    for (int i = 0; i < k; i++) {
        scanf("%d", &a);
        aa[a] = 0;
    }

    for (int i = 0; i < 100001; i++) {
        if (aa[i] > 0) {
            bb[ind] = i;
            ind += 1;
            kol += 1;
        }
    }
    printf("%d\n", kol);
    if (kol>0)
        for (int i = 0; i < kol; i++)
            printf("%d ", bb[i]);

    return 0;
}
