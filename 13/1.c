#define _CRT_SECURE_NO_WARNINGS
#define EPS 1e-15
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long double doit(long double x) {
	long double sum = 1;
	long double tek = 1;
	long int n = 1;
	
	if (x < 0) {
		x *= -1;
		while (fabs(tek) >= EPS) {
			tek *= (x / n);
			n += 1;
			sum += tek;
		}
		return 1 / sum;
	}	
	else {
		while (fabs(tek) >= EPS) {
			tek *= (x / n);
			n += 1;
			sum += tek;
		}
		return sum;
	}
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int n;
	scanf("%d\n", &n);
	long double x;

	for (int i = 0; i < n; i++) {
		scanf("%lf\n", &x);
		printf("%0.15g\n", doit(x));
	}

	return 0;	
}