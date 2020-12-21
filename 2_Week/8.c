#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int isvis(int y) {
    if ((y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0)))
        return 1;
    else
        return 0;
}
int opr_dn(int m, int v) {
    switch (m) {
    case 1:
        return 31;
    case 3:
        return 31;
    case 4:
        return 30;
    case 5:
        return 31;
    case 6:
        return 30;
    case 7:
        return 31;
    case 8:
        return 31;
    case 9:
        return 30;
    case 10:
        return 31;
    case 11:
        return 30;
    case 12:
        return 31;
    case 2: {
        if (v == 1)
            return 29;
        else
            return 28;
        }
    }
}

int main(){

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int d;
    int m;
    int y;
    int k;
    scanf("%d %d %d %d", &d, &m, &y, &k);
    int v = 0;

    while (k > 0) {
        
        if (d < opr_dn(m, isvis(y))) {
            k--;
            d++;
        }
        else if (m == 12) {
            k--;
            d = 1;
            m = 1;
            y++;
        }
        else{
            k--;
            d = 1;
            m++;
        }
    }
    printf("%d %d %d", d, m, y);
    return 0;
}
