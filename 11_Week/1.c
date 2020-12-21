#define _CRT_SECURE_NO_WARNINGS
#define SIZE 1000000
#include <stdio.h>
#include <stdlib.h>

typedef struct hash_table {
	int val;
	int sost;
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

int hash_find(hash_table* hash, int val) {
	int ind = abs(hash_func((char*)&val, sizeof(int)) % (2 * SIZE));
	while (hash[ind].sost == 1) {
		if (hash[ind].val == val)
			return ind;
		else
			ind += 1;
	}
	return -1;
}

void hash_add(hash_table* hash, int val) {
	int ind = abs(hash_func((char*)&val, sizeof(int)) % (2 * SIZE));
	while (hash[ind].sost == 1)
		ind += 1;
	hash[ind].sost = 1;
	hash[ind].val = val;
}
hash_table hash[3 * SIZE] = {0};

int main() {

	FILE* input = fopen("input.bin", "rb");
	FILE* output = fopen("output.bin", "wb");

	int uniq = 0;
	int n;
	fread(&n, sizeof(int), 1, input);

	int* aa = (int*)calloc(n, sizeof(int));
	//hash_table* hash = (hash_table*)calloc(3 * n, sizeof(hash_table));

	if (aa == 0)
		exit(666);

	int help;
	for (int i = 0; i < n; i++) {
		fread(&help, sizeof(int), 1, input);

		if (hash_find(hash, help) == -1) {
			hash_add(hash, help);
			aa[uniq] = help;
			uniq += 1;
		}
	}
	fwrite(&uniq, sizeof(int), 1, output);

	for (int i = 0; i < uniq; i++)
		fwrite(&aa[i], sizeof(int), 1, output);


	//free(hash);
	free(aa);

	fclose(input);
	fclose(output);
	return 0;
}
