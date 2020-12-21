#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>
#include <stdint.h>
#include <string.h>


int merge(const int* a, int ak, const int* b, int bk, int* res) {
	int i = 0;
	int j = 0;
	while (ak > i || bk > j) {
		if (ak > i && bk > j) {
			if (a[i] < b[j]) {
				res[i + j] = a[i];
				i += 1;
			}
			else {
				res[i + j] = b[j];
				j += 1;
			}
		}
		else if (ak > i) {
			res[i + j] = a[i];
			i += 1;
		}
		else if (bk > j) {
			res[i + j] = b[j];
			j += 1;
		}
		
	}
	return 1;
}



int main() {

	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	FILE* input = fopen("input.bin", "rb");
	FILE* output = fopen("output.bin", "wb");

	if (input == 0 || output == 0)
		exit(666);

	int n;
	int m;

	fread(&n, sizeof(int), 1, input);
	fread(&m, sizeof(int), 1, input);

	int* nn = (int*)calloc(n, sizeof(int));
	int* mm = (int*)calloc(m, sizeof(int));
	int* res = (int*)calloc((n + m), sizeof(int));

	if (nn == 0 || mm == 0 || res == 0)
		exit(666);

	for (int i = 0; i < n; i++)
		fread(&nn[i], sizeof(int), 1, input);

	for (int i = 0; i < m; i++)
		fread(&mm[i], sizeof(int), 1, input);


	int a = merge(nn, n, mm, m, res);

	for (int i = 0; i < n + m; i++)
		fwrite(&res[i], sizeof(int), 1, output);


	free(nn);
	free(mm);
	free(res);
	
	_fcloseall;
	//fclose(input);
	//fclose(output);
	return 0;
}
