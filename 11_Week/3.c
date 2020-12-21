#define _CRT_SECURE_NO_WARNINGS
#define SIZE 10000000
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
int a, b, c;
long long int M;
uint64_t state = 1;

typedef struct hash_table {
	uint64_t val;
	int sost;
	uint64_t num;
}hash_table;

uint64_t func(uint64_t s) {
	return (s * s * a + s * b + c) % M;
}

int hash_func(const char* value, int n) {
	int key = 0;
	for (int i = 0; i < n; i++)
	{
		key += value[i];
		key += (key << 10);
		key ^= (key >> 6);
	}
	key += (key << 3);
	key ^= (key >> 11);
	key += (key << 15);
	return key;
}

uint64_t hash_find(hash_table* hash, uint64_t val) {
	int ind = abs(hash_func((char*)&val, sizeof(uint64_t))) % SIZE;
	while (hash[ind].sost == 1) {
		if (hash[ind].val == val)
			return hash[ind].num;
		else
			ind += 1;
	}
	return -666;
}

void hash_add(hash_table* hash, uint64_t val, uint64_t num) {
	int ind = abs(hash_func((char*)&val, sizeof(uint64_t))) % SIZE;
	while (hash[ind].sost == 1)
		ind += 1;

	hash[ind].sost = 1;
	hash[ind].val = val;
	hash[ind].num = num;
}

hash_table hash[SIZE] = { 0 };
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%lld\n", &M);
	scanf("%d %d %d\n", &a, &b, &c);


	state = 1;
	
	uint64_t i = 0;
	while (hash_find(hash, state) == -666) {
		hash_add(hash, state, i);
		state = func(state);
		i += 1;
	}
	printf("%lld %lld\n", hash_find(hash, state), i);
	return 0;
}
