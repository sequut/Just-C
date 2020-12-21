#define _CRT_SECURE_NO_WARNINGS
#define LENGTH_KEY 4
#include <stdio.h> 
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

int comp(const int* i, const int* j) {
	return *i - *j;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n,m;

	scanf("%d\n", &n);
	int* aa = (int*)calloc(n, sizeof(int));
	if (aa == 0)
		exit(666);

	for (int i = 0; i < n; i++)
		scanf("%d", &aa[i]);


	scanf("%d\n", &m);
	int* bb = (int*)calloc(m, sizeof(int));
	if (bb == 0)
		exit(666);

	for (int i = 0; i < m; i++)
		scanf("%d ", &bb[i]);

	qsort(aa, n, sizeof(int), comp);
	qsort(bb, m, sizeof(int), comp);


	int* ne = (int*)calloc(n, sizeof(int));
	if (ne == 0)
		exit(666);

	int a = 0;
	int tek = 0;
	int b = 0;
	while (a < n) {
		if ((aa[a - 1] == aa[a]) && (a > 0))
			a += 1;

		else if (b >= m) {
			ne[tek] = aa[a];
			a += 1;
			tek += 1;
		}


		else if (bb[b] < aa[a])
			b += 1;

		else if (aa[a] == bb[b]) {
			a += 1;
			b += 1;
		}

		else {
			ne[tek] = aa[a];
			tek += 1;
			a += 1;
		}
	}




	printf("%d\n", tek);
	for (int i = 0; i < tek; i++)
		printf("%d ", ne[i]);

	free(aa);
	free(ne);
	free(bb);
	return 0;
}
