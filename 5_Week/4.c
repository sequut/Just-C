#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 

void prost(int* aa, int n) {
	for (int i = 2; i * i <= n; i++)
		if (aa[i] == 0)
			for (int j = i * i; j <= n; j += i)
				aa[j] = 1;
	aa[0] = 1;
	aa[1] = 1;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	int q;

	scanf("%d %d", &n, &q);

	int* aa = (int*)calloc((n+1), sizeof(int)); //0 - prime/ 1 - not

	if (aa == 0) {
		printf(":(");
		return 0;
	}

	int a;
	prost(aa, n+1);

	for (int i = 0; i < q; i++) {
		scanf("%d", &a);
		printf("%d ", a);
		if (aa[a] == 0)
			printf("prime\n");
		else if (aa[a] == 1)
			printf("not\n");
	}
	
	free(aa);

	return 0;
}
