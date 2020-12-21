#define _CRT_SECURE_NO_WARNINGS
#define LENGTH_KEY 4
#include <stdio.h> 
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#pragma pack(push, 1)
typedef struct elem_s {
	unsigned char key[4];
	uint32_t value;
}Elem;
#pragma pack(pop)


void Radix_sort(Elem* aa, int n) {
	Elem* res = (Elem*)calloc(n, sizeof(Elem));
	if (res == 0)
		exit(666);

	Elem* bb;

	for (int j = 0; j < 4; j++) {
		int Help[256] = { 0 };

		for (int i = 0; i < n; i++)
			Help[(int)aa[i].key[j]] += 1;

		int su = 0;
		for (int i = 0; i < 256; i++) {
			su += Help[i];
			Help[i] = su - Help[i];
		}

		for (int i = 0; i < n; i++) {
			res[Help[aa[i].key[j]]] = aa[i];
			Help[aa[i].key[j]] += 1;
		}
		bb = aa;
		aa = res;
		res = bb;

	}
	free(res);
}

int main() {
	FILE* input = fopen("input.bin", "rb");
	FILE* output = fopen("output.bin", "wb");

	if (input == 0 || output == 0)
		exit(666);

	int n;
	fread(&n, sizeof(int), 1, input);

	Elem* aa = (Elem*)calloc(n, sizeof(Elem));
	if (aa == 0)
		exit(666);

	fread(aa, sizeof(Elem), n, input);

	Radix_sort(aa, n);

	fwrite(aa, sizeof(Elem), n, output);

	free(aa);
	fclose(input);
	fclose(output);
	return 0;
}
