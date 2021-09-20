
#define _CRT_SECURE_NO_WARNINGS
#define DELTA 0.0000001
#include <stdio.h>
#include <stdlib.h>
double Function(double x);
//double Function(double x) {
//	if (x < 0.0 || x > 1.0)
//		exit(666); //out of range
//	return x * x - x;
//}

double count(double point) {
	double answer;
	if (point + DELTA > 1.0) {
		answer = Function(point - DELTA) - Function(point);
		answer /= ((-1)*(double)DELTA);
	}
	else {
		answer = Function(point + DELTA) - Function(point);
		answer = answer / (double)DELTA;
	}

	return answer;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	double point;
	double answer;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lf", &point);
		answer = count(point);
		printf("%lf\n", answer);
	}

	return 0;
}