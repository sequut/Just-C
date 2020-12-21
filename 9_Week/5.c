#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

void partition_v2(int* aa, int* left, int* right, int pivot) {
	int help;

	while (aa[*left] < pivot)
		*left += 1;
	while (aa[*right] > pivot)
		*right -= 1;

	if (*left <= *right) {
		help = aa[*left];
		aa[*left] = aa[*right];
		aa[*right] = help;
		*left += 1;
		*right -= 1;
	}

	while (*left <= *right) {
		while (aa[*left] < pivot)
			*left += 1;
		while (aa[*right] > pivot)
			*right -= 1;

		if (*left <= *right) {
			help = aa[*left];
			aa[*left] = aa[*right];
			aa[*right] = help;
			*left += 1;
			*right -= 1;
		}
	}
}


void quicksort(int* aa, int len) {
	int left = 0;
	int right = len - 1;
	int pivot = aa[len / 2];

	partition_v2(aa, &left, &right, pivot);

	if (right > 0)
		quicksort(aa, right + 1);

	if (left < len)
		quicksort(&aa[left], len - left);
}


int main() {
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	FILE* input = fopen("input.bin", "rb");
	FILE* output = fopen("output.bin", "wb");

	if (input == 0 || output == 0)
		exit(666);

	int n;

	fread(&n, sizeof(int), 1, input);

	int* aa = (int*)calloc(n, sizeof(int));

	if (aa == 0)
		exit(666);

	fread(aa, sizeof(int), n, input);

	quicksort(aa, n);

	fwrite(aa, sizeof(int), n, output);

	free(aa);
	fclose(input);
	fclose(output);
	return 0;
}
