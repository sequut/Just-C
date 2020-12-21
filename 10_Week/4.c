#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>


void alg(int** aa, int n) {
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				aa[i][j] = min(aa[i][j], aa[i][k] + aa[k][j]);
				if (i == j)
					aa[i][j] = 1;
			}	
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d\n", &n);

	int** aa = (int**)calloc(n, sizeof(int*));
	int* help = (int*)malloc(sizeof(int) * n * n);
	if (aa == 0 || help == 0)
		exit(666);

	for (int i = 0; i < n; i++) {
		aa[i] = help + i * n;
	}
	
	char a;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%c", &a);
			if (a=='\n')
				scanf("%c", &a);

			if (a == '1')
				aa[i][j] = 1;
			else
				aa[i][j] = 999;
		}
	}

	alg(aa, n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (aa[i][j] == 999)
				aa[i][j] = 0;
			else
				aa[i][j] = 1;
			printf("%d", aa[i][j]);
		}
		printf("\n");
	}
	return 0;
}
