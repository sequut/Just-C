#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, a, mi, ma, mii, mai;
    mi = 10001;
    ma = -10001;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        if (a>ma){
          ma=a;
          mai=i;
        }
        if (a<mi){
          mi=a;
          mii=i;
        }
    }
    printf("%d %d %d %d", mi, mii+1, ma, mai+1);
}
