#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int comp(const int* i, const int* j) {
	return *i - *j;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);


	int n;
	scanf("%d", &n);

	int* aa = (int*)calloc(n, sizeof(int));
	int* ne = (int*)calloc(n, sizeof(int));
	if (aa == 0 || ne == 0)
		exit(666);

	for (int i = 0; i < n; i++)
		scanf("%d", &aa[i]);


	qsort(aa, n, sizeof(int), comp);

	int tek = 0;
	int proshl = aa[0];
	ne[tek] = proshl;
	tek += 1;
	for (int i = 1; i < n; i++) {
		if (proshl != aa[i]) {
			ne[tek] = aa[i];
			proshl = aa[i];
			tek += 1;
		}
	}
	

	printf("%d\n", tek);
	for (int i = 0; i < tek; i++)
		printf("%d\n", ne[i]);

	free(aa);
	free(ne);

	return 0;
}
