#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int comp(const int* i, const int* j){
	return *i - *j;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	
	int n;
	scanf("%d", &n);

	int* aa = (int*)calloc(n, sizeof(int));

	if (aa == 0)
		exit(666);

	for (int i = 0; i < n; i++)
		scanf("%d", &aa[i]);

	long long int su = 0;

	qsort(aa, n, sizeof(int), comp);

	for (int i = 0; i < n; i++)
		su += (long long int)aa[i]*(n - i - 1);
	
	

	printf("%lld\n", su);

	free(aa);

	return 0;
}
