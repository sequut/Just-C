#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
const double eps = 1e-12;


double sin_count(double x) {
	int count = 0;
	double tek = x;
	double sum = 0.0;

	while (fabs(tek) > eps) {
		sum += tek;
		count += 1;
		tek *= -x * x / (2 * count * (2 * count + 1));
	}
	return sum;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d\n", &n);

	double x;
	for (int i = 0; i < n; i++) {
		scanf("%lf\n", &x);
		printf("%0.15lf\n", sin_count(x));
	}
	return 0;
}
