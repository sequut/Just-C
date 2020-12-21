#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

typedef struct sList{
	char value[8];
	int next;
} List;

void delete(List* aa, int kuda, int* first) {
	if (kuda == -1) {
		printf("%s\n", aa[*first].value);
		*first = aa[*first].next;
	}
	else {
		printf("%s\n", aa[aa[kuda].next].value);
		aa[kuda].next = aa[aa[kuda].next].next;
	}
}//rabotaet

void razd() {
	printf("===\n");
}//rabotaet

void printList(List* aa, int first) {
	while (first != -1) {
		printf("%s\n", aa[first].value);
		first = aa[first].next;
	}
}//rabotaet

void add(List* aa, int kuda, char* chto, int* first, int n) {
	
	strcpy(aa[n].value, chto);
	if (kuda == -1) {
		aa[n].next = *first;
		*first = n;
	}
	else {
		aa[n].next = aa[kuda].next;
		aa[kuda].next = n;
	}
	
	printf("%d\n", n);
}


void test(int n, int f, int q) {
	List* aa = (List*)calloc((n+q+1), sizeof(List));
	if (aa == 0)
		return 0;

	for (int i = 0; i < n; i++)
		scanf("%s %d\n", aa[i].value, &aa[i].next);

	int oper;
	int kuda;
	char chto[8];
	
	for (int i = 0; i < q; i++) {
		scanf("%d ", &oper);
		if (oper == 0) {
			scanf("%d %s", &kuda, &chto);
			add(aa, kuda, chto, &f, n);
			n += 1;
		}
		else {
			scanf("%d", &kuda);
			delete(aa, kuda, &f);
		}
	}
	razd();
	printList(aa, f);
	razd();
	free(aa);
}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d\n", &t);

	int n;
	int f;
	int q;

	for (int i = 0; i < t; i++) {
		scanf("%d %d %d\n", &n, &f, &q);
		test(n, f, q);
	}
	return 0;
}
