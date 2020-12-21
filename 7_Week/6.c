#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

typedef struct sList {
	int next;
	int prev;
} List;

void delete(List* aa, int chto, int n) {

	printf("%d\n", chto);

	aa[aa[chto].prev].next = aa[chto].next;
	aa[aa[chto].next].prev = aa[chto].prev;
}


int main() {
	int n, k;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d %d\n", &n, &k);

	List* aa = (List*)calloc((n+1), sizeof(List));

	if (aa == 0)
		exit(1);

	int kol = n;
	int tek = k;
	int pods = k;

	for (int i = 2; i < n; i++) {
		aa[i].next = i + 1;
		aa[i].prev = i - 1;
	}
	aa[1].prev = n;
	aa[1].next = 2;
	aa[n].next = 1;
	aa[n].prev = n - 1;

	while (kol != 1) {
		pods = k;
		delete(aa, tek, n);
		while (pods > 0) {
			tek = aa[tek].next;
			pods -= 1;
		}
		kol -= 1;
	}
	printf("%d", tek);

	free(aa);

	return 0;
}
