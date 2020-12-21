#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 


typedef struct sList{
	char value[8];
	int ind;
} List; 

void sort(List* aa, int n) {
	char hp[8];
	int pom;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (aa[j].ind > aa[j+1].ind) {
				strcpy(hp, aa[j].value);
				strcpy(aa[j].value, aa[j + 1].value);
				strcpy(aa[j + 1].value, hp);

				pom = aa[j].ind;
				aa[j].ind = aa[j+1].ind;
				aa[j+1].ind = pom;

			}
		}
	}
}


int main() {

	int n;
	char str[8];
	int ind;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &n);

	List* aa = (List*)calloc((1000000 + 1), sizeof(List));
	if (aa == 0)
		return 0;

	for (int i = 0; i < n; i++)
		scanf("%d %s\n", &aa[i].ind, &aa[i].value);
	
	sort(aa, n);

	for (int i = 0; i < n; i++)
		printf("%d %s\n", aa[i].ind, aa[i].value);


	free(aa);
	return 0;
}
