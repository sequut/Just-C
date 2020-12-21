#define _CRT_SECURE_NO_WARNINGS
#define SIZE 10000000
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct hash_table {
	uint32_t val;
	int sost;
	uint32_t num;
}hash_table;

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

uint32_t hash_find(hash_table* hash, uint32_t val) {
	int ind = abs(hash_func((char*)&val, sizeof(uint32_t))) % SIZE;
	while (hash[ind].sost == 1) {
		if (hash[ind].val == val)
			return hash[ind].num;
		else
			ind += 1;
	}
	return -666;
}

void hash_add(hash_table* hash, uint32_t val, uint32_t num) {
	int ind = abs(hash_func((char*)&val, sizeof(uint32_t))) % SIZE;
	while (hash[ind].sost == 1)
		ind += 1;

	hash[ind].sost = 1;
	hash[ind].val = val;
	hash[ind].num = num;
}

hash_table hash[SIZE] = { 0 };
int main() {
	uint32_t tek = 0;
	uint32_t key;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	printf("eval %d\n", tek);
	fflush(stdout);
	scanf("%u", &key);
	fflush(stdout);
	tek += 1;
	while (hash_find(hash, key) == -666) {
		hash_add(hash, key, tek);

		printf("eval %d\n", tek);
		fflush(stdout);
		scanf("%u", &key);
		fflush(stdout);
		tek += 1;
	}
	printf("answer %u %u\n", hash_find(hash, key) - 1, tek - 1);
	return 0;
}
