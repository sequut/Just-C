#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>

int main() {
	
	FILE* input = fopen("input.bin", "rb");
	FILE* output = fopen("output.bin", "wb");

	int a;
	int b;

	fread(&a, sizeof(int), 1, input);
	fread(&b, sizeof(int), 1, input);	

	long long int la = a;
	long long int lb = b;

	long long int srav = la + lb;

	int c;
	if (srav < 0) {
		if (srav % 2 == 0)
			c = srav / 2;
		else
			c = (srav / 2) - 1;
	}
	else
		c = srav / 2;

	fwrite(&c, sizeof(int), 1, output);
	fclose(input);
	fclose(output);
	return 0;
}
