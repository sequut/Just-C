#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int nod(int a, int b){
	while ((a > 0) && (b > 0)) {
		if (a > b)
			a %= b;
		else
			b %= a;
	}
	return a + b;

}




int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	int a, b;
	scanf("%d\n", &t);

	for (int i = 0; i < t; i++) {
		scanf("%d %d\n", &a, &b);
		printf("%d\n", nod(a, b));
	}


	return 0;
}