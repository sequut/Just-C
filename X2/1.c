#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void extended_euclid(long long a, long long b, long long* x, long long* y, long long* d) {
	long long q, r, x1, x2, y1, y2;
	if (b == 0) {
		*d = a;
		*x = 1;
		*y = 0;
		return;
	}
	x2 = 1, x1 = 0;
	y2 = 0, y1 = 1;
	while (b > 0) {
		q = a / b; 
		r = a - q * b;
		*x = x2 - q * x1;
		*y = y2 - q * y1;
		a = b;
		b = r;

		x2 = x1;
		x1 = *x;
		y2 = y1;
		y1 = *y;
	}
	*d = a;
	*x = x2;
	*y = y2;
}

long long obr(long long a, long long mod) {
	long long d, x, y;
	extended_euclid(a, mod, &x, &y, &d);
	if (d == 1)
		return x;
	return 0;
}

long long count_M(long long* aa, int k) {
	long long M = 1;
	for (int i = 0; i < k; i++)
		M *= aa[i];
	return M;
}

void count_MI(long long* MI, long long* a, long long M, int k) {
	for (int i = 0; i < k; i++)
		MI[i] = M / a[i];
}

void count_MI_1(long long* MI_1, long long* MI, long long* m, int k) {
	for (int i = 0; i < k; i++) {
		MI_1[i] = obr(MI[i], m[i]);
		if (MI_1[i] < 0)
			MI_1[i] += m[i];
	}	
}

long long count_X(long long* rr, long long* MI, long long* MI_1, int k, long long M, long long* a) {
	long long x = 0;
	for (int i = 0; i < k; i++)
		x = x % M + (((rr[i] * MI_1[i]) % a[i]) * MI[i]) % M;
	
	x %= M;
	return x;
}


long long count(long long* a, long long* rr, long long* MI, long long* MI_1, int k){
	long long M;
	M = count_M(a, k);
	count_MI(MI, a, M, k);
	count_MI_1(MI_1, MI, a, k);

	return count_X(rr, MI, MI_1, k, M, a);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int k;
	scanf("%d", &k);

	long long* rr = calloc(k, sizeof(long long));
	if (rr == 0)
		exit(666);
	long long* a = calloc(k, sizeof(long long));
	if (a == 0)
		exit(666);	
	long long* MI = calloc(k, sizeof(long long));
	if (MI == 0)
		exit(666);
	long long* MI_1 = calloc(k, sizeof(long long));
	if (MI_1 == 0)
		exit(666);

	for (int i = 0; i < k; i++)
		scanf("%lld", &a[i]);

	for (int i = 0; i < k; i++)
		scanf("%lld", &rr[i]);

	
	long long x;
	x = count(a, rr, MI, MI_1, k);
	//x = count_X(rr, MI, MI_1, k, M, a);

	printf("%lld\n", x);

	free(rr);
	free(a);
	free(MI);
	free(MI_1);
	return 0;
}