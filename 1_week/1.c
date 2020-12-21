#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, su=0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        su += i;
    printf("%d", su);
}