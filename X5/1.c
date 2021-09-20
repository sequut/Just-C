#pragma comment(linker, "/STACK:50000000")
#include <stdio.h>

int n											;
int aa[1000000]									;

void alg(int x, int y, int k)					{
    if ((x < 0) || (x > n) || (y < 0) || (y > n))
        return									;

    aa[x * n + y] = k							;

    if (!aa[(x + 1) * n + y])
        alg(x + 1, y, k)						;
    if (!aa[(x - 1) * n + y])
        alg(x - 1, y, k)						;
    if (!aa[x * n + (y + 1)])
        alg(x, y + 1, k)						;
    if (!aa[x * n + (y - 1)])
        alg(x, y - 1, k)						;
												}

int find()										{
    int number = 0								;
    for (int i = 0;i < n;i++)					{
        for (int j = 0;j < n;j++)				{
            if (aa[i * n + j] == 0)				{
                number += 1						;
                alg(i, j, number)				;
												}
												}
												}

    return number - 1							;
												}

int main()										{
    freopen("input.txt", "r", stdin)			;
    freopen("output.txt", "w", stdout)			;

    scanf("%d\n", &n)							;
    char tek									;

    for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++)				{
            tek = fgetc(stdin)					;
            if (tek == '\n')
                j -= 1							;
            else if (tek == '*')
                aa[i * n + j] = -1				;
												}

    printf("%d", find())						;
    return 0									;
		

										}