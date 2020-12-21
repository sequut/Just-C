#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <math.h>

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int a,z=0;
    scanf("%d", &a);
    for (int i = 2; i*i <= a; i++) {
        if (a % i == 0){
            z = 1;
            break;
        }
    }
    if (a==1)
       z=1;
    if (z == 1)
        printf("NO");
    if (z==0)
        printf("YES");
}
