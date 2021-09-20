#define _CRT_SECURE_NO_WARNINGS
#define EPS 1e-15
#define PI 3.1415926535897932384626
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Vector_s {
	double x;
	double y;
	double z;
} Vector;

const double con = 180 / PI;

double doit(double ax, double ay, double bx, double by, double cx, double cy) {
	Vector b = { 0 };
	b.x = bx - ax;
	b.y = by - ay;
	
	Vector a = { 0 };
	a.x = cx - ax;
	a.y = cy - ay;

	Vector ne = { 0 }; //получил через векторное произведение
	//ne.x = a.y * b.z - a.z * b.y;
	//ne.y = a.z * b.x - a.x * b.z;
	ne.z = fabs(a.x * b.y - a.y * b.x);

	double sin_ = ne.z;
	double cos_ = (a.x * b.x + a.y * b.y);
	
	return (con * atan2(ne.z, (a.x * b.x + a.y * b.y)));
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d\n", &n);
	double ax, ay, bx, by, cx, cy;

	for (int i = 0; i < n; i++) {
		scanf("%lf %lf %lf %lf %lf %lf\n", &ax, &ay, &bx, &by, &cx, &cy);
		printf("%0.20g\n", doit(ax, ay, bx, by, cx, cy));
	}
	return 0;
}