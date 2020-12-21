#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>
#include <stdint.h>

typedef struct stroka_s {
	uint8_t str[66];
	int le;
}stroka;
stroka aa[10001] = {0};

int main() {

	FILE* input = fopen("input.bin", "rb");
	FILE* output = fopen("output.bin", "wb");
	if ((input == 0) || (output == 0))
		return 0;

	int n;
	fread(&n, sizeof(int), 1, input);

	int l;
	for (int i = 0; i < n; i++) {
		fread(&l, sizeof(int), 1, input);
		aa[i].le = l;
		fread(&aa[i].str, sizeof(uint8_t), l, input);
		aa[i].str[l] = 9;
	}

	int m;
	fread(&m, sizeof(int), 1, input);
	uint16_t chto;
	int tek_razr = 0;
	uint8_t sum = 0;

	for (int i = 0; i < m; i++) {
		fread(&chto, sizeof(uint16_t), 1, input);

		for (int j = 0; j < aa[chto].le; j++) {
			sum += aa[chto].str[j] * (1 << tek_razr);
			tek_razr += 1;

			if (tek_razr == 8) {
				fwrite(&sum, sizeof(uint8_t), 1, output);
				sum = 0;
				tek_razr = 0;
			}
		}
	}
	if (tek_razr != 0)
		fwrite(&sum, sizeof(uint8_t), 1, output);

	fclose(input);
	fclose(output);

	return 0;
}
