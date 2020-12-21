#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int partition(int* a, int n, int pivot) {
	int tek = 0;
	int left_size = 0;
	int* res = (int*)calloc(n, sizeof(int));
	if (res == 0)
		exit(666);

	for (int i = 0; i < n; i++) {
		if (a[i] > pivot) 
			res[n - i - 1] = a[i];

		else if (a[i] < pivot) {
			res[i] = a[i];
			left_size += 1;
		}

		else if (tek == 0) {
			tek = 1;
			res[i] = a[i];
			left_size += 1;
		}
		else {
			tek = 0;
			res[n - i - 1] = a[i];
		}
	}
	a = res;
	free(res);

	return left_size;
};


int main() {

	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	FILE* input = fopen("input.bin", "rb");
	FILE* output = fopen("output.bin", "wb");

	if (input == 0 || output == 0)
		exit(666);

	int n;
	int pivot;

	fread(&n, sizeof(int), 1, input);
	fread(&pivot, sizeof(int), 1, input);

	int* aa = (int*)calloc(n, sizeof(int));

	if (aa == 0)
		exit(666);

	fread(aa, sizeof(int), n, input);


	int k = partition(aa, n, pivot);

	fwrite(&k, sizeof(int), 1, output);
	fwrite(aa, sizeof(int), n, output);


	free(aa);
	
	_fcloseall;
	//fclose(input);
	//fclose(output);
	return 0;
}
