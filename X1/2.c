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
int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	long long m;
	int t;
	scanf("%d %lld\n", &t, &m);
	long long a;

	for (int i = 0; i < t; i++) {
		scanf("%lld\n", &a);

		printf("%lld\n", Find_obr(a, m));
	}
	return 0;
}