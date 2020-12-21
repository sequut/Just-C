#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

char** aa[1000001] = { 0 };
int sch[1000001] = { 0 };

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;
	scanf("%d\n", &n);

	for (int i = 0; i < n; i++) {
		char str [8];
		scanf("%d %s", &m, str);

		aa[m] = (char**)realloc(aa[m], (sch[m]+1)*sizeof(char*));
		if (aa[m] == 0) 
			exit(666);

		aa[m][sch[m]] = (char*)malloc(strlen(str) * sizeof(char));
		if (aa[m][sch[m]] == 0) 
			exit(666);

		strcpy(aa[m][sch[m]], str);
		sch[m] += 1;

	}
	for (int i = 0; i < 1000001; i++) {
		for (int j = 0; j < sch[i]; j++) {
			printf("%d %s\n", i, aa[i][j]);
			if (aa[i][j] > 0) {
				free(aa[i][j]);
			}
		}
		if (aa[i] > 0) {
			free(aa[i]);
		}

	}
	return 0;
}
