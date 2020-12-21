#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>

typedef union perevod_u {
	int val;
	char mas[4];
}perevod;

void reverse(char* str) {
	char help;
	help = str[0];
	str[0] = str[3];
	str[3] = help;

	help = str[1];
	str[1] = str[2];
	str[2] = help;
}

int main() {
	
	FILE* input = "input.bin";
	FILE* output = "output.bin";

	input = fopen(input, "rb");
	output = fopen(output, "wb");

	perevod n;
	perevod x;
	perevod su;
	su.val = 0;

	
	fread(&n.val, sizeof(int), 1, input);

	if (n.val > 10000 || n.val < 1) {
		reverse(n.mas);
		for (int i = 0; i < n.val; i++) {
			fread(&x.val, sizeof(int), 1, input);
			reverse(x.mas);

			su.val += x.val;
		}
		reverse(su.mas);
	}
	else {
		for (int i = 0; i < n.val; i++) {
			fread(&x.val, sizeof(int), 1, input);
			su.val += x.val;
		}
	}
	fwrite(&su, sizeof(int), 1, output);


	fclose(input);
	fclose(output);
		

	return 0;
}
