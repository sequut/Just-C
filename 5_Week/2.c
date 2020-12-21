#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 

void treyg(double* aa, int n) {

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if ((i == 0) || (j == 0))
				aa[i * (1000 + 1) + j] = 1;
			else
				aa[i * (1000 + 1) + j] = aa[i * (1000 + 1) + j - 1] + aa[(i - 1) * (1000 + 1) + j];

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


	scanf("%d\n", &q);

	int* bb = (int*)calloc((2 * q), sizeof(int));

	if (bb == 0)
		return 0;


	for (int i = 0; i < 2 * q; i += 2) {
		scanf("%d %d\n", &n, &k);
		bb[i] = n;
		bb[i + 1] = k;
	}

	double* aa = (double*)calloc(((1000 + 1) * (1000 + 1)), sizeof(double));
	if (aa == 0){
        free(bb);
		return 0;
}


	treyg(aa, 1000);

	for (int i = 0; i < 2 * q; i += 2)
		printf("%0.10g\n", aa[(bb[i] - bb[i + 1]) * (1000 + 1) + bb[i + 1]]);


	free(aa);
	free(bb);
	return 0;
}
