
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Help_s {
	int n;
	char* str[100];
}Help;

void take(Help* aa) {
	aa->str[aa->n - 1] = (char*)calloc(101, sizeof(char));
	if (aa->str[aa->n - 1] == 0)
		exit(666);
}

void print_an(Help aa) {
	for (int i = 0; i < aa.n; i++)
		printf("[%s]\n", aa.str[i]);
}

void clear(Help* aa) {
	for (int i = 0; i < aa->n; i++)
		free(aa->str[i]);
}

Help parse(char* str) {
	Help aa = {0};

	int i = 0;
	int sost = 0;

	int count = 0;

	while (str[i] != '\0') {
		if (str[i] == '"') {
			i += 1;
			aa.n += 1;
			count = 0;
			take(&aa);
			while (str[i] != '"') {
				aa.str[aa.n - 1][count] = str[i];
				i += 1;
				count += 1;
			}
			aa.str[aa.n - 1][count] = '\0';
			count = 0;
		}
		else {
			if (str[i] == ' ') {
				sost = 0;
				count = 0;
			}
			else {
				if (sost == 0) {
					aa.n += 1;
					count = 0;
					take(&aa);
				}			
				sost = 1;
				aa.str[aa.n - 1][count] = str[i];
				count += 1;
				if (str[i + 1] == ' ' || str[i + 1] == '\0') {
					sost = 0;
					aa.str[aa.n - 1][count] = '\0';
					count = 0;
				}
			}
		}
		i += 1;
	}
	return aa;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	char* str[102];
	gets(str);
	Help answer;
	answer = parse(str);
	print_an(answer);
	clear(&answer);
	return 0;
}