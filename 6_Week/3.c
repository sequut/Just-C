#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

typedef struct sStroka_values {
	int counts[127];
	int len;
	char* string;
} Stroka;

void delete(Stroka* stroka) {
	free(stroka->string);
	//stroka->len = 0;
}

void printStroka(Stroka aa) {
	printf("%s\n", aa.string);
}

void zapoln_simv(Stroka* aa, int len) {
	for (int i = 0; i < 127; i++)
		aa->counts[i] = 0;

	for (int i = 0; i < len; i++)
		aa->counts[(int)aa->string[i]] += 1;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d\n", &n);

	Stroka* aa = (Stroka*)malloc(n * sizeof(Stroka));

	if (aa == 0)
		return 0;

	int sost;
	int tek = 0;
	int a;
	char chto;

	for (int i = 0; i < n; i++) {
		scanf("%d ", &sost);

		if (sost == 0) {
			scanf("%d ", &a);

			aa[tek].string = (char*)malloc((a + 1) * sizeof(char));
			
			if (aa[tek].string == 0)
				return 0;

			scanf("%s", aa[tek].string);
			zapoln_simv(&aa[tek], a);
			tek += 1;
		}

		else if (sost == 1) {
			scanf("%d", &a);
			delete(&aa[a]);
		}

		else if (sost == 2) {
			scanf("%d", &a);
			printStroka(aa[a]);
		}

		else {
			scanf("%d %c", &a, &chto);
			printf("%d\n", aa[a].counts[(int)chto]);
		}
	}


	for (int i = 0; i < tek; i++)
		if (aa[i].len!=0)
			free(aa[i].string);
	free(aa);
	return 0;
}
