#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int ma_el = -10000;
    int poz = 0;
    int n;
    int ne_l = 0;
    int l = 0;
    int r = 0;
    int su = 0;
    int ma = 0;
    int a;
    
    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        if (a > ma_el) {
            ma_el = a;
            poz = i;
        }

        su += a;    
        if (su < 0) {
            su = 0;
            ne_l = i + 1;
        }

        if (su > ma) {
            ma = su;
            r = i;
            l = ne_l;
        }
    }
    if (ma_el > 0)
        printf("%d %d %d", l, r, ma);
    else
        printf("%d %d %d", poz, poz, ma_el);
    return 0;
}
