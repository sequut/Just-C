#define kol_razd 4
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h>

typedef struct Tokens_s {
	int num;
	char** arr;
} Tokens;

char cy[1000001];

void tokensSplit(Tokens* tokens, const char* str, const char* delims, int l) {
	if (tokens->arr == NULL) {
		int i = 0;
		int idet = 0;
		int znak = 0;
		int kol_slov = 0;

		while (str[i] != '\0') {
			znak = 0;
			for (int j = 0; j < l; j++)
				if (str[i] == delims[j]) {
					znak = 1;
					break;
				}
			if (znak == 0) {
				idet = 1;
			}

			else if (idet == 1) {
				idet = 0;
				kol_slov += 1;
			}
			i += 1;
		}
		if (idet == 1)
			kol_slov += 1;
		tokens->num = kol_slov;
	}

	else {
		int kol_slov = tokens->num;
		printf("%d\n", kol_slov);

		int i = 0;
		int idet = 0;
		int znak = 0;
		int tek = 0;
		int nach_sl = 1000001;

		int sch_cy = 0;

		while (str[i] != '\0') {
			znak = 0;
			for (int j = 0; j < l; j++)
				if (str[i] == delims[j]) {
					znak = 1;
					break;
				}

			if (znak == 0) {
				if (i < nach_sl)
					nach_sl = i;
				idet = 1;
				cy[sch_cy] = str[i];
				sch_cy += 1;
			}

			else if (idet == 1) {
				cy[sch_cy] = '\0';
				tokens->arr[tek] = (char*)malloc((i - nach_sl + 2) * sizeof(char));
				strcpy(tokens->arr[tek], cy);

				idet = 0;

				sch_cy = 0;
				nach_sl = 1000001;

				printf("%s\n", tokens->arr[tek]);
				idet = 0;
				tek += 1;
			}
			i += 1;
		}

		if (idet == 1) {
			cy[sch_cy] = '\0';
			tokens->arr[tek] = (char*)malloc((i - nach_sl + 2) * sizeof(char));
			strcpy(tokens->arr[tek], cy);
			nach_sl = 1000001;
			printf("%s\n", tokens->arr[tek]);
		}
	}

}

void tokensFree(Tokens* tokens) {
	for (int i = 0; i < tokens->num; i++)
		if (tokens->arr[i]!=NULL) {
			free(tokens->arr[i]);
			tokens->arr[i] = NULL;
		}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	char aa[1000001];
	scanf("%s", aa);
	int l = 4;
	char delims[kol_razd] = { ',', '.', ':', ';' };

	Tokens tokens;
	tokens.num = -1;
	tokens.arr = NULL;

	//printf("%x", &tokens.arr);
	tokensSplit(&tokens, aa, delims, l);
	tokens.arr = (char**)malloc(tokens.num * sizeof(char*));
	tokensSplit(&tokens, aa, delims, l);

	tokensFree(&tokens);
	tokensFree(&tokens);
	tokensFree(&tokens);

	return 0;
}
