#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 

int perevod(char a, char b) {
    if ((a == 'M') && (b == 'o'))
        return 1;
    else if ((a == 'T') && (b == 'u'))
        return 2;
    else if ((a == 'W') && (b == 'e'))
        return 3;
    else if ((a == 'T') && (b == 'h'))
        return 4;
    else if ((a == 'F') && (b == 'r'))
        return 5;
    else if ((a == 'S') && (b == 'a'))
        return 6;
    else if ((a == 'S') && (b == 'u'))
        return 7;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);


    char aa[3];
    for (int i = 0; i < 3; i++)
        scanf("%c", &aa[i]);
    printf("%d", perevod(aa[0], aa[1]));
}
