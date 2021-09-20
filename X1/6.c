#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long fast_step_mod(long long num, long long step, long long mod) {
	long long result = 1;
	while (step) {
		if (step % 2 == 0) {
			step /= 2;
			num *= num;
			num %= mod;
		}
		else {
			result *= num;
			result %= mod;
			step -= 1;
		}
	}
	return result;
}

long long Find_obr(long long a, long long m) {
	if (a == 0)
		return -1;

	return fast_step_mod(a, m - 2, m);
}

long long binom(long long n, long long k, long long mod, long long* aa) {
	long long result = 1;

	/*for (int i = 1; i <= n - k; i += 1) {
		result *= i;
		result %= mod;
	}*/
	result = aa[n - k];
	result = Find_obr(result, mod);
	result %= mod;

	long long help = aa[k];
	help = Find_obr(help, mod);

	result *= help;
	result %= mod;

	result *= aa[n];
	result %= mod;

	return result;
}
long long aa[1000001];
int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	long long m = 1000000007;
	int t;
	scanf("%d\n", &t);
	long long n, k;

	aa[0] = 1;
	for (int i = 1; i <= 1000000; i += 1) {
		aa[i] = aa[i - 1] * i;
		aa[i] %= m;
	}

	for (int i = 0; i < t; i++) {
		scanf("%lld %lld\n", &n, &k);

		printf("%lld\n", binom(n, k, m, aa));
	}
	return 0;

}