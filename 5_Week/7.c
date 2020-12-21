#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <math.h>

typedef struct LongNum_s {
	int len;
	int arr[3000];
} LongNum; //rabotaet

void vivod(LongNum* chto) {
	for (int i = ((int)(chto->len - 1)); i >= 0; i--)
		printf("%d", chto->arr[i]);
	printf("\n");
} //rabotaet

void perenazn(LongNum* chto, LongNum* kuda) {
	for (int i = 0; i < chto->len; i++)
		kuda->arr[i] = chto->arr[i];
	kuda->len = chto->len;
} //rabotaet

void scanLongNum(LongNum* a) {				//--функция считывания длинного числа
	char str[1001];
	scanf("%s\n", str);
	int i = 0;
	a->len = strlen(str);
	while (str[i] != '\0') {
		a->arr[strlen(str) - 1 - i] = str[i] - '0';
		i++;
	}
	
} //rabotaet

LongNum mult10(LongNum a, int k) {
	for (int i = a.len - 1; i >= 0; i--) {
		a.arr[i + k] = a.arr[i];
		if (i < k)
			a.arr[i] = 0;
	}
	a.len = a.len+k;
	return a;
} //rabotaet

void multInt(LongNum* a, int n) {
	LongNum help;
	int hh;
	int f = a->len;
	help.len = f;
	for (int j = 0; j < 3000; j++)
		help.arr[j] = 0;

	for (int i = 0; i < f; i++) {

		help.arr[i] += (a->arr[i] * n) % 10;
		help.arr[i+1] += (a->arr[i] * n) / 10;
	}

	for (int j = 0; j < f + 2; j++) {
		if (help.arr[j] > 9) {

			for (int g = 1; g > 0; g--) {
				hh = pow(10, g);
				help.arr[j + g] += help.arr[j] / hh;
				help.arr[j] = help.arr[j] % hh;
			}
		}
	}

	if (help.arr[help.len] > 0)
		help.len += 1;

	perenazn(&help, a);
} //rabotaet

void plus(LongNum* a, LongNum b, LongNum* c) {

	c->len = b.len;

	for (int i = 0; i < b.len; i++) {

		if (a->arr[i] + b.arr[i] > 9) {
			c->arr[i] = (a->arr[i] + b.arr[i]) % 10;

			if (b.len < i + 2) {
				c->len += 1;
				c->arr[i + 1] = (a->arr[i] + b.arr[i]) / 10;
			}
			else
				a->arr[i + 1] += (a->arr[i] + b.arr[i]) / 10;

		}
		else
			c->arr[i] = a->arr[i] + b.arr[i];
	}
} //rabotaet

LongNum mult_long(LongNum a, LongNum b) {
	LongNum res;
	LongNum help = a;

	for (int i = 0; i < 3000; i++) 
		res.arr[i] = 0;
	res.len = a.len;

	for (int i = 0; i < b.len; i++) {
		help = a;
		multInt(&help, b.arr[i]);
		plus(&res, mult10(help, i), &help);
		perenazn(&help, &res);
	}
	return res;
}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	LongNum a, b;
	for (int i = 0; i < 3000; i++) {
		a.arr[i] = 0;
		b.arr[i] = 0;
	}
	scanLongNum(&a);
	scanLongNum(&b);
	
	LongNum c;
	c.len = a.len;

	c = mult_long(a, b);
	vivod(&c);

	return 0;
}
