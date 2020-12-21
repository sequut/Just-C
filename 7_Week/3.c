#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 


typedef union Double_u {
	double num;
	long long int u;
}Double;


int main() {

	int n;
	int p;
	int q;
	Double x;
	long long int m;


	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d\n", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d/%d xor %llx", &p, &q, &m);
		x.num = (double)p / (double)q;
		
		x.u ^= m;
		printf("%0.15g\n", x.num);
	}

	return 0;
}
