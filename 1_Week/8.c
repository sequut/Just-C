#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int h,m,s,n;
    scanf("%d %d %d %d", &h, &m,&s, &n);
    
    int t=0;
    t = h*3600 + 60*m + s + n;
    h = t/3600;
    m = (t - h*3600)/60;
    s = t - 3600*h - 60*m;
    h = h%24;
    printf("%d %d %d", h, m, s);
   
 return 0;
 }
