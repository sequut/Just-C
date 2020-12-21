#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>	

void proverka(int n) {
	if (n > 4)
		printf(",\n");
	else
		printf("\n}\n");
}

void read_and_write_name(int* n, FILE* input) {
	
	unsigned char a;
	printf("\t\"");

	fread(&a, sizeof(char), 1, input);
	*n -= sizeof(char);
	while ((int)a != 0) {
		printf("%c", a);
		fread(&a, sizeof(char), 1, input);
		*n -= sizeof(char);
	}
	printf("\": ");
}

int main() {
	
	FILE* input = fopen("input.bin", "rb");
	freopen("output.txt", "w", stdout);

	int n;
	fread(&n, sizeof(int), 1, input);
	n -= sizeof(int);

	unsigned char t;

	printf("{\n");

	int a;
	long long int b;
	double c;
	char ch;

	
	while (n > 0) {
		fread(&t, sizeof(unsigned char), 1, input);
		n -= sizeof(unsigned char);

		if ((int)t == 1) {
			read_and_write_name(&n, input);
			fread(&c, sizeof(double), 1, input);
			n -= sizeof(double);
			printf("%0.15g", c);
			proverka(n);

		}
		
		else if((int)t == 2) {
			read_and_write_name(&n, input);
			fread(&a, sizeof(int), 1, input);
			n -= sizeof(int);

			printf("\"");

			for (int i = 0; i < a-1; i++) {
				fread(&ch, sizeof(char), 1, input);
				n -= sizeof(char);
				printf("%c", ch);
			}
			printf("\"");
			proverka(n);
		}

		else if ((int)t == 8) {
			read_and_write_name(&n, input);
			fread(&ch, sizeof(unsigned char), 1, input);
			n -= sizeof(unsigned char);
			if ((int)ch == 0)
				printf("false");
			else
				printf("true");
			proverka(n);
		}

		else if ((int)t == 10) {
			read_and_write_name(&n, input);
			printf("null");
			proverka(n);
		}

		else if ((int)t == 16) {
			read_and_write_name(&n, input);
			fread(&a, sizeof(int), 1, input);
			n -= sizeof(int);
			printf("%d", a);
			proverka(n);
		}
		else if ((int)t == 18) {
			read_and_write_name(&n, input);
			fread(&b, sizeof(long long int), 1, input);
			n -= sizeof(long long int);
			printf("%lld", b);
			proverka(n);
		}
	}

	fclose(input);
	return 0;
}
