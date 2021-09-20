#define NNNN 10000
#include <stdio.h>
#include <math.h>

typedef struct Span_s {
    long double c0;
    long double c1;
    long double c2;
    long double c3;
} Span;

long double newFunction(Span aa, long double point, long double l) {
    return aa.c1 + 2 * aa.c2 * (point - l) + 3 * aa.c3 * (point - l) * (point - l);
}

long double count(Span x, Span y, Span z, long double l, long double r) {
    long double an = 0;
    long double in_x, in_y, in_z;
    long double dt = (r - l) /NNNN;
    long double tek = l;
    long double res=0;

    for(int i = 0; i <= NNNN; i++) {
        tek = l + dt * i;
        in_x = newFunction(x, tek, l);
        in_y = newFunction(y, tek, l);
        in_z = newFunction(z, tek, l);

        an = sqrtl(in_x * in_x + in_y * in_y + in_z * in_z);

        if ((i % 2 == 0) && (i != NNNN) && (i != 0))
            an *= 2;
        else if (i % 2 == 1)
            an *= 4;

        res += an;
    }
    return res * dt/3;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    long double l, r;
    scanf("%d\n", &n);

    long double su = 0;
    for (int i = 0; i < n; i++) {
        Span x = { 0 };
        Span y = { 0 };
        Span z = { 0 };
        scanf("%Lf %Lf\n", &l, &r);
        scanf("%Lf %Lf %Lf %Lf\n", &x.c0, &x.c1, &x.c2, &x.c3);
        scanf("%Lf %Lf %Lf %Lf\n", &y.c0, &y.c1, &y.c2, &y.c3);
        scanf("%Lf %Lf %Lf %Lf\n", &z.c0, &z.c1, &z.c2, &z.c3);

        su += count(x, y, z, l, r);
    }
    printf("%0.20Lf", su);

    return 0;
}