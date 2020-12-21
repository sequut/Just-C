#define _CRT_SECURE_NO_WARNINGS
#define CONST 100000000
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct asymptotics_s {
	float step;
	float pokaz;
	float log;
} asymptotics;

void obrabotka(asymptotics* bb, char* str, int i) {
	if (strcmp(str, "O( 1 )") == 0)
		return;

	float a;
	int cnt = 0;
	char* pch = strtok(str, " ");

	while (pch != NULL) {
		if (pch[0] == 'O') {
			pch = strtok(NULL, " ");
			continue;
		}
		if (pch[0] == ')')
			return;

		if (pch[0] == 'N') {
			if (pch[1] != '^')
				bb[i].step = 1;
			else {
				sscanf(pch, "N^%f", &a);
				if (a == 0)
					bb[i].step = -1;
				else
					bb[i].step = a;
			}
		}
		else if (pch[0] == 'l') {
			if (pch[4] != '^')
				bb[i].log = 1;
			else {
				sscanf(pch, "logN^%f", &a);
				if (a == 0)
					bb[i].log = -1;
				else
					bb[i].log = a;
			}
		}
		else {
			sscanf(pch, "%f^N", &a);
			if (a == 1)
				bb[i].pokaz = -1;
			else
				bb[i].pokaz = a;
		}
		pch = strtok(NULL, " ");
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d\n", &n);

	asymptotics* bb = (asymptotics*)calloc(2 * n, sizeof(asymptotics));
	if (bb == 0)
		exit(666);

	char str[100];
	for (int i = 0; i < 2 * n; i++) {
		bb[i].log = -1;
		bb[i].step = -1;
		bb[i].pokaz = -1;
		gets(str);
		obrabotka(bb, str, i);
	}

	for (int i = 0; i < 2 * n; i += 2) {
		if (bb[i].pokaz == bb[i + 1].pokaz && bb[i].step == bb[i + 1].step && bb[i].log == bb[i + 1].log)
			printf("0\n");

		else if ((bb[i].pokaz < bb[i + 1].pokaz) || (bb[i].pokaz == -1 && bb[i + 1].pokaz != -1))
			printf("-1\n");
		else if ((bb[i].pokaz > bb[i + 1].pokaz) || (bb[i + 1].pokaz == -1 && bb[i].pokaz != -1))
			printf("1\n");
		else {
			if ((bb[i].step < bb[i + 1].step) || (bb[i].step == -1 && bb[i + 1].step != -1))
				printf("-1\n");
			else if ((bb[i].step > bb[i + 1].step) || (bb[i + 1].step == -1 && bb[i].step != -1))
				printf("1\n");
			else {
				if ((bb[i].log < bb[i + 1].log) || (bb[i].log == -1 && bb[i + 1].log != -1))
					printf("-1\n");
				else
					printf("1\n");
			}
		}
	}

	free(bb);
	return 0;
}
