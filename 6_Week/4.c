#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

typedef struct sList {
	int value;
	int next;
	int prev;
} List;

void delete(List* aa, int chto, int* first, int* last) {
	printf("%d\n", aa[chto].value);
	if (chto == *first)
		*first = aa[*first].next;
	if (chto == *last)
		*last = aa[*last].prev;
	
	aa[aa[chto].prev].next = aa[chto].next;
	aa[aa[chto].next].prev = aa[chto].prev;
}

void printList(List* aa, int first, int last) {
	while (first != -1) {
		printf("%d\n", aa[first].value);
		first = aa[first].next;
	}
}

void after(List* aa, int kuda, int chto, int* first, int* last, int n) {
	aa[n].value = chto;
	printf("%d\n", n);
	if (*last == -1)
		*last = n;

	if (kuda == -1) {
		aa[n].prev = -1;
		aa[n].next = *first;

		aa[*last].next = -1;
		aa[*first].prev = n;
		*first = n;
	}
	else {
		if (kuda == *last)
			*last = n;
		aa[n].next = aa[kuda].next;
		aa[n].prev = kuda;
		aa[aa[kuda].next].prev = n;
		aa[kuda].next = n;
	}
}

void before(List* aa, int kuda, int chto, int* first, int* last, int n) {
	aa[n].value = chto;
	printf("%d\n", n);
	if (*first == -1)
		*first = n;

	if (kuda == -1) {
		aa[n].prev = *last;
		aa[*last].next = n;
		aa[*first].prev = -1;
		
		aa[n].next = -1;
		*last = n;
	}
	else {
		if (kuda == *first)
			*first = n;
		aa[n].prev = aa[kuda].prev;
		aa[n].next = kuda;
		aa[aa[kuda].prev].next = n;
		aa[kuda].prev = n;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d\n", &t);

	int n;
	int first;
	int q;
	int last;
	int oper;
	int kuda;
	int chto;

	for (int j = 0; j < t; j++) {
		scanf("%d %d %d %d\n", &n, &first, &last, &q);
		List* aab = (List*)calloc((n + q + 2), sizeof(List));
		List* aa = aab + 1;
		if (aab == 0)
			return 0;

		for (int i = 0; i < n; i++)
			scanf("%d %d %d\n", &aa[i].value, &aa[i].next, &aa[i].prev);

		aa[-1].next = first;
		aa[-1].prev = last;

		for (int m = 0; m < q; m++) {
			scanf("%d", &oper);

			if (oper == 0) {
				scanf("%d\n", &kuda);
				delete(aa, kuda, &first, &last);
			}
			else if (oper == 1) {
				scanf("%d %d\n", &kuda, &chto);
				after(aa, kuda, chto, &first, &last, n);
				aa[-1].next = first;
				aa[-1].prev = last;
				n += 1;
			}
			else {
				scanf("%d %d\n", &kuda, &chto);
				before(aa, kuda, chto, &first, &last, n);
				aa[-1].next = first;
				aa[-1].prev = last;
				n += 1;
			}
		}

		printf("===\n");
		printList(aa, first, last);
		printf("===\n");
		free(aab);
	}
	return 0;
}
