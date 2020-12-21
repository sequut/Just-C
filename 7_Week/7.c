#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int n;
	int kol = 0;
	scanf("%d\n", &n);
	
	long long int* aa = (long long int*)calloc((n), sizeof(long long int));

	if (aa == 0)
		return 0;

	for (int i = 0; i < n; i++) {

		scanf("%llx", &aa[i]);
		for (int j = i - 1; j >= 0; j--)
			if (!(aa[i] & aa[j]))
				kol += 1;
	}
	printf("%d\n", kol);
	
	free(aa);
}
