#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    int a;
    scanf("%d\n", &n);
    
    int bb[10001] = {0};
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        bb[a] += 1;
    }

    for (int i = 1; i <= 10000; i++)
        if (bb[i]>0)
            printf("%d: %d\n", i, bb[i]);
    return 0;

}
