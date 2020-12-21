#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>


typedef struct LongNum_s {
	int len;
	int arr[500];
} LongNum;

void vivod(LongNum* chto) {
	for (int i = (int)(chto->len - 1); i >= 0; i--)
		printf("%d", chto->arr[i]);
	printf("\n");
}

void plus(LongNum* a, LongNum* b, LongNum* c) {

	c->len = b->len;

	for (int i = 0; i < b->len; i++) {

		if (a->arr[i] + b->arr[i] > 9) {
			c->arr[i] = (a->arr[i] + b->arr[i]) % 10;

			if (b->len < i + 2) {
				c->len += 1;
				c->arr[i + 1] = (a->arr[i] + b->arr[i]) / 10;
			}

			else
				a->arr[i + 1] += (a->arr[i] + b->arr[i]) / 10;

		}
		else
			c->arr[i] = a->arr[i] + b->arr[i];
	}
}

void perenazn(LongNum* chto, LongNum* kuda) {
	for (int i = 0; i < chto->len; i++)
		kuda->arr[i] = chto->arr[i];
	kuda->len = chto->len;
}


void fib(int n) {
	LongNum a;
	LongNum b;
	LongNum c;
	int i;
	for (i = 0; i < 500; i++) {
		a.arr[i] = 0;
		b.arr[i] = 0;
		c.arr[i] = 0;
	}

	i = 0;

	a.len = 1;
	a.arr[a.len - 1] = 0;
	b.len = 1;
	b.arr[b.len - 1] = 1;
	c.len = 1;
	c.arr[c.len - 1] = 0;


	while (i < n)
	{
		perenazn(&b, &a);
		perenazn(&c, &b);

		plus(&a, &b, &c);
		i++;
	}
	vivod(&c);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);

	fib(n);

	return 0;
}
