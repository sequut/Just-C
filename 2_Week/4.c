#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int a1;
    int a2;
    int b1;
    int b2;
    int c1;
    int c2;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d %d %d %d %d %d", &a1, &a2, &b1, &b2, &c1, &c2);


    if ((a1 >= b1 + c1) && ((a2 >= b2) && (a2 >= c2)))
        printf("YES");

    else if ((a1 >= b2 + c1) && ((a2 >= b1) && (a2 >= c2)))
        printf("YES");
    
    else if ((a1 >= b1 + c2) && ((a2 >= b2) && (a2 >= c1)))
        printf("YES");
    
    else if ((a1 >= b2 + c2) && ((a2 >= b1) && (a2 >= c1)))
        printf("YES");

    else if ((a2 >= b1 + c1) && ((a1 >= b2) && (a1 >= c2)))
        printf("YES");

    else if ((a2 >= b2 + c1) && ((a1 >= b1) && (a1 >= c2)))
        printf("YES");

    else if ((a2 >= b1 + c2) && ((a1 >= b2) && (a1 >= c1)))
        printf("YES");

    else if ((a2 >= b2 + c2) && ((a1 >= b1) && (a1 >= c1)))
        printf("YES");

    else printf("NO");
    return 0;
}
