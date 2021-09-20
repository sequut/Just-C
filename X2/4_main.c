
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void Init(const int* arr, int n);
int Query(int l, int64_t sum);
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int m, n;
    scanf("%d %d", &n, &m);
    int* aa = (int*)calloc(n, sizeof(int));
    if (aa == 0)
        exit(555);

    for (int i = 0; i < n; i++)
        scanf("%d", &aa[i]);

    Init(aa, n);
    int l;
    int64_t s;

    for (int i = 0; i < m; i++) {
        scanf("%d %lld", &l, &s);
        printf("%d\n", Query(l, s));
    }

    free(aa);
    return 0;
}

/*
#include <stdint.h>
#include "sol.h"
static int a=0;
int getVerticesCount()
{
    return 5;
}
int readEdge(Edge* buf)
{
    if (a == 0)
    {
        buf->from = 0;
        buf->to = 2;
        buf->weight = 178;
    }
    if (a == 1)
    {
        buf->from = 1;
        buf->to = 1;
        buf->weight = 356;
    }
    if (a == 2)
    {
        buf->from = 2;
        buf->to = 0;
        buf->weight = 101;
    }
    if (a == 3)
    {
        buf->from = 4;
        buf->to = 1;
        buf->weight = 286;
    }
    if (a == 4)
    {
        buf->from = 4;
        buf->to = 1;
        buf->weight = 213;
    }
    a++;
    if (a < 5)
        return 1;
    else
        return 0;
}
int main()
{
    init();
    return 0;
}

 */