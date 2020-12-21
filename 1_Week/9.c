#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    long long k=0;
    int i,j,c,f;
    
    for (i=1; i*i*i<=n; i++)
        for (j=i; j*j<=n; j++){
            if ((n/(i*j)) - j + 1>0)
                k+=(n/(i*j)) - j + 1;
            }
    printf ("%lld", k);
    
 return 0;
 }
