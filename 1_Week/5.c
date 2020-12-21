#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <math.h>

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int a,b;
    scanf("%d%d", &a, &b);
    
    if (a%b!=0){
      if (a>=0)
        printf("%d %d %d %d", a/b, a/b + 1, a/b, a%b);
      else
        printf("%d %d %d %d", a/b - 1, a/b, a/b, -(b*(a/b - 1) - a));
    }
    else
      printf("%d %d %d %d", a/b, a/b, a/b, a%b);

 return 0;
 }
