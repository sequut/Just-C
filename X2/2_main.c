
#define _CRT_SECURE_NO_WARNINGS
#include "modular.h" //в этом хедере должны быть объявления
#include <assert.h>
#include <stdio.h>
int main() {
	MOD = 13; //устанавливаем глобальный модуль
	int a = 45;
	a = pnorm(a);
	assert(a == 6);
	int x = pmul(padd(7, psub(2, 3)), 5);
	assert(x == 4);
	int y = pdiv(7, x);
	assert(pmul(x, y) == 7);
	MOD = 2; //меняем модуль на другой
	assert(pnorm(5) == 1);

	

	MOD = 1000000007;
	assert(pmul(111111114, 56543223) == 452702362);
	assert(pdiv(111111114, 56543223) == 822705498);
	assert(padd(111111114, 56543223) == 167654337);
	assert(psub(111111114, 56543223) == 54567891);
	assert(pnorm(-56543223) == 943456784);
	assert(pnorm(-56543223) == 943456784);


	MOD = 5;
	assert(padd(3, 4) == 2);

	assert(psub(1, 4) == 2);
	//printf("%d", psub(1, 4));

	return 0;
}