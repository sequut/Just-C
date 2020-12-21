#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m, p, k, l, x;
	int u, a, i;


	scanf("%d\n", &n);
	scanf("%d %d %d %d", &m, &p, &k, &l);
	x = m - 1;
	while (x % ((p - 1) * l + (k - 1) != 0))
		x = x - 1;
	x = x / ((p - 1) * l + k - 1);
	i = x * l;
	a = 0; u = 0;
	while (n > i * a)
		a = a + 1;

	while (n > ((a - 1) * x * l + x * u))
		u = u + 1;
	printf("%d %d", a, u);
	return 0;
}
