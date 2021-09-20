#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compwz(double x) {
	return ((x > -0.00000001) && (x < 0.00000001));
}

void su(double* aa, int gde, int chto, double na_chto, int n) {
	for (int i = 0; i < n + 1; i++)
		aa[gde * (n + 1) + i] += na_chto * aa[chto * (n + 1) + i];
}

void mult(double* aa, int gde, double na_chto, int n) {
	for (int i = 0; i < n + 1; i++)
		aa[gde * (n + 1) + i] *= na_chto;
}

int Gauss(double* aa, double* answers, int n) {
	for (int i = 0; i < n; i++) {
		int j = i + 1;
		while (compwz(aa[i * (n + 1) + i])) {
			if (j >= n)
				return -1;
			if (!compwz(aa[j * (n + 1) + i]))
				su(aa, i, j, 1, n);
			j += 1;
		}

		mult(aa, i, 1.0 / aa[i * (n + 1) + i], n);

		for (int j = i + 1; j < n; j++)
			su(aa, j, i, -aa[j * (n + 1) + i], n);
	}
	for (int i = n - 1; i > 0; i--)
		for (int j = i - 1; j >= 0; j--)
			su(aa, j, i, -aa[j * (n + 1) + i], n);

	for (int i = 0; i < n; i++)
		answers[i] = aa[i * (n + 1) + n];

	return 1;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	double* aa = (double*)calloc((n * (n + 1)), sizeof(double));
	if (aa == 0)
		return 0;

	double* answers = (double*)calloc(n, sizeof(double));
	if (answers == 0)
		return 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n + 1; j++)
			scanf("%lf", &aa[i * (n + 1) + j]);

	if (Gauss(aa, answers, n) == 1)
		for (int i = 0; i < n; i++)
			printf("%lf\n", answers[i]);

	free(aa);
	free(answers);
	return 0;
}