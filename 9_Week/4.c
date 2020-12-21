#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

void Merge(int* aa, int left, int middle, int right) {

	int* LEFT = (int*)calloc((middle - left), sizeof(int));
	int* RIGHT = (int*)calloc((right - middle), sizeof(int));

	if (LEFT == 0 || RIGHT == 0)
		exit(666);

	for (int i = 0; i < middle - left; i++)
		LEFT[i] = aa[left + i];

	for (int i = 0; i < right - middle; i++)
		RIGHT[i] = aa[middle + i];

	int indL = 0;
	int indR = 0;

	for (int i = left; i < right; i++) {
		if ((indL < middle - left) && (indR < right - middle)) {
			if (RIGHT[indR] > LEFT[indL]) {
				aa[i] = LEFT[indL];
				indL += 1;
			}
			else {
				aa[i] = RIGHT[indR];
				indR += 1;
			}
		}
		else if (indL < middle - left) {
			aa[i] = LEFT[indL];
			indL += 1;
		}
		else {
			aa[i] = RIGHT[indR];
			indR += 1;
		}
	}
}

void Merge_sort(int* aa, int left, int right) {
	if ((right - left) < 2)
		return;

	int middle = (left + right) / 2;
	Merge_sort(aa, left, middle);
	Merge_sort(aa, middle, right);
	Merge(aa, left, middle, right);
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

	Merge_sort(aa, 0, n);
	

	fwrite(aa, sizeof(int), n, output);

	free(aa);
	fclose(input);
	fclose(output);
	return 0;
}
