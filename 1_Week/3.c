#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int a, n, su = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        if (a % 2 == 0)
            su += a;
    }
    printf("%d", su);
}
