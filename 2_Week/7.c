#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int l;
    int r;
    int k;
    int sch = 0;
    scanf("%d %d %d", &l, &r, &k);

    for (int i = l; i<=r-k+1; i++)
        
        for (int j = 1; j <= (r - l) / (k - 1); j++) 
            if ((i+(k-1)*j<=r) && (i + k*j > r))
                sch++;
       

    printf("%d", sch);
    
    return 0;
}
