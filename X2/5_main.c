
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 1000
#include <stdio.h>
#include <stdlib.h>

typedef struct Factors {
	int k;
	int primes[32];
	int powers[32];
} Factors;

void Factorize(int X, Factors* res);

void print_struct(Factors aa) {
	if (aa.k == 0) {
		printf("1\n");
		return;
	}
	for (int i = 0; i < aa.k; i++) {
		printf("%d^%d", aa.primes[i], aa.powers[i]);
		if (i < aa.k - 1) {
			printf(" * ");
		}
	}
	printf("\n");
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	int x;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)	{
		Factors aa = { 0 };
		scanf("%d", &x);
		
		Factorize(x, &aa);
		printf("%d = ", x);
		print_struct(aa);
	}
	return 0;
}