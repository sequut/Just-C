#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <math.h>

typedef struct LongNum_s {
	int len;
	int arr[3000];
} LongNum;

void vivod(LongNum* chto) {
	for (int i = ((int)(chto->len - 1) ); i >= 0; i--)
		printf("%d", chto->arr[i]);
	printf("\n");
}

void perenazn(LongNum* chto, LongNum* kuda) {
	for (int i = 0; i < chto->len; i++)
		kuda->arr[i] = chto->arr[i];
	kuda->len = chto->len;
}

void multInt(LongNum* a, int n) {
	LongNum help;
	int hh;
	int f = a->len;
	help.len = f;
	for (int j = 0; j < 3000; j++)
		help.arr[j] = 0;

	for (int i = 0; i < f; i++) {

		help.arr[i] += a->arr[i] * n;

		for (int j = 3; j > 0; j--) {
			hh = pow(10, j);
			help.arr[i + j] += help.arr[i] / hh;
			help.arr[i] = help.arr[i] % hh;
		}
	}

	for (int j = 0; j < f+2; j++) {
		if (help.arr[j]>9){

			for (int g = 3; g > 0; g--) {
				hh = pow(10, g);
				help.arr[j + g] += help.arr[j] / hh;
				help.arr[j] = help.arr[j] % hh;
			}
		}
	}

	if (help.arr[help.len + 2] > 0)
		help.len += 3;

	else if (help.arr[help.len + 1] > 0)
		help.len += 2;

	else if (help.arr[help.len] > 0)
		help.len += 1;

	perenazn(&help, a);
}

void fact(int n) {

	LongNum rez;

	for (int j = 0; j < 3000; j++)
		rez.arr[j] = 0;

	rez.len = 1;
	rez.arr[rez.len - 1] = 1;

	int i = 1;

	while (i <= n)
	{
		multInt(&rez, i);
		i++;
	}
	vivod(&rez);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);

	fact(n);

	return 0;
}
