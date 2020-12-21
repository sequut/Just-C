#define _CRT_SECURE_NO_WARNINGS
#define SIZE 5002
#include <stdio.h>
#include <stdlib.h>

int findnull(int n, int* kol_vo) {
	for (int i = 1; i <= n; i++)
		if (kol_vo[i] == 0) {
			return i;
		}
	return -1;
}

int Topolog_sort(int* aa, int n, int* res, int* kol_vo) {
	for (int k = 0; k < n; k++) {
		int nach = findnull(n, kol_vo);

		if (nach == -1)
			return -1;

		kol_vo[nach] = -1;
		res[k] = nach;

		for (int i = 1; i <= n; i++)
			if (aa[i + nach * SIZE] > 0)
				kol_vo[i] -= 1;
	}
}

int aa[SIZE][SIZE] = { 0 };

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;
	scanf("%d %d\n", &n, &m);

	int* kol_vo = (int*)calloc((n + 2), sizeof(int));
	int* res = (int*)calloc(n, sizeof(int));
	if (res == 0 || kol_vo == 0)
		exit(666);

	int a, b;
	for (int i = 0; i < m; i++) {
		scanf("%d %d\n", &b, &a);
		if (aa[b][a] == 0)
			kol_vo[a] += 1;
		aa[b][a] = 1;
	}

	if (Topolog_sort(aa, n, res, kol_vo) == -1)
		printf("bad course");
	else
		for (int i = 0; i < n; i++)
			printf("%d ", res[i]);

	free(kol_vo);
	free(res);
	return 0;
}
