#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void treyg(int* aa, int n, int m) {

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if ((i == 0) || (j == 0))
				aa[i * (2000 + 1) + j] = 1;
			else
				aa[i * (2000 + 1) + j] = (aa[i * (2000 + 1) + j - 1] + aa[(i - 1) * (2000 + 1) + j]) % m;
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	int k;
	int q;
	int m;

	scanf("%d %d\n", &m, &q);

	int* bb = (int*)calloc((2 * q), sizeof(int));

	if (bb == 0)
		return 0;


	for (int i = 0; i < 2 * q; i += 2) {
		scanf("%d %d\n", &n, &k);
		bb[i] = n;
		bb[i + 1] = k;
	}

	int* aa = (int*)calloc(((2000 + 1) * (2000 + 1)), sizeof(int));
	if (aa == 0) {
		free(bb);
		return 0;
	}


	treyg(aa, 2000, m);

	for (int i = 0; i < 2 * q; i += 2)
		if (bb[i + 1]<0 || bb[i + 1]>bb[i])
			printf("0\n");
		else
			printf("%d\n", aa[(bb[i] - bb[i + 1]) * (2000 + 1) + bb[i + 1]]);


	free(aa);
	free(bb);
	return 0;
}