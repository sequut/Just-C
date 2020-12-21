#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int poz = 0;
    int neg = 0;
    int nul = 0;
    int n;
    int a;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d ", &a);
        if (a > 0)
            poz += 1;
        else if (a < 0)
            neg += 1;
        else
            nul += 1;
    }
    float ne = (float)neg / (double)n;
    float po = (float)poz / (float)n;
    float nu = (float)nul / (float)n;
    printf("%0.5lf %0.5lf %0.5lf", ne, nu, po);
    return 0;
}
